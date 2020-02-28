// https://leetcode.com/problems/heaters/submissions/
// failed with my solution.. using binary search, need study more
// time: O(nlogn) space: O(1)
// Runtime: 72 ms, faster than 94.73% of C++ online submissions for Heaters.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Heaters.
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end());
		int answer=0, left, right, mid;
		for(int i=0; i<houses.size(); i++) {
			if(houses[i] <= heaters[0])
				answer = max(answer, heaters[0] - houses[i]);
			else if(houses[i] >= heaters.back())
				answer = max(answer, houses[i] - heaters.back());
			else {
				left = 0;
				right = heaters.size()-1;
				while(left <= right) {
					mid = (left+right)/2;
					if(heaters[mid] == houses[i]) break;
					else if(heaters[mid] < houses[i]) left = mid+1;
					else right = mid-1;
				}
				if(left>right)
					answer = max(answer, min(heaters[left]-houses[i], houses[i]-heaters[right]));
			}
		}
		return answer;
	}
};