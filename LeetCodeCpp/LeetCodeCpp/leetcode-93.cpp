#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//�ж�s�Ƿ��ʾ1-255���������ⲿ��֤s��sizeΪ1-3
	bool isValid(string s) {
		//idx��ʾ��1����Ϊ'0'���±�
		int len = s.size(), idx = 0, sum = 0;
		if (len == 1 && s[0] == '0')
			return true;
		for (int i = 0; i < len; i++) {
			if (s[i] != '0') {
				idx = i; break;
			}
		}
		if (idx != 0)
			return false;
		for (int i = 0; i < len; i++) {
			sum = sum * 10 + s[i] - '0';
		}
		if (sum >= 1 && sum <= 255)
			return true;
		return false;
	}

	vector<string> restoreIpAddresses(string s) {
		//numAddr��ʾ�Ѿ�ʹ�õ��ַ�����
		int len = s.size(), numAddr = 0;
		vector<string> result;
		for (int addr1 = 1; addr1 <= 3; addr1++) {
			numAddr = addr1;
			//���ʣ�µ��ַ�����9�����ǲ����ܽ�����ΪIP��ַ�ĺ�3λ��
			if (len - numAddr > 9)
				continue;
			//���ʣ�µ��ַ�С��3�����Ѿ������ܽ�����ΪIP��ַ
			if (len - numAddr < 3)
				break;
			//�ж�s[0..addr1-1]�Ƿ����Ҫ��
			if (!isValid(s.substr(0, addr1)))
				continue;
			for (int addr2 = 1; addr2 <= 3; addr2++) {
				numAddr = addr1 + addr2;
				//���ʣ�µ��ַ�����6�����ǲ����ܽ�����ΪIP��ַ�ĺ�2λ��
				if (len - numAddr > 6)
					continue;
				//���ʣ�µ��ַ�С��2�����Ѿ������ܽ�����ΪIP��ַ
				if (len - numAddr < 2)
					break;
				//�ж�s[addr1..addr2-1]�Ƿ����Ҫ��
				if (!isValid(s.substr(addr1, addr2)))
					continue;
				for (int addr3 = 1; addr3 <= 3; addr3++) {
					numAddr = addr1 + addr2 + addr3;
					//���ʣ�µ��ַ�����3�����ǲ����ܽ�����ΪIP��ַ�����1λ��
					if (len - numAddr > 3)
						continue;
					//���ʣ�µ��ַ�С��1�����Ѿ������ܽ�����ΪIP��ַ
					if (len - numAddr < 1)
						break;
					//�ж�s[addr1+addr2..addr3-1]�Ƿ����Ҫ��
					if (!isValid(s.substr(addr1 + addr2, addr3)))
						continue;
					//�ж�s[addr1+addr2+addr3..len-1]�Ƿ����Ҫ��
					if (!isValid(s.substr(addr1 + addr2 + addr3)))
						continue;
					//��ʱaddr1��addr2��addr3�Ѿ���s�ֳ�4�����Թ���IP��ַ�Ĳ���
					string tempRes = "";
					tempRes += s.substr(0, addr1); tempRes += ".";
					tempRes += s.substr(addr1, addr2); tempRes += ".";
					tempRes += s.substr(addr1 + addr2, addr3); tempRes += ".";
					tempRes += s.substr(addr1 + addr2 + addr3);
					result.push_back(tempRes);
				}
			}
		}
		return result;
	}
};