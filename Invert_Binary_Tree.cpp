// https://leetcode.com/problems/invert-binary-tree/submissions/
// postorder로 순회, 왼쪽 오른쪽 노드를 서로 바꾼다.
// time: O(n) space: O(n) (stack 사용)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 10.1 MB, less than 5.45% of C++ online submissions for Invert Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(root == NULL) return 0;
		TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

/** BFS Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(root == NULL) return 0;
		queue<TreeNode*> q;
		TreeNode *ptr, *temp;
		q.push(root);
		while(q.empty() == 0) {
			temp = q.front();
			q.pop();
			ptr = temp->right;
			temp->right = temp->left;
			temp->left = ptr;
			if(temp->left != NULL) q.push(temp->left);
			if(temp->right != NULL) q.push(temp->right);
		}
		return root;
	}
};
*//