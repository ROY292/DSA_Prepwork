// class Solution {
// public:
//     int countTriples(int n) {
//         int cnt = 0;

//         for(int i = 1;i<=n;i++)
//         {
//             for(int j = 1;j<=n;j++)
//             {
//                 int temp = (i*i) + (j*j);
//                 int t = (int)sqrt(temp);
//                 if(t*t == temp && t <= n)
//                     cnt++;
//             }
//         }

//         return cnt;
//     }
// };

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int u = 2; u <= sqrt(n); u++) {
            for (int v = 1; v < u; v++) {
                if (~(u - v) & 1 || gcd(u, v) != 1) continue;
                int c = u * u + v * v;
                if (c > n) continue;
                res += (n / c) << 1;
            }
        }
        return res;
    }
};
