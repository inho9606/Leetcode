class MovingAverage {
public:
    /** Initialize your data structure here. */
	queue<int> window;
	int n, sum=0, s=0;
	MovingAverage(int size) {
		n = size;
	}
    
	double next(int val) {
		if(s<n) s+=1;
		else {
			sum -= window.front();
			window.pop();
		}
		window.push(val);
		sum += val;
		return (double)sum/s;
	}
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */