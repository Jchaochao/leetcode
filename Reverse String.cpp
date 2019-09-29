/*
Easy Problem, just need reverse a vector, we can acheive this goal by swap.

Time: O(n)
Space: O(1)
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int halfLen = len/2;
        for(int i = 0;i<halfLen;++i)
        {
            char temp = s[i];
            s[i] = s[len-1-i];
            s[len-1-i]=temp;
        }
    }
};
