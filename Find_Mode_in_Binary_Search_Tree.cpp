// https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/
// I. Store the nodes into a vector using tree traversal.
// II. Sort the vector containing tree's nodes.
// III. Find the maximum duplicates in the array
// III. Count each numbers in the array, and it appears as many as the maximum duplicates is, then add it to the answer vector.
// time: O(nlogn) space: O(n)
// Runtime: 20 ms, faster than 88.83% of C++ online submissions for Find Mode in Binary Search Tree.
// Memory Usage: 22.7 MB, less than 100.00% of C++ online submissions for Find Mode in Binary Search 
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
	void postorder(vector<int>& nums, TreeNode* root) {
		if(root == NULL) return;
		nums.push_back(root->val);
		postorder(nums, root->left);
		postorder(nums, root->right);
	}
	vector<int> findMode(TreeNode* root) {
		vector<int> answer, nums;
		int m=0, cnt=0;
		postorder(nums, root);
		sort(nums.begin(), nums.end());
		for(int i=0; i<nums.size(); i++) {
			if(i > 0 && nums[i] > nums[i-1]) {
				if(cnt > m) m = cnt;
				cnt = 0;
			}
			cnt += 1;
			if(i == nums.size()-1 && cnt > m) m = cnt;
		}
		cnt = 0;
		for(int i=0; i<nums.size(); i++) {
			if(i > 0 && nums[i] != nums[i-1]) {
				if(cnt == m) answer.push_back(nums[i-1]);
				cnt=0;
			}
			cnt+=1;
			if(i == nums.size()-1 && cnt == m) answer.push_back(nums[i]);
		}
		return answer;
	}
};