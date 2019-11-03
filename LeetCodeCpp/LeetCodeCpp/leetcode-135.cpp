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
			//���ֻʣ��һ��С���ѣ��䵥����Ϊһ���ͷ�͸߷�
			if (idx == len - 1) {
				result += 1; break;
			}
			//�ҵ�һ���ϸ�����ĸ߷峤��up
			up = 1; down = 1;
			while (idx < len - 1 && ratings[idx + 1] > ratings[idx]) {
				up++; idx++;
			}
			//�ҵ�һ���ϸ�ݼ��ĵͷ峤��down
			while (idx < len - 1 && ratings[idx + 1] < ratings[idx]) {
				down++; idx++;
			}
			//����һ���ͷ��һ���߷���Ҫ���ǹ�����
			result += (up + 1)*up / 2;
			result += (down + 1)*down / 2;
			if (up > down)
				result -= down;
			else
				result -= up;
			//����Ѿ����㵽�����һ��С���ѣ���ȫ������
			if (idx == len - 1)
				break;
			if (idx < len - 1) {
				//�������Ϊһ��ƽ�£��򽫵�һ��ֵ����ǰһ���ͷ����͵㣬�ڶ���ֵ������һ���߷����͵㣬���ڲ�������͵㣬�����ȥ
				if (ratings[idx + 1] == ratings[idx])
					idx++;
				//ǰһ���ͷ����͵��ں�һ���߷�����ʱ���ټ��ϣ�������ǰ��ȥ
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
		//res[i]��ʾ��i��С�����õ����ǹ�����
		int result = 0, *res = new int[len];
		//���һ��С���ѷ���������ߵĸߣ��͸��������С���Ѷ�һ�����ǹ������������һ��
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				res[i] = 1; continue;
			}
			if (ratings[i] > ratings[i - 1])
				res[i] = res[i - 1] + 1;
			else
				res[i] = 1;
		}
		//��ʱres�д洢���Ǵ����������������ǹ�����
		//���������ƴ��ҵ������res��ֵ��ÿ��ѡȡ���������Ҫ���ֵ�ʹ��ҵ���Ҫ���ֵ�нϴ���Ǹ�����
		for (int i = len - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				res[i] = max(res[i], res[i + 1] + 1);
		}
		//�������С���ѵ��ǹ��������
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