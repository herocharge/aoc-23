parts = []
idx = 0
while True:
    inp = input()
    if len(inp) < 3:
        break
    inp = inp[1:][:-1]
    inp = inp.split(',')
    part = "{"
    for x in inp:
        part += x.split('=')[1] + ","
    part = part[:-1] + "},"
    print(part)
