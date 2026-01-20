class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans (nums.size(),-1);


        for(int i = 0 ;i <nums.size();i++)
        {
            int temp = 0;
            while(temp <= nums[i])
            {
                if((temp | (temp + 1)) == nums[i])
                {
                    ans[i] = temp;
                    break;
                }
                temp++;
            }
            if(temp > nums[i])
                ans[i] = -1;
        }

        return ans;
    }
};