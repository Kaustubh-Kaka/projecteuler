def nCr(n, r):
    if(r==0 or r==n):
        return 1
    else:
        ans = 1
        for i in range(n):
            ans*=i+1
        for i in range(min(r,n-r)):
            ans//=(i+1)**2
        for i in range(min(r,n-r)+1,max(r,n-r)+1):
            ans//=i
        return ans

print(nCr(40,20))