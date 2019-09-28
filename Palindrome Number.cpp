/*
This is a easy problem just get all digits in a vector then we can get the result by
compare.

Time: O(n) n stands for nums of digits of the integer.
Space: O(n)
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        vector<int> nums;
        while(x)
        {
            int temp = x%10;
            nums.emplace_back(temp);
            x/=10;
        }
        int len = nums.size();
        int halfLen = len/2;
        for(int i = 0; i<halfLen;++i)
        {
            if(nums[i]!=nums[len-i-1])
                return false;
        }
        return true;
    }
};
