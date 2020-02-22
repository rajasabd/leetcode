/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* space is o(n) because of the stack usage */

typedef struct ListNode *Node;

class Solution {
public:
    bool isPalindrome_on(ListNode* head)
    {
        stack<int> revData;
        ListNode* pTempNode = head;
        int tempVal= 0;
        bool result = 1;
        
        if(NULL == head)
        {
            return 1;
        }
        
        while(NULL != pTempNode)
        {
            revData.push(pTempNode->val);
            pTempNode = pTempNode->next;    
        }
        
        pTempNode = head;
        while(NULL != pTempNode)
        {
            if(revData.top() != pTempNode->val)
            {
                result = 0;
                break;
            }
            revData.pop();
            pTempNode = pTempNode->next;    
        }
        
        return result;
    }
    
/*To determine if the list is palindromic,
we would like to start in the middle, and step outwards comparing pairs of values. However this requires stepping backwards, which we cannot do as the list doesn't have links in that direction. We would need to build a new data structure to remember where we came from.

But we don't have to create a new data-structure if we modify the list itself in a non-destructive way to provide this information, by reversing the direction of some of the links.

Here's how we do it:

Reverse the first half of the list.
Step outwards from the middle.
Restore the list to its original state.
*/
   bool isPalindrome(Node head) {
    int n = length(head);

    Node left_head;
    Node right_head;
    reverseTill(head, n/2, &left_head, &right_head);
    
    Node L = left_head;
    Node R = right_head;
    
    if (n % 2 == 1) {
        R = R->next;
    }
    
    while (L || R) {
        if (L->val != R->val) {
            repairList(left_head, right_head);
            return false;
        }
        L = L->next;
        R = R->next;
    }
    
    repairList(left_head, right_head);
    return true;    
}

void reverseTill(Node head, int k, Node *left_head_ptr, Node *right_head_ptr) {
    Node previous = NULL;
    for (int i = 0; i < k && head; i++) {
        Node temp = head->next;
        head->next = previous;
        previous = head;
        head = temp;
    }
    *left_head_ptr = previous;
    *right_head_ptr = head;
}

void repairList(Node left_head, Node right_head) {
    while (left_head) {
        Node temp = left_head->next;
        left_head->next = right_head;
        right_head = left_head;
        left_head = temp;
    }
}

int length(Node head) {
    int i;
    for (i = 0; head; i++) {
        head = head->next;
    }
    return i;
} 
};

