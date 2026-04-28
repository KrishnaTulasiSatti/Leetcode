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
    bool fun(TreeNode* p,TreeNode* q) {
        if(p == NULL && q == NULL) return true;

        if(p == NULL || q == NULL) return false;


        bool left = false;
        bool right = false;

        if(p->val == q->val) {
            left = fun(p->left,q->left);
            right = fun(p->right,q->right);
        }

        return left && right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool ans = fun(p,q);

        return ans;
    }
};