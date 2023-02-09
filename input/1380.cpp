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
int n;
string girl[102];
int bun[102];
queue<string> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int idx =1;

    while(1) {
        for(int i=0;i<n;i++){
            bun[i] = 0;
        }
        cin >> n;
        if(n == 0){
            return 0;
        }
        getchar();
        for(int i=0;i<n;i++){
            getline(cin,  girl[i]);
        }
        for(int i=0;i<2*n-1;i++){
            int a;
            char b;
            cin >> a >> b;
            if(bun[a-1] == 1){
                bun[a-1] = 0;
            }else{
                bun[a-1] = 1;
            }
        }

        for(int i=0;i<n;i++){
            if(bun[i] == 1){
                cout << idx << " " << girl[i] << endl;
                idx++;
            }
        }

    }

}

