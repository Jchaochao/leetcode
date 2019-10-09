/*
Use a vector of 26 zeros to record the time of every character appearing time in s,
and minus 1 when encounter a same character in t. If any of it is smaller than zero, then
return false, else return true.

Time: O(n)
Space: O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        int flag = 0;
        if(slen != tlen)
            return false;
        if(slen == 0)
            return true;
        vector<int> temp(26,0);
        for(int i = 0;i<slen;++i)
            temp[s[i]-'a']++;
        for(int j = 0; j < tlen;++j)
        {
            temp[t[j]-'a']--;
            if(temp[t[j]-'a']<0)
                return false;
        }
        return true;
    }
};
