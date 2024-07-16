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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int frq[100001] = {0};
        for(int i = 0 ; i < nums.size() ; i++) {
            frq[nums[i]] = 1;
        }
        ListNode* temp = head;
        ListNode* res = NULL;
        ListNode* temp2 = NULL;
        while(temp != NULL) {
             if(frq[temp->val] == 1) {
                 if(temp->next == NULL) temp2->next = NULL; 
                 temp = temp->next;
               
             }
             else{
                if(res == NULL) {
                    res = temp;
                }
                else{
                    temp2->next = temp;
                }
                temp2 = temp;
                temp = temp->next;
             }
        }
        return res;
    }
};