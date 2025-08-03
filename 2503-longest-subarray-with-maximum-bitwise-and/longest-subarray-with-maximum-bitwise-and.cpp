class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int mx = *max_element(nums.begin(),nums.end());
        cout<<" Mx: "<<mx<<endl;

        int ans = 0;
        int cnt = 0;
        for(auto x: nums)
        {
            if(x==mx)
            {
                cnt++;
            }
            else
            {
                ans = max(ans,cnt);
                cnt = 0;
            }
        }
        ans = max(ans,cnt);

        return ans;
    }
};