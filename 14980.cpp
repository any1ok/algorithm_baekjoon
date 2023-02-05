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

int map[101][101];
int map2[101][101];
int N,L;



int main(){
    cin >> N >> L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){

            cin >> map[i][j];
            map2[j][i] = map[i][j];
        }
    }
    int cnt=0;

    for(int i=0;i<N;i++){

        int same =1;
        for(int j=0;j<N-1;j++){
            int after = map[i][j+1];
            int now = map[i][j];
            if(after > now) {
                if (after - now == 1) {
                    if(same >=L){
                        same = 1;
                        if(j == N-2){
                            cnt++;
                        }
                        continue;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            else if(after == now){
                same++;
            }
            else if(after < now) {
                if (after - now == -1) {
                    int k = j+2;
                    same = 1;
                    while(same < L && after == map[i][k] && k < N){
                        k++;
                        same++;
                    }
                    if(same == L){
                        same = 0;
                        j = j+L-1;
                        if(j == N-2){
                            cnt++;
                        }
                        continue;
                    }
                    break;
                }
                else{
                    break;
                }
            }

            if(j == N-2){
                cnt++;
            }
        }
    }


    for(int i=0;i<N;i++){

        int same =1;
        for(int j=0;j<N-1;j++){
            int after = map2[i][j+1];
            int now = map2[i][j];
            if(after > now) {
                if (after - now == 1) {
                    if(same >=L){
                        same = 1;
                        if(j == N-2){
                            cnt++;
                        }
                        continue;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            else if(after == now){
                same++;
            }
            else if(after < now) {
                if (after - now == -1) {
                    int k = j+2;
                    same = 1;
                    while(same < L && after == map2[i][k] && k < N){
                        k++;
                        same++;
                    }
                    if(same == L){
                        same = 0;
                        j = j+L-1;
                        if(j == N-2){
                            cnt++;
                        }
                        continue;
                    }
                    break;
                }
                else{
                    break;
                }
            }

            if(j == N-2){
                cnt++;
            }
        }
    }
    cout << cnt;

}
