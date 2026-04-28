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
        
        if(root == NULL) return NULL;

        int curr = root->val;

        // Both lie on left side
        if(p->val < curr && q->val < curr) {
            return lowestCommonAncestor(root->left,p,q);
        }

        // Both lie on right side
        if(p->val > curr && q->val > curr) {
            return lowestCommonAncestor(root->right,p,q);
        }

        // If one lie on left and other on right, then the node is lca

        return root;
    }
};