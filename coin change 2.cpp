class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int cat = coins.size();
        vector<vector<int>>dp(cat+1,vector<int>(amount+1,0));
        dp[0][0] = 1;
        for(int i = 1;i<=cat;++i)
        {
            dp[i][0] = 1;
            for(int j = 1;j<=amount;++j)
            {
                if(j>=coins[i-1])
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[cat][amount];
    }
};
