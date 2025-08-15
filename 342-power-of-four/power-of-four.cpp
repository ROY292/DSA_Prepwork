class Solution {
public:
    double log4(int n)
    {
        return log(n)/log(4);
    }
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        double pow = log4(n);
        return ceil(pow) == floor(pow);
    }
};