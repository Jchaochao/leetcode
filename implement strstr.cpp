class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0 ;
        int len1 = haystack.size();
        int len2 = needle.size();
        if(len1<len2)
            return -1;
        for(int i = 0;i<=len1-len2;++i)
        {
            int j = 0;
            for(j = 0;j<len2;++j)
            {
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==len2)
                return i;
        }

        return -1;
    }
};
