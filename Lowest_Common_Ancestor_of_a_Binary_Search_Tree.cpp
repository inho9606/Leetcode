// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/
// ����Ž�� ����. p, q �� �ϳ��� subtree�� root�� ���� ������ �ش� subtree�� root�� ��ȯ. p, q �� �� ��� root�� ������ ������ ���� Ž��, �� �� root���� ũ�� ������ Ž��.
// time: O(logn) space: O(1)
// Runtime: 36 ms, faster than 84.07% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 25.7 MB, less than 100.00% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while(root != NULL) {
			if(p->val < root->val && q->val < root->val)
				root = root->left;
			else if(p->val > root->val && q->val > root->val)
				root = root->right;
			else break;
		}
		return root;
	}
};