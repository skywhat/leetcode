#https://www.geeksforgeeks.org/counting-inversions/

def mergeSort(s, l, r):
    if l>=r:
        return 0
    cnt = 0
    mid = (l+r)/2
    cnt += mergeSort(s, l, mid)
    cnt += mergeSort(s, mid+1, r)
    cnt += merge(s, l, mid, r)
    return cnt

def merge(s, l, mid, r):
    t = []
    i = l
    j = mid+1
    cnt = 0
    while i<=mid and j<=r:
        if s[i] < s[j]:
            t.append(s[i])
            i+=1
        else:
            t.append(s[j])
            j+=1
            cnt += mid-i+1
    while i<=mid:
        t.append(s[i])
        i+=1
    while j<=r:
        t.append(s[j])
        j+=1
    for i, x in enumerate(t):
        s[l+i] = x
    return cnt

if __name__=="__main__":
    s = [1,20,6,4,5]
    cnt = mergeSort(s, 0, len(s)-1)
    print s
    print "inversion count: ", cnt

    s = [9,8,7,6,5,4,3,2,1]
    cnt = mergeSort(s, 0, len(s)-1)
    print s
    print "inversion count: ", cnt
