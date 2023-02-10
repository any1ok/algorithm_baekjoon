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

long long ri = 2000000000;
long long le ;
int house[200001];
int N,C;
int mx =0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> C;
    for(int i=0;i<N;i++){
        cin >> house[i];
    }
    sort(house, house+N);

    while(le <= ri){
        int idx =1;
        long long mid = (ri + le)/2;
        int be = house[0];
        for(int i=1;i<N;i++){
            int now = house[i];
            if(now - be >= mid){
                be = now;
                idx++;
            }
        }
        if(idx < C){
            ri = mid-1;
        }else{
            le = mid +1;
            if(mx < mid){
                mx = mid;
            }
        }
    }

    cout << mx;

}

