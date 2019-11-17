#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int op(int a, int b, char ch) {
		if (ch == '+')
			return a + b;
		else if (ch == '-')
			return a - b;
		else if (ch == '*')
			return a * b;
		else if (ch == '/')
			return a / b;
		else
			return 0;
	}

	int evalRPN(vector<string>& tokens) {
		int len = tokens.size();
		stack<int> numSt;
		for (int i = 0; i < len; i++) {
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
				int num1 = numSt.top(); numSt.pop();
				int num2 = numSt.top(); numSt.pop();
				char chOp = tokens[i][0];
				numSt.push(op(num2, num1, chOp));
				continue;
			}
			numSt.push(atoi(tokens[i].c_str()));
		}
		return numSt.top();
	}
};