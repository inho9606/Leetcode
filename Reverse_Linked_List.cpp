// https://leetcode.com/problems/reverse-linked-list/submissions/
// 각 주소의 다음값을 이전으로 가리키게 함. 이전값 포인터, 현재값 포인터, 다음값 포인터 총 세 개를 사용
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