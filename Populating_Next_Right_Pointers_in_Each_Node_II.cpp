// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/
// I. Initialize the previous node is NULL when starting the new level.
// II. If the parent has two childs, then connect those.
// III. If the previous is not NULL, then connect previous node and the most left child. Set the previous node to the most right child.
// IV. Move parent node to the next right one and repeat II and III until the node faces NULL.
// V. If the parent node cannot move to the next, then move to the most left node on the next level.
// time: O(n) space: O(1)
// Runtime: 16 ms, faster than 89.57% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage: 17.5 MB, less than 62.98% of C++ online submissions for Populating Next Right Pointers in Each Node II.
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
		Node* ptr, *temp=NULL, *prev=NULL;
		for(ptr = root; ptr!=NULL;) {
			temp = ptr;
			prev=NULL;
			while(temp) {
				if(prev!=NULL) {
					if(temp->left) prev->next = temp->left;
					else if(temp->right) prev->next = temp->right;
				}
				if(temp->left && temp->right)
					temp->left->next = temp->right;
				if(temp->right) prev = temp->right;
				else if(temp->left) prev=temp->left;
				temp = temp->next;
			}
		if(ptr->left) ptr = ptr->left;
		else if(ptr->right) ptr = ptr->right;
		else if(ptr->next) ptr = ptr->next;
		else break;
		}
		return root;
	}
};

/*
* Classic BFS with level
* time: O(n) space: O(n)
class Solution {
public:
	Node* connect(Node* root) {
		Node* ptr, *prev=NULL;
		int level, pre;
		queue<pair<Node*,int>> q;
		q.push({root, 1});
		while(q.empty() == 0) {
			ptr = q.front().first;
			level = q.front().second;
			q.pop();
			if(ptr == NULL) continue;
			if(level == pre) prev->next = ptr;
			q.push({ptr->left, level+1});
			q.push({ptr->right, level+1});
			prev = ptr;
			pre = level;
		}
		return root;
	}
};
*/