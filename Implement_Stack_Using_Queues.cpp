// https://leetcode.com/problems/implement-stack-using-queues/submissions/
// �� ���� queue�� ����� push�� ������ a�� �ֶ� ������  b�� �ű�� a�� ä�� ����, b���� a�� �������� �ű��.
// time: O(n) n is the size of the stack. space: O(2n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
// Memory Usage: 8.8 MB, less than 80.00% of C++ online submissions for Implement Stack using Queues.

class MyStack {
public:
	/** Initialize your data structure here. */
	queue<int> st, q;
	MyStack() {
	}
    
    /** Push element x onto stack. */
	void push(int x) {
		while(st.empty() == 0) {
			q.push(st.front());
			st.pop();
		}
		st.push(x);
		while(q.empty() == 0) {
			st.push(q.front());
			q.pop();
		}
	}
    
    /** Removes the element on top of the stack and returns that element. */
	int pop() {
		int x = st.front();
		st.pop();
		return x;
	}
    
    /** Get the top element. */
	int top() {
		return st.front();
	}
    
    /** Returns whether the stack is empty. */
	bool empty() {
		return st.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */