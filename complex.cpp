#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int map[25][25];
int visited[25][25];
vector<int> cntVec;

int dr[4] = { 0,0,1,-1 };   //상하
int dc[4] = { -1,1,0,0 };   //좌우
int N;   //지도의 크기
int cnt;   //단지수

void dfs(int r, int c) {

    for (int i = 0; i < 4; i++) {

        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= N || nr < 0 || nc >= N || nc < 0) continue;   //인덱스가 벗어나는 경우는 건너뜀

        if (visited[nr][nc] == 0 && map[nr][nc] == 1) {   //방문 안했고 집이 있으면
            visited[nr][nc] = 1;   //방문표시
            cnt += 1;   //집개수
            dfs(nr, nc);
        }
    }
}


int main() {

    int res = 0;

    cin >> N;
    string str;

    for (int i = 0; i < N; i++) {   //지도입력
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            visited[i][j] = 0;

            if (str[j] == '1') {
                map[i][j] = 1;
            }
            else map[i][j] = 0;
        }
    }

    //확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (map[i][j] == 1 && visited[i][j] == 0) { //집이면서 방문을 안한 경우
                visited[i][j] = 1;   //방문표시
                cnt = 1;
                dfs(i, j);   //dfs 수행
                cntVec.push_back(cnt);
                res++;                          //단지 그룹 1개 탐색 끝남
            }
        }
    }

    sort(cntVec.begin(), cntVec.end());
    cout << res << "\n";   //단지개수 출력

    for (int i = 0; i < cntVec.size(); i++) {   //집개수출력
        cout << cntVec[i] << "\n";
    }

    return 0;
}