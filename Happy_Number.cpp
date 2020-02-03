// https://leetcode.com/problems/happy-number/submissions/
// 처음에는 n의 자리수를 제곱해서 더한 값이 1이 되는 순간이 나오면 트루, 자기 자신 n으로 돌아가면 false라고 했는데 2, 3 등에서 무한루프에 빠지는 것을 발견. 손으로 디버깅해본 결과, 무한이 순환하는 숫자의 경우 4를 반드시 거쳐가는 규칙을 발견. n의 자리수의 제곱 합이 4가 되었을 때 거짓을 반환했더니 문제 해결.
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