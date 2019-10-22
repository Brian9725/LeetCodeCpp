#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//left��ʾδ����str��'('������right��ʾδ����str��')'����
	void dfs(vector<string>& result, string str, int left, int right) {
		if (left == 0 && right == 0) {
			result.push_back(str);
			return;
		}
		//���ʣ���'('��')'�࣬���ʱstr�Ѿ�������Ҫ��
		if (left > right) {
			return;
		}
		//��str�м���'('
		if (left > 0) {
			dfs(result, str + '(', left - 1, right);
		}
		//��str�м���')'
		if (right > 0) {
			dfs(result, str + ')', left, right - 1);
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n <= 0) {
			return result;
		}
		dfs(result, "", n, n);
		return result;
	}
};