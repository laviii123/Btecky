N=int(input())
#part 1
i=1
while(i<=N):
    spaces=i-1
    while(spaces>0):
        print(" ",end="")
        spaces=spaces-1
    p=1
    while(p<=i):
        print("*",end="")
        p=p+1
    print()
    i=i+1
#part 2
i=1
p=N-1
while(i<=N-1):
    spaces=1
    while(spaces<=N-i-1):
        print(" ",end="")
        spaces=spaces+1 
    j=1
    while(j<=p):
        print("*",end="")
        j=j+1
    print()
    i=i+1
    p=p-1

# Output
# 4
# *
#  **
#   ***
#    ****
#   ***
#  **
# *
