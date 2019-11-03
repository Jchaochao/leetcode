class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> record(27,0);
        int len = s.length();
        for(int i =0;i <len;++i)
        {
            record[s[i]-'a']++;
        }
        for(int i =0;i<len;++i)
        {
            if(record[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
