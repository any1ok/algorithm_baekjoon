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
long long le = -1 ;
long long X,Y;
long long mn =2000000002;

vector<pair<int,int>> v[10001];
long long money[100001];
long long N,M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> money[i];
        ri += money[i];
        le = max(le, money[i]);
    }

    while(le <= ri){
        long long mid = (le+ri)/2;
        long long sum =0;
        long long idx =0;

        for(int i=0;i<N;i++){
            if(sum + money[i]> mid){
                sum =0;
                idx++;
            }
            sum += money[i];
        }
        if(sum != 0) idx++;
        if(idx > M){
            le = mid +1;
        }else{
            ri = mid-1;
            if(mn > mid){
                mn = mid;
            }
        }

    }
    cout << mn;

}

