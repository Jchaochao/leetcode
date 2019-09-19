//This is a normal case
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        while(num>0)
        {
            if(num==1)
                return true;
            if(num%4 != 0)
                return false;
            num = num >>2;
        }
        return true;
    }
};

/*
Power of four must be a power of two so it must be only the highest bit is one, so
we use num*(num-1) to see if this is power of two. Then if it is power of four, the
bit may be 1 is fixed in 0x55555555, so we just need to know if its only '1' is in
these specific seat.
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};
