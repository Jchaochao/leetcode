class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1)
            return 0;
        int result = 0;
        for(int i = 1;i<n;++i)
        {
            int deltax = abs(points[i][0]-points[i-1][0]);
            int deltay = abs(points[i][1]-points[i-1][1]);
            result+=max(deltax,deltay);
        }
        return result;
    }
};
