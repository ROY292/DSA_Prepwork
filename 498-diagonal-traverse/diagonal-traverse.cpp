// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
//         int row = mat.size();
//         int col = mat[0].size();

//         vector<int> v;

//         for(int it = 0;it<row;it++)
//         {
//             if(it%2 ==0)
//             {
//                 int i = it;
//                 int j = 0;
//                 while(i>=0)
//                 {
//                     v.push_back(mat[i][j]);
//                     i--;
//                     j++;
//                 }

//             }else
//             {
//                 int i = 0;
//                 int j = it;
//                 while(j>=0)
//                 {
//                     v.push_back(mat[i][j]);
//                     i++;
//                     j--;
//                 }
//             }
//         }

//         for(int it = col-1;it>=0;it--)
//         {
//             if(it%2 ==0)
//             {
//                 int i = col;
//                 int j = it;
//                 while(i>=it)
//                 {
//                     v.push_back(mat[i][j]);
//                     i--;
//                     j++;
//                 }

//             }else
//             {
//                 int i = it;
//                 int j = col;
//                 while(j>=it)
//                 {
//                     v.push_back(mat[i][j]);
//                     i++;
//                     j--;
//                 }
//             }
//         }

//         return v;
//     }
// };

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> v;

        // Phase 1: diagonals starting from first row
        for (int it = 0; it < col; it++) {
            int i = 0, j = it;
            vector<int> temp;
            while (i < row && j >= 0) {
                temp.push_back(mat[i][j]);
                i++;
                j--;
            }
            if (it % 2 == 0) reverse(temp.begin(), temp.end());
            v.insert(v.end(), temp.begin(), temp.end());
        }

        // Phase 2: diagonals starting from last column
        for (int it = 1; it < row; it++) {
            int i = it, j = col - 1;
            vector<int> temp;
            while (i < row && j >= 0) {
                temp.push_back(mat[i][j]);
                i++;
                j--;
            }
            if ((col + it - 1) % 2 == 0) reverse(temp.begin(), temp.end());
            v.insert(v.end(), temp.begin(), temp.end());
        }

        return v;
    }
};
