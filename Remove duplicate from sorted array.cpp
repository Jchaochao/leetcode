class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len ==0)
            return 0;
        int fast = 0;
        int slow = 0;
        while(fast<len)
        {
            if(nums[slow]==nums[fast])
                ++fast;
            else
            {
                slow++;
                nums[slow]=nums[fast];
            }
        }
        return slow+1;
    }
};
