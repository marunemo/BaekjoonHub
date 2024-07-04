from sys import stdin, setrecursionlimit

# 재귀와 입력을 위한 전처리
setrecursionlimit(10000)
input = stdin.readline

# 팀의 총 능력치 계산
def calcTotalStat(statTable, team, teamSize):
    totalStat = 0
    for i in range(teamSize):
        for j in range(i, teamSize):
            totalStat += statTable[team[i]][team[j]] + statTable[team[j]][team[i]]
    return totalStat

# 스타트 팀과 링크 팀으로 분리
def teamGenerator(statTable, isSelected, selectedMember, order, teamSize):
    # 팀의 숫자가 n / 2일 경우 팀 결정 및 총 능력치 계산
    if order == teamSize:
        selectTeam = []
        restTeam = []
        for i in range(teamSize * 2):
            if isSelected[i]:
                selectTeam.append(i)
            else:
                restTeam.append(i)
        selectStat = calcTotalStat(statTable, selectTeam, teamSize)
        restStat = calcTotalStat(statTable, restTeam, teamSize)
        return abs(selectStat - restStat)
    
    # 팀이 균등하게 나눠지지 않은 경우 큰 값 반환
    if selectedMember == teamSize * 2 - 1:
        return 10000
    
    # 팀의 총 능력치 차이의 최솟값 구하기
    teamStat = []
    for i in range(selectedMember + 1, teamSize * 2):
        isSelected[i] = True
        teamStat.append(teamGenerator(statTable, isSelected, i, order + 1, teamSize))
        isSelected[i] = False
    return min(teamStat)

# 값 입력 및 기본 arg 설정
n = int(input())
statTable = []
for _ in range(n):
    statTable.append(list(map(int, input().split())))
isSelected = [False] * n
selectedMember = -1
order = 0
teamSize = n // 2

# 팀의 능력치 차이 최솟값 출력
minGap = teamGenerator(statTable, isSelected, selectedMember, order, teamSize)
print(minGap)