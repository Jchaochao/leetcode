/*
Catalan Number
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        if(n<=1)
            return 1;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i <= n; ++i )
        {
            int temp = 0;
            for(int j = 0;j<i;++j)
                temp += dp[j]*dp[i-j-1];
            dp[i]=temp;
        }
        return dp[n];
    }
};
