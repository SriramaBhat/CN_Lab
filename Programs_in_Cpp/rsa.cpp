// C++ Program to implement RSA Algorithm
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    int rem;
    while(b!=0) {
        rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}

int main() {
    double p, q;
    cout << "Enter two prime numbers: " << endl;
    cin >> p >> q;
    double n = p*q;
    double phi = (p-1)*(q-1);
    double e = 2;
    while (e < phi) {
        if(gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    double d1 = 1/e;
    double d = fmod(d1, phi);
    double msg;
    cout << "Enter the number to be transmitted:" << endl;
    cin >> msg;
    cout << "Messge before encryption: " << msg << endl;
    double c = pow(msg, e);
    double m = pow(c, d);
    c = fmod(c, n);
    cout << "Message after encryption: " << c << endl;
    m = fmod(m, n);
    cout << "Message after decryption: " << m <<endl;
    return 0;
}