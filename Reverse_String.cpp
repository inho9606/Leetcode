// https://leetcode.com/problems/reverse-string/submissions/
// swap the first item and the last item, and swap the second item and the second item from the last... until two pointers are intersected.
// time: O(n/2) space: O(1)
// Runtime: 48 ms, faster than 77.70% of C++ online submissions for Reverse String.
// Memory Usage: 15.3 MB, less than 65.85% of C++ online submissions for Reverse String.
class Solution {
public:
	void reverseString(vector<char>& s) {
		int i=0, j=s.size()-1, temp;
		while(i<j) {
			temp = s[j];
			s[j] = s[i];
			s[i] = temp;
			i++;
			j--;
		}
	}
};