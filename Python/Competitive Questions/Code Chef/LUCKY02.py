t = int(input())
while (t):
    n = input()
    flag = 0
    for i in n:
        if (i != '3' and i != '7'):
            print("BETTER LUCK NEXT TIME")
            flag = 1
            break
    if (flag == 0):
        print("LUCKY")
    t-=1