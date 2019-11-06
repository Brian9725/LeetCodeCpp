#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string result = "1", temp = "";
		if (n == 1) 
			return result;
		for (int i = 2; i <= n; i++) {
			temp = "";
			int len = result.size(), cnt = 1, idx = 0;
			if (len == 1) {
				result = "1" + result;
				continue;
			}
			for (int j = 1; j < len; j++) {
				if (result[j] == result[j - 1]) 
					cnt++;
				else {
					temp += to_string(cnt);
					temp += result[idx];
					cnt = 1; idx = j;
				}
				if (j == len - 1) {
					temp += to_string(cnt);
					temp += result[idx];
				}
			}
			result = temp;
		}
		return result;
	}
};