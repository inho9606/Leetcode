// https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/
// Recursive solution,
// time: O(n) space: O(n)
// Runtime: 40 ms, faster than 95.66% of C++ online submissions for N-ary Tree Preorder Traversal.
// Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for N-ary Tree Preorder Traversal.
/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/
class Solution {
public:
	void traversal(Node* root, vector<int>& a) {
		if(root==NULL) return;
		a.push_back(root->val);
		for(int i=0; i<root->children.size(); i++) {
			traversal(root->children[i], a);
		}
	}
	vector<int> preorder(Node* root) {
		vector<int> answer;
		traversal(root, answer);
		return answer;
	}
};