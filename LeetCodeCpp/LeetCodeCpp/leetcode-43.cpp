#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.size(), len2 = num2.size();
		//����һ��len1+len2���ȵ�int������
		int *tempResult = new int[len1 + len2];
		for (int i = 0; i < len1 + len2; i++) {
			tempResult[i] = 0;
		}
		for (int i = len1 - 1; i >= 0; i--) {
			for (int j = len2 - 1; j >= 0; j--) {
				//����ɼ�leetcode���
				int temp1 = num1[i] - 48, temp2 = num2[j] - 48;
				int mulNum = temp1*temp2;
				tempResult[i + j + 1] += mulNum % 10;
				tempResult[i + j] += mulNum / 10;
			}
		}
		//�����λ
		for (int i = len1 + len2 - 2; i > 0; i--) {
			if (tempResult[i] > 9) {
				tempResult[i - 1] += tempResult[i] / 10;
				tempResult[i] %= 10;
			}
		}
		//idxΪtempResult�е�һ����Ϊ0�������±꣬Ĭ��Ϊ���һλ��Ӧ��tempResultȫΪ0�����
		int idx = len1 + len2 - 1;
		for (int i = 0; i < len1 + len2; i++) {
			if (tempResult[i] != 0) {
				idx = i;
				break;
			}
		}
		string result = "";
		for (int i = idx; i < len1 + len2; i++) {
			result += tempResult[i] + 48;
		}
		return result;
	}
};