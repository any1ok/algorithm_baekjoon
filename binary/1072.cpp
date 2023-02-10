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

long long ri = 2000000002;
long long le ;
long long X,Y;
int mn =2000000002;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> X >> Y;
    long long first = Y*100 /X;
    while(le <= ri){
        long long mid = (ri + le)/2;
        long long next = (Y+mid)*100 / (X+mid);
        if(first != next ){
            ri = mid - 1;
            if(mn > mid){
                mn = mid;
            }
        }else{
            le = mid + 1;
        }
    }

    if(mn == 2000000002){
        cout << -1;
    }else {
        cout << mn;
    }
}

