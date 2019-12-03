class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1;
        int temp = nums[0];
        int half = nums.size()/2;
        for(int i = 1;i<nums.size();++i)
        {
            if(count>half)
                return temp;
            if(nums[i]==temp)
                count+=1;
            else
            {
                count= 1;
                temp = nums[i];
            }
        }
        return temp;
    }
};
