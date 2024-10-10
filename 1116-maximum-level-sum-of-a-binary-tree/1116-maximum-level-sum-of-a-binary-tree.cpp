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
        queue<TreeNode*>q;
        q.push(root);
        int maxi = INT_MIN;
        int j = 1;
        int ans = 1;
        while(!q.empty()) {
            int s = q.size();
            int sum = 0;
            for(int i = 0 ; i < s ; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
           // cout<<sum<<" "<<maxi<<" "<<j<<endl;
            if(sum > maxi) {
                maxi = sum;
                ans = j;
            }
            j++;
           // cout<<ans<<endl;
        }
        return ans;
    }
};