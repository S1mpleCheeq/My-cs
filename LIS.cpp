//��֪n�����ų�һ�ţ�֪��������ߣ������ٳ��߼����ˣ������Ǵ���i��ߵ�����i������ߵݼ�

#include<iostream>
#include<vector>

using namespace std;

int Findth(vector<int> low, int R, int x) {
	int L = 1;
	int res = 0;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (low[mid] >= x) {
			res = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}
	return res;
}

vector<int> LIS(vector<int> nums) {
	int n = nums. size();
	vector<int> low(n + 1, 0);
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	int ans = 1;
	low[1] = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > low[ans]) 
			low[++ans] = nums[i];
		else low[Findth(low, ans, nums[i])] = nums[i];
		dp[i+1] = ans;
	}
	return dp;
}


int main() {
	int n;
	cin >> n;
	vector<int> height(n);
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	vector<int> LLIS = LIS(height);
	reverse(height.begin(), height.end());
	vector<int> RLIS = LIS(height);
	int m = 0;
	for (int i = 1; i < n; i++) {
		m = max(LLIS[i] + RLIS[n - i + 1], m);
	}
	m--;
	int result = n - m;
	cout << result;
	return 0;
}
