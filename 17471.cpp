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




using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

int map[200][200];
int visit[11];
int state[11];
int dosi[12];
int N;
vector<vector<int>> v;
int tt[101];

int dfs(){
    queue<int> q;
    int group=0;
    int mn = 10000000;
    int dosi_hap;
    for(int i=0;i<N;i++){
        if(visit[i]== 1)
            continue;
        q.push(i);
        group++;
        dosi_hap=dosi[i];
        visit[i] = 1;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int j=0;j < v[now].size();j++){
                if(visit[v[now][j]] == 1 || state[now] != state[v[now][j]])
                    continue;
                q.push(v[now][j]);
                visit[v[now][j]] = 1;
                dosi_hap += dosi[v[now][j]];
            }
        }
        tt[group] = dosi_hap;
    }
    if(group == 2){
        return abs(tt[1]-tt[2]);
    }
    return 100000000;
}


int main(){

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> dosi[i];
    }

    for(int i=0;i<N;i++){
        int k;
        cin >> k;
        vector<int> tv;
        for(int j=0;j<k;j++){

            int t;
            cin >> t;
            tv.push_back(t-1);
        }
        v.push_back(tv);
    }


    int answer = 100000000;
    while(state[N] == 0){
        state[0]++;
        for(int i=0;i<N;i++){
            if(state[i] == 2){
                state[i] = 0;
                state[i+1]++;
            }
        }
        for(int i=0;i<N;i++){
            visit[i] = 0;
        }
        int asd = dfs();
        if(answer > asd)
        answer = asd;

    }

    if(answer == 100000000){
        cout << -1;
    }else{
        cout << answer;
    }




}
