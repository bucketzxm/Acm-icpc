/***********************************
	Mergesort ÇóÄæÐò¶ÔÊý 
	2014.4.24
***********************************/

int tmp[5000];

int mergesort(int *p, int l, int r)
{
	if(l+1>=r)return 0;
	int m = (l+r)/2;
	int ans = 0;
	ans += mergesort(p,l,m);
	ans += mergesort(p,m,r);
	int i=l,j=m,k=0;
	while(i!=m || j!=r)
	{
		if(i==m || (j!=r && p[i]>p[j]))
		{
			tmp[k++] = p[j++];
			ans += m-i;
		}
		else
			tmp[k++] = p[i++];
			
	}
	memcpy(p+l,tmp,(r-l)*sizeof(int));
	return ans;
}
