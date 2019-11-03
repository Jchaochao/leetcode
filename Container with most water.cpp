/*
Brute force: time is n^2, we start from two ends, left ends and right ends,
and everytime we move the end with a lower height toward middle.

Time: O(n)
Space:O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int h = min(height[l], height[r]);
            result = max(result, h * (r - l));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return result;
    }
};
