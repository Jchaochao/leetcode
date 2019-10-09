/*
A very simple question.

Time: O(kn)
Space: O(1)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        int temp = 0;
        vector<int> res;
        if(len==0)
            return {};
        int count = len-k+1;
        int comp = 0;
        for(int i =0;i<count;++i)
        {
            temp = nums[i];
            for(int j=1;j<k;++j)
            {
                comp = nums[i+j];
                if(comp>temp)
                    temp = comp;
            }
            res.emplace_back(temp);
        }
        return res;
    }
};
