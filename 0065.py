def convEval(conv):

    pl = [conv[0], 1+conv[0]*conv[1]]
    ql = [1, conv[1]]

    for i in range(len(conv)):
        if(i>1):
            pl.append(pl[i-2]+conv[i]*pl[i-1])
            ql.append(ql[i-2]+conv[i]*ql[i-1])
    return [pl,ql]

def digsum(n):
    a = 0
    while(n):
        a+=n%10
        n//=10
    return a

a = [2,1,2]

for i in range(2,200):
    a.append(1)
    a.append(1)
    a.append(2*i)

x = convEval(a[:100])

print(digsum(x[0][len(x[0])-1]))