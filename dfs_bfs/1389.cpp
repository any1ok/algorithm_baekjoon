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
//
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
int visit[101][101];
vector<int> ca[101];
int N,M;


void dfs(int s){

    queue<int> q;
    q.push(s);
    visit[s][s] = 0;

    while(!q.empty()){
        int now = q.front();
        int pt = visit[s][now];
        q.pop();
        for(int i=0;i<ca[now].size();i++){
            if(visit[s][ca[now][i]] == -1) {
                visit[s][ca[now][i]] = pt + 1;
                q.push(ca[now][i]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        ca[a-1].push_back(b-1);
        ca[b-1].push_back(a-1);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visit[i][j] = -1;
        }
    }

    for(int i=0;i<N;i++){
        dfs(i);
    }
    int min = 10000;
    int user = 0;
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=0;j<N;j++){
            sum += visit[i][j];
        }
        if(min > sum){
            min = sum;
            user = i;
        }
    }
    cout << user+1;

}

