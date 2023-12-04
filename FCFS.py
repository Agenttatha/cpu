at = [0, 3, 4, 5, 5]
bt = [2, 4, 3, 3, 1]
l = []
n = len(at)
for i in range(n):
    l.append([at[i], i])
l.sort()
ct = [0]*n
tat = [0]*n
wt = [0]*n
ctime = 0
i = 0
while i < n:
    if at[l[i][1]] <= ctime:
        ctime += bt[l[i][1]]
        ct[i] = ctime
        tat[i] = ct[i] - at[l[i][1]]
        wt[i] = tat[i] - bt[l[i][1]]
        i += 1
    else:
        ctime += 1
print("Completion time: ", ct)
print("Avg Turn around time: ", sum(tat)/n)
print("Avg Waiting time: ", sum(wt)/n)