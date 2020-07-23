// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/
// I. Visit all nodes, and if the previous visit's level and current level are same, then the previous node's next sets current node. 
// II. To do this work with BFS, record node and it's level on queue.
// Followup Key Idea: Parent node can connect it's children.
// time: O(n) space: O(n)
// Runtime: 20 ms, faster than 99.10% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 17.6 MB, less than 9.67% of C++ online submissions for Populating Next Right Pointers in Each Node.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node* connect(Node* root) {
		queue<pair<Node*,int>> q;
		Node *ptr, *prev=NULL;
		int level, prelevel;
		q.push({root,1});
		while(q.empty() == 0) {
			ptr = q.front().first;
			level = q.front().second;
			q.pop();
			if(ptr==NULL) continue;
			if(prev!=NULL && prelevel == level) prev->next = ptr;
			if(ptr->left != NULL) q.push({ptr->left, level+1});
			if(ptr->right != NULL) q.push({ptr->right, level+1});
			prev = ptr;
			prelevel = level;
		}
		return root;
	}
};

/*
* Followup Solution: O(n), O(1)
class Solution {
public:
	Node* connect(Node* root) {
		Node* ptr, *t;
		for(ptr=root; ptr != NULL && ptr->left != NULL; ptr = ptr->left) {
			for(t = ptr; t != NULL; t = t->next) {
				t->left->next = t->right;
				if(t->next != NULL)
					t->right->next = t->next->left;
			}
	}
		return root;
	}
};
*/