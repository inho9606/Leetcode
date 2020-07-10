// https://leetcode.com/problems/validate-binary-search-tree/submissions/
// I. Decide the range that childnodes can be. Left child of the node should be less than the current node and grater than current node's parent node. Right child of the current node should be grater than current node and current node's parent node. It means that the child node is affected by parent and grandparent nodes.
// II. Initialize leftlimit and rightlimit which limits value of childnodes. And update those limits when moving to left or right child. Rightchild updates leftlimit, which means leftchild of rightchild should be less than leftlimit and grater than rightchild. And leftchild updates rightlimit.
// 한국어: 왼쪽 자식으로 갈 때는 현재 노드 값보다 작아야 하고 동시에 현재 노드의 부모 값보다 커야 함. 오른쪽 자식은 현재 값보다 커야하고 현재 노드의 부모보다 작아야 함. 시작할 때에는 루트의 부모가 없으므로 최대값으로 초기화. 그리고 이게 같은 부모의 값에 영향을 받는 것이 아니기 때문에 두 개의 변수로 제어하는 것이 필요. 왼쪽으로 내려갈 때에는 부모보다 작기만 하면 되지만, 왼쪽으로 가서 오른쪽으로 내려갈 때에는 현재의 값이 손자에게 영향을 미치므로 업데이트 필요. 마찬가지로 오른쪽으로 가던 것이 오른쪽으로 계속 내려가면 현재의 값보다 크기만 하면 되어서 상관없는데, 오른쪽으로 가서 왼쪽으로 내려가면 현재의 값에 영향을 받아서 업데이트 필요.
// time: O(n) space: O(1)
// Runtime: 16 ms, faster than 88.61% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 21.4 MB, less than 97.58% of C++ online submissions for Validate Binary Search Tree.
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
	bool dfs(TreeNode* root, long long leftlimit, long long rightlimit) {
		if(root==NULL) return 1;
		if(root->left != NULL && (root->left->val >= root->val || root->left->val <= leftlimit)) return 0;
		if(root->right != NULL && (root->right->val <= root->val || root->right->val >= rightlimit)) return 0;
		bool l = dfs(root->left, leftlimit, root->val);
		if(l == 0) return 0;
		bool r = dfs(root->right, root->val, rightlimit);
		if(r==0) return 0;
		return 1;
	}
	bool isValidBST(TreeNode* root) {
		return dfs(root, LLONG_MIN, LLONG_MAX);
	}
};