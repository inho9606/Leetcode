// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
// I. Make new string with 0 representing a binary number.
// II. For n times, add 1 to the binary number string, and if the binary string is involved in the given string S. If it is not, the return false.
// time: O(n^2) space: O(n) * insert method at 0 index might take O(n) 
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary String With Substrings Representing 1 To N.
// Memory Usage: 6.3 MB, less than 90.71% of C++ online submissions for Binary String With Substrings Representing 1 To N.
class Solution {
public:
	bool queryString(string S, int N) {
		string b = "0";
		for(int i=1; i<=N; i++) {
			if(b[b.size()-1] == '0') b[b.size()-1] = '1';
			else {
				for(int j=b.size()-1; j>=0; j--) {
					if(b[j] == '1') b[j] = '0';
					else { b[j] = '1'; break; }
					if(j==0) b.insert(b.begin(), '1');
				}
			}
			if(S.find(b) >= S.size()) return 0;
		}
		return 1;
	}
};