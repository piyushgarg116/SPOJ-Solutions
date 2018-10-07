#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define f first
#define s second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long int ll;

string grid[182];
int n, m, x[] = {0,0,1,-1}, y[] = {1,-1,0,0};
int visited[182][182];

bool isValid(int r, int c)
{
	if(r >= 0 && r < n && c >= 0 && c < m)
		return true;
	return false;
}

int bfs()
{
	queue<pii> pendingNodes;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(grid[i][j] == '1')
			{
				visited[i][j] = 0;
				pendingNodes.push(mp(i,j));
			}
	while(!pendingNodes.empty())
	{
		pii fr = pendingNodes.front();
		pendingNodes.pop();
		for(int i = 0; i < 4; ++i)
			if(isValid(fr.f+x[i],fr.s+y[i]) && visited[fr.f+x[i]][fr.s+y[i]] == -1)
			{
				visited[fr.f+x[i]][fr.s+y[i]] = visited[fr.f][fr.s]+1;
				pendingNodes.push(mp(fr.f+x[i],fr.s+y[i]));
			}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    clock_t start_s = clock();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n >> m;
    	for(int i = 0; i < n; ++i)
    			cin >> grid[i];
    	memset(visited,-1,sizeof(visited));
    	bfs();
    	for(int i = 0; i < n; ++i)
    	{
    		for(int j = 0; j < m ; ++j)
    			cout << visited[i][j] << " ";
    		cout << endl;
    	}
    }
    #ifndef ONLINE_JUDGE
    clock_t stop_s = clock();
    cout << "Time Elapsed: " << ((stop_s-start_s)/double(CLOCKS_PER_SEC))*1000 << " ms" << endl;
    #endif
    return 0;
}
