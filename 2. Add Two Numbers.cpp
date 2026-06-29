class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* dummy = new ListNode(); 
    ListNode* ans = dummy;
    int carry = 0;
    
    while (p1 || p2) {
        int sum = carry; 
        
        if (p1) {
            sum += p1->val;
            p1 = p1->next;
        }
        if (p2) {
            sum += p2->val;
            p2 = p2->next;
        }
        
        ans->next = new ListNode(sum % 10); 
        carry = sum / 10;                 
        ans = ans->next;                    
    }
    
    if (carry) {
        ans->next = new ListNode(carry); 
    }
    
    ListNode* result = dummy->next;
    delete dummy; 
    return result;
}
};
