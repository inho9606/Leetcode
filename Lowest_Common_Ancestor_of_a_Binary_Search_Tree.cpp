// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/
// 이진탐색 시행. p, q 중 하나라도 subtree의 root와 값이 같으면 해당 subtree의 root를 반환. p, q 둘 다 모두 root의 값보다 작으면 왼쪽 탐색, 둘 다 root보다 크면 오른쪽 탐색.
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