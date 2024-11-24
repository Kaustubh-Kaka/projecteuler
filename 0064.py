def issrt(n):
    low = 0
    mid = 0
    high = n
    while(high-low>1):
        mid = (low+high)//2
        if(mid**2<=n): low = mid
        else: high = mid
    return low**2==n

def srt(n):
    low = 0
    mid = 0
    high = n
    while(high-low>1):
        mid = (low+high)//2
        if(mid**2<=n): low = mid
        else: high = mid
    return low

def gcd(a, b):
    if(a%b==0): return b
    else: return gcd(b,a%b)

def contF(n):
    p1 = 0
    q1 = 1
    p2 = 1
    q2 = 1
    p1n = 0
    q1n = 1
    p2n = 1
    q2n = 1
    lst = []
    ub = 2*srt(n)+1
    while(1):
        low = 0
        high = ub
        mid = 0
        while(high - low>1):
            mid = (low+high)//2
            if((mid*q1-p1)**2*q2**2<n*p2**2*q1**2): low = mid
            else: high = mid
        lst.append(low)
        p1 -= low*q1
        q1n = (p1*q2)**2-n*(p2*q1)**2
        q2n = q1n
        p1n = p1*q1*q2**2
        p2n = -p2*q2*q1**2
        p1 = p1n
        q1 = q1n
        p2 = p2n
        q2 = q2n
        t1 = gcd(p1,q1)
        p1//=t1
        q1//=t1
        t2 = gcd(p2,q2)
        p2//=t2
        q2//=t2
        #print(p1,q1,p2,q2)
        if(lst[len(lst)-1]==2*lst[0]): break    
    return lst

cnt = 0

n = int(1e4)

tmp = []

for i in range(1,n+1):
    if(not issrt(i)):
        if((len(contF(i))-1)%2): cnt+=1

print(cnt)