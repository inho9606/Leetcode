// https://leetcode.com/problems/rotate-array/submissions/
// time: O(n^2) space: O(1) O(n) 시도했지만 테스트케이스 4만개에서 결국 실패...
// 오른쪽 끝에 있는 것을 왼쪽 앞에 넣는다.
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

// 오른쪽 끝으로부터 k-1만큼 왼쪽으로 와서 첫번째 요소랑 바꿔치기한다. 바꿔치기가 끝나면 정렬이 덜 된 부분을 찾아서 반복 수행.
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