/*
  [NWERC'06] PRIME PATH
  by: Jan Kuipers
*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

int main () {

  vector<int> p;
  for (int i=1000; i<10000; i++) {
    int ok=1;
    for (int d=2; ok && d*d<=i; d++)
      if (i%d==0) ok=0;
    if (ok) p.push_back(i);
  }

  int N = p.size();
  vector<vector<int> > next(N);
  vector<vector<int> > dist(N);

  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++) {
      int pi=p[i], pj=p[j];
      int diff=0, d=0;
      for (int k=0; k<4; k++) {
	if (pi%10!=pj%10) diff++, d=pj%10;
	pi/=10;
	pj/=10;
      }
      if (diff==1) {
	next[i].push_back(j);
	dist[i].push_back(1);
      }
    }

  int runs;
  cin>>runs;
  
  while (runs--) {
    int fr,to;
    cin>>fr>>to;
    for (int i=0; i<p.size(); i++) if (p[i]==fr) { fr=i; break;}
    for (int i=0; i<p.size(); i++) if (p[i]==to) { to=i; break;}
    
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,fr));

    vector<int> best(N,-1);
    while (!pq.empty()) {
      int d = -pq.top().first;
      int i = pq.top().second;
      pq.pop();

      if (best[i]!=-1) continue;
      best[i]=d;

      for (int j=0; j<next[i].size(); j++)
	pq.push(make_pair(-(d+dist[i][j]),next[i][j]));
    }

    if (best[to]==-1)
      cout << "IMPOSSIBLE" << endl;
    else
      cout << best[to] << endl;
  }
  
  return 0;      
}
