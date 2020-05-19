// https://leetcode.com/problems/longest-univalue-path/submissions/
// time: O(n) space: O(1)
// Runtime: 280 ms, faster than 8.08% of C++ online submissions for Longest Univalue Path.
// Memory Usage: 72 MB, less than 7.14% of C++ online submissions for Longest Univalue Path.
class Solution {
private:
	int answer=0;
public:
	int dfs(TreeNode* root){
		if(root == NULL) return 0;
		int left, right;
		if(root->left != NULL) left = dfs(root->left);
		if(root->right != NULL) right = dfs(root->right);
		if(root->left==NULL || root->val != root->left->val) left = 0;
		if(root->right==NULL || root->val != root->right->val) right = 0;
		if(left+right+1 > answer) answer = left+right+1;
		return max(left, right) + 1;
	}
	int longestUnivaluePath(TreeNode* root) {
		dfs(root);
		return answer>=1 ? answer-1: 0;
	}
};
