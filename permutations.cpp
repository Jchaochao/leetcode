class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i)
            used.push_back(0);
        recur(nums,0);
        return result;
    }
private:
    vector<vector<int>>result;
    vector<int> used;
    vector<int> temp;
    void recur(vector<int>& nums,int len)
    {
        int n = nums.size();
        if(len == n)
        {
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            if(used[i]==1)
                continue;
            temp.push_back(nums[i]);
            used[i]=1;
            recur(nums,len+1);
            used[i]=0;
            temp.pop_back();
        }
    }
};
