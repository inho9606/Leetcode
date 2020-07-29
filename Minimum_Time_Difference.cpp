// https://leetcode.com/problems/minimum-time-difference/submissions/
// I. Convert all input to minutes.
// II. Sort converted list, and find the minimum difference.
// time: O(nlogn) space: O(n)
// Runtime: 36 ms, faster than 72.44% of C++ online submissions for Minimum Time Difference.
// Memory Usage: 13.4 MB, less than 84.85% of C++ online submissions for Minimum Time Difference.
class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		int n, answer = 1440;
		vector<int> converted(timePoints.size());
		for(int i=0; i<timePoints.size(); i++) {
			n = stoi(timePoints[i].substr(0, 2));
			n *= 60;
			n += stoi(timePoints[i].substr(3, 2));
			converted[i] = n;
		}
		sort(converted.begin(), converted.end());
		for(int i=0; i<converted.size()-1; i++) {
			if(converted[i+1] - converted[i] < answer)
				answer = converted[i+1] - converted[i];
		}
		if(converted[0] + 1440 - converted[converted.size()-1] < answer) answer = converted[0] + 1440 - converted[converted.size()-1];
		return answer;
	}
};