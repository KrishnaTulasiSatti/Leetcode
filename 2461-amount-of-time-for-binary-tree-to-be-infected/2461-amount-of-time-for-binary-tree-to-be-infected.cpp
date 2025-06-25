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

TreeNode* startAdd = NULL;

void find(TreeNode* root,int start) {

    if(root == NULL) return;

    if(root->val == start) {
        startAdd = root;
        return;
    }

    find(root->left,start);
    find(root->right,start);

}

void trackParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& m) {

    queue<TreeNode*>q;

    q.push(root);

    while(!q.empty()) {

        auto top = q.front();
        q.pop();

        if(top->left) {
            q.push(top->left);
            m[top->left] = top;
        }

        if(top->right) {
            q.push(top->right);
            m[top->right] = top;
        }


    }
}
    int amountOfTime(TreeNode* root, int start) {
        
        // First you need to  find the address of start node

        // Later from the start node
        // you can either move to top or left or right in 1 sec to infect or burn

        // But to move to top we have to maintain the parents of each node


        // ---- Finding the address of start node

        find(root,start);

        // cout << startAdd->val; // Perfect

        // ---- Keep track of parents

        unordered_map<TreeNode*,TreeNode*>m;

        trackParents(root,m);

        // for(auto it : m) {
        //     cout << it.first->val << " " << it.second->val<< endl;
        // }  // Perfect

        
        //  ----- Now the main solution

        queue<TreeNode*>q;

        q.push(startAdd);

        vector<int>vis(100001,-1);

        vis[startAdd->val] = 1;

        int level = 0;

        while(!q.empty()) {

           

            int size = q.size();

            for(int i = 0 ; i < size ; i++) {

                auto top = q.front();
                q.pop();

                auto parent = m[top];
                if(parent && vis[parent->val] == -1) {
                    vis[parent->val] = 1;
                    q.push(parent);
                }

                if(top->left && vis[top->left->val] == -1) {
                    vis[top->left->val] = 1;
                    q.push(top->left);
                }

                if(top->right && vis[top->right->val] == -1) {
                    vis[top->right->val] = 1;
                    q.push(top->right);
                }
            }
            level++;
        }

        return level-1;
    }
};