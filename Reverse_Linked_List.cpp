// https://leetcode.com/problems/reverse-linked-list/submissions/
// �� �ּ��� �������� �������� ����Ű�� ��. ������ ������, ���簪 ������, ������ ������ �� �� ���� ���
// time: O(n), space: O(c) c= 3
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
	ListNode* reverseList(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode *prev=head, *ptr=head->next;
		ListNode *ptr2= ptr->next;
		while(ptr != NULL) {
			ptr->next = prev;
			prev = ptr;
			ptr = ptr2;
			if(ptr2 != NULL) ptr2= ptr2->next;
		}
		head->next = NULL;
		return prev;
	}
};