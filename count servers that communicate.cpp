class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i = 0;i< m ;++i)
        {
            for(int j = 0; j< n;++j)
            {
                if(grid[i][j]==1)
                {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        for(int i = 0;i<m;++i)
            for(int j = 0;j<n;++j)
            {
                if(grid[i][j]==1&& (row[i]>1 || col[j]>1 ))
                    result+=1;
            }
        return result;
    }
};
