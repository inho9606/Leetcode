// https://leetcode.com/problems/find-the-difference/submissions/
// using XOR bit operation. XOR operation toggles itself and zero. So, exor on s+t should be the new element.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Difference.
// Memory Usage: 9.2 MB, less than 11.11% of C++ online submissions for Find the Difference.
class Solution {
public:
	char findTheDifference(string s, string t) {
		string n = s + t;
		int answer=0;
		for(int i=0; i<n.size(); i++)
			answer ^= n[i];
		return answer;
	}
};

/*
* O(nlogn) solution with sort
class Solution {
public:
	char findTheDifference(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		for(int i=0; i<s.size(); i++) {
			if(s[i] != t[i]) return t[i];
		}
		return t[t.size()-1];
	}
};
*/