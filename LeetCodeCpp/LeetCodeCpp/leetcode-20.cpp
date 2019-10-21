#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> myStack;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (myStack.empty()) {
				myStack.push(s[i]);
				continue;
			}
			char tempVal = myStack.top();
			if ((tempVal == '(' && s[i] == ')') || (tempVal == '[' && s[i] == ']') || (tempVal == '{' && s[i] == '}')) {
				myStack.pop();
				continue;
			}
			myStack.push(s[i]);
		}
		return myStack.empty() ? true : false;
	}
};