class Solution {
public:
/* Think, if you run n2 for finding minimums is it worth it. like the minimuim difference will always be with the closest possible value. so using that fact we can combine both the passes into one. we know that if we encounter a new min difference, that means it was not before so all the pairs before this pair that we thought is minimum is not actually minimum. And it starts from my current pair. Remember only the closest value will give the minimum pair so no point comparing with every value in sorted array. */
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        int difference = INT_MAX;
        vector<vector<int>> ans;

        // for(int i = 1;i<arr.size();i++)
        // {
        //     difference = min(difference,abs(arr[i] - arr[i-1]));
        // }
       
        // for(int i = 0;i<arr.size();i++)
        // {
        //     for(int j = i+1;j<arr.size();j++)
        //     {
        //         if(abs(arr[i] - arr[j]) == difference)
        //         {
        //             ans.push_back({arr[i],arr[j]});
        //         }
        //         if(abs(arr[i] - arr[j]) > difference)
        //             break;
        //     }
        // }

        for(int i = 1;i<arr.size();i++)
        {
            int mindif = abs(arr[i] - arr[i-1]);
            if(mindif < difference)
            {
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
                difference = mindif;
            }
            else if( mindif == difference)
            {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};