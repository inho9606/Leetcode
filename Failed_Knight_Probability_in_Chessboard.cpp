// https://leetcode.com/problems/knight-probability-in-chessboard/
// Failed,, tried to solution like BFS, not DP..
// Needs to understand hidden testcases
class Solution {
public:
	double knightProbability(int N, int K, int r, int c) {
		double answer=1, p, t;
		int i, j, valid, pos;
		queue<pair<int,int>> q;
		vector<vector<bool>> v(N, vector<bool>(N, 0));
		q.push({r, c});
		v[r][c] = 1;
		valid = 1;
		for(int cnt=0; cnt<K; cnt++) {
			t=0;
			pos=0;
			while(valid > 0) {
				p=0;
				i = q.front().first;
				j = q.front().second;
				q.pop();
				if(i-2 >= 0 && j-1 >= 0 && v[i-2][j-1] == 0) {
					p+=1;
					q.push({i-2, j-1});
					v[i-2][j-1] = 1;
				}
				if(i-2 >= 0 && j+1 < N && v[i-2][j+1] == 0) {
					p+=1;
					q.push({i-2, j+1});
					v[i-2][j+1] = 1;
				}
				if(i-1 >= 0 && j-2 >= 0 && v[i-1][j-2] == 0) {
					p+=1;
					q.push({i-1, j-2});
					v[i-1][j-2] = 1;
				}
				if(i+1 < N && j-2 >= 0 && v[i+1][j-2] == 0) {
					p+=1;
					q.push({i+1, j-2});
					v[i+1][j-2] = 1;
				}
				if(i+2 < N && j-1 >= 0 && v[i+2][j-1] == 0) {
					p+=1;
					q.push({i+2, j-1});
					v[i+2][j-1] = 1;
				}
				if(i+2 < N && j+1 < N && v[i+2][j+1] == 0) {
					p+=1;
					q.push({i+2, j+1});
					v[i+2][j+1] = 1;
				}
				if(i+1 < N && j+2 < N && v[i+1][j+2] == 0) {
					p+=1;
					q.push({i+1, j+2});
					v[i+1][j+2] = 1;
				}
				if(i-1 >= 0 && j+2 < N && v[i-1][j+2] == 0) {
					p+=1;
					q.push({i-1, j+2});
					v[i-1][j+2] = 1;
				}
				t += p/8;
				pos += p;
				valid-=1;
			}
			answer *= t;
			valid = pos;
		}
		return answer;
	}
};