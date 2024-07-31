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
int depth(TreeNode* root) {
    if(root == NULL) return 0;
    return 1+max(depth(root->left),depth(root->right));
}
int sum = 0;

void deepestSum(TreeNode* root,int l,int len) {
       if(root == NULL) return;
       if(l == len-1) sum+=root->val;
       deepestSum(root->left,l+1,len);
       deepestSum(root->right,l+1,len);
}
    int deepestLeavesSum(TreeNode* root) {
        int len = depth(root);
        deepestSum(root,0,len);
        return sum;
    }
};