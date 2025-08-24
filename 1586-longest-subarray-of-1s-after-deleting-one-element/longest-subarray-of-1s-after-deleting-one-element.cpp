class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        if(nums.size()== 1) return 0;

        vector<int> left(nums.size(),0),right(nums.size(),0);

        left[0] = nums[0];
        right[nums.size()-1] = nums[nums.size()-1];

        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                left[i] = 0;
            }
            else
            {
                left[i] = left[i-1] + nums[i];
            }
        }

        for(int i = nums.size()-2;i>=0;i--)
        {
            if(nums[i] == 0)
            {
                right[i] = 0;
            }
            else
            {
                right[i] = right[i+1] + nums[i];
            }
        }
        if(left[nums.size()-1] == nums.size())
            return nums.size()-1;
      

        int ans = 0;
        // for(auto x: left)
        //     cout<<" left: "<<x<<endl;
        
        // for(auto x: right)
        //     cout<<" right: "<<x<<endl;

        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                if(i == 0)
                    ans = max(ans, right[i+1]);
                else if(i == nums.size()-1)
                    ans = max(ans, left[i-1]);
                else
                    ans = max(ans, (left[i-1] + right[i+1]));
            }
        }

        return ans;

        
    }

};