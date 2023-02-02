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




using namespace std;

int N;
int map[20][20];
int board[20][20];
int s[21];
int answer = 100000;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c;
            cin >> c;
            if(c == 'H')
                board[i][j] = 1;
            else{
                board[i][j] = 0;
            }
        }
    }
    while(s[N] == 0){

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                map[i][j] =board[i][j];

            }

        }



        for(int i=0;i<N;i++){
            if(s[i] == 1){
                for(int j=0;j<N;j++){
                        map[i][j] = abs(map[i][j]-1);
                }
            }
        }



        int cnt =0;
        for(int i=0;i<N;i++){
            int hap =0;
                for(int j=0;j<N;j++){
                    hap += map[j][i];
                }
            if(hap > N/2){
                cnt += (N - hap);
            }
            else{
                cnt += hap;
            }
        }

        answer = min(cnt,answer);
//        for(int i=0;i<N;i++){
//            if(s[i] == 1){
//                for(int j=0;j<N;j++){
//                    if(map[i][j] == 0){
//                        map[i][j] = 1;
//                    }
//                    if(map[i][j] == 1){
//                        map[i][j] = 0;
//                    }
//                }
//            }
//        }

        s[0]++;
        for(int i=0;i<N;i++){
            if(s[i] == 2){
               s[i+1]++;
               s[i]=0;
            }

        }
    }
    cout << answer ;


}
