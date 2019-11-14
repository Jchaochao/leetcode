class Solution {
public:
    int jump(vector<int>& nums) {
        int lastIdx = nums.size()-1;
        if(lastIdx<=0)
            return 0;
        int tempmax = 0;
        int i =0;
        int jumps = 0;
        int cur = 0;
        while(i<=lastIdx)
        {
            if(cur>=lastIdx)
                return jumps;
            ++jumps;
            if(i+nums[i]>tempmax)
                tempmax = i+nums[i];
            if(tempmax>=lastIdx)
                    return jumps;
            int steps = tempmax - i;
            for(int j = 0;j<steps;++j)
            {
                i++;
                if(i+nums[i]>tempmax)
                {
                    tempmax = i+nums[i];
                    cur = i;
                }
            }
        }
        return jumps;
    }
};
