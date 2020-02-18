// https://leetcode.com/problems/sum-of-left-leaves/submissions/
// BFS used. Check if the left node is not null and it's left and right nnodes are null. Plus the value to answer if conditions are satisfied
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
// Memory Usage: 13.5 MB, less than 63.64% of C++ online submissions for Sum of Left Leaves.
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
	int sumOfLeftLeaves(TreeNode* root) {
		int answer = 0;
		queue<TreeNode*> t;
		t.push(root);
		while(t.empty() == 0) {
			root = t.front();
			t.pop();
			if(root == NULL) continue;
			if(root->left != NULL && root->left->left == NULL && root->left->right == NULL) answer += root->left->val;
			t.push(root->left);
			t.push(root->right);
		}
		return answer;
	}
};