/*
Return sum of two integer without using + or -, we can know a^b is add with carry,
a&b is carry, so when we do this recursively, when carry is 0, then we get the answer.
*/
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b & 0x7fffffff) << 1;
        return getSum(sum, carry);
    }
};
