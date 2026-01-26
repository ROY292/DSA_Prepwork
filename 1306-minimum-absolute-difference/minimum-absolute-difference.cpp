class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        int difference = INT_MAX;

        for(int i = 1;i<arr.size();i++)
        {
            difference = min(difference,abs(arr[i] - arr[i-1]));
        }
        vector<vector<int>> ans;
        for(int i = 0;i<arr.size();i++)
        {
            for(int j = i+1;j<arr.size();j++)
            {
                if(abs(arr[i] - arr[j]) == difference)
                {
                    ans.push_back({arr[i],arr[j]});
                }
                if(abs(arr[i] - arr[j]) > difference)
                    break;
            }
        }
        return ans;
    }
};