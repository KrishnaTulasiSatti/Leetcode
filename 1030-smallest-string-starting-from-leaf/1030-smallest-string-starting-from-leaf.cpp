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
string ans = "";
void traverse(TreeNode* root,string str) {
    if(root == NULL)  return;
    str+=(root->val+'a');
    if(root->left == NULL && root->right == NULL) {
        reverse(str.begin(),str.end());
        if(ans == "") ans = str;
        else ans = min(ans,str);
        return;
    }
    traverse(root->left,str);
    traverse(root->right,str);
}
    string smallestFromLeaf(TreeNode* root) {
        string str;
        traverse(root,str);
        return ans;
    }
};