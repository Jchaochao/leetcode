class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        result.push_back("");
        for(int i = 0;i<S.size();++i)
        {
            int size = result.size();
            if(S[i]>='0'&&S[i]<='9')
            {
                for(int j = 0;j<size;++j)
                    result[j]+=S[i];
            }
            else
            {

                for(int j = 0;j<size;++j)
                {
                    result.push_back(result[j]);
                    result[j]+=tolower(S[i]);
                    result[size+j]+=toupper(S[i]);

                }
            }
        }
        return result;
    }
};
