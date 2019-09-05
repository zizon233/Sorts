def merge(li1, li2):
    li = []
    append = li.append
    i,j = 0,0
    t1, t2 = len(li1), len(li2)
    while 1:
        if i == t1 and j == t2:
            return li
        elif i==t1 or (j!=t2 and li1[i] > li2[j]):
            append(li2[j])
            j+=1
        else:
            append(li1[i])
            i+=1

def mergesort(start, end):
    global li
    if end-start == 1:
        return li[start:end]
    li1 = mergesort(start, (start+end)//2)
    li2 = mergesort((start+end)//2, end)
    li3 = merge(li1, li2)
    return li3