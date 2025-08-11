// class Solution {

//     const long long MOD = 1000000007;

// public:
//     vector<int> productQueries(int n, vector<vector<int>>& queries) {
//         int temp = n;

//         int div = 2 * ceil(log2(n));
//         cout << " DIV: " << div;

//         vector<int> powers;
//         while (temp > 0) {
//             powers.push_back(div);
//             temp -= div;
//             div /= 2;
//         }
//         sort(powers.begin(), powers.end());

//         vector<int> ans;
        
//         for (auto& x : queries) {
//             long long temp = 1;
//             for (int i = x.at(0); i <= x.at(1); i++) {
//                 temp = (temp * powers[i]) % MOD;
//             }
//             ans.push_back(temp);
//         }

//         return ans;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const long long MOD = 1000000007LL;

    long long modpow(long long a, long long e) {
        long long r = 1 % MOD;
        a %= MOD;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // 1) gather powers (2^bit) present in n, in ascending exponent order
        vector<long long> vals;
        long long cur = 1; // 2^0 % MOD
        int temp = n;
        for (int bit = 0; temp > 0; ++bit) {
            if (temp & 1) {
                vals.push_back(cur); // 2^bit % MOD
            }
            cur = (cur * 2) % MOD;
            temp >>= 1;
        }
        // vals now holds powers in ascending exponent order

        // 2) prefix products
        int m = vals.size();
        vector<long long> pref(m + 1, 1);
        for (int i = 0; i < m; ++i) pref[i+1] = (pref[i] * vals[i]) % MOD;

        // 3) precompute modular inverses of pref entries (m is small, <= 31 for 32-bit n, <= 60 for 64-bit)
        vector<long long> invPref(m + 1);
        for (int i = 0; i <= m; ++i) invPref[i] = modpow(pref[i], MOD - 2);

        // 4) answer queries
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            // product = pref[r+1] * invPref[l] % MOD
            long long res = pref[r+1];
            res = (res * invPref[l]) % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};
