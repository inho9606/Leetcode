// https://leetcode.com/problems/simplify-path/submissions/
// Using two stacks
// I. Store directories to stack1. If the dir is '..', then pop the stack.
// II. Move data from stack1 to stack2 to make it have higher to lower path from top to bottom.
// III. Add the path from the top of the stack2 into string.
// time: O(n) space: O(n)
// Runtime: 12 ms, faster than 84.86% of C++ online submissions for Simplify Path.
// Memory Usage: 7.8 MB, less than 67.93% of C++ online submissions for Simplify Path.
class Solution {
public:
	string simplifyPath(string path) {
		string answer = "";
		stack<string> st1, st2;
		int i,j;
		for(i=0; i<path.size(); i++) {
			if(path[i] == '/') {
				if(i==path.size()-1) break;
				if(i+1 < path.size() && path[i+1] == '/') continue;
				for(j=i+1; j<=path.size(); j++) {
					if(j == path.size() || path[j] == '/') {
						if(path.substr(i+1, j-i-1) == ".") break;
						else if(path.substr(i+1, j-i-1) == "..") {
							if(st1.empty() == 0) st1.pop();
						}
						else st1.push(path.substr(i+1, j-i-1));
						i = j-1;
						break;
					}
				}
			}
		}
		while(st1.empty() == 0) {
			st2.push(st1.top());
			st1.pop();
		}
		if(st2.empty() == 1) return "/";
		while(st2.empty() == 0) {
			answer += "/" + st2.top();
			st2.pop();
		}
		return answer;
	}
};