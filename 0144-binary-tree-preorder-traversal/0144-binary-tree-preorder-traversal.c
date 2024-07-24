/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 
 void preorder(struct TreeNode* root,int* arr,int* ind) {
    if(root == NULL) return;
    arr[(*ind)++] = root->val;
    preorder(root->left,arr,ind);
    preorder(root->right,arr,ind);

 }
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int* arr = (int*)malloc(1000*sizeof(int));
    int ind = 0;
    preorder(root,arr,&ind);
    *returnSize = ind;
    return arr;
}