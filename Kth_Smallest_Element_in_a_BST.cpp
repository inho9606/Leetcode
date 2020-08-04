// https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
// I. Find the smallest number; push all leftnodes into stack.
// II. Find the kth smallest number by traversaling tree using stack; top element of stack is the current smallest element.
// time: O(n) space: O(logn)
// Runtime: 28 ms, faster than 76.73% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 24.2 MB, less than 67.11% of C++ online submissions for Kth Smallest Element in a BST.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		TreeNode* ptr;
		for(ptr=root; ptr!=NULL; ptr=ptr->left)
			st.push(ptr);
		for(int i=1; i<k; i++) {
			ptr = st.top();
			st.pop();
			for(ptr=ptr->right; ptr!=NULL; ptr=ptr->left)
				st.push(ptr);
		}
		return st.top()->val;
	}
};