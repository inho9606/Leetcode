// https://leetcode.com/problems/mini-parser/
// Gave up...
// I think it is almost stack problem. When { is appeared, add new integers to the stack. and When it is closed, add the topest item on stack to the bottom. But I have no idea how to handle two cases,  with no [] and with one pair of [].
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
	NestedInteger deserialize(string s) {
		NestedInteger answer = NestedInteger(), temp;
		stack<NestedInteger> st;
		int n=0;
		bool minus = 0;
		for(int i=0; i<s.size(); i++) {
			if(s[i] >= '0' && s[i] <= '9') {
				n *= 10;
				n += s[i]-48;
			}
			else if(s[i] == '-') minus = 1;
			else if(s[i] == '[') {
				temp = NestedInteger();
				st.push(temp);
			}
			else if(s[i] == ']') {
				if(minus == 1) n *= -1;
				if(n!=0) st.top().setInteger(n);
				temp = st.top();
				st.pop();
				if(st.empty() == 0) st.top().add(temp);
				else st.push(temp);
				n = 0;
				minus = 0;
			}
			else if(s[i] == ',') {
				if(minus == 1) n *= -1;
				if(st.top().isInteger() == 0)
					st.top().setInteger(n);
				n = 0;
				minus = 0;
			}
			if(i==s.size()-1 && st.empty() == 1) {
				st.push(NestedInteger());
				if(minus == 1) n*=-1;
				if(n!=0) st.top().setInteger(n);
			}
		}
		return st.top();
	}
};