class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int n = nums.size();
        int temp = numeric_limits<int>::max();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n-2 ;++i)
        {
            int l = i+1, r = n-1;
            while(l<r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum == target)
                    return target;
                int distance = abs(target - sum);
                if(distance<temp)
                {
                    temp = distance;
                    result = sum;
                }
                if(sum<target)
                    l++;
                else
                    r--;

            }
        }
        return result;
    }
};
