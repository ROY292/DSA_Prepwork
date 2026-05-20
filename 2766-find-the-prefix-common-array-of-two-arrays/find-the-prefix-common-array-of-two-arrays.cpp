class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int temp = 0;
        for(int i = 0;i< A.size();i++)
        {
            mp[A[i]]++;
            
            
            if(mp[A[i]] == 2)
                temp++;

           // cout<<" temp: "<<temp<<" a[i] "<<mp[A[i]]<<endl;
            mp[B[i]]++;
            if(mp[B[i]] == 2)
                temp++;

          //       cout<<" !temp: "<<temp<<" b[i] "<<mp[B[i]]<<endl;
            
            ans.push_back(temp);
        }

        return ans;
    }
};