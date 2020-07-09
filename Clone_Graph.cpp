// BFS Method used
// I. Build new graph with BFS way on the original graph.
// II. If the node is already visited, then check if the current node got connected to the visited node. If it is not, then find the created nodes, and connect them.
// time: O(n^2) space: O(n)
// Runtime: 8 ms, faster than 96.65% of C++ online submissions for Clone Graph.
// Memory Usage: 8.8 MB, less than 68.92% of C++ online submissions for Clone Graph.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
	Node* cloneGraph(Node* node) {
		Node *answer=NULL, *ptr, *ptr2, *t1;
		vector<Node*> nodes;
		vector<bool> visited(101, 0);
		queue<Node*> q;
		int x;
		if(node==NULL) return answer;
		else answer = new Node(node->val);
		q.push(node);
			visited[node->val] = 1;
		nodes.push_back(answer);
		while(q.empty() == 0) {
			ptr = q.front();
			q.pop();
			for(int i=0; i<nodes.size(); i++) {
				if(nodes[i]->val == ptr->val) { ptr2 = nodes[i]; break; }
			}
			for(int i=0; i<ptr->neighbors.size(); i++) {
				x = ptr->neighbors[i]->val;
				if(visited[x] == 0) {
					t1 = new Node(x);
					ptr2->neighbors.push_back(t1);
					t1->neighbors.push_back(ptr2);
					visited[x] = 1;
					q.push(ptr->neighbors[i]);
					nodes.push_back(t1);
				}
				else {
					for(int j=0; j<ptr2->neighbors.size(); j++) {
						if(x == ptr2->neighbors[j]->val) break;
						if(j == ptr2->neighbors.size() -1) {
							for(int k=0; k<nodes.size(); k++) {
								if(x == nodes[k]->val) { ptr2->neighbors.push_back(nodes[k]); nodes[k]->neighbors.push_back(ptr2); break; }
							}
						}
					}
				}
			}
		}
		return answer;
	}
};