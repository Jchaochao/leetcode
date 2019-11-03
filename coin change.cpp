class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        int cat = coins.size();
        dp[0]=0;
        for(int i =0;i<cat;++i)
        {
            for(int j = coins[i];j<=amount;++j)
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
        }
        int result=(dp[amount]==amount+1)?-1:dp[amount];
        return result;
    }
};
