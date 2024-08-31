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
vector<int>vec;
void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    vec.push_back(root->val);
    inorder(root->right);
}
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* r = new TreeNode(vec[0]);
        TreeNode* temp = r;
        for(int i = 1 ; i < vec.size() ; i++) {
           temp->right = new TreeNode(vec[i]);
           temp = temp->right;
        }
        return r;
     
    }
};