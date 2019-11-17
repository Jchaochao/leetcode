class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=1)
            return n;
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
            return (a[1]<b[1]) || (a[1]==b[1]&& a[1]>b[1]);
        });
        int count = 1;
        int cur = points[0][1];
        for(int i =0;i<n;++i)
        {
            if(cur<points[i][0])
            {
                ++count;
                cur = points[i][1];
            }
        }
        return count;
    }
};
