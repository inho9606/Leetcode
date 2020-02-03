// https://leetcode.com/problems/remove-linked-list-elements/submissions/
// 현재 노드로부터 다음 노드의 값을 체크, 제거해야할 대상이면 다음 노드를 다음 다음 노드로 변경. 다음 노드가 제거 대상이 아니면 다음 노드로 이동.
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