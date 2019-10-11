/*
move zeros to the end of array.
[You must do this in-place without making a copy of the array.
Minimize the total number of operations.]

Time: O(n)
Space: O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        for(int i =0;i<len;++i)
        {
            if(nums[i]!=0)
            {
                nums[start] = nums[i];
                start++;
            }
        }
        for(int i = start;i<len;++i)
            nums[i] = 0;
    }
};
