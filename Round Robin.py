at = [5, 4, 3, 1, 2, 6]
bt = [5, 6, 7, 9, 2, 3]
qt = 3
n = len(at)
l = []
for i in range(n):
    l.append([at[i], i])
l.sort()
ctime = 0
ct = [0]*n
tat = [0]*n
wt = [0]*n
rt = [-1]*n
queue = []
rem = []
completed = 0
while completed < n:
    for i in range(len(l)):
        if l[i] and at[l[i][1]] <= ctime:
            queue.append([bt[l[i][1]], l[i][1]])
            l[i] = None
    if rem:
        queue.append(rem)
        rem = []
    if not queue:
        ctime += 1
        continue
    burst, pid = queue.pop(0)
    if rt[pid] == -1:
        rt[pid] = ctime
    if burst > qt:
        rem = [burst-qt, pid]
        ctime += qt
    else:
        ctime += burst
        completed += 1
        ct[pid] = ctime
        tat[pid] = ct[pid] - at[pid]
        wt[pid] = tat[pid] - bt[pid]
        rt[pid] -= at[pid]

print("completion time: ", ct)
print("Avg Turn around time: ", sum(tat)/n)
print("Avg Waiting time: ", sum(wt)/n)
print("Avg Response time: ", sum(rt)/n)
