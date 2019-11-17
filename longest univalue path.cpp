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
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;
        find(root, result);
        return result;
    }
private:
    int find(TreeNode* node, int& result)
    {
        if(!node)
            return 0;
        int left = find(node->left,result);
        int right = find(node->right,result);
        if(node->left && node->left->val == node->val )
            left+=1;
        else
            left = 0;
        if(node->right && node->right->val == node->val )
            right+=1;
        else
            right = 0;
        result = max(result,left+right);
        return max(left,right);
    }
};
