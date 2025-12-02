// class Solution {
// public:
//     int countTrapezoids(vector<vector<int>>& points) {
//         unordered_map<int,vector<int>> mp;

//         for(auto x: points)
//         {
//             mp[x.at(1)].push_back(x.at(0));
//         }
//         int ans = 0;
//         for(auto x: mp)
//         {
//             cout<<" y: "<<x.first<<endl;
//             for(auto y: x.second)
//                 cout<<" x: "<<y;
//             cout<<endl;
//             ans+= x.second.size()%2+1;
//             // if(x.second.size()%2!= 0)
//             // ans++;
//         }

//         return ans;

//     }
// };

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int MOD = 1000000007;
        unordered_map<int, long long> groups;
        for (auto& point : points)
            groups[point[1]]++;
        long long res = 0, total = 0;
        for (auto& group : groups){
            long long lines = group.second * (group.second - 1) / 2;
            res = (res + total * lines) % MOD;
            total = (total + lines) % MOD;
        }
        return (int)res;
    }
};