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

    unordered_map<int,int>m;

    int sum(TreeNode* root) {
        if(root == NULL) return 0;
        int s = root->val + sum(root->left) + sum(root->right);
        m[s]++;
        return s;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {

        int res = sum(root);

        int maxFrq = 0;

        for(auto it : m) maxFrq = max(maxFrq,it.second);

        vector<int>ans;

        for(auto it : m) {
            if(it.second == maxFrq) ans.push_back(it.first);
        }

        return ans;
    }
};