#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	//��������������ȼ���������������������ŵ����ȼ���#��ǽ�����
	int prior(char a, char b) {
		//+�����ȼ�С��*��/��(
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
		//���Ϸ���һЩ���
		if ((a == ')' && b == '(') || (a == '(' && b == '#') || (a == '#' && b == ')'))
			return -2;
		//����Ҫ���������
		if (a == '(' && b == ')')
			return 0;
		//������ɱ�ʶ
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
		//����else��leetcode����
		else
			return 0;
	}

	//ͬleetcode-224
	int calculate(string s) {
		s += "#";
		stack<char> opStack; stack<int> numStack;
		int len = s.size(), idx = 0, num = 0, tempIdx = idx;
		opStack.push('#');
		while (idx < len) {
			//�����������#����������������Ѿ�����
			if (prior(opStack.top(), s[idx]) == 10) break;
			num = 0; tempIdx = idx;
			while (s[idx] >= '0' && s[idx] <= '9') {
				num = num * 10 + (s[idx] - '0'); idx++;
			}
			//���tempIdx!=idx���������������һ������
			if (tempIdx != idx) {
				numStack.push(num);
				continue;
			}
			//�������������һ������������ж�����opStackջ��Ԫ�ص����ȼ�
			switch (prior(opStack.top(), s[idx])) {
				//�����ǰ����������ȼ��ߣ�������ջ
			case -1:
				opStack.push(s[idx]); idx++; break;
				//������������˵�������е��Ѿ�������ɣ����������ż���
			case 0:
				opStack.pop(); idx++; break;
				//���ջ����������ȼ��ߣ����������������������numStack
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