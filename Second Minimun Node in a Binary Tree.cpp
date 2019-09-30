/*
This tree has a property that the root is always the smallest, so we just need to find
the smallest number which is not K(root->val), we can search from the root using a top-down
method, the first we see which is not K will be the answer.
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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root->left)
            return -1;
        int k = root->val;
        int left =findSmallestNotK(root->left,k);
        int right = findSmallestNotK(root->right,k);
        if(left==-1)
            return right;
        else if(right ==-1)
            return left;
        else
            return min(left,right);

    }
    int findSmallestNotK(TreeNode* node, int k)
    {
        if(node->val > k)
            return node->val;
        if(!node->left)
            return -1;
        int left =findSmallestNotK(node->left,k);
        int right = findSmallestNotK(node->right,k);
        if(left==-1)
            return right;
        else if(right ==-1)
            return left;
        else
            return min(left,right);
    }
};
