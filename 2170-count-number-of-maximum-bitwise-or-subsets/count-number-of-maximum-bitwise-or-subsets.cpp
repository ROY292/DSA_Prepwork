class Solution {
public:
vector<vector<int>> generateSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    int n = nums.size();
    int total = 1 << n;  // 2^n subsets

    for (int mask = 0; mask < total; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }

    return subsets;
}

    int countMaxOrSubsets(vector<int>& nums) {

        int maxOR = 0;

        for(auto x: nums)
            maxOR|= x;

        
        // sort(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.end());

        // for(int i = 0;i<nums.size();++)
        // {
        //     int txor = nums[i];
        //     for(int j = i;j<nums.size();j++)
        //     {
        //         txor |= nums[j];
        //         if(txor == maxOR)
        //         {
        //             ans+= nums.size() - j - 1;
        //         }
        //     }
        // }
        int ans=0;
        vector<vector<int>> vec = generateSubsets(nums);

        for(auto x: vec)
        {
            int txor = 0;
            for(auto i: x)
            {
                txor|=i;
                if(txor == maxOR)
                {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};