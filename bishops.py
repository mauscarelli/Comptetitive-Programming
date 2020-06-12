from sys import stdin

for line in stdin:
    if line == '':
        break
    n = int(line)
    if n == 1:
        print('1')
    else:
        print(2*(n-1))