#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[51][51];
int visited[51][51];

int dy[4] = { 0,0,-1,1 };   //상하
int dx[4] = { -1,1,0,0 };   //좌우
int T, M, N, K, cnt;    //테스트케이스수, 가로, 세로, 배추위치수, 지렁이수

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {        

        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (ny >= M || ny < 0 || nx >= N || nx < 0) continue;   //인덱스가 벗어나는 경우는 건너뜀

        if (visited[nx][ny] == 0 && map[nx][ny] == 1) {   //방문 안했고 배추가 있으면
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cnt = 0;
        cin >> M >> N >> K;

        while (K--) {
            int X, Y;
            cin >> X >> Y;   //x가로 y세로
            map[Y][X] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 0 && map[i][j] == 1) {
                    cnt++;    //지렁이개수
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
}
