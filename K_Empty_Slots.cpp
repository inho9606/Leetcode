// https://leetcode.com/problems/k-empty-slots/submissions
// I. The bulb turned on should be ordered, so use set for turned bulbs.
// II. When turning on each bulb, check distance between the new bulb and next one, and the new bulb and previous one.
// time: O(nlogn) space: O(n)
// Runtime: 392 ms, faster than 71.81% of C++ online submissions for K Empty Slots.
// Memory Usage: 90.6 MB, less than 47.87% of C++ online submissions for K Empty Slots.
class Solution {
public:
	int kEmptySlots(vector<int>& bulbs, int K) {
		set<int> s;
		for(int i=0; i<bulbs.size(); i++) {
			auto p = s.insert(bulbs[i]).first;
			if(i==0) continue;
			p++;
			if(p!=s.end()) {
				if(*(p--) - *p == K+1) return i+1;
			}
			else p--;
			if(p != s.begin()) {
				if(*(p--) - *p == K+1) return i+1;
			}
		}
		return -1;
	}
};