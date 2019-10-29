#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		int len = path.size();
		stack<string> resStack;
		for (int i = 1; i < len; i++) {
			if (path[i] == '/')
				continue;
			if (path[i] == '.') {
				//如果表示的是当前目录
				if (i == len - 1 || (i < len - 1 && path[i + 1] == '/'))
					continue;
				//如果是要返回上一级目录
				if (path[i + 1] == '.') {
					if (i + 1 == len - 1 || (i + 1 < len - 1 && path[i + 2] == '/')) {
						if (!resStack.empty())
							resStack.pop();
						i++;
						continue;
					}
				}
			}
			string tempPath = "";
			int j = 0;
			for (j = i; j < len; j++) {
				if (path[j] != '/')
					tempPath += path[j];
				else
					break;
			}
			resStack.push(tempPath);
			i += j - i - 1;
		}
		string result = "";
		if (!resStack.empty()) {
			result = resStack.top();
			resStack.pop();
		}
		while (!resStack.empty()) {
			result = resStack.top().append("/").append(result);
			resStack.pop();
		}
		result = "/" + result;
		return result;
	}
};