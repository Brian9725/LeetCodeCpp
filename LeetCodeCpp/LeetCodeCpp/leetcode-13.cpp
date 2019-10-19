#include<string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int sum = 0, num[100], len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == 'I')
				num[i] = 1;
			else if (s[i] == 'V')
				num[i] = 5;
			else if (s[i] == 'X')
				num[i] = 10;
			else if (s[i] == 'L')
				num[i] = 50;
			else if (s[i] == 'C')
				num[i] = 100;
			else if (s[i] == 'D')
				num[i] = 500;
			else if (s[i] == 'M')
				num[i] = 1000;
		}
		for (int i = len - 1; i >= 0; i--) {
			if (i == len - 1) {
				sum += num[i];
				continue;
			}
			if (num[i] < num[i + 1])
				sum -= num[i];
			else
				sum += num[i];
		}
		return sum;
	}
};