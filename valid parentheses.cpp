class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len == 0)
            return true;
        stack<char> stk;
        for(int i = 0;i < len;++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' )
                stk.push(s[i]);
            else
            {
                if(s[i]==')')
                {
                    if(stk.empty() || stk.top()!='(')
                        return false;
                    else
                        stk.pop();
                }
                else if(s[i]==']')
                {
                    if(stk.empty() || stk.top()!='[')
                        return false;
                    else
                        stk.pop();
                }
                else if(s[i]=='}')
                {
                    if(stk.empty() || stk.top()!='{')
                        return false;
                    else
                        stk.pop();
                }
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};
