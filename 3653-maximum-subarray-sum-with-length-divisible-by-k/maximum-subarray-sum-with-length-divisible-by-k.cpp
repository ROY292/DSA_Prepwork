// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k) {
        
//         long long m = 0;
//         long long n = INT_MIN;

//         for(int i = 0;i<nums.size();i++)
//         {
//             long long subs = 0;
//             for(int j = i;j<nums.size();j++)
//             {
//                 subs+=nums[j];
//                 if((j-i)%k == 0)
//                 {
//                     cout<<" i: "<<i<<" j: "<<j<<endl;
//                     if((j-i)> m)
//                     {
//                         m = (j-i);
//                         n = subs;
//                     }
//                     cout<<" m: "<<m<<endl;
//                 }
                
//             }
//         }

//         return n;
//     }
// };


class Solution {

   public:
   long long maxSubarraySum(vector<int>& nums, int k) {
    vector<long long> ps(1);
    for (int n : nums)
        ps.push_back(ps.back() + n);
    long long res = LLONG_MIN;
    for (int p = 0; p < k; ++p) {
        long long sum = 0;
        for (int i = p; i + k <= nums.size(); i += k) {
            long long n = ps[i + k] - ps[i];
            sum = max(n, sum + n);
            res = max(res, sum);
        }
    }
    return res;
}
};