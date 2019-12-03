class Solution {
public:
    string convertToTitle(int n) {
        if(n<=0)
            return "";
        string result;
        int temp = 0;
        while(n>0)
        {
            temp = (n-1)%26;
            n=(n-1)/26;
            result+=('A'+temp);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
