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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int right = 1,left = 0,top = 0,bottom = 0;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        ListNode* temp = head;
        int i = 0,j = 0;
        while(temp != NULL) {
            if(right == 1) {
                ans[i][j] = temp->val;
                j++;
                if(j > n-1 || (j <= n-1 && ans[i][j] != -1)) {
                    j--,i++;
                    right = 0;
                    bottom = 1;
                }
            }
            else if(bottom == 1) {
                ans[i][j] = temp->val;
                i++;
                if(i > m-1 || (i <= m-1 && ans[i][j] != -1)) {
                    i--,j--;
                    bottom = 0;
                    left = 1;
                }
            }
            else if(left == 1) {
                ans[i][j] = temp->val;
                j--;
                if(j < 0 || (j >= 0 && ans[i][j] != -1)) {
                    j++,i--;
                    left = 0;
                    top = 1;
                }
            }
            else if(top == 1) {
                ans[i][j] = temp->val;
                i--;
                if(i < 0 || (i >= 0 && ans[i][j] != -1)) {
                    i++,j++;
                    top = 0;
                    right = 1;
                }
            }
            temp = temp->next;
        }
        return ans;
    }
};