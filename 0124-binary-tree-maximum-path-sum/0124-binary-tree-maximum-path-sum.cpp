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

    int maxi = INT_MIN;

    int fun(TreeNode* root) {
        if(root == NULL) return 0;

        int left = fun(root->left);
        int right = fun(root->right);

        maxi = max(maxi,root->val);
        maxi = max(maxi,root->val + left + right);
        maxi = max(maxi,root->val + left);
        maxi = max(maxi,root->val + right);

        return root->val + max({0,left,right});
    }

    int maxPathSum(TreeNode* root) {
        
        int res = fun(root);
        // cout << res;

        return maxi;
    }
};