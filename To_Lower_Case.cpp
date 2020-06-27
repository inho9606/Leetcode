// https://leetcode.com/problems/to-lower-case/submissions/
// Used Ascii code. Can make the space complexity decreased if string  replace is used.
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for To Lower Case.
// Memory Usage: 6.2 MB, less than 22.00% of C++ online submissions for To Lower Case.
class Solution {
public:
	string toLowerCase(string str) {
		string answer = "";
		for(int i=0; i<str.size(); i++) {
			if(str[i] >= 65 && str[i] <= 90) answer += str[i]+32;
			else answer += str[i];
		}
		return answer;
	}
};