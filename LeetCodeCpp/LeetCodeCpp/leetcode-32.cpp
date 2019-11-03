#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> myStack;
		//��-1ѹջ���ڼ��㳤��
		myStack.push(-1);
		int result = 0, len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') 
				myStack.push(i);
			else {
				myStack.pop();
				//�����ʱջΪ�գ��൱�ڰ�-1��������ʱ�ɵ�ǰ��")"����-1
				if (myStack.empty()) 
					myStack.push(i);
				else 
					result = max(result, i - myStack.top());
			}
		}
		return result;
	}

	/*��̬�滮
		int longestValidParentheses(string s) {
		int result = 0, len = s.size();
		int* dp = new int[len];
		for (int i = 0; i < len; i++)
			dp[i] = 0;
		for (int i = 1; i < len; i++) {
			if (s[i] == ')') {
				//�������"...()"����ôdp[i]=dp[i-2]+2
				if (s[i - 1] == '(')
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				//�������"((...))����ôdp[i]=dp[i-1]+2
				else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
				result = max(result, dp[i]);
			}
		}
		return result;
	}
	*/
};