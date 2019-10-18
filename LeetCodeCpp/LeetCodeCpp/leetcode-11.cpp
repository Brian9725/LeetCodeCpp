#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int heightSize = height.size();
		int max = 0, i = 0, j = heightSize - 1, v = 0;
		while (i < j) {
			//��ȥ������ӱ�Ȼ����v��С��ÿ�ζ���ȥ�������Ӳ��п�����v����
			if (height[i] < height[j]) {
				v = height[i] * (j - i);
				i++;
			}
			else {
				v = height[j] * (j - i);
				j--;
			}
			if (max < v)
				max = v;
		}
		return max;
	}
};