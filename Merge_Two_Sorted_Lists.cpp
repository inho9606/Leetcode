// https://leetcode.com/problems/merge-two-sorted-lists/submissions/
// time: O(L1.size+L2.size)
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
	ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
		ListNode *L3 = new ListNode(0);
		ListNode* ptr = L3;
		while(L1 != NULL && L2 != NULL) {
			if(L1->val <= L2->val) {
				ptr->next = L1;
				L1 = L1->next;
			}
			else {
				ptr->next = L2;
				L2 = L2->next;
			}
			ptr = ptr->next;
		}
		if(L1 == NULL) ptr->next = L2;
		else ptr->next = L1;
		return L3->next;
	}
};