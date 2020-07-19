def mergeSort(s, l, r):
    if l>=r:
        return
    mid = (l+r)/2
    mergeSort(s, l, mid)
    mergeSort(s, mid+1, r)
    merge(s, l, mid, r)

def merge(s, l, mid, r):
    t = []
    i = l
    j = mid+1
    while i<=mid and j<=r:
        if s[i] < s[j]:
            t.append(s[i])
            i+=1
        else:
            t.append(s[j])
            j+=1
    while i<=mid:
        t.append(s[i])
        i+=1
    while j<=r:
        t.append(s[j])
        j+=1
    for i, x in enumerate(t):
        s[l+i] = x

if __name__=="__main__":
    s = [3,5,1,2,7,8,10,0]
    mergeSort(s, 0, len(s)-1)
    print s

    s = [9,8,7,6,5,4,3,2,1]
    mergeSort(s, 0, len(s)-1)
    print s
