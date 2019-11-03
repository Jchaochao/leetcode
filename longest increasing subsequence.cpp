class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len==0)
            return 0 ;
        vector<int> record(len,1);
        for(int i =0;i<len;++i)
        {
            for(int j = 0;j<i;++j)
                if(nums[i]>nums[j] && record[i]<record[j]+1)
                    record[i]=record[j]+1;
        }
        int result = 0;
        for(int i =0;i<len;++i)
        {
            if(record[i]>result)
                result = record[i];
        }
        return result;
    }
};
