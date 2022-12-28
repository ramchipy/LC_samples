from datetime import datetime
import math

def number_of_primes_less_than_brute_force(n):
    count = 0
    for i in range(2, n):
        is_prime = True
        for j in range(2, ((i)//2)+1):
            if (i%j) == 0:
                is_prime = False
                break
        if is_prime:
            count += 1
    return count

def number_of_primes_less_than_1(n):
    if n < 2:
        return 0
    count = 0
    primes = []    
    for i in range(2, n):
        is_prime = True
        for p in primes:
            if (i % p) == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(i)
            count += 1
        else:
            pass
            #print("{} is not prime {}".format(i, primes))  
    return count

def number_of_primes_less_than_2(n):
    if n < 2:
        return 0
    isPrime = [True]*n
    count = n-2
    for i in range(2, int(math.sqrt(n)+1)):
        if isPrime[i]:
            for k in range(i*i, n, i):
                if isPrime[k]:
                    count -= 1
                    isPrime[k] = False
    return count



for n in [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072]:    
    start = datetime.now()
    count = number_of_primes_less_than_1(n)
    #print("There are {} prime numbers less than {}".format(number_of_primes_less_than_1(n), n))    
    print("Optimal1    {:6}:{:6} finished in {:.6f} seconds".format(n, count, (datetime.now()-start).total_seconds()))

    start = datetime.now()
    #print("There are {} prime numbers less than {}".format(number_of_primes_less_than_brute_force(n), n))
    count = number_of_primes_less_than_brute_force(n)
    print("Brute force {:6}:{:6} finished in {:.6f} seconds".format(n, count, (datetime.now()-start).total_seconds()))

    start = datetime.now()
    #print("There are {} prime numbers less than {}".format(number_of_primes_less_than_brute_force(n), n))
    count = number_of_primes_less_than_2(n)
    print("Optimal2    {:6}:{:6} finished in {:.6f} seconds".format(n, count, (datetime.now()-start).total_seconds()))
    print("======================================================")
    