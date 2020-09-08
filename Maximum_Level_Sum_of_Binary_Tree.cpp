// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/
// BFS, record level and check the sum of values.
// time: O(n) space: O(n)
// Runtime: 320 ms, faster than 45.37% of C++ online submissions for Maximum Level Sum of a Binary Tree.
// Memory Usage: 110.1 MB, less than 12.46% of C++ online submissions for Maximum Level Sum of a 
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
	int maxLevelSum(TreeNode* root) {
		if(root==NULL) return 0;
		int answer=0, sum=0, psum=0, level=0, l=0;
		TreeNode* ptr;
		queue<pair<TreeNode*,int>> q;
		q.push({root, 1});
		while(q.empty() == 0) {
			ptr = q.front().first;
			l = q.front().second;
			q.pop();
			if(l > level) {
				if(sum > psum) { answer = level; psum = sum; }
				sum = 0;
				level = l;
			}
			sum += ptr->val;
			if(ptr->left != NULL) q.push({ptr->left, l+1});
			if(ptr->right != NULL) q.push({ptr->right, l+1});
		}
		if(sum > psum) answer = level;
		return answer;
	}
};