#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	//定义运算符的优先级，这里有四则运算和括号的优先级，#标记结束符
	int prior(char a, char b) {
		//+的优先级小于*、/和(
		if ((a == '+' && b == '*') || (a == '+' && b == '/') || (a == '+' && b == '('))
			return -1;
		if ((a == '-' && b == '*') || (a == '-' && b == '/') || (a == '-' && b == '('))
			return -1;
		if ((a == '*' && b == '('))
			return -1;
		if ((a == '/' && b == '('))
			return -1;
		if ((a == '(' && b == '+') || (a == '(' && b == '-') || (a == '(' && b == '*') || (a == '(' && b == '/') || (a == '(' && b == '('))
			return -1;
		if ((a == '#' && b == '+') || (a == '#' && b == '-') || (a == '#' && b == '*') || (a == '#' && b == '/') || (a == '#' && b == '('))
			return -1;
		//不合法的一些情况
		if ((a == ')' && b == '(') || (a == '(' && b == '#') || (a == '#' && b == ')'))
			return -2;
		//不需要操作的情况
		if (a == '(' && b == ')')
			return 0;
		//计算完成标识
		if (a == '#' && b == '#')
			return 10;
		return 1;
	}

	int operate(int a, char oper, int b) {
		if (oper == '+')
			return a + b;
		else if (oper == '-')
			return a - b;
		else if (oper == '*')
			return a * b;
		else if (oper == '/')
			return a / b;
		//不加else，leetcode报错
		else
			return 0;
	}

	//同leetcode-224
	int calculate(string s) {
		s += "#";
		stack<char> opStack; stack<int> numStack;
		int len = s.size(), idx = 0, num = 0, tempIdx = idx;
		opStack.push('#');
		while (idx < len) {
			//如果遇到两个#，则表明所有运算已经结束
			if (prior(opStack.top(), s[idx]) == 10) break;
			num = 0; tempIdx = idx;
			while (s[idx] >= '0' && s[idx] <= '9') {
				num = num * 10 + (s[idx] - '0'); idx++;
			}
			//如果tempIdx!=idx，则表明遇到的是一个数字
			if (tempIdx != idx) {
				numStack.push(num);
				continue;
			}
			//如果不是数字则一定的运算符，判读其与opStack栈顶元素的优先级
			switch (prior(opStack.top(), s[idx])) {
				//如果当前的运算符优先级高，将其入栈
			case -1:
				opStack.push(s[idx]); idx++; break;
				//遇到左右括号说明括号中的已经计算完成，弹出左括号即可
			case 0:
				opStack.pop(); idx++; break;
				//如果栈顶运算符优先级高，将其计算出来并将结果存入numStack
			case 1:
				char oper = opStack.top(); opStack.pop();
				int num2 = numStack.top(); numStack.pop();
				int num1 = numStack.top(); numStack.pop();
				numStack.push(operate(num1, oper, num2));
				break;
			}
		}
		return numStack.top();
	}
};