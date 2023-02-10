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

// dfs
//int dx[4] = {0, -1, 0, 1};
//int dy[4] = {1, 0, -1, 0};
//int map[101][101];
//int visit[101][101];
//int visit2[101][101];
//vector<pair<int,int>> cctv;


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


// dp
//int dp[100001];
//string girl[102];
//queue<string> q;


// binary
//long long ri ;
//long long le = -1 ;
//long long X,Y;
//long long mn =2000000002;



int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int map1[101][101];
int map2[101][101];
int visit1[101][101];
int visit2[101][101];
vector<pair<int,int>> cctv;
int N;
int cnt1;
int cnt2;
pair<int,int> dfs(){
    queue<pair<int,int>> q1;


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit1[i][j] == 1)
                continue;
            q1.push({i,j});
            visit1[i][j] = 1;
            cnt1++;
            while(!q1.empty()){
                int x = q1.front().first;
                int y = q1.front().second;
                q1.pop();
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >=0 && ny >=0 && nx < N && ny <N && visit1[nx][ny] == 0 && map1[nx][ny] == map1[x][y]){
                        q1.push({nx,ny});
                        visit1[nx][ny] = 1;
                    }
                }
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit2[i][j] == 1)
                continue;
            q1.push({i,j});
            visit2[i][j] = 1;
            cnt2++;
            while(!q1.empty()){
                int x = q1.front().first;
                int y = q1.front().second;
                q1.pop();
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >=0 && ny >=0 && nx < N && ny <N && visit2[nx][ny] == 0 && map2[nx][ny] == map2[x][y]){
                        q1.push({nx,ny});
                        visit2[nx][ny] = 1;
                    }
                }
            }
        }
    }
    return {cnt1,cnt2};

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char a ;
            cin >> a;
            if(a == 'R'){
                map1[i][j] = 0;
                map2[i][j] = 0;
            }
            if(a == 'G'){
                map1[i][j] = 1;
                map2[i][j] = 0;
            }
            if(a == 'B'){
                map1[i][j] = 2;
                map2[i][j] = 1;
            }
        }
    }

    cout << dfs().first << " " << dfs().second << endl;


}

