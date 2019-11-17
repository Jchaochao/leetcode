class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        int result = 0;
        int temp = 0;
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<m;++j)
                if(grid[i][j]==1)
                {
                    temp = 0;
                    getArea(grid,i,j,temp,n,m);
                    if(temp>result)
                        result = temp;
                }
        }
        return result;
    }
private:
    void getArea(vector<vector<int>>& grid, int i ,int j ,int& temp,int n, int m )
    {
        temp+=1;
        grid[i][j]=-1;
        if(i>0 && grid[i-1][j]==1)
            getArea(grid,i-1,j,temp,n,m);
        if(j>0 && grid[i][j-1]==1)
            getArea(grid,i,j-1,temp,n,m);
        if(i<n-1 && grid[i+1][j]==1)
            getArea(grid,i+1,j,temp,n,m);
        if(j<m-1 && grid[i][j+1]==1)
            getArea(grid,i,j+1,temp,n,m);
        return;
    }
};
