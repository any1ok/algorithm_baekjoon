#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> computers(100001);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, max_c = 0;
    vector<pair<int, int>> result;
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        computers[b].push_back(a); //b를 해킹하면 a를 해킹할 수 있습니다! 아하하
    }

    for (int i = 1; i <= N; i++)
    {
        bool visited[100001] = {
            false,
        };
        int count = 0;
        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            int com = q.front();
            q.pop();
            visited[com] = true;

            for (int j = 0; j < computers[com].size(); j++)
            { //해당 컴퓨터가 해킹할 수 있는 것들 queue에 추가
                int ncom = computers[com][j];
                if (visited[ncom])
                    continue;
                q.push(ncom);
                visited[ncom] = true;
                count++;
            }
        }
        max_c = max(count, max_c);
        result.push_back(make_pair(i, count));
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i].second == max_c)
            cout << result[i].first << " ";
    }

    return 0;
}
