// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/submissions/
// Just Simulation like Brute Force..
// time: O(logn) space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
// Memory Usage: 5.8 MB, less than 97.02% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
class Solution {
public:
	int numberOfSteps (int num) {
		int answer=0;
		for(int i=num; i>0; ) {
			if(i%2==0) i/=2;
			else i-=1;
			answer+=1;
		}
		return answer;
	}
};