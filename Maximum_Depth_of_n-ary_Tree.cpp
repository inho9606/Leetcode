// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/submissions/
// I. Using BFS with queue recording the node and it's depth.
// II. Check the depth of the current node, and update it to answer.
// time: O(n), space: O(n)
// Runtime: 48 ms, faster than 93.21% of C++ online submissions for Maximum Depth of N-ary Tree.
// Memory Usage: 55.6 MB, less than 5.00% of C++ online submissions for Maximum Depth of N-ary Tree.
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
	int maxDepth(Node* root) {
		if(root==NULL) return 0;
		int answer= 0, level;
		Node* ptr;
		queue<pair<Node*,int>> tree;
		tree.push({root, 1});
		while(tree.empty() == 0) {
			ptr = tree.front().first;
			level = tree.front().second;
			tree.pop();
			if(level > answer) answer = level;
			if(ptr == NULL) continue;
			for(int i=0; i<ptr->children.size(); i++) {
				if(ptr->children[i] == NULL) continue;
				tree.push({ptr->children[i], level+1});
			}
		}
		return answer;
	}
};