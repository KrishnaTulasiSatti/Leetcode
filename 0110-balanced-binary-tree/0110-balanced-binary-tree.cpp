/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int check = 0;

    int fun(TreeNode* root) {

        if(root == NULL) return 0;
        
        int lh = 1 + fun(root->left);
        int rh = 1 + fun(root->right);

        if(abs(lh-rh) > 1) check = 1;

        return max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int res = fun(root);

        return !check;
    }
};