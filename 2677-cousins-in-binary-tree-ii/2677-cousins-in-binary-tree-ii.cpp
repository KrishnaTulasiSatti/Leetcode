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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
    
        while(!q.empty()) {
           int s = q.size();
           int sum = 0;
           for(int i = 0 ; i < s ; i++) {
              TreeNode* temp = q.front();
              q.pop(); 
              sum+=temp->val;
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
           }
           v.push_back(sum);
        }
        queue<TreeNode*>pq;
        pq.push(root);
        root->val = 0;
        int level = 1;
        while(!pq.empty()) {
            int s = pq.size();
            for(int i = 0 ; i < s ; i++) {
                TreeNode* temp = pq.front();
                pq.pop();
                int l = 0;
                int r = 0;
                if(temp->left) {
                    l+=temp->left->val;
                    pq.push(temp->left);
                }
                if(temp->right) {
                    r+=temp->right->val;
                    pq.push(temp->right);
                }
                if(temp->left) {
                    temp->left->val = v[level]-(l+r);
                }
                if(temp->right) {
                    temp->right->val = v[level]-(l+r);
                }
            }
            level++;
        }
        return root;

    }
};