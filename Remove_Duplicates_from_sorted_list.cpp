// https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/
// time: O(n) how to reduce the memory space?
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(head==NULL) return head;
		ListNode* ptr = head;
		while(ptr->next != NULL) {
			if(ptr->val == ptr->next->val) {
				ptr->next = (ptr->next)->next;
			}
			else ptr = ptr->next;
		}
		return head;
	}
};