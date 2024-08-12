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
    int cnt = 0;
    int findSum(TreeNode* root,int* size) {
        if(root == NULL) return 0;
        *size = *size+1;
        return root->val+findSum(root->left,size)+findSum(root->right,size);

    }
    void aveg(TreeNode* root) {
        if(root == NULL) return ;
        int c = 0;
        int ls = findSum(root->left,&c);
        int rs = findSum(root->right,&c);
        int avg = (root->val+ls+rs)/(c+1);
        if(avg == root->val) cnt++;
        aveg(root->left);
        aveg(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
       aveg(root);
       return cnt;
    }
};