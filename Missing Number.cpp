/*
Because this is from 0-n, so we can use the total of 0-n minus
the total of nums[0-n-1].

Time: O(n)
Space: O(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int total = len;
        for(int i =0;i<len;++i)
        {
            total+=i;
            total-=nums[i];
        }
        return total;
    }
};
