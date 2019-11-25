#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int lenS = s.size(), lenT = t.size();
		int cnt[256] = { 0 };
		//ͳ�Ƴ�t��ÿ���ַ�������
		for (int i = 0; i < lenT; i++) {
			cnt[t[i]]++;
		}
		int len = 0, minLength = s.size();
		string res = "";
		for (int left = 0, right = 0; right < s.size(); right++) {
			cnt[s[right]]--;
			//���cnt[s[right]]>=0��˵��s[right]��t�У�len��ʾs[left..right]�к��е�t���ַ��ĸ���
			if (cnt[s[right]] >= 0) {
				len++;
			}
			//len==lenTʱ˵��s[left..right]���Ѿ�����������t�е��ַ�������ȥ��һЩ�ַ�
			while (len == lenT) {
				if (right - left + 1 <= minLength) {
					minLength = right - left + 1;
					res = s.substr(left, right - left + 1);
				}
				cnt[s[left]]++;
				if (cnt[s[left]] > 0) {
					len--;
				}
				left++;
			}
		}
		return res;
	}
};