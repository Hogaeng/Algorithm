z=input()
z=int(z)
for d in range(1,z+1):
    s=""
    for k in [2,4,7,14,30]:
        if d-k+1>0:
            s+=str(d-k+1)+","
    s=s[0:len(s)-1]
    print("day",d,":",s)