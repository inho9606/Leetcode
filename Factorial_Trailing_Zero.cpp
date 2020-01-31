// https://leetcode.com/problems/factorial-trailing-zeroes/submissions/
// time: O(n/5) space: O(1)
// 문제에서 요구하눈 n!의 끝자리 0 개수를 찾으려면 n!의 값을 10으로 몇 번 나눌 수 있는지를 구해야 한다. n!= n*(N-1)*(n-2)*...*1이므로, 곱하는 수 중 2와 5의 개수를 세면 된다. 즉, 주어진 값을 5로 나눠지는 값이 2와 5의 개수가 된다.
class Solution {
public:
	int trailingZeroes(int n) {
		int answer=0;
		for(int i=n; i>0; i/=5)
			answer += i/5;
		return answer;
	}
};