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
void inOrder(TreeNode* root) {
    if(root == NULL) return;
    inOrder(root->left);
    inorder.push_back(root->val);
    inOrder(root->right);
}
    bool isValidBST(TreeNode* root) {
       inOrder(root);
       vector<int>temp = inorder;
       sort(temp.begin(),temp.end());
       set<int>s;
       for(auto it : inorder) s.insert(it);
       if(temp == inorder && s.size() == inorder.size()) return true;
       return false;
    }
};