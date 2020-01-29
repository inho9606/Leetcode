// https://leetcode.com/problems/symmetric-tree/submissions/
// time: O(2n)? BFS would be faster than DFS. Have no idea how to use Queue with pointers
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
	bool check(TreeNode* t1, TreeNode* t2) {
		bool answer;
		if(t1 == NULL && t2 == NULL) return 1;
		if(t1 == NULL || t2 == NULL) return 0;
		if(t1->val != t2->val) return 0;
		answer = check(t1->left, t2->right);
		if(answer == 0) return 0;
		answer = check(t1->right, t2->left);
		return answer;
	}
	bool isSymmetric(TreeNode* root) {
		return check(root, root);
	}
};