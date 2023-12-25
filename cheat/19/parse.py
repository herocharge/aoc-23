
functions = []
numsx = []
numsm = []
numsa = []
numss = []
while True:
    wrk = input()
    if len(wrk) < 3:
        break
    fname = wrk.split('{')[0]
    frules = wrk.split('{')[1][:-1]
    func = "bool "+ fname + "(int x, int m, int a, int s){"
    first = True
    for rule in frules.split(','):
        if ':' in rule:
            # conditional
            if first:
                func += "if(" + rule.split(':')[0] + "){return " + rule.split(':')[1] + "(x,m,a,s);}"
                first = False
            else:
                func += "else if(" + rule.split(':')[0] + "){return " + rule.split(':')[1] + "(x,m,a,s);}"
            c = rule.split(':')[0][0]
            print(c)
            if c == 'x':
                numsx.append(int(rule.split(':')[0][2:]))
            if c == 's':
                numss.append(int(rule.split(':')[0][2:]))
            if c == 'm':
                numsm.append(int(rule.split(':')[0][2:]))
            if c == 'a':
                numsa.append(int(rule.split(':')[0][2:]))



        else:
            # function call
            func += "return " + rule + "(x, m, a, s);"
    func += "}"
    print(func)
    functions.append(func)
    print()
for func in functions:
    print(func.split('{')[0] + ";")

print(numsx)
print(numsm)
print(numsa)
print(numss)
