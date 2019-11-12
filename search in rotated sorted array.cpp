class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left + right)/2;
            if(target== nums[mid])
                    return mid;
            if(nums[left]>nums[right])
            {
                if(nums[mid]>nums[right])//
                {
                    if(target>nums[mid])
                        left = mid+1;
                    else
                    {
                        if(target>=nums[left])
                            right = mid -1;
                        else
                            left = mid+1;
                    }
                }
                else
                {
                    if(target < nums[mid])
                        right = mid-1;
                    else
                    {
                        if(target > nums[right])
                            right = mid -1;
                        else
                            left = mid + 1;
                    }
                }
            }
            else//normal binary search
            {
                if(target>nums[right] || target <nums[left])
                    return -1;
                else if(target > nums[mid])
                    left = mid+1;
                else
                    right = mid-1;

            }
        }
        return -1;
    }

};
