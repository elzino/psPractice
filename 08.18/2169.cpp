#include <iostream>

using namespace std;


int arr[1001][1001];
int dp[1001][1001];

//내 풀이 -> n*m^2 -> 시간 초과
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin>>arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	for (int j = 2; j <= m; j++) {
		dp[1][j] = dp[1][j - 1] + arr[1][j];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int max = 0;
			for (int k = 1; k <= m; k++) {
				int temp = k - j;
				int sum = dp[i - 1][k];
				while (temp !=0) {
					sum += arr[i][temp+j];
					if (temp > 0) {
						temp--;
					}
					else {
						temp++;
					}
				}
				sum += arr[i][j];
				if (max < sum) {
					max = sum;
				}
			}
			dp[i][j] = max;
		}
	}
	cout << dp[n][m];
}


// n*m 풀이 -> 시간초과 안걸림

/*
#include <stdio.h>
int map[1000][1000];
int primap[1000][1000];

int Max(int a, int b)
{
return a > b ? a : b;
}

int main(void){

int N, M;

int line[2][1000];

int total = 0;

scanf("%d %d", &N, &M);
// 입력
for (int i = 0; i < N; i++)
for (int j = 0; j < M; j++)
scanf("%d", &map[i][j]);

primap[0][0] = map[0][0];
for (int i = 1; i < M; i++)
{
primap[0][i] = primap[0][i - 1] + map[0][i];
}

for (int height = 1; height < N; height++)
{
// 한번 저장
for (int row = 0; row < M; row++)
line[0][row] = line[1][row] = primap[height - 1][row] + map[height][row];

for (int row = 1; row < M; row++)
line[0][row] = Max(line[0][row], line[0][row-1]+map[height][row]);

for (int row = M-2; row >= 0; row--)
line[1][row] = Max(line[1][row], line[1][row + 1] + map[height][row]);

for (int row = 0; row < M; row++)
primap[height][row] = Max(line[0][row], line[1][row]);

}

printf("%d\n", primap[N - 1][M - 1]);

return 0;
}


출처: http://wootool.tistory.com/32 [우투리와툴툴]
*/