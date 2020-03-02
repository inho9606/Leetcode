// https://leetcode.com/problems/friend-circles/submissions/
// I. Find how many graphs there are in given M with DFS.
// II. From a vertex, visit all vertices connected, and invert the value to 2 to represent the visited vertex.
// III. When the loop finds 1, add 1 to count.
// time: O(n^2) space: O(n)
// Runtime: 24 ms, faster than 52.58% of C++ online submissions for Friend Circles.
// Memory Usage: 10.7 MB, less than 100.00% of C++ online submissions for Friend Circles.
class Solution {
public:
	void dfs(vector<vector<int> >& M, int from, int to) {
		M[from][to] = 2;
		M[to][from] = 2;
		for(int i=0; i<M.size(); i++) {
			if(M[to][i] == 1)
				dfs(M, to, i);
		}
	}
	int findCircleNum(vector<vector<int>>& M) {
		int answer=0;
		for(int i=0; i<M.size(); i++) {
			for(int j=0; j<M.size(); j++) {
				if(M[i][j] == 1) {
					answer += 1;
					dfs(M, i, j);
				}
			}
		}
		return answer;
	}
};

/*
* BFS Version
 Runtime: 32 ms, faster than 21.14% of C++ online submissions for Friend Circles. Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Friend Circles.
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		queue<pair<int,int> > path;
		int x, y, answer = 0;
		for(int i=0; i<M.size(); i++) {
			for(int j=0; j<M.size(); j++) {
				if(M[i][j] == 1) {
					answer += 1;
					path.push({i,j});
					M[i][j] = 2;
					while(path.empty() == 0) {
						y = path.front().first;
						x = path.front().second;
						path.pop();
						for(int k=0; k<M[x].size(); k++) {
							if(M[x][k] == 1) {
								M[x][k] = 2;
								path.push({x,k});
							}
						}
					}
				}
			}
		}
		return answer;
	}
};
*/