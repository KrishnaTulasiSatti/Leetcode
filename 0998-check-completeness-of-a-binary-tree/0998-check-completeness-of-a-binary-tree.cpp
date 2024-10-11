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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int s = q.size();
            int c = s;
            int flag = 0;
            for(int i = 0 ; i < s ; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) {
                    if(flag == 1) return false;
                    q.push(temp->left);
                }
                else flag = 1;
                if(temp->right) {
                    if(flag == 1) return false;
                    q.push(temp->right);
                }
                else flag = 1;



            }
            if(!q.empty() && pow(2,level) != s) return false;
            level++;

        }
        return true;
    }
};