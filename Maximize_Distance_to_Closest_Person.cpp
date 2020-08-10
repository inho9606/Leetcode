class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		vector<int> taken;
		int d=0;
		for(int i=0; i<seats.size(); i++) {
			if(seats[i] == 1) taken.push_back(i);
		}
		d = taken[0];
		for(int i=1; i<taken.size(); i++) {
			if((taken[i] - taken[i-1])/2 > d) d = (taken[i] - taken[i-1])/2;
		}
		if(seats.size()-1 - taken[taken.size()-1] > d) d = seats.size()-1 - taken[taken.size()-1];
		return d;
	}
};