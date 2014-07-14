// Segment Tree 
// 区间更新 / 区间查询
// 复杂度 O(nlogn) 
// 2014.5.4
// By Curs0r

#define lson t<<1,l,m
#define rson t<<1|1,m+1,r

class SEGTREE{
	private:
		ll* num;
		ll* sum;
		int sz;
		void build(int t, int l, int r)
		{
			num[t] = sum[t] = 0;
			if(l==r) return;
			int m = (l+r)>>1; 
			build(lson);
			build(rson);
		}
		void seg_add(int t, int l, int r, int pl, int pr, ll inc)
		{
			sum[t]+=inc*(pr-pl+1);
			if(l==pl && r==pr){num[t]+=inc;return;}
			int m = (l+r)>>1;
			if(pl>m) seg_add(rson, pl, pr, inc);
			else if(pr<=m) seg_add(lson, pl, pr, inc);
			else seg_add(lson, pl, m, inc),seg_add(rson, m+1, pr, inc);
		}
		ll seg_query(int t, int l, int r, int pl, int pr)
		{
			if(l==pl && r==pr) return sum[t];
			ll ret = num[t] * (pr-pl+1);
			int m = (l+r)>>1;
			if(pl>m)
				return ret + seg_query(rson, pl, pr);
			else if(pr<=m)
				return ret + seg_query(lson, pl, pr);
			else
				return ret + seg_query(lson, pl, m) + seg_query(rson, m+1, pr);
		}
	public:
		SEGTREE(int size)
		{
			sz = size > 0? size : 0;
			num = new ll[sz*3+1];
			sum = new ll[sz*3+1];
			this->init(sz); // initialize
		}
		~SEGTREE()
		{
			delete[] num;
			delete[] sum;
		}
		void resize(int size)
		{
			size = size > 0? size : 0;
			if(size <= sz) return;
			else{
				ll* tmp;
				tmp = new ll[size*3+1];
				delete[] num;
				num = tmp;
				tmp = new ll[size*3+1];
				delete[] sum;
				sum = tmp;
			}
			sz = size;
		}
		void init(int size)
		{
			build(1,0,sz);
		}
		void add(int l, int r, ll inc)
		{
			seg_add(1,0,sz,l,r,inc);
		}
		ll query(int l, int r)
		{
			return seg_query(1,0,sz,l,r);
		}
};
