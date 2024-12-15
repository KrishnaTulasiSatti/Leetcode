/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
bool res = false;
void traverse(TreeNode* root,string ll,string c) {
    if(root == NULL) return;
    
    c+=(root->val+'0');


    if(c.find(ll) != string::npos) res = true;

    traverse(root->left,ll,c);
    traverse(root->right,ll,c);

}
    bool isSubPath(ListNode* head, TreeNode* root) {
        string ll = "";
        ListNode* temp = head;
        while(temp != NULL) {
            ll+=(temp->val+'0');
            temp = temp->next;
        }

        traverse(root,ll,"");
        return res;
    }
};