n=int(input())
a=list(map(int,input().split()))

mp={}
cnt=sum(a)
for i in range(n):
    if a[i] not in mp:
        mp[a[i]]=1
    else:
        mp[a[i]]+=1

ans=[]
for i in range(n):
    x=cnt-a[i]
    if (x%2)==0:
        x=x//2
        if x==a[i] and mp.get(x)>=2:
            ans.append(i+1)

        elif x!=a[i] and mp.get(x) is not None:
            ans.append(i+1)

print(len(ans))
for i in range(len(ans)):
    print(ans[i],end=" ")
