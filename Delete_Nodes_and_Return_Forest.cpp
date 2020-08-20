// https://leetcode.com/problems/delete-nodes-and-return-forest/submissions/
// I. Find the deleting node among trees.
// II. Disconnect link from deleting node and it's parent. If it is root of the subtree, then replace root with it's child. If the node has no child, then remove the subtree.
// III. If the deleting node is not root, then make a new subtree with a root as one of children of the deleting node.
// time: O(nm) space: O(m) n is the number of given nodes, and m is the number of subtrees.
// Runtime: 28 ms, faster than 78.35% of C++ online submissions for Delete Nodes And Return Forest.
// Memory Usage: 21.6 MB, less than 98.29% of C++ online submissions for Delete Nodes And Return Forest.
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
	TreeNode* dfs(TreeNode* root, int target) {
		if(root==NULL) return NULL;
		if(root->val == target) return root;
		TreeNode* temp;
		if(root->left != NULL && root->left->val == target) {
			temp = root->left;
			root->left = NULL;
			return temp;
		}
		if(root->right != NULL && root->right->val == target) {
			temp = root->right;
			root->right = NULL;
			return temp;
		}
		TreeNode* child = dfs(root->left, target);
		if(child!=NULL) return child;
		return dfs(root->right, target);
	}
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		vector<TreeNode*> answer;
		TreeNode* ptr, *t;
		answer.push_back(root);
		for(int i=0; i<to_delete.size(); i++) {
			for(int j=0; j<answer.size(); j++) {
				ptr = dfs(answer[j], to_delete[i]);
				if(ptr!=NULL) {
					if(ptr->left != NULL && ptr->right != NULL) {
						if(ptr==answer[j]) answer[j] = ptr->left;
						else answer.push_back(ptr->left);
						answer.push_back(ptr->right);
					}
					else if(ptr->left != NULL || ptr->right != NULL) {
						if(ptr->left == NULL) {
							if(answer[j] == ptr) answer[j] = ptr->right;
							else answer.push_back(ptr->right);
						}
						else {
							if(answer[j] == ptr) answer[j] = ptr->left;
							else answer.push_back(ptr->left);
						}
					}
					else if(answer[j] == ptr)
						answer.erase(answer.begin()+j);
					break;
				}
			}
		}
		return answer;
	}
};