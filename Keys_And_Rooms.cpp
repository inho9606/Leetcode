// https://leetcode.com/problems/keys-and-rooms/submissions/
// BFS..
// If non-visited node exists after completing BFS, then return false. Otherwise return true.
// time: O(n) space: O(n)
// Runtime: 24 ms, faster than 46.72% of C++ online submissions for Keys and Rooms.
// Memory Usage: 10.3 MB, less than 94.56% of C++ online submissions for Keys and Rooms.
class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int n = rooms.size(), room;
		if(n==0) return 1;
		vector<bool> v(n, 0);
		queue<int> q;
		q.push(0);
		v[0] = 1;
		while(q.empty() == 0) {
			room = q.front();
			q.pop();
			for(int i=0; i<rooms[room].size(); i++) {
				if(v[rooms[room][i]] == 1) continue;
				q.push(rooms[room][i]);
				v[rooms[room][i]] = 1;
			}
		}
		for(int i=0; i<n; i++) {
			if(v[i] == 0) return 0;
		}
		return 1;
	}
};