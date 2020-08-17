// Simulation
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
// Memory Usage: 6.2 MB, less than 74.88% of C++ online submissions for Backspace String Compare.
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		string a, b;
		for(int i=0; i<S.size(); i++) {
			if(S[i] == '#') {
				if(a.size() > 0) a.pop_back();
			}
			else a += S[i];
		}
		for(int i=0; i<T.size(); i++) {
			if(T[i] == '#') {
				if(b.size() > 0) b.pop_back();
			}
			else b += T[i];
		}
		if(a != b) return 0;
		return 1;
	}
};