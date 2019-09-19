//This a normal solution by a loop of divide two and judge
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        while(n>0)
        {
            if(n==1)
                return true;
            if(n%2 == 1)
                return false;
            n = n>>1;
        }
        return true;

    }
};
/*
If n is power of two, then its highest bit is 1 and the other are all 0, then n-1
is all 1, if n & (n-1) != 0 , then return false;
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n - 1)));
    }
};
