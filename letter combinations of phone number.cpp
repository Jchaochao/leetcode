class Solution {
public:
    vector<string>ans;
    vector<string>a={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    string curr;
    void rec(string& digits,int pos){
        if(pos==digits.length()){
            ans.push_back(curr);
            return ;
        }
        for(char c:a[digits[pos]-'0']){
            curr[pos]=c;
            rec(digits,pos+1);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        int i=0;
        curr.resize(digits.size());
        if(!digits.size())
            return vector<string>();
        rec(digits,i);
        return ans;
    }
};
