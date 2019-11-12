class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(target<nums[0])
            return 0;
        if(target>nums[len-1])
            return len;
        int left = 0, right = len -1, mid;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid] == target )
                return mid;
            if(nums[mid] < target)
            {
                if(mid<len-1 && nums[mid+1]>target)
                    return mid+1;
                left = mid+1;
            }
            else
            {
                if(mid>0 && nums[mid-1]<target)
                    return mid;
                right = mid-1;
            }
        }
        return -1;
    }
};
