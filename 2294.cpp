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

int coin[101];
int dp[20010];

int main(){
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {

        cin >> coin[i];
        if (coin[i] > 10000) {
            coin[i]=0;
        }
    }

    for (int i = 0; i < k + 1; i++) {
        dp[i] = 1000001;

    }
    for(int i=0;i<n;i++){
        dp[coin[i]] = 1;
    }

    for(int i=1; i<k;i++){
        for(int j=0;j<n;j++){
            if (dp[i] != 1000001) {
                dp[i + coin[j]] = min(dp[i] + 1, dp[i + coin[j]]);
            }
        }
    }
    if (dp[k] == 1000001) {
        printf("-1");
        return 0;
    }
    else {
        printf("%d", dp[k]);
    }

}
