/*
Scan from start to end, for every i , we can define the maximum subarray end with
nums[i] is S(i). S(i) = max(S(i-1)+nums[i], nums[i]) , and don't forget when i equals
1 the S(1) is nums[1]. Then every time we get a new S(i), we compare it with result,
for O(n) time we can get the answer.

Time:O(n)
Space:O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int temp = nums[0];
        int len = nums.size();
        for(int i = 1; i < len; ++i)
        {
            temp = max(temp+nums[i],nums[i]);
            if(temp>result)
            {
                result = temp;
            }
        }
        return result;
    }
};

/*
Solution 2 is a divide-and-conquer method, it is more subtle.
The idea is easy, divide the problem into two parts and then merge them. We can easily
write the code how to get the result of two subproblems cause it is just two-line-thing.
The point is how we merge them. When we merge, we must take three parts into consideration:
left,right and the part that cross the middle. For the middle part, we just need to add another
two part: maximum of all subarrays that end with nums[mid] and maximun of all subarrays that
start with nums[mid+1](the idea for this part is deriveded by the 1st solution).
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums,0,nums.size()-1);
    }
private:
    int divideAndConquer(vector<int>& nums, int start, int end)
    {
        if(end>start)
        {
            //divide into two groups,and get the resolution for two parts
            int mid = (start + end) / 2 ;
            int leftRes= divideAndConquer(nums, start, mid);
            int rightRes = divideAndConquer(nums, mid + 1, end);

            //merge, there are three things should consider:leftpart,rightpart and the part across the middle
            //key point is how to get the middle part
            int leftMax = nums[mid];
            int rightMax = nums[mid+1];
            int leftSum = 0;
            int rightSum = 0;
            for(int i = mid;i>=start;--i)
            {
                leftSum += nums[i];
                if(leftSum>leftMax)
                    leftMax = leftSum;
            }
            for(int i = mid+1;i<=end;++i)
            {
                rightSum += nums[i];
                if(rightSum>rightMax)
                    rightMax = rightSum;
            }
            int middleSum = leftMax+rightMax;
            return max(max(leftRes,rightRes),middleSum);
        }
        else
        {
            return nums[start];
        }
    }
};
