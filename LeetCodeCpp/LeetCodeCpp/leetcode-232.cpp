#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
	//left用于弹出，right用于压入
	stack<int> left;
	stack<int> right;

	/** Initialize your data structure here. */
	MyQueue() {
		left = stack<int>();
		right = stack<int>();
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		while (!left.empty()) {
			right.push(left.top());
			left.pop();
		}
		right.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		while (!right.empty()) {
			left.push(right.top());
			right.pop();
		}
		int res = left.top(); left.pop();
		return res;
	}

	/** Get the front element. */
	int peek() {
		while (!right.empty()) {
			left.push(right.top());
			right.pop();
		}
		return left.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return left.empty() && right.empty();
	}
};