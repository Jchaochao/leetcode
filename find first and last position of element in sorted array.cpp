class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> indices {-1, -1};
        if (!nums.size())
            return indices;
        if (nums.size() == 1)
            if (nums[0] == target)
            {
                indices[0] = 0;
                indices[1] = 0;
                return indices;
            }
            else
                return indices;

        int left = 0, right = nums.size() - 1, mid;

		// Left index
        if (nums[0] == target)
            indices[0] = 0;
        else
            while (right >= left)
            {
                mid = (left + right) / 2;
                if (nums[mid] < target)
                {
                    if (mid < nums.size() - 1 && nums[mid + 1] == target)
                    {
                        indices[0] = mid + 1;
                        break;
                    }
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }

		// Right index
        if (nums[nums.size() - 1] == target)
            indices[1] = nums.size() - 1;
        else
        {
            // Right index
            left = 0;
            right = nums.size() - 1;
            while (right >= left)
            {
                mid = (left + right) / 2;
                if (nums[mid] > target)
                {
                    if (mid && nums[mid - 1] == target)
                    {
                        indices[1] = mid - 1;
                        break;
                    }
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
        }
        return indices;
    }
};
