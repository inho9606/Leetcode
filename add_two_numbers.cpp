// https://leetcode.com/problems/add-two-numbers/submissions/
// Idea: just like binary adder
// Refered to discuss section to optimize the code
// time: O(n) space: O(n) n is the length of given numbers.
// Runtime: 32 ms, faster than 68.99% of C++ online submissions for Add Two Numbers.
// Memory Usage: 70.1 MB, less than 85.91% of C++ online submissions for Add Two Numbers.
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry=0, t;
		ListNode l3(0);
		ListNode *ptr = &l3;
		while(l1 != NULL || l2 != NULL) {
			t = carry;
			if(l1 != NULL) t += l1->val;
			if(l2 != NULL) t += l2->val;
			carry = t/10;
			ptr->next = new ListNode(t%10);
			ptr = ptr->next;
			if(l1 != NULL) l1 = l1->next;
			if(l2 != NULL) l2= l2->next;
		}
		if(carry > 0) ptr->next = new ListNode(carry);
		return l3.next;
	}
};