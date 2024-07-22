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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int c = 0;
        while(!q.empty()) {
            vector<int>lev;
            int size = q.size();
              if(c % 2 == 0) {
                 for(int i = 0 ; i < size ; i++) {
                     TreeNode* node = q.front();
                     q.pop();
                     lev.push_back(node->val);
                     if(node->left != NULL) q.push(node->left);
                     if(node->right != NULL) q.push(node->right);
                } 
              }
              else{
                 stack<TreeNode*>st;
                 queue<TreeNode*>que;
                 //cout<<size<<" ";
                 for(int i = 0 ; i < size ; i++) {
                    st.push(q.front());
                    que.push(q.front());
                    q.pop();
                 }
                 for(int i = 0 ; i < size ; i++) {
                    TreeNode* node = st.top();
                    st.pop();
                    lev.push_back(node->val);
                 }
                 for(int i = 0 ; i < size ; i++) {
                     TreeNode* node = que.front();
                     que.pop();
                     if(node->left != NULL) q.push(node->left);
                     if(node->right != NULL) q.push(node->right);
                 }
              }
              ans.push_back(lev);
              c++;
            
            
        }
        return ans;
    }
};