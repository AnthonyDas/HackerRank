#include <stack>

class MyQueue {
	std::stack<int> newest_on_top, oldest_on_top;

public:

	// push_back
	void push(int x) {
		newest_on_top.push(x);
	}

	// pop_front
	void pop() {
		if (oldest_on_top.empty()) {
			while (!newest_on_top.empty()) {
				oldest_on_top.push(newest_on_top.top());
				newest_on_top.pop();
			}
		}
		if (!oldest_on_top.empty()) {
			oldest_on_top.pop();
		}
	}

	// front
	int front() {
		if (oldest_on_top.empty()) {
			while (!newest_on_top.empty()) {
				oldest_on_top.push(newest_on_top.top());
				newest_on_top.pop();
			}
		}
		return oldest_on_top.empty() ? 0 : oldest_on_top.top();
	}
};