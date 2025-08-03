class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        vector<int> ans;

        ans.push_back(nums[0]);
        int prev = nums[0];
        for(auto x: nums){
            if(x!= prev)
            {
                prev = x;
                ans.push_back(x);
            }
        }

        for(auto &x: ans)
            cout<<" ans: "<<x<<endl;
        int hilval = 0;
        for(int i = 1;i<ans.size()-1;i++)
        {
            if((ans[i] > ans[i-1] && ans[i] > ans[i+1]) || (ans[i] < ans[i-1] && ans[i] < ans[i+1]))
                hilval++;
        }
        
        return hilval;
    }
};