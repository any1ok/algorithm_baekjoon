#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int map1[8][8];

vector<pair<int,int>> cctv;
//int map2[101][101];
//int N,K;
//
//
//pair<int,int> quest[200001];
//
//priority_queue<int> pq;
//
//
//bool compare(const pair<int,int>& a, const pair<int,int>& b){
//    return a.first > b.first;
//}

int dp[100001];
int N,M;

void dfs(int x, int y, int dir){
    dir %= 4;
    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)return;
        if (map1[nx][ny] == 6) return;
        if (map1[nx][ny] != 0) continue;
        map1[nx][ny] = '#';
    }
}



int res = 100;
void direct(int n){
    int cctv_cnt = cctv.size();
    if (n == cctv_cnt) {
        int temp_res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map1[i][j] == 0) temp_res++;
            }
        }
        res = min(res, temp_res);
        return;
    }
    int x = cctv[n].first;
    int y = cctv[n].second;
    int map2[8][8];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map2[i][j] = map1[i][j];
        }
    }

    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map2[i][j] = map1[i][j];
            }
        }

        if (map1[x][y] == 1) {
            dfs(x, y, dir);
        }
        else if (map1[x][y] == 2) {
            dfs(x, y, dir);
            dfs(x, y, dir + 2);

        }
        else if (map1[x][y] == 3) {
            dfs(x, y, dir);
            dfs(x, y, dir + 1);
        }
        else if (map1[x][y] == 4) {
            dfs(x, y, dir);
            dfs(x, y, dir + 1);
            dfs(x, y, dir + 2);

        }
        else if (map1[x][y] == 5) {
            dfs(x, y, dir);
            dfs(x, y, dir + 1);
            dfs(x, y, dir + 2);
            dfs(x, y, dir + 3);
        }
        direct(n+1); /////////!!!!!! 재귀 지렸다 시발
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map1[i][j] = map2[i][j];
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map1[i][j];
            if (map1[i][j] >= 1 && map1[i][j] <= 5) {
                cctv.push_back({ i, j });
            }
        }
    }

    direct(0);
    cout << res;


}

