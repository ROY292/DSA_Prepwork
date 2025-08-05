class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        for(int i = 0;i<fruits.size();i++)
        {
            for(int j =0;j<fruits.size();j++)
            {
                if(baskets[j] >= fruits[i])
                { 
                    fruits[i] = -1;
                    baskets[j] = -1;
                    break;
                }
            }
        }

        int ans = 0;
        for(auto x: fruits)
        {
         
            if(x!= -1)
                ans++;
        }

        return ans;
    }
};