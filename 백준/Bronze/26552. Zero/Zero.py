import sys
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    num = int(input()) + 1
    while '0' in str(num):
        num += 1
    print(num)