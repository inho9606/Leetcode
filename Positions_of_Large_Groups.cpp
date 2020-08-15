// https://leetcode.com/problems/positions-of-large-groups/submissions/
// Count each characters. -- Brute Force
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 95.97% of C++ online submissions for Positions of Large Groups.
// Memory Usage: 7.2 MB, less than 93.41% of C++ online submissions for Positions of Large Groups.
class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> answer;
		int cnt=0, starting=0;
		for(int i=0; i<S.size(); i++) {
			if(i>0 && S[i] != S[i-1]) {
				if(cnt>=3)
					answer.push_back({starting, i-1});
				starting = i;
				cnt=0;
			}
			cnt+=1;
			if(i==S.size()-1 && cnt >=3)
				answer.push_back({starting, i});
		}
		return answer;
	}
};