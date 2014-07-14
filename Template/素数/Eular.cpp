/**********************************
	欧拉筛法	求素数表 & phi(i)
	2014.3.1
**********************************/


#define PRIME_MAXN 100000000
int vis[PRIME_MAXN];
int prime[PRIME_MAXN], n_prime;
int phi[PRIME_MAXN];
void Eular()
{
	n_prime=0;
	phi[1]=1;
	for(int i = 2; i < PRIME_MAXN; i++)
	{
		if(!vis[i]){
			prime[n_prime++] = i;
			phi[i] = i-1;
		}
		for(int j = 0; j < n_prime && i * prime[j] < PRIME_MAXN; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j]) phi[i * prime[j]] = phi[i] * phi[prime[j]];  
			else {
				phi[i * prime[j]] = phi[i] * prime[j]; 
				break;
			}
		}
	}
}
