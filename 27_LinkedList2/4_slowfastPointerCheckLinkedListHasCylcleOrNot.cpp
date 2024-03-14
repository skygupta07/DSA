/*


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;  // tortoise and hare both at starting line
        ListNode* fast = head;  // slow and fast pointer...

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast ) return true;
        } 
        return false;
    }
    
};

*/