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

pair<int,int> coin[10010];
int dp[20010];

int main(){


    while(1) {
        int n, m;
        float f1;
        cin >> n >> f1;
        m = 100*f1+0.5;

        if(n == 0){
            return 0;
        }



        for (int i = 0; i < n; i++) {
            int c, p;
            float f2;
            cin >> c >> f2;
            p = f2*100+0.5;
            coin[i].first = c;
            coin[i].second = p;

        }

        for (int i = 0; i < m + 1; i++) {
            dp[i] = -1;

        }
        int ans =0;
        for (int i = 0; i < n; i++) {
            dp[coin[i].second] = coin[i].first;
            if(ans < coin[i].first ){
                ans = coin[i].first;
            }
        }

//        for(int i=0;i<n;i++){
//            for(int j=1;j<=m;j++){
//                if(j-coin[i].second>=0) {
//                    dp[j] = max(dp[j],dp[j-coin[i].second]+coin[i].first);
//                    ans=max(ans,dp[j]);
//                }
//            }
//        } // 정답

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i] != -1) {
                    dp[i + coin[j].second] = max(dp[i] + coin[j].first, dp[i + coin[j].second]);
                    if(i + coin[j].second <= m) {
                        if(ans < dp[i + coin[j].second] ){
                            ans = dp[i + coin[j].second];
                        }

                    }
                }
            }
        }
//
        cout << ans << endl;
    }
}
