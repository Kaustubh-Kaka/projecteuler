from math import *

def sind(f,n = 1000, r = 9):
    a, b = log(1-f, 10), log(1+2*f, 10)
    return (r-n*a)/(b-a)
    
low,mid1,mid2,high = 0.01,0,0,0.99
eb = 1e-5

while(high-low>eb):
    mid1,mid2 = (2*low+high)/3,(low+2*high)/3
    if(sind(mid1)<sind(mid2)): high = mid2
    else: low = mid1

# print(low)

n = 1000

val = (int(ceil(sind(low))))

num = 0

fac = [1]

while(len(fac)<n+1):
    fac.append(fac[len(fac)-1]*len(fac))

for i in range(val, n+1):
    num+=fac[n]//(fac[i]*fac[n-i])

print((num/2**n))

print(fac[42]//(fac[21]**2))

    