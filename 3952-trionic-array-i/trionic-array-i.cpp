class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;

        while(i < n-1 && nums[i]< nums[i+1] )
            i++;
        while(j > 0 && nums[j] > nums[j-1])
            j--;

          if (i == 0 || j == n - 1 || i >= j)
            return false;
        
        while(i < j)
        {
            if(nums[i] <= nums[i+1])
                return false;
                i++;
        }
        
        return true;
    }
};