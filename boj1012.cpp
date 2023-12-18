#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int T; // 테스트 케이스
int M, N, K; // M은 열, N은 행, K는 배추 개수
vector<pair<int, int>> v; // 배추 위치 저장
bool arr[50][50]; // 배추 밭
bool visited[50][50]; // 방문 확인
pair<int, int> d[4] = { {1,0},{0,1}, {-1, 0}, {0,-1} };

void BFS(int R, int C);

int main()
{
	scanf("%d", &T); // 테스트 케이스 입력

	for (int tc = 1; tc <= T; tc++) {
		// 행, 열, 배추 개수 입력
		scanf("%d %d %d", &M, &N, &K);

		// 컨테이너 초기화
		v.resize(K);
		for (int i = 0; i < N; i++) {
			memset(arr[i], false, sizeof(arr[i]));
			memset(visited[i], false, sizeof(visited[i]));
		}

		// 배추 위치 입력
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &v[i].second, &v[i].first);

			arr[v[i].first][v[i].second] = true;
		}

		int larva = 0; // 애벌레 개수 저장

		// 배추밭을 방문하며 확인
		for (int i = 0; i < K; i++) {
			int R = v[i].first;
			int C = v[i].second;

			if (visited[R][C]) continue;
			else {
				BFS(R, C);
				larva++;
			}
		}

		printf("%d\n", larva);
	}

	return 0;
}

void BFS(int R, int C) // 파라미터는 배추의 좌표
{
	queue<pair<int, int> > q;
	q.push({ R, C });

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		visited[nowx][nowy] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextx = nowx + d[i].first;
			int nexty = nowy + d[i].second;

			if (nextx < 0 || N <= nextx || nexty < 0 || M <= nexty) continue;

			if (!visited[nextx][nexty] && arr[nextx][nexty]) {
				visited[nextx][nexty] = true;
				q.push({ nextx, nexty });
			}
		}
	}

}