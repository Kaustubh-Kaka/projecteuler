def srt(n):
    low,mid,high = 0,0,n
    while(high-low>1):
        mid = (low+high)//2
        if(mid**2<=n): low = mid
        else : high = mid
    return low
    
def solve(n):
    n*=10**202
    dd = str(srt(n))[0:100]
    ans = 0
    for x in dd:
        ans+=int(x)
    return ans

ans = 0

for i in range(2,100):
    if(srt(i)**2!=i):
        ans+=solve(i)

print(ans)

