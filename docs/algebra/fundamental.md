# Fundamentals

## **Binary exponentiation**
How to calculate $a^n$ using only $O(log n)$ multiplications instead of $O(n)$ ?

we have: $a^{b+c} = a^b \cdot a^c$ and $a^{2b} = a^b \cdot a^b = (a^b)^2 $. For $n = 14$, we have $a^{13} = a^{1101_2} = a^8 \cdot a^4 \cdot a^1 $. 

Notice that the number n has exactly $\lfloor log_2 n \rfloor$ + 1 digits in base 2, we only need to perform $O(log n)$ multiplications if we know the powers $a^1, a^2, a^4, a^8, ..., a^{2\lfloor log n \rfloor}$.

since an element in the sequence is just the square of the previous element, it is very easy to compute those.

Implementation:

```cpp
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
```

## **Problems**

1. **Computer $x^n$ mod $m$ .**

    the modulo operator doesn't interfere with multiplications ( $a \cdot b \bmod m \equiv (a \bmod m) \cdot (b \bmod m) \pmod m$ ), we can directly use the same code, and just replace every multiplication with a modular multiplication.

    **proof**:

    - $a (\bmod n) \equiv \bar{a} \iff a = np + \bar{a}$
    - $b (\bmod n) \equiv \bar{b} \iff b = nq + \bar{b}$
    - $ab = n(npq + q\bar{a} + p\bar{b}) + \bar{a} \bar{b} \Rightarrow ab = \bar{a} \bar{b} (\bmod n)$

    **code**:
```cpp
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
```

2. Computer $n$ - th Fibonacci number $F_n$ .

3. You are given a sequence of length  $n$ . Apply to it a given permutation  $k$  times .

4. Given  $n$  points  $p_i$ , apply  $m$  transformations to each of these points. Each transformation can be a shift, a scaling or a rotation around a given axis by a given angle. There is also a "loop" operation which applies a given list of transformations  $k$  times ("loop" operations can be nested). You should apply all transformations faster than  $O(n \cdot length)$ , where  $length$  is the total number of transformations to be applied (after unrolling "loop" operations).

5. Given a directed unweighted graph of  $n$  vertices, find the number of paths of length  $k$  from any vertex  $u$  to any other vertex  $v$ .

6. Multiply two numbers  $a$  and  $b$  modulo  $m$ .  $a$  and  $b$  fit in the built-in data types, but their product is too big to fit in a 64-bit integer. The idea is to compute  $a \cdot b \pmod m$  without using bignum arithmetics.

### Next Step

