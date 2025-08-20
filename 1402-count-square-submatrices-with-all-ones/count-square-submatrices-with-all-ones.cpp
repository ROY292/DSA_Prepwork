class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int row = m.size(),col = m[0].size();
        vector<vector<int>> v(row,vector<int> (col,0));

        for(int i = 0 ;i<row;i++)
        {
            v[i][0] = m[i][0];
        }
        for(int i = 0;i<col;i++)
        {
            v[0][i] = m[0][i];
        }

        // for(auto x: v)
        // {
        //     for(auto y: x)
        //     {
        //         cout<<" x: "<<y;
        //     }
        //     cout<<endl;
        // }
        for(int i = 0;i<row;i++)
        {
            for(int j = 1;j<col;j++)
            {
                if(m[i][j] == 0) continue;
                else
                {
                    if(i > 0 && j > 0)
                    {
                        if(m[i][j-1] == 1 && m[i-1][j] == 1 && m[i-1][j-1]==1)
                        {
                            v[i][j] = 1 + min(v[i][j-1],min(v[i-1][j], v[i-1][j-1]));
                        }
                        else
                        {
                            v[i][j] = 1;
                        }
                    }
                }
            }
        }
        int sum = 0;
        for(auto x: v)
        {
            for(auto y: x)
            {
                sum+=y;
            }
            
        }

        return sum;
    }
};