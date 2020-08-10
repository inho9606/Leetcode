// Mock Interview
// I. Add two nodes of each lists. If the added number is greater than 9, then use carrybit.
// II. Carrybit is the number divided by 10.
// III. The result node is carrybit + added number.
// Time: O(n) space: O(n) n is the total length of two lists.
// Spent 19 mins.
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
		ListNode l3(0);
		ListNode *p1=l1, *p2=l2, *p3=&l3;
		int carry = 0, n;
		while(p1 != NULL && p2 != NULL) {
			n = carry + p1->val + p2->val;
			carry = n/10;
			if(n>=10) {
				n %= 10;
			}
			p3->next = new ListNode(n);
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
		}
		while(p1!=NULL) {
			n = carry+p1->val;
			carry = n/10;
			if(n>=10) n %= 10;
			p3->next = new ListNode(n);
			p1 = p1->next;
			p3 = p3->next;
		}
		while(p2!=NULL) {
			n = carry+p2->val;
			carry = n/10;
			if(n>=10) n %= 10;
			p3->next = new ListNode(n);
			p2 = p2->next;
			p3 = p3->next;
		}
		if(carry!=0)
			p3->next = new ListNode(carry);
		return l3.next;
	}
};