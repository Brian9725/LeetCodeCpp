#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int flag = 1, idx = 0, result = 0;
		for (; str[idx] == ' '; idx++) {
			continue;
		}
		if (str[idx] == '-') {
			flag = 0;
		}
		else if (str[idx] == '+') {
			;
		}
		else if (str[idx] >= '0' && str[idx] <= '9') {
			result = str[idx] - 48;
		}
		else {
			return 0;
		}
		for (idx++; str[idx] >= '0' && str[idx] <= '9'; idx++) {
			if (result == 214748364) {
				if (flag) {
					if (str[idx] - 48 >= 7) {
						return 2147483647;
					}
					else {
						//�����ȼ���str[idx]-48������˳�����result*10+str[idx]���ܻ����
						return result * 10 + (str[idx] - 48);
					}
				}
				else {
					if (str[idx] - 48 > 7) {
						return -2147483648;
					}
					else {
						//�����ȼ���str[idx]-48������˳�����result*10+str[idx]���ܻ����
						return 0 - (result * 10 + (str[idx] - 48));
					}
				}
			}
			if (result > 214748364) {
				if (flag) {
					return 2147483647;
				}
				else {
					return -2147483648;
				}
			}
			result = result * 10 + str[idx] - 48;
		}
		if (!flag) {
			return 0 - result;
		}
		return result;
	}
};