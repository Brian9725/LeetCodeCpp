#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int len = ratings.size();
		if (len == 0)
			return 0;
		int result = 0, up = 1, down = 1, idx = 0;
		while (idx < len) {
			//如果只剩下一个小朋友，其单独成为一个低峰和高峰
			if (idx == len - 1) {
				result += 1; break;
			}
			//找到一个严格递增的高峰长度up
			up = 1; down = 1;
			while (idx < len - 1 && ratings[idx + 1] > ratings[idx]) {
				up++; idx++;
			}
			//找到一个严格递减的低峰长度down
			while (idx < len - 1 && ratings[idx + 1] < ratings[idx]) {
				down++; idx++;
			}
			//计算一个低峰和一个高峰需要的糖果数量
			result += (up + 1)*up / 2;
			result += (down + 1)*down / 2;
			if (up > down)
				result -= down;
			else
				result -= up;
			//如果已经计算到了最后一个小朋友，则全部结束
			if (idx == len - 1)
				break;
			if (idx < len - 1) {
				//如果是因为一个平坡，则将第一个值算作前一个低峰的最低点，第二个值算作后一个高峰的最低点，由于不共用最低点，不需减去
				if (ratings[idx + 1] == ratings[idx])
					idx++;
				//前一个低峰的最低点在后一个高峰间计算时会再加上，所以提前减去
				else
					result -= 1;
			}
		}
		return result;
	}

	/*
	int candy(vector<int>& ratings) {
		int len = ratings.size();
		if (len == 0)
			return 0;
		//res[i]表示第i个小朋友拿到的糖果数量
		int result = 0, *res = new int[len];
		//如果一个小朋友分数比他左边的高，就给他比左边小朋友多一个的糖果数量，否则给一个
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				res[i] = 1; continue;
			}
			if (ratings[i] > ratings[i - 1])
				res[i] = res[i - 1] + 1;
			else
				res[i] = 1;
		}
		//此时res中存储的是从左到右满足条件的糖果数量
		//比上述类似从右到左更新res的值，每次选取满足从左到右要求的值和从右到左要求的值中较大的那个即可
		for (int i = len - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				res[i] = max(res[i], res[i + 1] + 1);
		}
		//最后将所有小朋友的糖果数量相加
		for (int i = 0; i < len; i++)
			result += res[i];
		return result;
	}
	*/
};

int main() {
	vector<int> res;
	res.push_back(1);
	res.push_back(2);
	res.push_back(2);
	cout << Solution().candy(res);
	return 0;
}