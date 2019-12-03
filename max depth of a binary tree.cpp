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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        search(root,0);
        return result;
    }
private:
    int result = 0;
    void search(TreeNode* node,int depth)
    {
        if(!node)
            return;
        if(depth+1>result)
            result =depth+1;
        search(node->left,depth+1);
        search(node->right,depth+1);


    }
};
