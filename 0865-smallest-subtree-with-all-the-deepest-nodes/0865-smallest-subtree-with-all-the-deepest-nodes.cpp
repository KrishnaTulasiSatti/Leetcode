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
    
    TreeNode* res = NULL;

    int fun(TreeNode* root,int h,int level,int cnt) {

        if(root == NULL) return 0;

        int left = fun(root->left,h+1,level,cnt);
        int right = fun(root->right,h+1,level,cnt);

        int ans = (h == level-1) ? 1 : 0;

        int total =  ans + left + right;

        // cout << total << endl;

        if(total == cnt && res == NULL) {
            res = root;
        }

        return total;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;

        int cnt = 0;

        while(!q.empty()) {
            
            int size = q.size();
            cnt = size;

            for(int i = 0 ; i < size ; i++) {
                TreeNode* top = q.front();
                q.pop();

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);

            }
            level++;
        }

     //   cout << level << "--" << cnt << endl;

        int a = fun(root,0,level,cnt);

        return res;
    }
};