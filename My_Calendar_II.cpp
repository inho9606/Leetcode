// https://leetcode.com/problems/my-calendar-ii/submissions/
// I. Record the starting date and ending date on map. Starting date +=1, ending date -=1 because starting means the event will be counted, and ending means it is done, so make the space.
// II. From I, Map has range of events. So, plus the number of events on each day, and return false if the event has 3.
// time: O(n) space: O(n)
class MyCalendarTwo {
public:
	map<int,int> cal;
	MyCalendarTwo() {
	}
    
	bool book(int start, int end) {
		int event=0;
		cal[start] += 1;
		cal[end] -= 1;
		for(auto ptr=cal.begin(); ptr!=cal.end(); ptr++) {
			event += ptr->second;
			if(event>=3) {
				cal[start] -= 1;
				cal[end] += 1;
				return 0;
			}
		}
		return 1;
	}
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */