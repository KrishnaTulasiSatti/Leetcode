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
    int minimumOperations(TreeNode* root) {
        int cnt = 0;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            vector<int>v;
            for(int i = 0 ; i < s ; i++) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            vector<int>temp = v;
            sort(v.begin(),v.end());

             unordered_map<int,int>m;
             for(int i = 0 ; i < v.size() ; i++) {
                m[v[i]] = i;
             }

             for(int i = 0 ; i < v.size() ; i++) {
                if(v[i] != temp[i]) {
                    cnt++;
                    int p1 = m[temp[i]];
                    m[v[i]] = p1;
                    swap(v[p1],v[i]);
                }
             }
            
        }
        return cnt;
    }
};