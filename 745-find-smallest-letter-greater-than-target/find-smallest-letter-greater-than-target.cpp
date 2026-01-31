class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        sort(letters.begin(),letters.end());
        
        for(auto x: letters)
        {
            if(x > target)
            {
                ans = x;
                break;
            }
        }
            
        return ans;
        
    }
};