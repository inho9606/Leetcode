// https://leetcode.com/problems/power-of-two/submissions/
// 첫 번째 비트만 1인지 확인한다. 부호비트를 제외한 비트에서 1이 두 개 이상 있으면 False, n이 음수일 때에는 n을 부정하여 양수로 바꾼다.
// Followup! log_2를 사용하면 더 빠름. n이 2의 배수라면 log_2(n)의 값은 정수가 될 것.
// time: O(1)? space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Two.
// Memory Usage: 8.1 MB, less than 96.00% of C++ online submissions for Power of Two.
class Solution {
public:
	bool isPowerOfTwo(int n) {
		int bits = 0;
		if(n<0) n = !n;
		for(int i=0; i<31; i++) {
			if(n & 1 == 1) bits+=1;
			if(bits > 1) return 0;
			n = n>>1;
		}
		if(bits == 0) return 0;
		return 1;
	}
};

/** log를 활용한 풀이
class Solution {
public:
	bool isPowerOfTwo(int n) {
		double l = log2(n);
		if(l == (int)l) return 1;
		return 0;
	}
};
*//