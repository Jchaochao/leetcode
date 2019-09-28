/*
Key to this problem is how we can find the number encounters a endless loop,
we use a hash table to solve this problem. The bigest sum is 1999999999, then we can
use 730 to represent its sum. If it run into a endless loop, it will always encounter
a same number more than once, so when we get a sum, we give it a tag, then we solve this
problem.

Time: O(730)
Space: O(730)
*/
class Solution {
public:
    bool isHappy(int n) {
        bool hash[730]  = {0};
        memset(hash,0,sizeof(hash));
        int sum = 0;

        while(true)
        {
            sum = 0;
            while(n>0)
            {
                sum+=pow(n%10,2);
                n/=10;
            }
            if(sum == 1)
                return true;
            if(hash[sum]==1)
                return false;
            else
                hash[sum]=1;
            n=sum;
        }
    }
};
