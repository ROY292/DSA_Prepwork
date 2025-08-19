class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, ans = 0;

        for(auto x: nums)
        {
            if(x==0)
            {
                cnt++;
                ans+=cnt;
            }
            else
                cnt = 0;
        }

        return ans;
    }
};