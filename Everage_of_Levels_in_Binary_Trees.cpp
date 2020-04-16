// https://leetcode.com/problems/average-of-levels-in-binary-tree/submissions/
// I. Store each nodes with its level on the queue.
// II. Store each values in a vector.
// III. Get each level's average value.
// time: O(n) space: O(n)
// Runtime: 20 ms, faster than 69.38% of C++ online submissions for Average of Levels in Binary Tree.
// Memory Usage: 20.2 MB, less than 100.00% of C++ online submissions for Average of Levels in Binary Tree.
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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> answer;
		double avg;
		vector<long long> t(1);
		vector<vector<long long>> v;
		queue<pair<TreeNode*,int>> q;
		TreeNode* ptr;
		int level;
		long long sum;
		q.push({root, 1});
		while(q.empty() == 0) {
			ptr = q.front().first;
			level = q.front().second;
			q.pop();
			if(level > v.size()) {
				t[0] = ptr->val;
				v.push_back(t);
			}
			else
				v[level-1].push_back(ptr->val);
			if(ptr->left != NULL) q.push({ptr->left, level+1});
			if(ptr->right != NULL) q.push({ptr->right, level+1});
		}
		for(int i=0; i<v.size(); i++) {
			sum = 0;
			for(int j=0; j<v[i].size(); j++)
				sum += v[i][j];
			avg = (double)sum / v[i].size();
			answer.push_back(avg);
		}
		return answer;
	}
};