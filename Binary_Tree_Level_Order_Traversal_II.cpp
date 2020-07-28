// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/submissions/
// Just BFS and reverse the vector.
// time: O(n) space: O(n)
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> answer;
		int level;
		TreeNode* ptr;
		queue<pair<TreeNode*,int>> q;
		q.push({root, 0});
		while(q.empty() == 0) {
			ptr = q.front().first;
			level = q.front().second;
			q.pop();
			if(ptr==NULL) continue;
			if(level < answer.size())
				answer[level].push_back(ptr->val);
			else
				answer.push_back({ptr->val});
			if(ptr->left != NULL) q.push({ptr->left, level+1});
			if(ptr->right != NULL) q.push({ptr->right, level+1});
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
};