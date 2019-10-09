/*
Very naive, need to be polished.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row==0)
            return false;
        int col = matrix[0].size();
        if(col==0)
            return false;
        if(matrix.empty())
            return false;
        for(int i =0;i<row;++i)
        {
            if(matrix[i][0]>target)
                break;
            for(int j = 0;j<col;++j)
            {
                if(matrix[i][j]==target)
                    return true;
                else if(matrix[i][j]>target)
                    break;
                else
                    continue;
            }
        }
        return false;
    }
};
