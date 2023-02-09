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



using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

int map[101][101];
int map2[101][101];
int N,K;


pair<int,int> ju[300001];
int ba[300001];
priority_queue<int> pq;


bool compare(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        int t1,t2;
        cin >> t1 >> t2;
        pair<int,int> tmp;
        tmp.first = t1;
        tmp.second = t2;
        ju[i] = tmp;
    }

    for(int i=0;i<K;i++){
        int t1;
        cin >> t1;
        ba[i] = t1;
    }

    sort(ju , ju+N, compare);
    sort(ba,ba+K);

    long long sum =0;
    int idx = 0 ;
    for(int i=0;i<K;i++){
        int cur = ba[i];
        while(idx < N && cur >= ju[idx].first) {
            pq.push(ju[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;

}

