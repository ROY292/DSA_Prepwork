class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        

        int row = m.size(), col = m[0].size();
        vector<vector<int>> v(row,vector<int>(col,0));

        for(int i = 0;i<row;i++)
        {
            if(m[i][0] == '0')
                v[i][0] = 0;
            else
                v[i][0] = 1;
        }
        for(int i = 0;i<col;i++)
        {
            if(m[0][i] == '0')
                v[0][i] = 0;
            else
                v[0][i] = 1;
        }

        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(m[i][j] == '0') continue;
                else if((i==0 || j == 0))
                {
                    continue;
                }
                else
                {
                    v[i][j] = 1 + min(v[i-1][j],min(v[i][j-1],v[i-1][j-1]));
                }
            }
        }

        int mx = 0;
        for(auto x: v)
        {
            for(auto y: x)
            {
               // cout<<" x: "<<y;
                mx = max(mx,y);
            }
           // cout<<endl;
        }
        return mx*mx;
    }
};