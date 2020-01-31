// https://leetcode.com/problems/majority-element/submissions/
// time: O(nlogn) space: O(1)
// 주어진 배열을 정렬한 후, 앞에서부터 반복되는 숫자의 개수를 센다. 연속된 값이 이전의 연속된 값의 횟수보다 많으면 더 많아진 수를 업데이트한다. O(n)이 되게 하는 방법이 있을것같은데 모르겠다..
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int minimum=0, cnt=0, answer;
		sort(nums.begin(), nums.end());
		for(int i=0; i<nums.size(); i++) {
			if(i==0 || nums[i-1] != nums[i]) {
				if(i > 0 && cnt > minimum) { answer = nums[i-1]; minimum = cnt; }
				cnt = 1;
			}
			else cnt++;
			if(i == nums.size()-1 && cnt > minimum) answer = nums[i];
		}
		return answer;
	}
};