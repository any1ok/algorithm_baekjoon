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
long long N,Ha;
long long le;
long long ri =  1e18;
int map1[3][123470];
long long mn = 1e18;

bool game(long long mid ){
    long long hp = mid;
    long long ha = Ha;


    for(int i=0;i<N;i++){
        long long one = map1[1][i];
        long long two = map1[2][i];
        if(map1[0][i] == 1){

                long long t;
                if(two % ha == 0) t = two/ha - 1;
                else t = two/ha;

                hp -= one * t;
                if(hp <= 0) return false;


        }if(map1[0][i] == 2){
            ha += one;
            hp += two;
            if(hp > mid){
                hp = mid;
            }
        }
    }
    return true;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Ha;


    for(int i=0;i<N;i++){
        int t,a,hi;
        cin >> t >> a >> hi;
        map1[0][i] = t;
        map1[1][i] = a;
        map1[2][i] = hi;
    }
    while(le <= ri){
        long long mid = (le + ri)/2;
        if(game(mid)){
            ri = mid-1;
            if(mn > mid){
                mn = mid;
            }
        }else{
            le = mid+1;
        }

    }

    cout << mn;


}

