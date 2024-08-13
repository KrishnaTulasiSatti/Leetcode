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
int s = 0;
int Depth(TreeNode* root) {
    if(root == NULL) return 0;
    return 1+max(Depth(root->left),Depth(root->right));
}
void Sum(TreeNode* root,int l,int len) {
    if(root == NULL) return;
    if(l == len) {
        s+=root->val;
        return;
    }
    l = l+1;
    Sum(root->left,l,len);
    Sum(root->right,l,len);


}
    int deepestLeavesSum(TreeNode* root) {
        int len = Depth(root);
        cout<<len<<" ";
        int l = 1;
        Sum(root,l,len);
        return s;
    }
};