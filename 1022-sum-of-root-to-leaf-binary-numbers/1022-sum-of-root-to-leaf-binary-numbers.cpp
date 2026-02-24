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
    int res = 0;

    void fun(TreeNode* root,string& str) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            
            str+=((root->val)+'0');
            for(int i = 0 ; i < str.size() ; i++) res += (str[i]-'0')*pow(2,str.size()-1-i);
            str.pop_back();
            return;
        }

        str+=((root->val)+'0');
        fun(root->left,str);
        fun(root->right,str);
        str.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        string str = "";
        fun(root,str);
        return res;
    }
};