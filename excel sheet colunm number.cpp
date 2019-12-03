class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        long res = 0;
        long tmp = 1;
        for (int i = n-1; i >= 0; --i) {
            res += (s[i] - 'A' + 1) * tmp;
            tmp *= 26;
        }
        return res;
    }
};
