class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = digits.size() - 1;
        if (digits[pos] < 9) {
            digits[pos] = digits[pos] + 1;
            return digits;
        }

        digits[pos] = 0;
        int carry = 1;

        while (carry && pos) {
            pos--;
			digits[pos] = digits[pos] + carry;
            carry--;
            if (digits[pos] == 10) {
                digits[pos] = 0;
                carry++;
            }
        }

        if (digits[0] != 0) return digits;
        vector<int> newVec(digits.size() + 1, 0);
        newVec[0] = 1;
        return newVec;
    }
};
