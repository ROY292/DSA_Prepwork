class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        

        unordered_set<int> mp;

        for(auto x: nums)
            mp.insert(x);

        while(mp.find(original)!= mp.end())
            original*=2;
        
        return original;

    }
};