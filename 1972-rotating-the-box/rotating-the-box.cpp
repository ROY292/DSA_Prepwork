class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // vector<pair<int,int>> cnt;
        vector<vector<char>> rot(box[0].size(),vector<char>(box.size()));

        for(int i = 0;i<box.size();i++)
        {
            int stone = 0;
            int obs = 0;
            for(int j = 0;j<box[0].size();j++)
            {
                // cout<<" ij: "<<box[i][j];
                rot[j][box.size() - 1 - i] = box[i][j];
                // if(box[i][j] == '#')
                //     stone++;
                // if(box[i][j] == '*')
                //     obs++;  
            }
            // cnt.push_back(make_pair(obs,stone));
            // cout<<" obs: "<<cnt[i].first<<" stones: "<<cnt[i].second<<endl;
        }
      
        int m = box.size();
        int n = box[0].size();
        // for(int i = 0;i<rot.size();i++)
        // {
        //     for(int j = 0;j<rot[0].size();j++)
        //     {
        //         cout<<" ji: "<<rot[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<"=================================="<<endl;

        for (int j = 0; j < m; j++) {
            // Process each cell in column `j` from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                if (rot[i][j] == '.') {  // Found an empty cell; check if a
                                            // stone can fall into it
                    int nextRowWithStone = -1;

                    // Look for a stone directly above the empty cell
                    // `result[i][j]`
                    for (int k = i - 1; k >= 0; k--) {
                        if (rot[k][j] == '*')
                            break;  // Obstacle blocks any stones above
                        if (rot[k][j] ==
                            '#') {  // Stone found with no obstacles in between
                            nextRowWithStone = k;
                            break;
                        }
                    }

                    // If a stone was found above, let it fall into the empty
                    // cell `result[i][j]`
                    if (nextRowWithStone != -1) {
                        rot[nextRowWithStone][j] = '.';
                        rot[i][j] = '#';
                    }
                }
            }
        }
      
        return rot;
    }
};