b = [[1,1]]

while(len(b)<25):
    b.append([3*b[len(b)-1][0]+2*b[len(b)-1][1],4*b[len(b)-1][0]+3*b[len(b)-1][1]])
    if((b[len(b)-1][1]+1)//2>int(1e12)): break

print((b[len(b)-1][0]+1)//2)

# b^2-b/t^2-t = 1/2
# B = 2*b - 1, T = 2*t - 1
# 2*B^2 - T^2 = 1
# (B, T) = (1, 1)
# (sqrt(2)*B - T)(sqrt(B) + T) = 1
# (3 - 2*sqrt(2))(3 + 2*sqrt(2)) = 1
# 2*(3*B + 2*T)^2 - (4*B + 3*T)^2 = 1
# cross multiplying gives another series of solutions but those are negative
# recover (b, t) = ((B + 1)/2, (T + 1)/2)