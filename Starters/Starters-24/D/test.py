mi = 1e18;
for n in range (50000, 52000):
    prod = 1
    prime = True
    for i in range (1, int(n ** (1 / 2) + 1)):
        if n % i == 0:
            if i > 1:
                prime = False;
            prod *= i;
            prod *= n / i;
    if not prime:
        mi = min(mi, prod)
    print ("n = ", n, "prime = ", prime, "prod = ", prod)
print ("mi = ", mi)
