def en(n):
    return 2**n-n-1

def fact(n):
    ans = 1
    for i in range(n):
        ans*=i+1
    return ans

def ncr(n, r):
    return fact(n)//(fact(r)*fact(n-r))

n = 26

ans = 0

for i in range(n+1):
    ans = max(ans, ncr(n, i)* en(i))

print(ans)

'''
the idea is to observe that the number of such strings of length k is
nCk * (# of permutations which are composed of exactly two decreasing subsequences)
the second value turns out to be 2^n - n - 1 for permutations of length n and we are done
'''