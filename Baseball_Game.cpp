// https://leetcode.com/problems/baseball-game/submissions/
// Simulation Implement with vector like stack.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Baseball Game.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Baseball Game.
class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> t;
		int answer=0;
		for(int i=0; i<ops.size(); i++) {
			if(ops[i] == "+" && t.size()>1)
				t.push_back(t[t.size()-1]+t[t.size()-2]);
			else if(ops[i] == "D" && t.size() > 0)
				t.push_back(t[t.size()-1]*2);
			else if(ops[i] == "C" && t.size()>0)
				t.pop_back();
			else
				t.push_back(atoi(ops[i].c_str()));
		}
		for(int i=0; i<t.size(); i++)
			answer += t[i];
		return answer;
	}
};