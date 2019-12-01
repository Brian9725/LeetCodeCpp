#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	//将version转成数字序列
	vector<int> convert(string version) {
		int begin = 0, end = begin, len = version.size();
		vector<int> res;
		while (begin < len) {
			while (end + 1 < len && version[end + 1] != '.') {
				end++;
			}
			int num = 0;
			for (int i = begin; i <= end; ++i) {
				num = (version[i] - '0') + num * 10;
			}
			res.push_back(num);
			begin = end + 2; end = begin;
		}
		return res;
	}
	//填充0
	void insert(vector<int>& ver, int len) {
		while (len--) {
			ver.push_back(0);
		}
	}

	int compareVersion(string version1, string version2) {
		vector<int> ver1 = convert(version1), ver2 = convert(version2);
		int len1 = ver1.size(), len2 = ver2.size(), len = 0;
		if (len1 < len2) {
			insert(ver1, len2 - len1);
			len = len2;
		}
		else {
			insert(ver2, len1 - len2);
			len = len1;
		}
		for (int i = 0; i < len; ++i) {
			if (ver1[i] > ver2[i]) return 1;
			if (ver1[i] < ver2[i]) return -1;
		}
		return 0;
	}
};