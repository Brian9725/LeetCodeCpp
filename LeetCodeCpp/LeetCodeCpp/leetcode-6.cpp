#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) 
			return s;
		int len = s.size(), cnt = 0;
		string result = "";
		for (int i = 0; i < numRows; i++) {
			//�����Z�ֵ�ͷ��β����ÿ��Ԫ��֮������Ԫ�ظ�����һ����
			if (i == 0 || i == numRows - 1) {
				for (int j = i; j < len; j += 2 * numRows - 2) 
					result += s[j];
				continue;
			}
			//�������Z��ͷβ����ÿ��Ԫ��֮��ļ����������֮�䲻��ת��
			int  num = 2 * i;
			for (int j = i; j < len; j += num) {
				result += s[j];
				num = 2 * numRows - 2 - num;
			}
		}
		return result;
	}
};