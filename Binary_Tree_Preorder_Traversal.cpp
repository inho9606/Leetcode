// https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/
// Iterative solution:
// I. From the root to the most leftnode, push all nodes to a stack.
// II. The top node on the stack becomes root of subtree. So, move to it's rightchild, and push all nodes from the root and it's most left.
// III. Key idea: Push rootnode into stack, push all leftnodes into stack, and push all rightnodes into stack.
// time: O(n) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 8.3 MB, less than 92.42% of C++ online submissions for Binary Tree Preorder Traversal.
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> answer;
		TreeNode *ptr = root;
		stack<TreeNode*> st;
		for(ptr = root; ptr!=NULL; ptr = ptr->left) {
			st.push(ptr);
			answer.push_back(ptr->val);
		}
		while(st.empty() == 0) {
			ptr = st.top();
			st.pop();
			for(ptr=ptr->right; ptr!=NULL; ptr = ptr->left) {
				st.push(ptr);
				answer.push_back(ptr->val);
			}
		}
		return answer;
	}
};

/*
* Recursive Solution
* time: O(n) space: O(n)
class Solution {
public:
	void preorder(TreeNode* root, vector<int>& a) {
		if(root==NULL) return;
		a.push_back(root->val);
		preorder(root->left, a);
		preorder(root->right, a);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> answer;
		preorder(root, answer);
		return answer;
	}
};
*/