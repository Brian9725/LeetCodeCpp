#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//判断s是否表示1-255的整数，外部保证s的size为1-3
	bool isValid(string s) {
		//idx表示第1个不为'0'的下标
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
		//numAddr表示已经使用的字符个数
		int len = s.size(), numAddr = 0;
		vector<string> result;
		for (int addr1 = 1; addr1 <= 3; addr1++) {
			numAddr = addr1;
			//如果剩下的字符大于9个，是不可能将其设为IP地址的后3位的
			if (len - numAddr > 9)
				continue;
			//如果剩下的字符小于3个，已经不可能将其设为IP地址
			if (len - numAddr < 3)
				break;
			//判断s[0..addr1-1]是否符合要求
			if (!isValid(s.substr(0, addr1)))
				continue;
			for (int addr2 = 1; addr2 <= 3; addr2++) {
				numAddr = addr1 + addr2;
				//如果剩下的字符大于6个，是不可能将其设为IP地址的后2位的
				if (len - numAddr > 6)
					continue;
				//如果剩下的字符小于2个，已经不可能将其设为IP地址
				if (len - numAddr < 2)
					break;
				//判断s[addr1..addr2-1]是否符合要求
				if (!isValid(s.substr(addr1, addr2)))
					continue;
				for (int addr3 = 1; addr3 <= 3; addr3++) {
					numAddr = addr1 + addr2 + addr3;
					//如果剩下的字符大于3个，是不可能将其设为IP地址的最后1位的
					if (len - numAddr > 3)
						continue;
					//如果剩下的字符小于1个，已经不可能将其设为IP地址
					if (len - numAddr < 1)
						break;
					//判断s[addr1+addr2..addr3-1]是否符合要求
					if (!isValid(s.substr(addr1 + addr2, addr3)))
						continue;
					//判断s[addr1+addr2+addr3..len-1]是否符合要求
					if (!isValid(s.substr(addr1 + addr2 + addr3)))
						continue;
					//此时addr1、addr2和addr3已经将s分成4个可以构成IP地址的部分
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