// https://leetcode.com/problems/add-digits/submissions/
// My solution is iterative. Couldn't come up with the solution for follow up question
// time: O(n), Space: O(1)
Details 
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Digits.
// Memory Usage: 8.3 MB, less than 52.17% of C++ online submissions for Add Digits.
class Solution {
public:
	int addDigits(int num) {
		int sum;
		while(num / 10 != 0) {
			sum = 0;
			for(int i=num; i>0; i/=10) sum += i%10;
			num = sum;
		}
		return num;
	}
};

/* Follow Up Question
// time: O(1), Space: O(1)
class Solution {
public:
	int addDigits(int num) {
		return 1 + (num-1)%9;
	}
};
*/