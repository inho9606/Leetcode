// https://leetcode.com/problems/factorial-trailing-zeroes/submissions/
// time: O(n/5) space: O(1)
// �������� �䱸�ϴ� n!�� ���ڸ� 0 ������ ã������ n!�� ���� 10���� �� �� ���� �� �ִ����� ���ؾ� �Ѵ�. n!= n*(N-1)*(n-2)*...*1�̹Ƿ�, ���ϴ� �� �� 2�� 5�� ������ ���� �ȴ�. ��, �־��� ���� 5�� �������� ���� 2�� 5�� ������ �ȴ�.
class Solution {
public:
	int trailingZeroes(int n) {
		int answer=0;
		for(int i=n; i>0; i/=5)
			answer += i/5;
		return answer;
	}
};