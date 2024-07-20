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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            root = new TreeNode(val);
            return root;
        }
          TreeNode* curr = root;
          TreeNode* parent = NULL;
          while(curr != NULL) {
            parent = curr;
            if(curr->val > val) curr = curr->left;
            else if(curr->val < val) curr = curr->right;
         }
         if(parent->val > val) parent->left = new TreeNode(val);
         else parent->right = new TreeNode(val);
         return root;
    }
};