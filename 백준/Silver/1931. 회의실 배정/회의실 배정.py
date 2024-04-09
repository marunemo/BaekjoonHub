from sys import stdin

# 최대 회의의 수
answer = 0

# 회의의 수 입력 
cases = int(input())

# 회의실 사용시간 입력
meeting = []
for _ in range(cases):
    meeting.append(list(map(int, stdin.readline().split())))

# 회의 끝나는 시간 기준 정렬
meeting.sort(key=lambda x: (x[1], x[0]))

# 최대한 회의가 빨리 끝나는 회의 위주로 사용
currTime = 0
for start, end in meeting:
    if start >= currTime:
        currTime = end
        answer += 1

# 총 회의 개수 출력
print(answer)