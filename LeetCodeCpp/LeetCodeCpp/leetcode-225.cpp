#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
	queue<int> left;
	queue<int> right;

	/** Initialize your data structure here. */
	MyStack() {
		left = queue<int>();
		right = queue<int>();
	}

	/** Push element x onto stack. */
	void push(int x) {
		if (!left.empty())
			left.push(x);
		else
			right.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		while (left.size() > 1) {
			right.push(left.front());
			left.pop();
		}
		if (!left.empty()) {
			int res = left.front(); left.pop();
			return res;
		}
		while (right.size() > 1) {
			left.push(right.front());
			right.pop();
		}
		if (!right.empty()) {
			int res = right.front(); right.pop();
			return res;
		}
		return -1;
	}

	/** Get the top element. */
	int top() {
		while (left.size() > 1) {
			right.push(left.front());
			left.pop();
		}
		if (!left.empty()) {
			right.push(left.front());
			int res = left.front(); left.pop();
			return res;
		}
		while (right.size() > 1) {
			left.push(right.front());
			right.pop();
		}
		if (!right.empty()) {
			left.push(right.front());
			int res = right.front(); right.pop();
			return res;
		}
		return -1;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return left.empty() && right.empty();
	}
};
