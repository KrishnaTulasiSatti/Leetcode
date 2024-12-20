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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
          
        int level = 0;  
        while(!q.empty()) {
            
            int s = q.size();
            vector<TreeNode*>v;
            for(int i = 0 ; i < s ; i++) {
                TreeNode* f = q.front();
                q.pop();
                v.push_back(f);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
           
        
            if(level % 2) {
                 for(int i = 0 ; i < v.size()/2 ; i++) {
                    swap(v[i]->val,v[v.size()-1-i]->val);
                  }               
            }
            level++;
            

        }
        return root;
    }
};