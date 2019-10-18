#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int heightSize = height.size();
		int max = 0, i = 0, j = heightSize - 1, v = 0;
		while (i < j) {
			//舍去搞得柱子必然导致v变小，每次都舍去矮的柱子才有可能让v增大
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