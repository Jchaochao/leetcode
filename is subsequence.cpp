class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        int i = 0, j = 0;
        while(i< len1 && j <len2)
        {
            if(s[i]==t[j])
            {
                ++i;
                ++j;
            }
            else
                ++j;
        }
        return (i == len1);

    }
};
