class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
       
    }
};
