// https://leetcode.com/problems/merge-two-binary-trees/submissions/
// I. If the current nodes are not NULL, then add the values.
// II. If one of two nodes is NULL, then replace not Null pointer into NULL pointer.
// recursion: time: O(n) space: O(1)
// Runtime: 56 ms
// Memory Usage: 22.4 MB

/* Recursion Version */
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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if(t1 == NULL) return t2;
		if(t2 == NULL) return t1;
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};
/*
* Iterative Version
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if(t1 == NULL) return t2;
		if(t2 == NULL) return t1;
		TreeNode* root = t1;
		queue<TreeNode*> q1, q2;
		q1.push(t1);
		q2.push(t2);
		while(q1.empty() == 0 && q2.empty() == 0) {
			t1 = q1.front();
			t2 = q2.front();
			q1.pop();
			q2.pop();
			if(t1 != NULL && t2 != NULL) t1->val += t2->val;
			if(t1->left != NULL && t2->left != NULL) {
				q1.push(t1->left);
				q2.push(t2->left);
			}
			else if(t1->left == NULL && t2->left != NULL)
				t1->left = t2->left;
			if(t1->right != NULL && t2->right != NULL) {
				q1.push(t1->right);
				q2.push(t2->right);
			}
			else if(t1->right == NULL && t2->right != NULL) {
				t1->right = t2->right;
			}
		}
		return root;
	}
};
*/