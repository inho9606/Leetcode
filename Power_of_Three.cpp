// https://leetcode.com/problems/power-of-three/submissions/
// Using Exponential operation. The available maximum number among the powers of three less than INT_MAX is 3**19. If n is  power of three number, mod of 3**19 division by n would be 0.
// This is not my solution, I couldn't come up with this idea.
// time: O(1), space: O(1)
// Runtime: 20 ms, faster than 48.74% of C++ online submissions for Power of Three.
// Memory Usage: 8.1 MB, less than 90.48% of C++ online submissions for Power of Three.
class Solution {
public:
	bool isPowerOfThree(int n) {
		if(n>0 && 1162261467 % n == 0) return 1;
		return 0;
	}
};