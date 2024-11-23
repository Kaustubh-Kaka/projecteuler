def fact(n):
    ans = 1
    for i in range(n):
        ans*=i+1
    return ans

def digsum(n):
    ans = 0
    while(n):
        ans+=n%10
        n//=10
    return ans

print(digsum(fact(100)))