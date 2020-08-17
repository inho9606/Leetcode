// https://leetcode.com/problems/print-immutable-linked-list-in-reverse/submissions/
// Using stack. Push the nodes from left to the right into stack, and pop it, which means the order of pop is reverse of original order.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Print Immutable Linked List in Reverse.
// Memory Usage: 6.8 MB, less than 13.19% of C++ online submissions for Print Immutable Linked List in Reverse.
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
	void printLinkedListInReverse(ImmutableListNode* head) {
		stack<ImmutableListNode*> st;
		for(auto ptr = head; ptr!=NULL; ptr = ptr->getNext())
			st.push(ptr);
		while(st.empty() == 0) {
			st.top()->printValue();
			st.pop();
		}
	}
};