// https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/
// Copy the value of the given node to the give node's next node, and then delete the next one of the given node.
// time: O(1), space: O(1)
// Runtime: 12 ms, faster than 89.33% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage: 10.4 MB, less than 11.54% of C++ online submissions for Delete Node in a Linked List.

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
	void deleteNode(ListNode* node) {
		if(node->next == NULL) node = NULL;
		else{
			ListNode * temp = node->next;
			node->val = temp->val;
			node->next = temp->next;
			delete temp;
		}
	}
};