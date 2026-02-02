// class Solution {
//     private:
//     struct Cmp {
//     vector<int>* nums;

//     Cmp(vector<int>* n) : nums(n) {}

//     bool operator()(int i, int j) const {
//         if ((*nums)[i] != (*nums)[j])
//             return (*nums)[i] < (*nums)[j];
//         return i < j;   // tie-breaker (VERY important)
//     }
// };

// public:
//     long long minimumCost(vector<int>& nums, int k, int dist) {
//         set<int, Cmp> selected(Cmp(&nums));
//         set<int, Cmp> remaining(Cmp(&nums));

//         long long ans = INT_MAX;
//         long long curr = nums[0];
//         int j = 0;
//         for(j = 1;j<= dist + 1;j++)
//         {
//             selected.insert(nums[j]);
//         }
//         while(selected.size() > k-1)
//         {
//             long long temp = *selected.rbegin();
//             selected.erase(*selected.rbegin());
//             remaining.insert(temp);
//         }

//         for(auto x: selected)
//         {
//             curr+= x;
//         }
//         ans = min(ans,curr);

//         for(int i = 2;j<nums.size()-1;i++,j++)
//         {
//             //removal part
//             if(selected.count(nums[i-1]))
//             {
//                 curr -= nums[i-1];
//                 selected.erase(nums[i-1]);
//             }
//             else
//             {
//                 remaining.erase(nums[i-1]);
//             }

//             //addition part
//             remaining.insert(nums[j+1]);
//             long long rem = *remaining.begin();
//             if( selected.size() == k-1)
//             {
//                 if(*selected.rbegin() > rem)
//                 {
//                     remaining.erase(rem);
//                     remaining.insert(*selected.rbegin());
//                     curr-= *selected.rbegin();
//                     selected.erase(*selected.rbegin());
//                     selected.insert(rem);
//                     curr+= rem;
//                 }
//             }
//             else
//             {
//                 selected.insert(rem);
//                 curr+=rem;
//             }

//             ans = min(ans,curr);
//         }

//         return ans;
//     }
// };

// two multisets maintain the first k smallest values
class Container {
public:
    Container(int k) : k(k), sm(0) {}

    // adjust the size of the ordered set to ensure that the first k smallest
    // values are all in st1
    void adjust() {
        while (st1.size() < k && st2.size() > 0) {
            int x = *(st2.begin());
            st1.emplace(x);
            sm += x;
            st2.erase(st2.begin());
        }
        while (st1.size() > k) {
            int x = *prev(st1.end());
            st2.emplace(x);
            st1.erase(prev(st1.end()));
            sm -= x;
        }
    }

    // insert element x
    void add(int x) {
        if (!st2.empty() && x >= *(st2.begin())) {
            st2.emplace(x);
        } else {
            st1.emplace(x);
            sm += x;
        }
        adjust();
    }

    // delete element x
    void erase(int x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            st1.erase(it), sm -= x;
        } else {
            st2.erase(st2.find(x));
        }
        adjust();
    }

    // sum of the first k smallest elements
    long long sum() { return sm; }

private:
    int k;
    // st1 saves the k smallest values, st2 saves the other values
    multiset<int> st1, st2;
    // sm represents the sum of the first k smallest elements
    long long sm;
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // sliding window initialization
        Container cnt(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        long long ans = cnt.sum() + nums[k - 1];
        // enumerate the beginning of the last array
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.erase(nums[j]);
            }
            cnt.add(nums[i - 1]);
            ans = min(ans, cnt.sum() + nums[i]);
        }

        return ans + nums[0];
    }
};