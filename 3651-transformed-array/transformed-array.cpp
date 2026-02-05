class Solution {
    int right(vector<int> & n, int rem, int i)
    {
        rem = (i + rem)%n.size();
        return n[rem];
    }
    // int left(vector<int> & n, int rem, int i)
    // {
    //     rem = (i - rem + n.size())%n.size();
    //     return n[rem];
    // }

  int left(vector<int>& n, int rem, int i)
{
    int N = n.size();
    int idx = ((i - rem) % N + N) % N;
    return n[idx];
}


public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] > 0)
            {
               int temp = right(nums,nums[i],i);
               res.push_back(temp);
            }
            else if(nums[i] < 0)
            {
                int temp = left(nums,abs(nums[i]),i);
                res.push_back(temp);
            }
            else
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};