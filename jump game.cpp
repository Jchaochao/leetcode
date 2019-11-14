class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return true;
        int tempmax = 0;
        int i = 0;
        while(i<=tempmax)
        {
            if(i+nums[i]>tempmax)
                tempmax = i+nums[i];
            if(tempmax>=n-1)
                return true;
            ++i;

        }
        return false;
    }
};
