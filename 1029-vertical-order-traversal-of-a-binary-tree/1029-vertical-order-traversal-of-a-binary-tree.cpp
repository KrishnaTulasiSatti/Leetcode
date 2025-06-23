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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;

        queue<pair<TreeNode*,pair<int,int>>>q;

        q.push({root,{0,0}});

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            TreeNode* node = top.first;
            int line = top.second.first;
            int level = top.second.second;

            m[line][level].insert(node->val);

            if(node->left) q.push({node->left,{line-1,level+1}});
            if(node->right) q.push({node->right,{line+1,level+1}});
        }

        vector<vector<int>>ans;

        for(auto it : m) {
            vector<int>res;
            for(auto i : it.second) {
                res.insert(res.end(), i.second.begin(), i.second.end());
            }

            ans.push_back(res);
        }

        return ans;
    }
};