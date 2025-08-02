// class Solution {
// public:
//     long long minCost(vector<int>& basket1, vector<int>& basket2) {

//         map<int,int> mp,mp1,mp2;


//         for(auto x: basket1)
//             {
//                 mp[x]++;
//                 mp1[x]++;
//             }
        
//         for(auto x: basket2)
//           {
//             mp[x]++;
//             mp2[x]++;
//           }  

//         for(auto x: mp )
//            {
//                 if(x.second%2 != 0)
//                     return -1;
//            }

//            long long ans = 0;
//            long long  sum1  =accumulate(basket1.begin(),basket1.end(),0LL);
//            long long  sum2  =accumulate(basket2.begin(),basket2.end(),0LL);
//             sort(basket1.begin(),basket1.end());
//             sort(basket2.begin(),basket2.end());

//            for(int i = 0; i < basket1.size(); i++)
//            {
//                 if(basket1[i] < basket2[i])
//                 {
//                     ans+=basket1[i];
//                    // cout<<" ans: "<<ans;
//                     sum1 += basket2[i];
//                     sum1 -= basket1[i];
//                     sum2 += basket1[i];
//                     sum2 -= basket2[i];
//                     swap(basket1[i],basket2[i]);

//                   //  cout<<" SUM1: "<<sum1<<" SUM2: "<<sum2;
//                     if(sum1 == sum2)
//                         break;
//                 }
//                 else if(basket2[i] < basket1[i])
//                 {
//                     ans+=basket2[i];
//              //       cout<<" ans2: "<<ans;
//                     sum1 += basket2[i];
//                     sum1 -= basket1[i];
//                     sum2 += basket1[i];
//                     sum2 -= basket2[i];
//                     swap(basket2[i],basket1[i]);
//                   //  cout<<" 2SUM1: "<<sum1<<" 2SUM2: "<<sum2;
//                     if(sum1 == sum2)
//                         break;
//                 }
//                 else continue;
           
//             }
           
           
//         return ans;
//     }
// };

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> count;
        for (int x : basket1) count[x]++;
        for (int x : basket2) count[x]--;

        vector<int> extra1, extra2;
        int min_fruit = INT_MAX;

        for (auto& [fruit, freq] : count) {
            if (freq % 2 != 0) return -1; // odd imbalance, not possible
            int half = abs(freq) / 2;
            if (freq > 0) extra1.insert(extra1.end(), half, fruit);
            else extra2.insert(extra2.end(), half, fruit);
            min_fruit = min(min_fruit, fruit);
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend()); // descending

        long long total_cost = 0;
        for (int i = 0; i < extra1.size(); i++) {
            total_cost += min({extra1[i], extra2[i], 2 * min_fruit});
        }

        return total_cost;
    }
};
