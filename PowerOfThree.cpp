//This is a normal solution.
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        while(n>0)
        {
            if(n==1)
                return true;
            if(n%3!=0)
                return false;
            n/=3;
        }
        return true;
    }
};

/*
If n is power of three, the log3(n) must be interger, so we change log3(n) into
log10(n)/log10(3), the we use log10(n)/log10(3))-int(log10(n)/log10(3) to judge if
it is a interger.
But this method is not efficient in either time and space.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n>=0 && (log10(n)/log10(3))-int(log10(n)/log10(3)) == 0);
    }
};
