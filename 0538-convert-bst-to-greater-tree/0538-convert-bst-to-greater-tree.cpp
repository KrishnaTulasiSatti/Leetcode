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
void Inorder(TreeNode* root,vector<int>&in) {
    if(root == NULL) return;
    Inorder(root->left,in);
    in.push_back(root->val);
    Inorder(root->right,in);
}
int c = 0;
void change(TreeNode* root,vector<int>&v) {
    if(root == NULL) return;
    change(root->left,v);
    root->val = v[c];
    c++;
    change(root->right,v);
}
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;
        vector<int>inorder;
        Inorder(root,inorder);
        int sum = 0;
        vector<int>sums(inorder.size());
        for(auto it : inorder) {
          //  cout<<it<<" ";
          sum+=it;
        }
        cout<<endl;
        sums[0] = sum;
        for(int i = 1 ; i < inorder.size() ; i++) {
            sums[i] = sum-inorder[i-1];
            sum-=inorder[i-1];
        }
       // for(auto it : sums) cout<<it<<" ";
        change(root,sums);
        return root;
    }
};