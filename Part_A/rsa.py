import random
import math

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def find_coprime(phi):
    while True:
        e = random.randrange(2, phi)
        if gcd(e, phi) == 1:
            return e

def modular_exp(base, exponent, modulus):
    result = 1
    base %= modulus
    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % modulus
        exponent = exponent >> 1
        base = (base * base) % modulus
    return result

def find_private_key(e, phi):
    d = 0
    k = 1
    while True:
        d = (phi * k + 1) / e
        if d.is_integer():
            return int(d)
        k += 1

def rsa_encrypt(plaintext, e, n):
    ciphertext = []
    for symbol in plaintext:
        ciphertext.append(modular_exp(ord(symbol), e, n))
    return ciphertext

def rsa_decrypt(ciphertext, d, n):
    plaintext = []
    for symbol in ciphertext:
        plaintext.append(chr(modular_exp(symbol, d, n)))
    return ''.join(plaintext)

def main():
    p = 11
    q = 13
    n = p * q
    phi = (p - 1) * (q - 1)

    e = find_coprime(phi)
    d = find_private_key(e, phi)

    plaintext = input("Enter Plaintext: ")
    ciphertext = rsa_encrypt(plaintext, e, n)

    print(f'Plaintext: {plaintext}')
    print(f'Ciphertext: {ciphertext}')
    print(f'Decrypted message: {rsa_decrypt(ciphertext, d, n)}')

if __name__ == '__main__':
    main()