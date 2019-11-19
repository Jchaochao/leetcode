class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size();
        int n2 = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int result = 0;
        int j = 0;
        int i = 0;
        while(i<n1 && j<n2)
        {
            if(g[i]>s[n2-1])
                break;
            if(g[i]<=s[j])
            {
                result+=1;
                ++j;
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return result;
    }
};
