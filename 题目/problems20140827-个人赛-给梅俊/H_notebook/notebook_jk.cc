/*
  [NWERC'06] LEONARDO'S NOTEBOOK
  by: Jan Kuipers
*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>

const int N=26;

int main () {

  int runs;
  cin>>runs;
  while (runs--) {
    string s;
    cin>>s;

    vector<int> cnt(N+1);
    vector<int> u(N,0);

    for (int i=0; i<N; i++)
      if (!u[i]) {
	int j=i,n=0;
	do {
	  u[j]=1;
	  j=s.find('A'+j);
	  n++;
	}
	while (j!=i);

	cnt[n]++;
      }

    int ok=1;
    for (int i=0; i<=N; i++)
      if (i%2==0 && cnt[i]%2!=0) ok=0;

    if (ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  
  return 0;
}
