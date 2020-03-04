// https://leetcode.com/problems/fibonacci-number/submissions/
// f[n] = f[n-1]+f[n-2];
// time: O(n) space: O(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Fibonacci Number.
class Solution {
public:
	int fib(int N) {
		vector<int> f(N+1);
		f[0] = 0;
		if(N >=1 ) f[1] = 1;
		for(int i=2; i<=N; i++)
			f[i] = f[i-1]+f[i-2];
		return f[N];
	}
};