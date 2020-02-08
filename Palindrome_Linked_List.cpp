// https://leetcode.com/problems/palindrome-linked-list/submissions/
// 한 번 순회해서 리스트의 길이를 알아내고, 전체 길이 빼기 절반 끝에 부분을 거꾸로 만든다. 그리고 그 바뀐 부분이랑 처음 길이만큼이 서로 같으면 트루. 아니면 폴스
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