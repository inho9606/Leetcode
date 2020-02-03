// https://leetcode.com/problems/remove-linked-list-elements/submissions/
// ���� ���κ��� ���� ����� ���� üũ, �����ؾ��� ����̸� ���� ��带 ���� ���� ���� ����. ���� ��尡 ���� ����� �ƴϸ� ���� ���� �̵�.
// time: O(n) space: O(n)
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
	ListNode* removeElements(ListNode* head, int val) {
		if(head==NULL) return head;
		ListNode *ptr = new ListNode(0);
		ptr->next = head;
		head = ptr;
		while(ptr != NULL && ptr->next != NULL) {
			if(ptr->next->val == val)
				ptr->next = ptr->next->next;
			else ptr=ptr->next;
		}
		return head->next;
	}
};