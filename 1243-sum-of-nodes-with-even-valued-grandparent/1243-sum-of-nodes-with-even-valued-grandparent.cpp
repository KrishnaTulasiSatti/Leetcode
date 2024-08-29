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
int sum = 0;
void findSum(TreeNode* root) {
    if(root->left == NULL && root->right == NULL) return;
    if(root->left != NULL) {
       if(root->left->left != NULL) sum+=(root->left->left->val);
       if(root->left->right != NULL) sum+=(root->left->right->val);
    }
    if(root->right != NULL) {
       if(root->right->right != NULL) sum+=(root->right->right->val);
       if(root->right->left != NULL) sum+=(root->right->left->val);
    }
}
void traverse(TreeNode* root) {
    if(root == NULL) return;
    if(root->val % 2 == 0) {
        findSum(root);
    }
    traverse(root->left);
    traverse(root->right);
}
    int sumEvenGrandparent(TreeNode* root) {
        traverse(root);
        return sum;
    }
};