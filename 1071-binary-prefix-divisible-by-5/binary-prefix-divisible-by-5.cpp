class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result;
        int value = 0;  // store the prefix modulo 5

        for (int bit : A) {
            value = (value * 2 + bit) % 5;
            result.push_back(value == 0);
        }

        return result;
    }
};
