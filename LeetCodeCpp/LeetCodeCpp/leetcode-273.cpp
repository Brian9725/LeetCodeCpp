#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	//��λ��Ӣ�ı�
	vector<string> numOneWord = { "Zero" ,"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	//ʮ����Ӣ�ı�
	vector<string> numTenWord = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	//��ʮ��Ӣ�ı�
	vector<string> numTensWord = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

	//��1000���ڵ���ת��Ӣ�ı�ʾ��0Ϊ""
	string numToWords(int num) {
		int one = num % 10;
		int ten = (num % 100) / 10;
		int hundred = num / 100;
		string result = "";
		if (hundred != 0) {
			result += numOneWord[hundred] + " Hundred ";
		}
		if (ten != 0) {
			if (ten == 1) {
				result += numTenWord[one] + " ";
				result = result.substr(0, result.size() - 1);
				return result;
			}
			result += numTensWord[ten] + " ";
		}
		if (one != 0) {
			result += numOneWord[one] + " ";
		}
		result = result.substr(0, result.size() - 1);
		return result;
	}

	string numberToWords(int num) {
		if (num == 0)
			return numOneWord[0];
		vector<string> unit = {"", "Thousand", "Million", "Billion" };
		string result = ""; int curUnit = 0;
		while (num) {
			int temp = num % 1000;
			if (temp != 0)
				result = numToWords(temp) + " " + unit[curUnit] + " " + result;
			curUnit++; num /= 1000;
		}
		while (result[result.size() - 1] == ' ')
			result = result.substr(0, result.size() - 1);
		return result;
	}
};