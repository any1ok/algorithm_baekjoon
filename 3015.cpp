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


stack<pair<long long,long long>> s;
long long result;
int main() {
    int N;
    cin >> N;
    for(int i = 0 ;i <N ;i++){
        long long temp;
        cin >> temp;

        while(!s.empty() && s.top().first < temp ){
            result += s.top().second;
            s.pop();
        }

        if(s.empty()){
            s.push({temp,1});
        }else{
            if(s.top().first == temp){
                long long temp2 = s.top().first;
                long long ban = s.top().second;
                s.pop();
                result += ban;
                if(!s.empty()){
                    result++;
                }
                s.push({temp2,ban+1});

            }
            else{
                s.push({temp,1});
                result++;
            }
        }


    }
    cout << result;
}
