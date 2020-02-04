// https://leetcode.com/problems/count-primes/submissions/
// 에라토스내의 채 이용. 2부터 n까지의 수를 검사, 배열에서 i의 값이 0이면 i의 배수를 모두 1로 변경. 0의 개수가 곧 prime(소인수?)의 개수
// time: O(n) space: O(n)
class Solution {
public:
	int countPrimes(int n) {
		if(n <= 2) return 0;
		vector<int> f(n,0);
		int answer=0;
		for(int i=2; i<n; i++) {
			if(f[i] == 0) { 
				answer++;
				for(int j=i*2; j<n; j+=i) f[j] = 1;
			}
		}
		return answer;
	}
};