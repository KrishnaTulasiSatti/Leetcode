/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prevnode = NULL;
    struct ListNode *crtnode,*nextnode;
    crtnode = nextnode = head;
    while(nextnode != NULL){
        nextnode = crtnode->next;
        crtnode->next = prevnode;
        prevnode = crtnode;
        crtnode = nextnode;
    }
    head = prevnode;
    return head;
}