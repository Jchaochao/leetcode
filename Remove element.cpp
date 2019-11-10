class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int slow = 0;
        int fast = 0;
        while(fast<len)
        {
            if(nums[fast]==val)
                fast++;
            else
            {
                nums[slow]= nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};
