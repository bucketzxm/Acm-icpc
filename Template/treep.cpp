#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;
const int MAX_T = 1000000;
#undef NULL
const int NULL = 0;
typedef int T;
struct Treap {
	int key[MAX_T], size[MAX_T], p[MAX_T];
	T ls[MAX_T], rs[MAX_T];
	T ss[2], ss0[2], ss1[2];
	int mc;

	void init() {
		key[0] = size[0] = p[0] = ls[0] = rs[0] = 0;
		mc = 1;
	}

	T newT(int k) {
		key[mc] = k;
		size[mc] = 1;
		p[mc] = rand();
		ls[mc] = rs[mc] = NULL;
		return mc++;
	}

	T change(T t, T l, T r) {
		size[t] = size[l] + size[r] + 1;
		ls[t] = l;
		rs[t] = r;
		return t;
	}

	void splitSize(T t, int s, T * res) {
		if (s <= 0) {
			res[0] = NULL;
			res[1] = t;
		} else if (s <= size[ls[t]]) {
			splitSize(ls[t], s, res);
			res[1] = change(t, res[1], rs[t]);
		} else {
			splitSize(rs[t], s - size[ls[t]] - 1, res);
			res[0] = change(t, ls[t], res[0]);
		}
	}

	void splitKey(T t, int k, T * res) {
		if (t == NULL) {
			res[0] = res[1] = NULL;
		} else if (k < key[t]) {
			splitKey(ls[t], k, res);
			res[1] = change(t, res[1], rs[t]);
		} else {
			splitKey(rs[t], k, res);
			res[0] = change(t, ls[t], res[0]);
		}
	}

	T merge(T t1, T t2) {
		if (t1 == NULL)
			return t2;
		if (t2 == NULL)
			return t1;
		if (p[t1] < p[t2])
			return change(t1, ls[t1], merge(rs[t1], t2));
		return change(t2, merge(t1, ls[t2]), rs[t2]);
	}

	void print(T t, string s) {
		if (t == NULL)
			return;
		print(rs[t], s + "      ");
		printf("%s%3d%3d\n", s.c_str(), key[t], size[t]);
		print(ls[t], s + "      ");
		if (s == "")
			puts("--------------------------");
	}

} treap;

