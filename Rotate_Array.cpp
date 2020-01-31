// https://leetcode.com/problems/rotate-array/submissions/
// time: O(n^2) space: O(1) O(n) �õ������� �׽�Ʈ���̽� 4�������� �ᱹ ����...
// ������ ���� �ִ� ���� ���� �տ� �ִ´�.
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int t;
		for(int i=0; i<k; i++) {
			t = nums.back();
			nums.pop_back();
			nums.insert(nums.begin(), t);
		}
	}
};

// ������ �����κ��� k-1��ŭ �������� �ͼ� ù��° ��Ҷ� �ٲ�ġ���Ѵ�. �ٲ�ġ�Ⱑ ������ ������ �� �� �κ��� ã�Ƽ� �ݺ� ����.
/**
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		if(k==0) return;
		int t, j=nums.size()-k;
		int last = nums[j-1], n = nums.size(), l;
		for(int i=0; i<n; i++) {
			t = nums[j];
			nums[j] = nums[i];
			nums[i] = t;
			j++;
			if(j==n) {
				for(l=n-1; nums[l] != last; l--) ;
				if(l != n-1) j = l+1;
				else break;
			}
		}
	}
};
*//