t = int(input())
a = [1,1,2] + [0]*120
for i in range(3,101):
    for j in range(i):
        a[i] += a[j]*a[i-j-1]

i = 1
while i <= t:
    s = int(input())
    print(a[s])
    i = i+1

