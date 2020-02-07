// https://leetcode.com/problems/power-of-two/submissions/
// ù ��° ��Ʈ�� 1���� Ȯ���Ѵ�. ��ȣ��Ʈ�� ������ ��Ʈ���� 1�� �� �� �̻� ������ False, n�� ������ ������ n�� �����Ͽ� ����� �ٲ۴�.
// Followup! log_2�� ����ϸ� �� ����. n�� 2�� ������ log_2(n)�� ���� ������ �� ��.
// time: O(1)? space: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Two.
// Memory Usage: 8.1 MB, less than 96.00% of C++ online submissions for Power of Two.
class Solution {
public:
	bool isPowerOfTwo(int n) {
		int bits = 0;
		if(n<0) n = !n;
		for(int i=0; i<31; i++) {
			if(n & 1 == 1) bits+=1;
			if(bits > 1) return 0;
			n = n>>1;
		}
		if(bits == 0) return 0;
		return 1;
	}
};

/** log�� Ȱ���� Ǯ��
class Solution {
public:
	bool isPowerOfTwo(int n) {
		double l = log2(n);
		if(l == (int)l) return 1;
		return 0;
	}
};
*//