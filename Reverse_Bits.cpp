// https://leetcode.com/problems/reverse-bits/submissions/
// �־��� �� n�� 1�̶� ���� �����Ͽ� ������ ���� �ִ� ���� ���ο� ������ ���Ѵ�. �׸��� �־��� ���� ��Ʈ�� ���������� �о ������ �� ��Ʈ�� ���ο� ���� ��Ʈ�� �ٲ۴�. �׸��� �������� ��Ʈ�� �������� �о ���ο� ���� ���Ѵ�.
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