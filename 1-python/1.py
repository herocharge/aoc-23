with open('input1', 'r') as f:
    txt = f.readlines()

ans = 0
for s in txt:
    s = s[:-1]
    wrd = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    frst = ''
    for i in range(len(s)):
        if s[i] in [chr(ord('0') + i) for i in range(10)]:
            frst = int(s[i])
            break
        for num in range(1, 10):
            if len(s) - i < len(wrd[num]):
                continue
            if s[i:i+len(wrd[num])] == wrd[num]:
                frst = num
        if frst != '':
            break
    print(frst)
    last = ''
    s = s[::-1]
    for i in range(len(s)):
        if s[i] in [chr(ord('0') + i) for i in range(10)]:
            last = int(s[i])
            break
        for num in range(1, 10):
            if len(s) - i < len(wrd[num]):
                continue
            print(wrd[num][::-1])
            if s[i:i+len(wrd[num])] == wrd[num][::-1]:
                last = num
        if last != '':
            break
    print(last)
    ans += frst * 10 + last
    print(frst * 10 + last)
    print(ans)
