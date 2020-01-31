// https://leetcode.com/problems/min-stack/submissions/
// time: O(n) space: O(n)
// �ּҰ��� �����ϴ� m ������ ���� ������ ���� �͸� �����Ѵ�. ���� ����Ǿ� �ִ� ������ ū ���� �Ű� �� �ʿ䰡 ����. getmin�� ���� �͸� ����ϸ� �ǰ� �ּҰ� ���Ŀ� ���� ū ���� ���� ���� �� ���� ���������Ŷ�..
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> st, m;
	MinStack() {
	}
	void push(int x) {
		st.push(x);
		if(m.empty() == 1 || m.top() >= x) m.push(x);
	}
	void pop() {
		if(m.empty() == 0 && m.top() == st.top()) m.pop();
		st.pop();
	}
	int top() {
		return st.top();
	}
	int getMin() {
		return m.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */