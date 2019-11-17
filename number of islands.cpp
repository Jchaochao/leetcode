class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        int count = 0;
        int temp = 0;
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<m;++j)
                if(grid[i][j]=='1')
                {
                    count+=1;
                    mergeArea(grid,i,j,count,n,m);
                }
        }
        return count;
    }
private:
    void mergeArea(vector<vector<char>>& grid, int i ,int j ,int temp,int n, int m )
    {
        grid[i][j]='a';
        if(i>0 && grid[i-1][j]=='1')
            mergeArea(grid,i-1,j,temp,n,m);
        if(j>0 && grid[i][j-1]=='1')
            mergeArea(grid,i,j-1,temp,n,m);
        if(i<n-1 && grid[i+1][j]=='1')
            mergeArea(grid,i+1,j,temp,n,m);
        if(j<m-1 && grid[i][j+1]=='1')
            mergeArea(grid,i,j+1,temp,n,m);
        return;
    }
};
