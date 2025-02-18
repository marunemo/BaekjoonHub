n, m=map(int, input().split())
while n + m > 0:
    print("YNeos"[n <= m::2])
    n, m=map(int, input().split())