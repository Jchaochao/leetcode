class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0)
            return 0;
        int n = obstacleGrid[0].size();
        vector<vector<long>>dp(m+1,vector<long>(n+1,0));
        dp[0][1]=1;
        for(int i =1; i<=m;++i)
            for(int j=1;j<=n;++j)
            {
                if(obstacleGrid[i-1][j-1]==1)
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        return dp[m][n];
    }
};
