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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it : nums) m[it]++;
        int flag = 0;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            int a = temp->val;
            if(m[a] != 0 && flag == 0) {
                cnt++;
                flag = 1;
            }
            else if(m[a] == 0) {
                flag = 0;
            }
            temp = temp->next;
        }
        return cnt;
    }
};