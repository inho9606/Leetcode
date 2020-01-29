// https://leetcode.com/problems/same-tree/submissions/
// time: O(n) memory: O(1)
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		bool answer;
		if(p == NULL && q == NULL) return 1;
		if((p == NULL || q == NULL) && !(p == NULL && q == NULL)) return 0;
		if(p->val != q->val) return 0;
		answer = isSameTree(p->left, q->left);
		if(answer == 0) return 0;
		answer = isSameTree(p->right, q->right);
		return answer;
	}
};