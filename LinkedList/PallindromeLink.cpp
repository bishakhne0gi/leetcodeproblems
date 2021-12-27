/**Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 */


/**
 ALGO
    Floyd's rabbit and tortoise method
 * 
 */
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
     ListNode* middleNode(ListNode* head) {
        ListNode *slow, *fast;
        slow=head;
        fast=head;
        if(head != NULL){
            while(fast != NULL && fast->next != NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        return slow;
    }
    ListNode * reverse(ListNode * head)
    {
            ListNode * prev= NULL;
            ListNode * current=head;
            ListNode * temp;
            while(current!=NULL)
            {
                temp=current->next;
                current->next=prev;
                prev=current;
                current=temp;
            }
            head=prev;
         return head;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast,  *last;
        ListNode *mid=middleNode(head);
        if(head==NULL)
                return true;
        slow=head;
        fast=head;
        if(head != NULL){
            while(fast != NULL && fast->next != NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        //fast will not be NULL when the number of nodes is odd
        if(fast!=NULL)
            last=reverse(mid->next);
        else
            //fast will be NULL when number of nodes is even
            last=reverse(mid);
        ListNode * curr=head;
        while(last!=NULL)
        {
            if(last->val!=curr->val)
            {
                return false;
            }
            last=last->next;
            curr=curr->next;
        }
        return true;
        
    }
};