// https://www.google.com/search?source=hp&ei=SVgxXu-FK8LnwQOgw5uQAQ&q=path+sum+%EB%A6%AC%ED%8A%B8%EC%BD%94%EB%93%9C&oq=path+sum+%EB%A6%AC%ED%8A%B8%EC%BD%94%EB%93%9C&gs_l=psy-ab.3...3948.5564..8409...0.0..2.276.1977.2j8j3......0....1..gws-wiz.......0j0i131j0i30j33i160.ttnWM5B-Tkk&ved=0ahUKEwivzqqLx6jnAhXCc3AKHaDhBhIQ4dUDCAk&uact=5#spf=1580292179348
// time: O(n) memory : O(n)
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
	bool hasPathSum(TreeNode* root, int sum) {
		if(root == NULL) return 0;
		int s;
		TreeNode* ptr;
		queue<pair<TreeNode*,int> > path;
		path.push({root, root->val});
		while(path.empty() == 0) {
			s = path.front().second;
			ptr = path.front().first;
			if(s==sum && ptr->left == NULL && ptr->right == NULL) return 1;
			path.pop();
			if(ptr->left != NULL) path.push({ptr->left, s+ptr->left->val});
			if(ptr->right != NULL) path.push({ptr->right, s+ptr->right->val});
		}
	return 0;
	}
};