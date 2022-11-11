d = {}
n = int(input())
for i in range(0, n):
    x = input().split()
    d[x[0]] = x[1]
while True:
    try:
        nm = input()
        if d.has_key(nm):
            print(nm, '=', d[nm], sep="")
        else:
            print("Not found")
    except e:
        print(e)
        break