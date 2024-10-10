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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int s = q.size();
            int a = INT_MIN;
            int b = INT_MAX;
           // cout<<level<<" ";
            for(int i = 0 ; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(level % 2 != 0 && temp->val % 2 != 0) return false;
                if(level % 2 == 0 && temp->val % 2 == 0) return false;
                if(level % 2 == 0) {
                     if(temp->val <= a) return false;
                     a = temp->val;
                }
                else {
                    if(b <= temp->val) return false;
                    b = temp->val;
                }
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);

            }
            level++;
        }
        return true;
    }
};