n = int(input())
while n != 0:
    print(["PREMIADO","TENTE NOVAMENTE"][n%42!=0])
    n = int(input())