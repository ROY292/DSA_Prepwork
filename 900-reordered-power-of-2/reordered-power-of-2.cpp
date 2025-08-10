class Solution {
public:
vector<int> getPermutations(int num) {
    // Convert number to string to manipulate digits
    std::string s = std::to_string(num);
    
    // Sort digits so next_permutation works correctly
    std::sort(s.begin(), s.end());
    
    std::vector<int> permutations;
    
    do {
        // Convert each permutation back to integer
        if(s[0] != '0')
             permutations.push_back(std::stoi(s));
    } while (std::next_permutation(s.begin(), s.end()));
    
    return permutations;
}
    bool reorderedPowerOf2(int n) {

        vector<int> ans = getPermutations(n);

        for(auto &x: ans)
        {
            double temp = log2(x);
            int inter = log2(x);
            if(temp == inter)
                return true;
        }
        return false;
    }
};