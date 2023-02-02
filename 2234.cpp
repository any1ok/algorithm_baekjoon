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
int visit[200][200];
int N,M;
int mx;
int mmx;
queue<pair<int,int>> q;
vector<pair<int,int>> wall;

int room_cnt;
void bfs(){

    for(int i=0;i<2*M+1;i++){
        for(int j =0; j<2*N+1;j++){
            if(visit[i][j] == 1)
                continue;

            if(map[i][j] == 1 ){
                visit[i][j] = 1;
                continue;
            }

            room_cnt++;
            int size =0;


            q.push({i,j});

            if(mx < size){
                mx = size;
            }

            if(map[i][j] == 2){
                size ++;
            }

            visit[i][j] = 1;



            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if( nx >=0 && ny >=0  && nx < 2*M+1 && ny <2*N+1){
                        if(visit[nx][ny] == 1 || map[nx][ny] == 1)
                            continue;
                        q.push({nx,ny});
                        visit[nx][ny] = 1;
                        if(map[nx][ny] == 2){
                            size++;
                        }
                    }
                }
            }
            if(mx < size){
                mx = size;
            }


        }
    }


}


int main(){
    cin >> N >> M;
    for(int i=0;i<2*M+1;i++){
        for(int j =0; j<2*N+1;j++){
            map[i][j] = 1;
        }
    }

    for(int i=0;i<M;i++){
        for(int j =0; j<N;j++){
            int n;
            cin >> n;
            int x = 2*i+1;
            int y = 2*j+1;
            map[x][y] = 2;
            for(int k =0; k<4;k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                map[nx][ny] = n % 2;
                if (map[nx][ny] == 1) {
                    wall.push_back({nx, ny});
                }
                n = n / 2;
            }
        }
    }


//    for(int i=0;i<2*M+1;i++){
//        for(int j =0; j<2*N+1;j++){
//            cout << map[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    bfs();
    cout << room_cnt << endl;
    cout << mx << endl;

    for(int i=0;i<wall.size();i++){

        for(int i=0;i<2*M+1;i++){
            for(int j =0; j<2*N+1;j++){
                visit[i][j] = 0;
            }
        }
        map[wall[i].first][wall[i].second] = 0;
        bfs();
        if(mmx < mx){
            mmx = mx;
        }
        map[wall[i].first][wall[i].second] = 1;

    }
   cout << mmx << endl;

}
