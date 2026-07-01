class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
    int cnt = 1;
    while(temp != NULL) {
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
} 
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next!=NULL){
            len ++;
            tail = tail->next;
        }
        if(k%len == 0) return head;
        k = k%len;
        tail ->next = head;
        ListNode *newLastnode = findNthNode(head, len-k);
        head = newLastnode->next;
        newLastnode->next = NULL;
        return head;
    }
};
