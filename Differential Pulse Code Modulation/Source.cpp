#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

int c[16];
int x[20001];
int dp[256][20001];

int main() {
	int n, m;
	while (std::cin >> n >> m && (n || m)) {
		std::memset(dp, 0xff, sizeof(dp));
		for (int i = 0; i < m; i++) std::cin >> c[i];
		for (int i = 0; i < n; i++) std::cin >> x[i + 1];

		dp[128][0] = 0;
		for (int i = 1; i <= n; i++) { //��O���珈������
			for (int j = 0; j < 256; j++) { //�O���0~255�S�Ă̌��ʁB
				if (dp[j][i - 1] < 0) continue; //���肦�Ȃ��l
				for (int k = 0; k < m; k++) { //�S�ẴR�[�h�u�b�N�ɂ��Ē��ׂ�
					int ny = j + c[k];
					if (ny < 0) ny = 0;
					else if (ny > 255) ny = 255;

					int v = (x[i] - ny) * (x[i] - ny);
					if (dp[ny][i] < 0) dp[ny][i] = dp[j][i - 1] + v;
					else {
						dp[ny][i] = std::min(dp[j][i - 1] + v, dp[ny][i]);
					}
				}
			}
		}
		int min = INT_MAX;
		for (int i = 0; i < 256; i++) if (dp[i][n] >= 0) min = std::min(dp[i][n], min);
		std::cout << min << std::endl;
	}

	return 0;
}