import re
with open("input2", "r") as f:
    al = f.readlines()

ans = 0
for s in al:
    reds = re.findall("[0-9]* red",s)
    greens = re.findall("[0-9]* green",s)
    blues = re.findall("[0-9]* blue",s)
    reds = list(map(lambda x : int(x.split(' ')[0]),reds))
    greens = list(map(lambda x : int(x.split(' ')[0]),greens))
    blues = list(map(lambda x : int(x.split(' ')[0]),blues))
    ans += (max(reds) * max(greens) * max(blues))
print(ans)

