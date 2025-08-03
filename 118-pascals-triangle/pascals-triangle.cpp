class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i = 1;i<numRows;i++)
        {
            int len = ans[i-1].size();
            cout<<" len: "<<len<<endl;
            vector<int> temp;
            int combiner = 0;
            for(auto x:ans[i-1])
            {
                temp.push_back(combiner+x);
                combiner = x;
            }
            temp.push_back(1);
            ans.push_back(temp);
        }

        return ans;
    }
};