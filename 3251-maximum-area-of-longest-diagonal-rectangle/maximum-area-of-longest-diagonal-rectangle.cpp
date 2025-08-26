class Solution {
public:
    int aor(int x, int y)
    {
        return x*y;
    }
    double pytho(int x, int y)
    {
        return sqrt((x*x) + (y*y));
    }
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = aor(dimensions[0][0],dimensions[0][1]);
        double mx = pytho(dimensions[0][0],dimensions[0][1]);

        for(auto &x: dimensions)
        {
            double temp = pytho(x[0],x[1]);
            if(temp >= mx)
            {
               
                if(temp == mx)
                    ans = max(ans,aor(x[0],x[1]));
                else
                    ans = aor(x[0],x[1]);

                mx = temp;
                
            }
        }


        return ans;
    }
};