class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        for(int i =0;i<n;++i)
            for(int j = i;j<n-i-1;++j)
            {
                int target = matrix[i][j];
                insert(matrix,j,n-1-i,target,4);
            }
        return;
    }
    void insert(vector<vector<int>>& matrix,int i ,int j,int intarget,int k )
    {
        int n = matrix.size();
        if(k==1)
            matrix[i][j]=intarget;
        else
        {
            int outtarget = matrix[i][j];
            matrix[i][j]=intarget;
            insert(matrix,j,n-1-i,outtarget,k-1);

        }

    }

};
