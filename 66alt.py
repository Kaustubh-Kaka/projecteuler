a,b,c,d,e,f = 0,1,1,0,0,0

D = 54

it = 0

while(1):
    e,f = a+b,c+d
    if(e**2-D*f**2==1): 
        print(e,f)
        break
    elif(e**2-D*f**2>1):
        c,d = e,f
    else:
        a,b = e,f
    it+=1
    if(it>100): break
    print(e,f,e**2-D*f**2)
