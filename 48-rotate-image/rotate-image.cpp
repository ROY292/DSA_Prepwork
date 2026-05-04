class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        
        
        for(int i = 0 ;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix.size();j++)
            {
               if(j>=i)
                swap(matrix[i][j],matrix[j][i]);
                
            }
        }
        
        // note that if you're doing transpose of a matrix, only tranpose the upper half triangle or you will end up getting the same matrix as the beginning one.
        
        for(int i = 0;i<matrix.size();i++)
        {
            int l = 0,r = matrix.size()-1;
            while(l<r)
            {
                swap(matrix[i][l],matrix[i][r]);
                l++;r--;
            }
        }
    }
};