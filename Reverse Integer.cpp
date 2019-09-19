/*
This is a simple question, reverse is easy, what is difficult is that you need to
handle the overflow. you just need to judge if the number is over 214748364(INT_MAX/10)
because INT_MAX is 2147483647 and INT_MIN is -21474836478, 214748365*10 must overflow,
and the most important is when result = 214748364, then the x%10 must be 1, if x%10=2,
then the original number 2463847412 is already overflow for int.
*/
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x!=0)
        {
            if(abs(result)>(INT_MAX/10))
                return 0;
            result*=10;
            result += (x%10);
            x/=10;

        }
        return result;
    }
};
