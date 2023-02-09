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


pair<int,int> quest[200001];

priority_queue<int> pq;


bool compare(const pair<int,int>& a, const pair<int,int>& b){
    return a.first > b.first;
}

int main(){
    cin >> N ;
    for(int i=0;i<N;i++){
        int t1,t2;
        cin >> t1 >> t2;
        pair<int,int> tmp;
        tmp.first = t1;
        tmp.second = t2;
        quest[i] = tmp;
    }



    sort(quest , quest+N, compare);


    long long sum =0;
    int k =0;
    for(int i=N-1;i>=0;i--){
        while(k<N &&  i+1 <= quest[k].first){
            pq.push( quest[k].second);
            k++;
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;

}

