/*
Like a sliding window, we define S(n) is the
longest substring number in the first n characters,
Then we can get S(n) = S(n-1)  when last character in
the sequence plus the S(n-1) characters before have
repeat, and S(n) = S(n-1) + 1,if we find the
last number and the S(n-1) numbers is a not
repeated sequence.
*/
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
