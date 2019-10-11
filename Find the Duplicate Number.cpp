/*
Need to be modified.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fastp = 0;
        int slowp = 0;
        while(true)
        {
            fastp = nums[nums[fastp]];
            slowp = nums[slowp];
            if(fastp == slowp)
                break;
        }
        fastp = 0;
        while(fastp!=slowp)
        {
            fastp = nums[fastp];
            slowp = nums[slowp];
        }
        return slowp;
    }
};
