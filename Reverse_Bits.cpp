// https://leetcode.com/problems/reverse-bits/submissions/
// 주어진 수 n을 1이랑 엔드 연산하여 오른쪽 끝에 있는 값을 새로운 변수에 더한다. 그리고 주어진 수의 비트를 오른쪽으로 밀어서 오른쪽 끝 비트를 새로운 연산 비트로 바꾼다. 그리고 더해지는 비트를 왼쪽으로 밀어서 새로운 수를 더한다.
// time: O(1) space: O(1)
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t answer = 0;
			for(int i=0; i<32; i++) {
				answer = answer<<1;
				answer += (n&1);
				n = n>>1;
			}
			return answer;
	}
};