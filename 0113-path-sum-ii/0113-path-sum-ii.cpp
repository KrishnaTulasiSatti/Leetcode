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
vector<vector<int>>ans;

void traverse(TreeNode* root,int target,int sum,vector<int>v) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        sum = sum+root->val;
        if(sum == target) {
            v.push_back(root->val);
            ans.push_back(v);
            return;
        }
    }
    sum+=root->val;
    v.push_back(root->val);
    traverse(root->left,target,sum,v);
    traverse(root->right,target,sum,v);
    
    
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        traverse(root,targetSum,0,v);
        return ans;
    }
};