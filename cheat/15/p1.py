s = input()
s = s.split(',')
ans = 0
for x in s:
    print(x)
    curr = 0
    for c in x:
        curr += ord(c)
        curr *= 17
        curr %= 256
    ans += curr

print(ans)
