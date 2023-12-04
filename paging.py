from sys import maxsize
from random import randint

def FIFO(refString, n, l):
    print("FIFO algorithm:")
    page_Faults = 0
    Frames = [None for i in range(n)]
    frameIndex = 0
    
    for i in range(len(refString)):
        if refString[i] not in Frames:
            page_Faults += 1
            Frames[frameIndex] = refString[i]
            print("Frames:", str(Frames).ljust(l * 5), "|Miss-", refString[i])
            frameIndex = (frameIndex + 1) % n
        else:
            print("Frames:", str(Frames).ljust(l * 5), "|Hit-", refString[i])

    print("Number of Page Faults in FIFO algorithm:", page_Faults)

def LeastRecent(refString, n, l):
    print("LRU algorithm:")
    page_Faults = 0
    Frames = [None for i in range(n)]
    max_e = max(refString)
    visited = [0 for i in range(max_e + 1)]
    Frame_i = 0
    
    for i in range(len(refString)):
        if Frame_i < n:
            if refString[i] not in Frames:
                page_Faults += 1
                Frames[Frame_i] = refString[i]
                Frame_i += 1
                print("Frames:", str(Frames).ljust(l * 5), "|Miss-", refString[i])
            else:
                print("Frames:", str(Frames).ljust(l * 5), "|Hit-", refString[i])
        else:
            if refString[i] not in Frames:
                page_Faults += 1
                least_visited = 0
                min_ = visited[Frames[0]]
                
                for k in range(len(Frames)):
                    if visited[Frames[k]] < min_:
                        least_visited = k
                        min_ = visited[Frames[k]]
                
                Frames[least_visited] = refString[i]
                print("Frames:", str(Frames).ljust(l * 5), "|Miss-", refString[i])
            else:
                print("Frames:", str(Frames).ljust(l * 5), "|Hit-", refString[i])
                
            visited[refString[i]] = i

    print("Number of Page Faults in LRU algorithm:", page_Faults)

L = int(input("Please enter the length of reference string:"))
refString = [randint(0, 9) for i in range(L)]
n = int(input("Please enter the number of Frames:"))
print("References:", refString, '\n')

FIFO(refString, n, L)
print()
LeastRecent(refString, n, L)
