class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if(nums.size() <= 1) return nums;
		set<int> s;
		bool ok;
		for(int i=0; i<nums.size()-1; i++) {
			ok=0;
			for(int j=i+1; j<nums.size(); j++) {
				if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
					s.insert(nums[j]);
					ok=1;
				}
				else {
					if(s.find(nums[i]) != s.end() && s.find(nums[j]) != s.end()) s.erase(s.find(nums[j]));
				}
			}
			if(ok==1) s.insert(nums[i]);
		}
		return vector<int>(s.begin(), s.end());
	}
};