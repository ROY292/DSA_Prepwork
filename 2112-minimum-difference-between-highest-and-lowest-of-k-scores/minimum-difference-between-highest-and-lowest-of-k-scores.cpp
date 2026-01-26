// class Solution {
// public:
//     int minimumDifference(vector<int>& nums, int k) {
        
//         int diff = INT_MAX;

//         sort(nums.begin(),nums.end());

//         for(int i = 0; i < nums.size() - k + 1;i+=k)
//         {
//             int mindiff = nums[i];
//             int j = 0;
//             while(j<=k)
//             {
//                 j++;
//                 if(i+j >= nums.size())
//                 {    break; // overflow changes are there in case only single element is there for example.
//                 }
//                 else{ 
//                 mindiff = nums[i+j] - mindiff;
//                 }
                
//             }
//             diff = min(diff,mindiff);

//         }
//         return diff;
//     }
// };

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};