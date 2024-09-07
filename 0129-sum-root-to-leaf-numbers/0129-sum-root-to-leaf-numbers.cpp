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
vector<string>sum;
void traverse(TreeNode* root,string v) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        v+=(to_string(root->val));
        sum.push_back(v);
        return;
    }
    v+=(to_string(root->val));
    traverse(root->left,v);
    traverse(root->right,v);
    

}
    int sumNumbers(TreeNode* root) {
        traverse(root,"");
       // for(auto it : sum) cout<<it<<" "; 
        long res = 0;
        for(auto it : sum) res+=(stol(it));
        return res;
    }
};