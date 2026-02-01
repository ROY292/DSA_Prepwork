class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        if(n == 3)
        {
            sum = accumulate(nums.begin(),nums.end(),0);
            return sum;
        }
        sort(nums.begin()+1,nums.end());
        for(int i = 0;i<3;i++)
            sum+= nums[i];
        
        return sum;
        
    }
};