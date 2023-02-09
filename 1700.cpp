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

vector<int> in;
vector<int> co;

int map2[101][101];
int N,K;





int main(){
    cin >> N >> K;

    for(int i = 0;i<K;i++){
        int t;
        cin >> t;
        co.push_back(t);
    }
    int cnt =0;

    while(!co.empty()){
        if(find(in.begin(), in.end(), co[0]) == in.end()) {
            if(in.size() < N){
                in.push_back(co[0]);
                co.erase(co.begin());
                continue;
            }else{
                cnt++;
                int mx = 0;
                int index = 0;
                for(int i=0;i<in.size();i++){
                    int pt  = find(co.begin(), co.end(), in[i]) - co.begin();
                    if( mx < pt ){
                        mx = pt;
                        index = i;
                    }
                }
                in.erase(in.begin()+index);
                in.push_back(co[0]);
                co.erase(co.begin());
                continue;
            }
        }
        else{
            co.erase(co.begin());
        }
    }

    cout << cnt;
}

