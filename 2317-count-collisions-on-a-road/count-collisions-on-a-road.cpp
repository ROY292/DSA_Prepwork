// class Solution {
// public:
//     int countCollisions(string directions) {
//         // bool pres = false;
//         // int ans = 0;
        
//         // for(int i = 0;i< directions.size()-1;i++)
//         // {
//         //     if(directions[i] == 'S')
//         //     {
//         //         if(i == 0)
//         //         {
//         //             if(directions[i+1] != 'S')
//         //                 ans+=1;
//         //         }
//         //         else
//         //         {
//         //             ans+=2;
//         //             pres = true;
//         //             i++;
//         //         }
//         //     }
//         //     else if(directions[i] != directions[i+1] && directions[i+1]!='S')
//         //     {
//         //         ans+=2;
//         //         i++;
//         //         pres = false;
//         //     }
//         //     else if(directions[i] == directions[i+1])
//         //     {
//         //     if(pres)
//         //         {pres = false;
//         //         ans+=1;
//         //         }
//         //     }
//         //     else
//         //     {
//         //         continue;
//         //     }
//         // }

//         // return ans;

        
//     }
// };

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = n - 1;

        while (l < n && directions[l] == 'L') {
            l++;
        }

        while (r >= l && directions[r] == 'R') {
            r--;
        }

        int res = 0;
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') {
                res++;
            }
        }
        return res;
    }
};