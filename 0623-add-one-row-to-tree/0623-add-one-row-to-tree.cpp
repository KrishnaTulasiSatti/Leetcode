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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;

        q.push(root);

        int level = 1;

        vector<TreeNode*>res;

        if(depth == 1) {

            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
            
        }

        while(!q.empty()) {

            if(level == depth) break;

            int size = q.size();
            vector<TreeNode*>v;

            for(int i = 0 ; i < size ; i++) {
                auto top = q.front();
                q.pop();

                v.push_back(top);

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }

            level++;

            res = v;

            

        }

        for(auto it : res) {
            TreeNode* l = NULL;
            TreeNode* r = NULL;

            if(it->left) l = it->left;
            if(it->right) r = it->right;

            it->left = new TreeNode(val);
            it->left->left = l;

            it->right = new TreeNode(val);
            it->right->right = r;
        }

        return root;
    }
};