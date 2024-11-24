a,b,c,d,e,f = 0,1,1,0,0,0

D = 562678 #998799649

it = 0

while(1):
    #la,lb,le,lf,lc,ld = a,b,e,f,c,d
    e,f = a+c,b+d
    if(e**2-D*f**2==1): 
        print(e,f,e**2-D*f**2)
        break
    elif(e**2-D*f**2>1):
        c,d = e,f
    else:
        a,b = e,f
    it+=1
    #print(e,f,e**2-D*f**2)

print(it)

#optimize with multi step stern brocot tree traversal
