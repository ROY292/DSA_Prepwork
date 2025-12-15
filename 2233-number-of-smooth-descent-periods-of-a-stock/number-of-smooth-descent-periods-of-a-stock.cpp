// class Solution {
// public:
//     long long getDescentPeriods(vector<int>& prices) {
//         long long cnt = 0;

//         for(int i = 0;i<prices.size();i++)
//         {
//             long long temp =0;
//             for(int j = i;j<prices.size();j++)
//             {
//                 if(j == i)
//                     temp++;
//                 else if(prices[j-1] - prices[j] == 1)
//                     temp++;
//                 else
//                     break;
//             }
//             cnt+=temp;
//         }

//         return cnt;
//     }


// };

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 1;  // total number of smooth descending periods,
                            // initial value is dp[0]
        int prev = 1;  // total number of smooth descending periods ending with
                       // the previous element, initial value is dp[0]
        // traverse the array starting from 1, and update prev and the total res
        // according to the recurrence relation
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ++prev;
            } else {
                prev = 1;
            }
            res += prev;
        }
        return res;
    }
};