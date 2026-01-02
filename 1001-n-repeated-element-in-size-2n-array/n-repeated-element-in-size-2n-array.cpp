class Solution {
public:
    // int repeatedNTimes(vector<int>& nums) {
    //     int obj = nums[0];
    //     int cnt = 1;

    //     for (int i = 1; i < nums.size(); i++) {
    //         if (nums[i] == obj)
    //             cnt++;
    //         else
    //             cnt--;

    //         if (cnt == 0) {
    //             obj = nums[i];
    //             cnt = 1;
    //         }
    //     }
    //     return obj;
    // } boyers murray not applicable since the count is strictly n/2 not more

    int repeatedNTimes(vector<int>& nums) {
    unordered_set<int> seen;
    for (int x : nums) {
        if (seen.count(x)) return x;
        seen.insert(x);
    }
    return -1;
}

};
