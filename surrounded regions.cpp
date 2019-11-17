//This method is really naive and need to be improved
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n==0)
            return;
        int m = board[0].size();
        vector<int> up(m,0);
        int left = 0;
        int count = 0;
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
            {
                if(board[i][j]=='O' && (i==0||j==0||i==n-1||j==m-1) )
                    mergeArea(board,i,j,'o',n,m);
            }
        for(int i = 0; i<n;++i)
        {
            left = 0;
            for(int j = 0; j <m;++j)
            {
                if(board[i][j]=='X')
                {
                    up[j]=1;
                    left = 1;
                }
                else if(board[i][j]=='O')
                {
                    if(i==0||j==0||i==n-1||j==m-1)
                        continue;
                    if(left==1 && up[j]==1)
                    {
                        count = 0;
                        for(int k = i+1;k<n;++k)
                            if(board[k][j]=='X')
                            {
                                count+=1;
                                break;
                            }
                        for(int k = j+1;k<m;++k)
                            if(board[i][k]=='X')
                            {
                                count+=1;
                                break;
                            }
                        if(count == 2)
                            board[i][j]='x';
                    }
                }
            }
        }
        for(int i =0;i<n;++i)
            for(int j = 0;j<m;++j)
            {
                if(board[i][j]=='x')
                    board[i][j]='X';
                if(board[i][j]=='o')
                    board[i][j]='O';
            }

        return;
    }
private:
    void mergeArea(vector<vector<char>>& grid, int i ,int j ,int temp,int n, int m )
    {
        grid[i][j]='o';
        if(i>0 && grid[i-1][j]=='O')
            mergeArea(grid,i-1,j,temp,n,m);
        if(j>0 && grid[i][j-1]=='O')
            mergeArea(grid,i,j-1,temp,n,m);
        if(i<n-1 && grid[i+1][j]=='O')
            mergeArea(grid,i+1,j,temp,n,m);
        if(j<m-1 && grid[i][j+1]=='O')
            mergeArea(grid,i,j+1,temp,n,m);
        return;
    }
};


/*
updated:
if 'O' is not able to extend into edge of the graph, then it will eventually and definitely convert into 'X'
*/
