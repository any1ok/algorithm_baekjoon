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

int pizA[1001];
int pizB[1001];
int k,m,n;


int main(){
    cin >> k >> m >> n;
    map<int, int> m1;
    map<int, int> m2;
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        pizA[i] = tmp;
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        pizB[i] = tmp;
    }

    for(int i=0;i<m;i++){ // 몇개 더해
        for(int j=0;j<m;j++){ // 시작
            int t = i+1;
            if(i == m-1 && j == 1){
                break;
            }
            int sum =0;
            int idx = j;
            while(t--){
                sum += pizA[idx];
                idx++;
                if(idx == m)
                    idx = 0;
            }
            auto it = m1.find(sum);
            if(it == m1.end()){
                m1.insert({sum,1});
            }else{
                int ab = it->second;
                ab++;
                it->second = ab;
            }
        }
    }
    for(int i=0;i<n;i++){ // 몇개 더해
        for(int j=0;j<n;j++){ // 시작
            int t = i+1;
            if(i == n-1 && j == 1){
                break;
            }
            int sum =0;
            int idx = j;
            while(t--){
                sum += pizB[idx];
                idx++;
                if(idx == n)
                    idx = 0;
            }
            auto it = m2.find(sum);
            if(it == m2.end()){
                m2.insert({sum,1});
            }else{
                int ab = it->second;
                ab++;
                it->second = ab;
            }
        }
    }

    int answer =0;




    for(auto it = m1.begin(); it != m1.end(); it++){
        int tmp = k-it->first;
        auto it2 = m2.find(tmp);
        if(it2 != m2.end()){
            answer += it->second*it2->second;
        }
    }

    auto it3 = m1.find(k);
    if(it3 != m1.end()) {
        answer += it3->second;
    }
    auto it4 = m2.find(k);
    if(it4 != m2.end()) {
        answer += it4->second ;
    }

    cout << answer;


}

