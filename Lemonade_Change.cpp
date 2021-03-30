// https://leetcode.com/problems/lemonade-change/submissions/
// Simulation
// I. Consider the cases that customers pay $10 or $20.
// If the customer pays $10, then you should have at least one $5.
// If the customer pays $20, then you should have 3 $5 or 1 $10 and 2 $5.
// Runtime: 12 ms, faster than 84.57% of C++ online submissions for Lemonade Change.
// Memory Usage: 17.1 MB, less than 33.72% of C++ online submissions for Lemonade Change.
// time: O(n) space: O(1)
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		vector<int> change(3, 0);
		for(int i=0; i<bills.size(); i++) {
			if(bills[i] == 5) change[0] += 1;
			else if(bills[i] == 10) {
				if(change[0] == 0) return 0;
				change[0] -= 1;
				change[1] += 1;
			}
			else {
				if(change[1] >= 1 && change[0] >= 1) {
					change[1] -= 1;
					change[0] -= 1;
				}
				else if(change[0] >= 3)
					change[0] -= 3;
				else return 0;
				change[2] += 1;
			}
		}
		return 1;
	}
};