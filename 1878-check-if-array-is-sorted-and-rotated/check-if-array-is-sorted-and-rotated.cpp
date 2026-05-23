class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());

        int n = nums.size();
        int cnt = n;
        while(cnt--)
        {
            if(nums == sorted)  return true;
            int temp = nums[0];
            for(int i = 0;i<n-1;i++)
            {
                
                nums[i] = nums[i+1];
            }
            nums[n-1] = temp;
            
        }
            return false;
        // for(int i = 0;i<n;i++)
        // {
        //     if(nums[i] != sorted[i])
        //         return false;
        // }
        // return true;
    }
};