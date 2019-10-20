#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string letter[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	//num��¼letter��ÿ���ַ����ĳ���
	int num[8] = { 3,3,3,3,3,4,3,4 };

	void dfs(string digits, vector<string>& results, string& result, int i, int len) {
		if (i == len) {
			results.push_back(result);
			return;
		}
		//digits[i]-50��Ӧdigits[i]����ʾ���ֶ�Ӧ�ַ�����letter�е��±�
		//���磺digital[i]='2'��digits[i]-50=0����Ӧletter[0]="abc"
		for (int idx = 0; idx < num[digits[i] - 50]; idx++) {
			result += letter[digits[i] - 50][idx];
			dfs(digits, results, result, i + 1, len);
			result.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> results;
		int len = digits.size();
		if (len == 0) {
			return results;
		}
		string result = "";
		dfs(digits, results, result, 0, len);
		return results;
	}
};