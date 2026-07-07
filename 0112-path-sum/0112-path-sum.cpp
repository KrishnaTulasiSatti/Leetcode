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

    bool fun(TreeNode* root,int targetSum,int sum) {

        if(root == NULL) return false;

        if(root->left == NULL && root->right == NULL) {
            sum += root->val;
            if(sum == targetSum) return true;
            return false;
        }

        sum += root->val;

        return fun(root->left,targetSum,sum) || fun(root->right,targetSum,sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return fun(root,targetSum,0);
    }
};