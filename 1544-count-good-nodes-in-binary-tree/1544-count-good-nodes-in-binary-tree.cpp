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
void traverse(TreeNode* root,priority_queue<int>pq) {
    if(root == NULL) return;
    pq.push(root->val);
    traverse(root->left,pq);
    traverse(root->right,pq);
   // cout<<pq.top()<<endl;
    if(pq.top() <= root->val) cnt++;

}
    int goodNodes(TreeNode* root) {
        priority_queue<int>pq;
        traverse(root,pq);
        return cnt;
    }
};