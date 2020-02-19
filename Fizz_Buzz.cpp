// https://leetcode.com/problems/fizz-buzz/submissions/
// Check if each numbers from 1 to n can be divided by 3 or 5.
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 96.99% of C++ online submissions for Fizz Buzz.
// Memory Usage: 9.9 MB, less than 86.67% of C++ online submissions for Fizz Buzz.
class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> answer(n, "");
		for(int i=1; i<=n; i++) {
			if(i%3 == 0) answer[i-1] += "Fizz";
			if(i%5==0) answer[i-1] += "Buzz";
			if(answer[i-1] == "") answer[i-1] = to_string(i);
		}
		return answer;
	}
};