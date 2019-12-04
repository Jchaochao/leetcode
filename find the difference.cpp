class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> temp(26,0);
        char result;
        for(int i = 0;i<t.size();++i)
            temp[t[i]-'a']+=1;
        for(int i = 0;i<s.size();++i)
            temp[s[i]-'a']-=1;
        for(int i =0;i<26;++i)
            if(temp[i]>0)
            {
                result =  ('a'+i);
                //cout<<i<<endl;
            }
        return result;
    }
};
