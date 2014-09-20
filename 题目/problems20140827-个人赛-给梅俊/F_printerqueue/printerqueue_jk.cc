/*
  [NWERC'06] PRINTER QUEUE
  by: Jan Kuipers
*/

using namespace std;

#include <iostream>
#include <vector>

int main () {

  int runs;
  cin>>runs;
  while (runs--) {

    int N,M;
    cin>>N>>M;
    vector<int> p(N);
    for (int i=0; i<N; i++)
      cin>>p[i];

    int now=0,time=0;
    vector<int> done(N,0);

    while (!done[M]) {
      int n=now, next=-1;
      do {
	if (!done[n]) if (next==-1 || p[n]>p[next]) next=n;
	n=(n+1)%N;
      }
      while (now!=n);

      done[next]=1;
      now=next;
      time++;
    }

    cout<<time<<endl;
  }

  return 0;
}
