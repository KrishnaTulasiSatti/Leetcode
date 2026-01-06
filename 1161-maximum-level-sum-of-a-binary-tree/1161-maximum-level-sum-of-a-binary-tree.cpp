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
    int maxLevelSum(TreeNode* root) {

        int level = 0;
        int sum = INT_MIN;

        queue<TreeNode*>q;
        q.push(root);

        int l = 0;

        while(!q.empty()) {

            int size = q.size();

            int s = 0;

            for(int i = 0 ; i < size ; i++) {
                TreeNode* top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                s += top->val;
            }

           // cout << s << " " << level << endl;
            if(s > sum) {
                sum = s;
                level = l;
            }

            l++;


        }

        return level+1;


    }
};