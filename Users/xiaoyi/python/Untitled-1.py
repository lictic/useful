def prime(p):
    a=0
    if p==1:
        return False
    else:
        for i in range(2,p):
            if (p%i!=0):
                a=a+1
        if(a==p-2):
            return True
        else:
            return False
def PrimeSum(m,n):
    sum1=0
    for i in range(m,n+1):
        if prime(i)==1:
            sum1=sum1+i
    return sum1


m,n=input().split()
m=int(m)
n=int(n)
print(PrimeSum(m,n))