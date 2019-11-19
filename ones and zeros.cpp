class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        if(len==0)
            return 0 ;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int k = 0;k < len;++k)
        {
            int one = 0, zero = 0;
            int size = strs[k].size();
            for(int j = 0;j< size;++j)
            {
                if(strs[k][j]=='0')
                    ++zero;
                else
                    ++one;
            }
            for(int i = m;i>=zero ; --i)
                for(int j = n; j >= one; --j)
                {
                    dp[i][j]= max(dp[i][j],dp[i-zero][j-one]+1);
                }

        }


        return dp[m][n];
    }
};
