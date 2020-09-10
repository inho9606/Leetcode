// https://leetcode.com/problems/android-unlock-patterns/submissions/
// I. Define directions wher each number on keyboard can go to.
// II. Record the last number where it came from. and if it is between current number and unaccessible number, then update the accessible number.
// III. Repeat it for n times. :: backtracking.
// time limit exceeded..
class Solution {
public:
	void dfs(vector<vector<int>> k, vector<bool> v, int& answer, int m, int n, int i, int cnt) {
		if(v[i] == 1) return;
		v[i] = 1;
		cnt += 1;
		if(cnt >= m && cnt <= n) answer += 1;
		else if(cnt > n) return;
		if(i==1) {
			if(k[i][3] == 0 && v[2]) k[i][3] = 1;
			if(k[i][7] == 0 && v[4]) k[i][7] = 1;
			if(k[i][9] == 0 && v[5]) k[i][9] = 1;
		}
		else if(i==2) {
			if(k[i][8] == 0 && v[5]) k[i][8] = 1;
		}
		else if(i==3) {
			if(k[i][1] == 0 && v[2]) k[i][1] = 1;
			if(k[i][7] == 0 && v[5]) k[i][7] = 1;
			if(k[i][9] == 0 && v[6]) k[i][9] = 1;
		}
		else if(i==4) {
			if(k[i][6] == 0 && v[5]) k[i][6] = 1;
		}
		else if(i==6) {
			if(k[i][4] == 0 && v[5]) k[i][4] = 1;
		}
		else if(i==7) {
			if(k[i][1] == 0 && v[4]) k[i][1] = 1;
			if(k[i][3] == 0 && v[5]) k[i][3] = 1;
			if(k[i][9] == 0 && v[8]) k[i][9] = 1;
		}
		else if(i==8) {
			if(k[i][2] == 0 && v[5]) k[i][2] = 1;
		}
		else if(i==9) {
			if(k[i][1] == 0 && v[5]) k[i][1] = 1;
			if(k[i][3] == 0 && v[6]) k[i][3] = 1;
			if(k[i][7] == 0 && v[8]) k[i][7] = 1;
		}
		for(int j=1; j <= 9; j++) {
			if(k[i][j] == 1) dfs(k, v, answer, m, n, j, cnt);
		}
	}
	int numberOfPatterns(int m, int n) {
		vector<vector<int>> keyboard(10, vector<int>(10, 1));
		vector<bool> v(10, 0);
		unordered_set<int> s;
		int answer=0, t;
		keyboard[1][1] = keyboard[1][3] = keyboard[1][7] = keyboard[1][9] = 0;
		keyboard[2][2] = keyboard[2][8] = 0;
		keyboard[3][1] = keyboard[3][3] = keyboard[3][7] = keyboard[3][9] = 0;
		keyboard[4][4] = keyboard[4][6] = 0;
		keyboard[5][5] = 0;
		keyboard[6][4] = keyboard[6][6] = 0;
		keyboard[7][1] = keyboard[7][3] = keyboard[7][7] = keyboard[7][9] = 0;
		keyboard[8][2] = keyboard[8][8] = 0;
		keyboard[9][1] = keyboard[9][3] = keyboard[9][7] = keyboard[9][9] = 0;
		t=0;
		dfs(keyboard, v, t, m, n, 1, 0);
		answer+=t*4;
		t=0;
		dfs(keyboard, v, t, m, n, 2, 0);
		answer+=t*4;
		dfs(keyboard, v, answer, m, n, 5, 0);
		return answer;
	}
};