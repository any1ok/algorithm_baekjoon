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

string girl[102];

queue<string> q;

long long ri ;
long long le ;
long long X,Y;
int mn =2000000002;

vector<pair<int,int>> v[10001];
int visit[10001];
int N,M;
int mx;
int s,e;
bool dfs(int cost){
    for(int i=0;i<=N;i++){
        visit[i] = 0;
    }
    queue<int> q;
    q.push(s);
    visit[s] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0;i < v[t].size();i++){
            if(visit[v[t][i].first] == 1 || v[t][i].second < cost )
                continue;
            if(v[t][i].first == e)
                return true;
            q.push(v[t][i].first);
            visit[v[t][i].first] = 1;
        }

    }

    return false;
}


int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int  a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        if( ri < c){
            ri =c;
        }
    }

    cin >> s >> e;
    while(le <= ri){
        int mid = (le+ri)/2;
        if(dfs(mid) ){
            le = mid+1;
            if( mx < mid ){
                mx = mid;
            }
        }else{
            ri = mid-1;
        }

    }
    cout << mx;


}

