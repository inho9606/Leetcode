// https://leetcode.com/problems/happy-number/submissions/
// ó������ n�� �ڸ����� �����ؼ� ���� ���� 1�� �Ǵ� ������ ������ Ʈ��, �ڱ� �ڽ� n���� ���ư��� false��� �ߴµ� 2, 3 ��� ���ѷ����� ������ ���� �߰�. ������ ������غ� ���, ������ ��ȯ�ϴ� ������ ��� 4�� �ݵ�� ���İ��� ��Ģ�� �߰�. n�� �ڸ����� ���� ���� 4�� �Ǿ��� �� ������ ��ȯ�ߴ��� ���� �ذ�.
// time: ?? space: O(1)
class Solution {
public:
	bool isHappy(int n) {
		int sum, t = n;
		while(t != 1) {
			sum = 0;
			for(int i=t; i>0; i/=10) sum += (i%10)*(i%10);
			t = sum;
			if(t==4) return 0;
		}
		return 1;
		}
};