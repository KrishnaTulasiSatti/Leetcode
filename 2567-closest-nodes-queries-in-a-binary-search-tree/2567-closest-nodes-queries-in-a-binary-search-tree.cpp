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
vector<int>inorder;
void in(TreeNode* root) {
    if(root == NULL) return;
    in(root->left);
    inorder.push_back(root->val);
    in(root->right);
}
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        in(root);

        vector<vector<int>>res;

        for(int i = 0 ; i < queries.size() ; i++) {
            int num = queries[i];
            int largest = -1;
            int smallest = -1;
            auto maxi = lower_bound(inorder.begin(),inorder.end(),num);
            if(maxi != inorder.end()) largest = *maxi;
            auto mini = upper_bound(inorder.begin(),inorder.end(),num);
            if(mini != inorder.begin()) {
                --mini;
                smallest = *mini;
            } 

            res.push_back({smallest,largest});
            
        }
        return res;
    }
};