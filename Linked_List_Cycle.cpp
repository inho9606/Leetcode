// https://leetcode.com/problems/linked-list-cycle/submissions/
// time: O(n) space: O(1)
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
	bool hasCycle(ListNode *head) {
		if(head == NULL) return 0;
		ListNode *ptr1=head, *ptr2=head;
		while(ptr1 != NULL && ptr2 != NULL) {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
			if(ptr2 != NULL) ptr2=ptr2->next;
			if(ptr1 != NULL && ptr1 == ptr2) return 1;
		}
		return 0;
	}
};