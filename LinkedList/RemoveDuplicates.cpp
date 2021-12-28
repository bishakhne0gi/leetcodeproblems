/**Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
**/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr=head;
        ListNode *next_next;
        if(curr==NULL)
            return head;
        while(curr->next != NULL)
        {
            if(curr->val==curr->next->val)
            {
                next_next=curr->next->next;
                delete(curr->next);
                curr->next=next_next;
            }
            else
            {
                curr=curr->next;
            }
        }
        return head;
    }
};