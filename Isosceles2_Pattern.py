N=int(input())
i=1
while(i<=N):
    spaces=1
    while(spaces<=N-i):
        print(" ",end="")
        spaces=spaces+1
    p=i # for increasing
    j=1
    while(j<=i):
        print(p,end="")
        p=p+1
        j=j+1
    
    p=p-2
    while(p>=i):
        print(p,end="")
        p=p-1
    print()
    i=i+1

# Output
# 4
#    1
#   232
#  34543
# 4567654
