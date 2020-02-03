// 두 개의 항을 연속해서 선택할 수 없기 때문에 [n-2]+n 과 [n3]+n 중 큰 값을 선택한다.
// time: O(n) space: O(n)
class Solution {
public:
	int rob(vector<int>& nums) {
		int answer = 0;
		vector<int> f(nums.size()+1,0);
		for(int i=0; i<nums.size(); i++) {
			if(i==0 || i==1) f[i+1] = nums[i];
			else {
				if(f[i-1] + nums[i] > f[i-2] + nums[i]) f[i+1] = f[i-1] + nums[i];
				else f[i+1] = f[i-2] + nums[i];
			}
			if(f[i+1] > answer) answer = f[i+1];
		}
		return answer;
	}
};