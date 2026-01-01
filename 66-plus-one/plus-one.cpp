class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 0;
        int  i = 0;
            if(digits[i] == 9)
            {
                digits[i] = 0;
                carry = 1;
                i++;
                while(i < digits.size() && digits[i] == 9)
                {
                    digits[i] = 0;
                    i++;
                }
                if(i == digits.size())
                    digits.push_back(1);
                else
                    digits[i]++;
            }
            else
                digits[i]++;
            
            reverse(digits.begin(),digits.end());
        
        return digits;
        
    }
};