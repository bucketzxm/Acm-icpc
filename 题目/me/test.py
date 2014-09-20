import os,sys

def find(x,p):
  if x == p[x]:
    return p[x]
  else:
    p[x] = find(p[x], p)
    return p[x]
def brute():
  fs = open("in","r")
  old = sys.stdin
  sys.stdin = fs
  N,M = map(int,input().split())
  tN = N
  p = [i for i in range(0,N+1)]
  num = [1 for i in range(0, N+1)]
  for i in range(0,M):
    a = [x for x in map(int, input().split())]

    if a[0] == 0:
      #print(str(a[1])+" "+str(a[2])+"\n")
      fx = find(a[1],p)
      fy = find(a[2],p)
      if p[fx] != p[fy]:
        p[fy] = fx
        num[fx] += num[fy]
        num[fy] = 0
        N -= 1
    else:
      sal = num.copy()
      sal.sort()
      #print(sal)
      print(str(sal[tN-a[1]+1]))
  sys.stdin = old
  fs.close()
  return N

if __name__=="__main__":
  #sys.stdin = fs
  brute()
