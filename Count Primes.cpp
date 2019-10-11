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

/*
Make a n-lenght vector record to record multiply of some small
numbers as 1
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        int count =1;
        vector<bool> record(n,false);
        for(int i = 3;i < n ; i+=2)
        {
            if(!record[i])
            {
                count++;
                for(int j = 3;i*j<n;j+=2)
                    record[i*j] = 1;

            }
        }
        return count;
    }
};
