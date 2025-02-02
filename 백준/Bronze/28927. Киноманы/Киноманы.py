a,b,c=map(int,input().split())
d,e,f=map(int,input().split())
result=3*a+20*b+120*c-3*d-20*e-120*f
if result==0:print("Draw")
elif result>0:print("Max")
else:print("Mel")