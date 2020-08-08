class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> answer;
		vector<int> s(nums.begin(), nums.end());
		sort(s.begin(), s.end());
		int cnt;
		for(int i=0; i<nums.size(); i++) {
			cnt=0;
			for(int j=0; j<s.size(); j++) {
				if(s[j] == nums[i]) {
					answer.push_back(cnt);
					break;
				}
				cnt++;
			}
		}
		return answer;
	}
};