#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int N;
int arr[100][100];
vector<pair<int, int> > v; // 섬의 위치 저장
int area[100][100]; // 각 섬에 번호 저장
pair<int, int> d[4] = { {0,1}, {-1,0},{0,-1}, {1,0} };
bool visited[100][100];

void BFS(int, int, int);
int find();

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);

			if (arr[i][j]) v.push_back({ i,j });
		}
	}

	for (int i = 0; i < 100; i++) memset(visited[i], false, sizeof(visited[i]));

	int island = 1; // 섬의 번호

	for (int i = 0; i < v.size(); i++) {
		if (area[v[i].first][v[i].second] > 0) continue;

		BFS(v[i].first, v[i].second, island);
		island++;
	}

	int answer = find();

	printf("%d", answer);

	return 0;
}

// 이차원 벡터에 섬의 번호마다 포함되는 섬의 좌표 저장
void BFS(int x, int y, int n)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		visited[nowx][nowy] = true;
		area[nowx][nowy] = n;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextx = nowx + d[i].first;
			int nexty = nowy + d[i].second;

			if (nextx < 0 || N <= nextx || nexty < 0 || N <= nexty) continue;

			if (!visited[nextx][nexty] && arr[nextx][nexty]) {
				visited[nextx][nexty] = true;
				q.push({ nextx, nexty });
			}
		}
	}
}

int find()
{
	int minDist = 300; // minDist = 100으로 했었음ㅠㅅㅠ

	for (int i = 0; i < v.size(); i++) {
		int x1 = v[i].first;
		int y1 = v[i].second;

		for (int j = i + 1; j < v.size(); j++) {
			int x2 = v[j].first;
			int y2 = v[j].second;

			if (area[x1][y1] == area[x2][y2]) continue;

			int temp = abs(x1 - x2) + abs(y1 - y2) - 1;
			if (temp < minDist) minDist = temp;
		}
	}

	return minDist;
}

/*

알고리즘 힌트 : 그래프 이론, BFS
1 try : 실패, 시간 복잡도 확인 
3 try : line 79, default value 잘못 설정

*/