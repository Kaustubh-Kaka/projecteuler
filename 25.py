def dc(n):
    ans = 0
    while(n):
        ans+=1
        n//=10
    return ans

fibl = [1,1]

while(dc(fibl[len(fibl)-1])<int(1e3)):
    fibl.append(fibl[len(fibl)-1]+fibl[len(fibl)-2])

print(len(fibl))