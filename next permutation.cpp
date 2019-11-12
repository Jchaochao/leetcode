class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return;
        int i = n-2;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j = i + 1;
        while(j<=n-1 && nums[j] > nums[i])
            j++;
        j--;
        swap(nums[i],nums[j]);
        sort(nums.begin()+i+1,nums.end());

    }
};
