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

//int dy[4] = {-1,0,1,0};
//int dx[4] = {0,-1,0,1};
//
//int map[101][101];
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
int k,m,n;


int main(){
    cin >> n;
    int k;
    cin >> k;
    dp[0] = k;
    for(int i=1;i<n;i++){
        cin >> k;
        if(dp[i-1]+k < k){
            dp[i] = k;
        }else{
            dp[i] = dp[i-1]+k ;
        }
    }
    int max=-2000;
    for(int i=0;i<n;i++){
        if(dp[i] > max){
            max = dp[i];
        }
    }
    cout << max;

}

