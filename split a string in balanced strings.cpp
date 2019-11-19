class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int nl = 0, nr = 0;
        int result = 0;
        for(int i =0;i<n;++i)
        {
            if(s[i]=='L')
                ++nl;
            else
                ++nr;
            if(nl==nr)
            {
                result+=1;
                nl = 0;
                nr = 0;
            }
        }
        return result;
    }
};
