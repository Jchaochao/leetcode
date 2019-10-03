/*
We difine a function called findLCA, and its return value is a integer,
1 means only have p, 2 means only have 3, 3 means have both(including itself
and its left subtree and its right subtree). And when we first found 3, we record
the result.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findLCA(root,0,p,q);
        return result;
    }
private:
    TreeNode* result;
    //return 1 means have p, return 2 means have q, return 3 means
    int findLCA(TreeNode* node,int depth,TreeNode* p, TreeNode* q)
    {
        if(result)
            return 0;
        int record = 0;
        if(!node)
            return 0;
        auto left = node->left;
        auto right = node->right;
        int searchLeft = findLCA(left,depth+1,p,q);
        int searchRight = findLCA(right, depth+1,p,q);
        if(node==p)
        {
            cout<<1<<endl;
            record = 1;
        }
        else if(node==q)
        {
            cout<<2<<endl;
            record = 2;
        }
        cout<<record<<':'<<searchLeft<<':'<<searchRight<<endl;
        if(searchLeft == 0 && searchRight == 0 && record == 0)
            return 0;
        if(searchLeft + record == 3 || searchRight + record ==3 || searchLeft + searchRight ==3)
        {
            cout<<3<<endl;
            if(!result)
                result = node;
            return 3;
        }

        if(searchLeft == 1 || searchRight == 1 || record == 1)
            return 1;
        if(searchLeft == 2 || searchRight == 2 || record == 2)
            return 2;
        return 0;


    }
};
