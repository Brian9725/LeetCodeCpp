#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> myStack;
		//将-1压栈便于计算长度
		myStack.push(-1);
		int result = 0, len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') 
				myStack.push(i);
			else {
				myStack.pop();
				//如果此时栈为空，相当于把-1弹出，此时由当前的")"代替-1
				if (myStack.empty()) 
					myStack.push(i);
				else 
					result = max(result, i - myStack.top());
			}
		}
		return result;
	}

	/*动态规划
		int longestValidParentheses(string s) {
		int result = 0, len = s.size();
		int* dp = new int[len];
		for (int i = 0; i < len; i++)
			dp[i] = 0;
		for (int i = 1; i < len; i++) {
			if (s[i] == ')') {
				//如果遇到"...()"，那么dp[i]=dp[i-2]+2
				if (s[i - 1] == '(')
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				//如果遇到"((...))，那么dp[i]=dp[i-1]+2
				else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
				result = max(result, dp[i]);
			}
		}
		return result;
	}
	*/
};