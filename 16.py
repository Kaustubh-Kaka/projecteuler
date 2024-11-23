def digsum(n):
    ans = 0
    while(n):
        ans+=n%10
        n//=10
    return ans

print(digsum(2**1000))