// https://leetcode.com/problems/palindrome-linked-list/submissions/
// �� �� ��ȸ�ؼ� ����Ʈ�� ���̸� �˾Ƴ���, ��ü ���� ���� ���� ���� �κ��� �Ųٷ� �����. �׸��� �� �ٲ� �κ��̶� ó�� ���̸�ŭ�� ���� ������ Ʈ��. �ƴϸ� ����
// time: O(n) space: O(1)
// Runtime: 20 ms, faster than 93.34% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 12.6 MB, less than 81.03% of C++ online submissions for Palindrome Linked List.
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
	bool isPalindrome(ListNode* head) {
		if(head == NULL || head->next == NULL) return 1;
		int length = 0;
		ListNode *cur, *before=NULL, *after;
		for(cur=head; cur != NULL; cur=cur->next) length++;
		cur = head;
		for(int i=0; i<length/2; i++) cur = cur->next;
		if(length %2 == 1) cur = cur->next;
		after = cur->next;
		while(cur != NULL) {
			cur->next = before;
			before = cur;
			cur = after;
			if(after != NULL) after = after->next;
		}
		cur = head;
		while(before != NULL) {
			if(cur->val != before->val) return 0;
			cur = cur->next;
			before = before->next;
		}
	return 1;
	}
};