#include<iostream>
#include<string>
using namespace std;

int dp[1005][1005];

class Solution {
public:
	//��Ϊ��̬�滮�㷨��ʱ�临�Ӷ�O(n?)������һ��Manacher�㷨��ʱ�临�Ӷ�O(n)
	string longestPalindrome(string s) {
		int len = s.size(), head = 0, tail = 0;
		//��ʼ��dp���飬dp[i][j]������s[i,j]�Ƿ�Ϊһ�����Ĵ�
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (i == j) 
					dp[i][j] = 1;
				else 
					dp[i][j] = -1;
			}
		}
		//����i��ʾ���Ĵ��ĳ��ȣ�j��ʾ���Ĵ���1��Ԫ�ص��±�
		for (int i = 2; i <= len; i++) {
			for (int j = 0; j <= len - i; j++) {
				//�����ǰ�жϵĻ��Ĵ�������2
				if (i == 2) {
					if (s[j] == s[j + 1]) {
						dp[j][j + 1] = 1;
						head = j;
						tail = j + 1;
					}
					else 
						dp[j][j + 1] = 0;
				}
				//�����ǰ�жϵĻ��Ĵ����Ȳ���2�����ж�s[j]=s[j+i-1]��s[j+1,j+i-2]�Ƿ�Ϊ���Ĵ�
				else {
					if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2] == 1) {
						dp[j][j + i - 1] = 1;
						head = j;
						tail = j + i - 1;
					}
					else 
						dp[j][j + i - 1] = 0;
				}
			}
		}
		string result = "";
		for (int i = head; i <= tail; i++)
			result += s[i];
		return result;
	}
};