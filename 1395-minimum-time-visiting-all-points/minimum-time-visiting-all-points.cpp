class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        

        int total = 0;
        int p1 = points[0][0], p2 = points[0][1];

        for(auto x: points)
        {
           
                int a = abs(x.at(0) - p1);
                int b = abs(x.at(1) - p2);

                total+= max(a,b);
                p1 = x.at(0);
                p2 = x.at(1);
            
        }

        return total;
    }
};