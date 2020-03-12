// https://leetcode.com/problems/reverse-string-ii/submissions/
// I. Initialize j to the start point, end point should be j+k.
// II. Reverse characters from j to j+k, which means to swap elements from j to (j+k)/2 with elements from the end to the middle of the range. (the end of the range is (j+k-1)-(i-j)
// III. Increase start point j to 2*k, and repeat II.
// time: O(n) space: O(1)
// Runtime: 4 ms, faster than 96.47% of C++ online submissions for Reverse String II.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Reverse String II.
class Solution {
public:
	string reverseStr(string s, int k) {
		char t;
		int j=0;
		while(j<s.size()) {
			if(s.size()-j < k) k = s.size()-j;
			for(int i=j; i<(j+j+k)/2; i++) {
				t = s[i];
				s[i] = s[j+k-1-i+j];
				s[j+k-1-i+j] = t;
			}
		j += 2*k;
		}
		return s;
	}
};