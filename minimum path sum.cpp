class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i =0;i<m;++i)
        {
            for(int j = 0;j<n;++j)
            {
                dp[i][j]=grid[i][j];
                if(i==0 && j==0)
                    continue;
                else if(i==0)
                    dp[i][j]+=dp[i][j-1];
                else if(j==0)
                    dp[i][j]+=dp[i-1][j];
                else
                    dp[i][j] += min(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
