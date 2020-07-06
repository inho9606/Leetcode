// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/
// Iterative Version with stack.
// I. Store pointers in stack from root to the most left node.
// II. Pick the top item of stack, and check if it's right node is null or not. If it is not nullpointer, then store it as subtree into stack.
// time: O(n) space: O(n)
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
//Memory Usage: 8.4 MB, less than 69.16% of C++ online submissions for Binary Tree Inorder Traversal.
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> answer;
		stack<TreeNode*> st;
		TreeNode* ptr = root;
		while(ptr!=NULL) {
			st.push(ptr);
			ptr = ptr->left;
		}
		while(st.empty() == 0) {
			ptr = st.top();
			answer.push_back(ptr->val);
			st.pop();
			ptr = ptr->right;
			while(ptr != NULL) {
				st.push(ptr);
				ptr = ptr->left;
			}
		}
		return answer;
	}
};

/** Recursion Version
class Solution {
public:
	void inorder(vector<int>& a, TreeNode* root) {
		if(root==NULL) return;
		inorder(a, root->left);
		a.push_back(root->val);
		inorder(a, root->right);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> answer;
		inorder(answer, root);
		return answer;
	}
};
*/