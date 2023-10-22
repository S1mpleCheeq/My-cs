// -6 有趣的数学题
// 考虑在下面被显示的数字金字塔。 写一个程序来计算从最高点开始在底部任意处结束的路径经过的数字和最大。每一步可以走左下方的点也可以走右下方的点。（只能走这两个点）。

//     7
//    3 8
//   8 1 0
//  2 7 4 4
// 4 5 2 6 5
// 在上面的样例中，从7到3到8到7到5的路径产生了最大和30。

// 输入格式:
// 第一行包含R(1<=R<=100)，表示金字塔的行数。

// 后面R行为这个金字塔特定行包含的整数，每个数字之间有一个空格分隔。

// 所有的整数均为非负且不大于500。

// 输出格式:
// 只有一个整数代表最大和。

// 输入样例:
// 5
// 7
// 3 8
// 8 1 0
// 2 7 4 4
// 4 5 2 6 5
// 输出样例:
// 30

cscscscscscs
#include <bits/stdc++.h>
using namespace std;
int ta[100][100];
int dp[100][100];
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for( int i = 0; i < n; i++){
        for( int j = 0; j <= i; j++){
            cin >> ta[i][j];
        }
    }
    for( int i = 0; i < n; i++){
        dp[n-1][i] = ta[n-1][i];
    }

    for( int i = n-2; i >= 0; i--){
        for( int j = i; j >= 0; j--){
            dp[i][j] = max( dp[i+1][j], dp[i+1][j+1] ) + ta[i][j];
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
/*int main() {
	int N;
	cin >> N;
	vector<vector<int>> Ta(N,vector<int>(N));
	vector<vector<int>> dp(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> Ta[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (i == 0 && j == 0)	dp[0][0] = Ta[0][0];
			else if (j == 0 && i != 0) dp[i][j] = dp[i - 1][j] + Ta[i][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + Ta[i][j];
		}
	}
	int mx = 0;
	mx = *max_element(dp[N-1].begin(), dp[N-1].end());
	cout << mx;
	return 0;
}

*/