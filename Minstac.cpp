// https://leetcode.com/problems/min-stack/submissions/
// time: O(n) space: O(n)
// 최소값을 관리하는 m 스텍은 현재 값보다 작은 것만 저장한다. 현재 저장되어 있는 값보다 큰 것은 신경 쓸 필요가 없음. getmin은 작은 것만 출력하면 되고 최소값 이후에 들어온 큰 값은 스텍 구조 상 먼저 빠져나갈거라서..
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