/*
An easy DP problem dp[n] = min(dp[n],dp[n-k]+dp[k]), key is how to reduce time. First solution is
the first edition I wrote, everytime I let k plus 1, but k can be i*i,bacause K is a square

Time: O(n)
Space: O(n)
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;
        int temp = 0;
        dp.emplace_back(0);
        for(int i = 1 ;i <=n;++i)
        {
            float root = sqrt(i);
            if(root - float(floor(root))==0)
            {
                dp.emplace_back(1);
            }
            else
            {
                int result = i;
                for(int j=1;j<=floor(i/2);++j)
                {
                    temp = dp[j]+dp[i-j];
                    if(temp<result)
                        result= temp;
                }
                dp.emplace_back(result);
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int j = 0; j < n + 1; j++) {
            for (int i = 1; i * i <= n; i++) {
                if (i * i <= j) {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};
