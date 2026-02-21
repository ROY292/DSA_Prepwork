class Solution {
private:
    int setbitcounter(int n)
    {
        int cnt = 0;
        while(n)
        {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }

    bool isPrime(int n)
    {
        if(n <= 1) return false;
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0) return false;
        }
        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for(int i = left; i <= right; i++)
        {
            int temp = setbitcounter(i);
            if(isPrime(temp))
                ans++;
        }

        return ans;
    }
};