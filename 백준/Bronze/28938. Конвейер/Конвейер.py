input()
n=sum(map(int, input().split()))
print(["Stay","Right","Left"][int(n>0)-int(n<0)])