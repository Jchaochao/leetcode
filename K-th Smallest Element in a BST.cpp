/*
I get all the scan in a vector, then I return the (k-1)th element.

Time: O(n)
Space: O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        auto nums = getNum(root);
        int len = nums.size() ;
        for(int i = 0; i < len ;++i)
            cout<<nums[i]<<endl;
        return nums[k-1];
    }
private:
    vector<int> getNum(TreeNode* node)
    {
        vector<int> result;
        if(node->left)
        {
            auto left = getNum(node->left);
            int leftLen = left.size();
            for(int i = 0; i< leftLen;++i)
                result.emplace_back(left[i]);
        }
        result.emplace_back(node->val);
        if(node->right)
        {
            auto right = getNum(node->right);
            int rightLen = right.size();
            for(int i = 0; i < rightLen ; ++i)
                result.emplace_back(right[i]);
        }
        return result;
    }
};

/*
Solution 2: There are two attentions. 1, make the parameter k changable through recursion,
second is , we allways find the smallest, so everytime we just need to k-1, and when we see
we get k==0, that means we find the result and just return the result is ok.

Time: O(k)
Space:O(?)
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root)
            return 0;

        int result;

        result = kthSmallest(root->left,k);
        if(k==0)
            return result;

        k--;
        if(k==0)
            return root->val;

        result = kthSmallest(root->right, k);
        if(k==0)
            return result;
        return 0;
    }

};
