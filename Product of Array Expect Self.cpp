/*
This is a solution that consider zeros and use division.
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result;
        int allProduct = 1;
        int len = nums.size();
        int countZero = 0;
        vector<int> zero;
        for(int i = 0;i < len; ++i)
        {
            if(nums[i]==0)
            {
                countZero+=1;
                zero.emplace_back(i);
            }
            else
                allProduct*=nums[i];

        }
        if(countZero >= 2)
        {
            for(int i =0; i < len; ++i)
                result.emplace_back(0);
        }
        else if(countZero == 1)
        {
            int tag = zero[0];
            for(int i = 0;i<len;++i)
            {
                if(i==tag)
                    result.emplace_back(allProduct);
                else
                    result.emplace_back(0);
            }
        }
        else
        {
            for(int i = 0;i<len;++i)
            {
                result.emplace_back(allProduct/nums[i]);

            }
        }
        return result;
    }

};

/*
solution 2: without division and cost is O(n)
compute left[] and right[]
result[i] = left[i]*right[i]
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        vector<int>result;
        int temp = 1;
        int len = nums.size();
        for(int i =0;i < len;++i)
        {
            left.emplace_back(temp);
            temp*=nums[i];
        }
        temp = 1;
        for(int i = len-1; i>=0;--i)
        {
            right.emplace_back(temp);
            temp*=nums[i];
        }
        reverse(right.begin(),right.end());
        for(int i = 0;i<len;++i)
        {
            result.emplace_back(left[i]*right[i]);
        }
        return result;
    }
};
