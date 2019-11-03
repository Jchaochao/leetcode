class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int>used(len2,0);
        vector<int>result;
        if(len1==0||len2==0)
            return result;
        for(int i =0;i<len1;++i)
        {
            for(int j = 0;j<len2;++j)
                if(nums1[i]==nums2[j]&&used[j]==0)
                {
                    result.emplace_back(nums1[i]);
                    used[j]=1;
                    break;
                }
        }
        return result;
    }
};
