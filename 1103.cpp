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
#include <string.h>
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



//int dx[4] = {0, -1, 0, 1};
//int dy[4] = {1, 0, -1, 0};
//int map1[101][101];
//int visit[101][101];
//vector<int> ca[101];
//
////
//void dfs(int s){
//
//    queue<int> q;
//    q.push(s);
//    visit[s][s] = 0;
//
//    while(!q.empty()){
//        int now = q.front();
//        int pt = visit[s][now];
//        q.pop();
//        for(int i=0;i<ca[now].size();i++){
//            if(visit[s][ca[now][i]] == -1) {
//                visit[s][ca[now][i]] = pt + 1;
//                q.push(ca[now][i]);
//            }
//        }
//    }
//}

//long long S,C;
//long long pa[1000001];
//long long ri = 3000000000;
//long long le = 1;
//while(le <= ri){
//long long mid = (le + ri)/2;
//long long cnt =0;
//for(int i=0;i<S;i++){
//cnt += pa[i]/mid;
//}
//if(cnt >=C){
//le = mid +1;
//if(mx < mid ){
//mx = mid;
//}
//
//}else{
//ri = mid -1;
//}
//}

char map1[50][50];
int dp[50][50];
int visit[50][50];
int n, m;
int k=0;
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

int dfs(int x,int y){
    if(x <0 || y < 0 || x >=n || y >=m || map1[x][y] == 'H'){
        return 0;
    }

    if(visit[x][y] == 1){
        k = 1;
        return 1987654321;
    }

    int &temp = dp[x][y];
    if(temp != -1){
        return temp;
    }
    visit[x][y] = 1;
    temp =0;
    for(int i=0;i<4;i++){
        int nx = x+ dx[i] * (map1[x][y] - '0');
        int ny = y + dy[i] * (map1[x][y] - '0');

        temp = max(temp, dfs(nx,ny)+1);
    }
    visit[x][y] = 0;
    return temp;

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; ++i)
        cin >> map1[i];
    int a = dfs(0,0);

    if(k == 1){
        cout << -1;
    }else{
        cout << a;
    }



    return 0;
}
