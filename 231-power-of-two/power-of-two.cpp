class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        double t1 = log2(n);
        int t2 = t1;
        return t1 == t2;
    }
};