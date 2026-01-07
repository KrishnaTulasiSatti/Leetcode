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

    long long maxi = 0;

    const int mod = 1e9+7;

    long long findSum(TreeNode* root) {

        if(root == NULL) return 0;

        long long l = findSum(root->left);
        long long r = findSum(root->right);

        return ((root->val + l) % mod + r%mod) % mod;
     }

    long long fun(TreeNode* root,long long sum) {

        if(root == NULL) return 0;

        long long l = fun(root->left,sum);
        long long r = fun(root->right,sum);

        long long s = ((root->val + l) % mod + r%mod) % mod;

        long long a = s;
        long long b = (sum-s);

        maxi = max(maxi,(a * b));

        return s;
    }

    int maxProduct(TreeNode* root) {
        long long sum = findSum(root);
      //  cout << sum ;

        long long ans = fun(root,sum);

        return maxi % mod;
    }
};

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
// class Solution {
// public:
//     vector<long long> vec;
//     long long maxi = LLONG_MIN;
//     long long mod = 1e9+7;
//     long long fun(TreeNode* root) {
//         if(root == NULL) return 0;
//         long long left = fun(root->left);
//         long long right = fun(root->right);
//         long long sum = (left+right+root->val)%mod;
//         vec.push_back(sum);
//         maxi = max(maxi, sum);
//         return sum;
//     }
//     int maxProduct(TreeNode* root) {
//         fun(root);
//         long long ans = 0;
//         for(int i=0; i<vec.size(); i++){
//             long long v1 = vec[i];
//             long long v2 = (maxi - vec[i])%mod;
//             ans = max(ans, (v1*v2)%mod);
//         }
//         return ans;
//     }
// };