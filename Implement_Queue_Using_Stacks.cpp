// https://leetcode.com/problems/implement-queue-using-stacks/discuss/?currentPage=1&orderBy=hot&query=
// 스텍 두 개에 옮겨담는다.
// time: O(n) space: O(n)
// Runtime: 4 ms, faster than 55.39% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Implement Queue using Stacks.
class MyQueue {
public:
    /** Initialize your data structure here. */
	stack<int> q, t;
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
	void push(int x) {
		while(q.empty() == 0) {
			t.push(q.top());
			q.pop();
		}
		q.push(x);
		while(t.empty() == 0) {
			q.push(t.top());
		t.pop();
		}
	}
    
    /** Removes the element from in front of queue and returns that element. */
	int pop() {
		int x = q.top();;
		q.pop();
		return x;
	}
    
    /** Get the front element. */
    int peek() {
		return q.top();
	}
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */