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
vector<int>inorder;
void trav(TreeNode* root) {
    if(root == NULL) return;
    trav(root->left);
    inorder.push_back(root->val);
    trav(root->right);
}
void convert(TreeNode* root,vector<int>&inorder,vector<int>&temp) {
    if(root == NULL) return;
    convert(root->left,inorder,temp);
    int ind = -1;
    for(int i = 0 ; i < temp.size() ; i++) {
        if(temp[i] == root->val) {
               ind = i;
               break;
            }
    }
    if(ind != -1) root->val = inorder[ind]; 
    convert(root->right,inorder,temp);
}
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        trav(root);
        vector<int>temp = inorder;
        for(int i = 0 ; i < inorder.size() ; i++) {
            sum+=inorder[i];
        }
        vector<int>in;
        int prev = 0;
        in.push_back(sum);
        for(int i = 1 ; i < inorder.size() ; i++) {
            prev+=inorder[i-1];
           in.push_back(sum-prev);
        }
        convert(root,in,temp);
        return root;
    }
};