#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		//flag��ʶ����
		int flag = 1, idx = 0, result = 0, tmpMax = INT_MAX / 10;
		for (; str[idx] == ' '; idx++)
			continue;
		if (str[idx] == '-')
			flag = 0;
		else if (str[idx] == '+')
			flag = 1;
		else if (str[idx] >= '0' && str[idx] <= '9') 
			result = str[idx] - 48;
		else 
			return 0;
		for (idx++; str[idx] >= '0' && str[idx] <= '9'; idx++) {
			if (result == tmpMax) {
				if (flag) {
					if (str[idx] - 48 >= 7)
						return INT_MAX;
					else 
						//�����ȼ���str[idx]-48������˳�����result*10+str[idx]���ܻ����
						return result * 10 + (str[idx] - 48);
				}
				else {
					if (str[idx] - 48 > 7) 
						return INT_MIN;
					else 
						//�����ȼ���str[idx]-48������˳�����result*10+str[idx]���ܻ����
						return 0 - (result * 10 + (str[idx] - 48));
				}
			}
			if (result > tmpMax) {
				if (flag) 
					return INT_MAX;
				else 
					return INT_MIN;
			}
			result = result * 10 + str[idx] - 48;
		}
		if (!flag) 
			return 0 - result;
		return result;
	}
};