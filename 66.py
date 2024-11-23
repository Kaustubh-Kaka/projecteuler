from math import *
import sys

sys.set_int_max_str_digits(100000)

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
    ts = len(lst)
    for i in range(1,ts):
        lst.append(lst[i])
    return lst

def minSol(n):
    conv = contF(n) 

    pl = [conv[0], 1+conv[0]*conv[1]]
    ql = [1, conv[1]]

    for i in range(len(conv)):
        if(i>1):
            pl.append(pl[i-2]+conv[i]*pl[i-1])
            ql.append(ql[i-2]+conv[i]*ql[i-1])
        if(pl[i]**2-n*ql[i]**2==1): return [pl[i], ql[i]]

bval = 2
bvalc = [3,2]

for i in range(2,int(1e3)):
    if(not issrt(i)):
        tsol = minSol(i)
        if(tsol[0]>bvalc[0]):
            bvalc = tsol
            bval = i

print(bval,bvalc)
