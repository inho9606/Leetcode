// https://leetcode.com/problems/perfect-number/submissions/
// I. Initialize sum to 1.
// II. From 2 to square root of given number n, find the numbers that can divide n. Then, add the number and the divided number to sum.
// time: O(logn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Perfect Number.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Perfect Number.
class Solution {
public:
	bool checkPerfectNumber(int num) {
		int sum=1;
		for(int i=2; i*i<=num; i++) {
			if(num%i == 0) {
				if(i*i!=num) sum += num/i;
				sum += i;
			}
		}
		if(num >= 2 && sum == num) return 1;
		return 0;
	}
};