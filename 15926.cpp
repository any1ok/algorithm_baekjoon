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


stack<int> s;
long long result;
int mx;
int main() {
    int n;
    cin >> n;
    int cnt =0;
    s.push(-1);
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        if(c == '('){
            s.push(i);
        }
        if(c == ')'){
            s.pop();
            if(s.empty()){
                s.push(i);
            }else {
                mx = max(mx , i - s.top());
            }
        }
    }
    cout << max(mx,cnt);
}
