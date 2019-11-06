class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int strNum = strs.size();
        if(strNum==0)
            return result;
        int maxlen = numeric_limits<int>::max();
        for(int i = 0; i < strNum; ++i)
        {
            int len = strs[i].length();
            maxlen = min(maxlen,len);
        }
        int idx = 0;
        while(idx<maxlen)
        {
            char temp = strs[0][idx];
            for(int i =0;i<strNum;++i)
                if(strs[i][idx]!=temp)
                    return result;
            result+=temp;
            idx++;
        }
        return result;

    }
};
