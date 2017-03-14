T=int(input())

for t in xrange(T):
    A=raw_input().split(' ')
    size=0
    for i in xrange(int(A[0])):
        N=raw_input().split(' ')
        k=[]
        for n in xrange(len(N)):
            votes=N.count(str(a))
            k.append(votes)

        for i in xrange(len(k)):
            if(k[i]>=A[1] and int(N[i])!=i ):
                size=size+1
