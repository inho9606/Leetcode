// https://leetcode.com/problems/license-key-formatting/submissions/
// I. Count all valid characters.
// II. Add the first part by dividing n by K.
// III. Make parts with K size after II.
// time: O(n) space: O(n)
// Runtime: 8 ms, faster than 96.69% of C++ online submissions for License Key Formatting.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for License Key Formatting.
class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string New = "";
		int i, j=0, n=0;
		for(i=0; i<S.size(); i++) {
			if(S[i] != '-') n++;
		}
		for(i=0; j<n%K; i++) {
			if(S[i] == '-') continue;
			New += toupper(S[i]);
			j++;
		}
		if(New.size() > 0 && n > K) New += "-";
		n = 0;
		for(; i<S.size(); i++) {
			if(S[i] == '-') continue;
			if(n == K) {
				New += "-";
				n = 0;
			}
			New += toupper(S[i]);
			n+=1;
		}
		return New;
	}
};
/*
* Another Solution with Stack, insert and erase
time: O(n^2) space: O(n^2)
// Runtime: 12 ms, faster than 77.23% of C++ online submissions for License Key Formatting.
// Memory Usage: 12.7 MB, less than 6.90% of C++ online submissions for License Key Formatting.
class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		stack<string> st;
		stack<char> stc;
		string t="", New = "";
		int n=0;
		for(int i=S.size()-1; i>=0; i--) {
			if(n == K) {
				while(stc.empty() == 0) {
					t += stc.top();
					stc.pop();
				}
				st.push(t);
				t.clear();
				n = 0;
			}
			if(S[i] == '-') continue;
			stc.push(toupper(S[i]));
			n += 1;
		}
		while(stc.empty() == 0) {
			t += stc.top();
			stc.pop();
		}
		New += t;
		while(st.empty() == 0) {
			if(New.size() > 0) New += "-";
			New += st.top();
			st.pop();
		}
		return New;
	}
};
*/