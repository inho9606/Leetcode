// https://leetcode.com/problems/climbing-stairs/submissions/class Solution {
// time: O(n)
class Solution {
public:
	int climbStairs(int n) {
	vector<int> f(n);
		f[0] = 1;
		for(int i=1; i<n; i++) {
			if(i==1) f[i] = 2;
			else f[i] = f[i-1]+f[i-2];
		}
		return f[n-1];
	}
};