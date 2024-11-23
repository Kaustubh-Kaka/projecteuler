f = open("./13text.txt")

n, s = 0,0

for i in range(100):
    n = int(f.readline())
    s+=n

print(str(s)[:10])