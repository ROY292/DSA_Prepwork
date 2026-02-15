// class Solution {
//     private: 
//     int tob(string a)
//     {
//         int ans = 0;
//         reverse(a.begin(),a.end());
//         int p = 0;
//         for(auto x: a)
//         {
//             if(x == '1')
//             {
//                 ans+= pow(2,p);
//             }
//             p++;

//         }

//         return ans;
//     }
// public:
//     string addBinary(string a, string b) {

//         int pa = tob(a);
//         int pb = tob(b);

//         int sum = pa + pb;

//         string rem = "";
//         while(sum/2 != 0)
//         {
//             int r = sum%2;
//             if(r > 0)
//             {
//                 rem+='1';
//             }
//             else
//             {
//                 rem+='0';
//             }
//             sum = sum/2;
//         }

//          if(sum%2 > 0)
//             {
//                 rem+='1';
//             }
//             else
//             {
//                 rem+='0';
//             }

//             reverse(rem.begin(),rem.end());

//             return rem;
        
        
//     }
// };

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
