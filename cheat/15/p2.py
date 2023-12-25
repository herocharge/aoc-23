s = input()
s = s.split(',')
boxes = [[] for i in range(256)]
ans = 0
for x in s:
    print(x)
    curr = 0
    focal = -1
    if x[-1] == '-':
        x = x[:-1]
    else:
        focal = int(x[-1])
        x = x[:-2]
    for c in x:
        curr += ord(c)
        curr *= 17
        curr %= 256
    if focal == -1:
        for j in range(len(boxes[curr])):
            if boxes[curr][j][0] == x:
                boxes[curr][j][1] = -1
    else:
        ok = True
        for j in range(len(boxes[curr])):
            if boxes[curr][j][0] == x and boxes[curr][j][1] != -1:
                boxes[curr][j][1] = focal
                ok = False
        if ok:
            boxes[curr].append([x, focal])

for i, box in enumerate(boxes):
    idx = 1
    for slot in box:
        if slot[1] == -1:
            continue
        ans += (i + 1) * idx * slot[1]
        idx += 1

print(ans)
