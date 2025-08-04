class Solution {
public:
int totalFruit(vector<int>& f) {
    unordered_map<int, int> cnt;
    int left = 0, ans = 0;
    for (int right = 0; right < f.size(); right++) {
        cnt[f[right]]++;
        while (cnt.size() > 2) {
            cnt[f[left]]--;
            if (cnt[f[left]] == 0) cnt.erase(f[left]);
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}
};
//     int totalFruit(vector<int>& f) {
//         int n = f.size();
//         int ele1 = f[0];
//         int ele2 = INT_MAX;
//         int ans = 0;
//         int freq = 1;
//         unordered_map<int,int> idx;
//         idx[ele1] = 0;
//         for(int i = 1;i<n;i++)
//         {
//             if(f[i] == ele1)
//             {
//                 idx[ele1] = i;
//                 freq++;
//             }
//             else if(f[i] == ele2 || ele2 == INT_MAX)
//             {
//                 if(ele2 == INT_MAX)  
//                 {
//                     ele2 = f[i];
//                 }
//                 idx[ele2] = i;

//                 freq++;
//             }
//             else
//             {
//                 ans = max(ans, freq);
//                 int prev = i-1;
//                 ele1 = f[prev];
//                 int temp = 0;
//                 while(f[prev] == ele1 && prev >= 0)
//                 {
//                     temp++;
//                     prev--;
//                 }
//                 freq = temp;
//                 ele2 = f[i];
                
//                 ele2 = INT_MAX;
//             }

//         }
//         ans = max(ans,freq);

//         return ans;
//     }
// };

