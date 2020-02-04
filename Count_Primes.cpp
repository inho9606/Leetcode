// https://leetcode.com/problems/count-primes/submissions/
// �����佺���� ä �̿�. 2���� n������ ���� �˻�, �迭���� i�� ���� 0�̸� i�� ����� ��� 1�� ����. 0�� ������ �� prime(���μ�?)�� ����
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