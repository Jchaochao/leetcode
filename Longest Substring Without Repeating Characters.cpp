//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int len = s.size();
        for(int rightEnd = 0; rightEnd < len ; ++rightEnd)
        {
            int findRepeat = 0;
            char tempC = s[rightEnd];

            string sub = s.substr(rightEnd  - result ,result+1);
            int sublen = sub.size();
            for(int i =0 ; i < sublen ;++i)
            {
                for(int j=i+1; j <sublen;++j )
                {
                    if(sub[i]==sub[j])
                    {
                        findRepeat = 1;
                        break;
                    }
                }
                if(findRepeat)
                    break;
            }

            if(findRepeat == 0)
                result+=1;
        }
        return result;
    }
};
