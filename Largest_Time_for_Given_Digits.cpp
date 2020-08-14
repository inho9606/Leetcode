// https://leetcode.com/problems/largest-time-for-given-digits/submissions/
// Find all available times by backtracking.
// time: O(nlogn) space: O(n) n is the number of possible times.
// Runtime: 8 ms, faster than 30.72% of C++ online submissions for Largest Time for Given Digits.
// Memory Usage: 10.6 MB, less than 6.46% of C++ online submissions for Largest Time for Given Digits.
class Solution {
public:
	void make(vector<string>& t, vector<int> v, int i, string n) {
		if(n.size() == 0 && v[i] > 2) return;
		else if(n.size() == 1) {
			if(n[0] == '2' && v[i] > 3) return;
		}
		else if(n.size() == 3 && v[i] > 5) return;
		if(n.size() == 2) n += ':';
		else {
			n += v[i]+48;
			v.erase(v.begin()+i);
		}
		if(v.size() == 0) {
			t.push_back(n);
			return;
		}
		for(int j=0; j<v.size(); j++)
			make(t, v, j, n);
	}
	string largestTimeFromDigits(vector<int>& A) {
		vector<string> times;
		for(int i=0; i<A.size(); i++) {
			make(times, A, i, "");
		}
		if(times.size() == 0) return "";
		sort(times.begin(), times.end());
		return times[times.size()-1];
	}
};