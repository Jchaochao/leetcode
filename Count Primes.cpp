/*
naive solution to countPrimes less than n
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        int count =1;
        for(int i = 3; i < n ;++i)
        {
            int flag = 0;
            int root = sqrt(i);
            for(int j = 2;j<=root;j++)
                if(i%j==0)
                {
                    flag = 1;
                    break;
                }
            if(flag == 0)
                count++;
        }
        return count;
    }
};
