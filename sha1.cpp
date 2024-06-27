/////////////// SHA-1 ///////////////

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int a, b, c, d, e;
int h0, h1, h2, h3, h4;

/////////////////   found in internet
vector<int> X;//8*64=512, each subscript stores 8 bits
int W[80];
int Turn; // number of encrypted packets

int leftRotate(unsigned int x, int n) {
    return x >> (32 - n) | (x << n);
}

void append(string m) {
    Turn = (m.size() + 8) / 64 + 1;
    X.resize(Turn * 64);
    int i = 0;
    for (; i < m.size(); i++) {
        X[i] = m[i];
    }
    X[i++] = 0x80;
    while (i < X.size() - 8) {
        X[i] = 0;
        i++;
    }
    long long int a = m.size() * 8;
    for (i = X.size() - 1; i >= X.size() - 8; i--) {
        X[i] = a % 256;
        a /= 256;
    }
}
/////////////////

void sha1(string text) {

    h0 = a = 0x67452301;
    h1 = b = 0xEFCDAB89;
    h2 = c = 0x98BADCFE;
    h3 = d = 0x10325476;
    h4 = e = 0xc3D2E1F0;

    int f, k;

    append(text);

    for (int i = 0; i < Turn; i++) {
       
        /////////////////   found in internet
        int n = i * 64;
        for (int i = 0; i < 16; i++) {
            W[i] = (X[n + 4 * i] << 24) + (X[n + 4 * i + 1] << 16)
                + (X[n + 4 * i + 2] << 8) + X[n + 4 * i + 3];
        }
        for (int i = 16; i < 80; i++) {
            W[i] = leftRotate(W[i - 16] ^ W[i - 14] ^ W[i - 8] ^ W[i - 3], 1);
        }
        /////////////////

        for (int i = 0; i < 80; i++) {

            if (i < 20) {
                f = (b & c) | ((~b) & d);
                k = 0x5A827999;
            }
            else if (i < 40) {
                f = b xor c xor d;
                k = 0x6ED9EBA1;
            }
            else if (i < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            }
            else {
                f = b xor c xor d;
                k = 0xCA62C1D6;
            }

            int temp = leftRotate(a, 5) + f + e + k + W[i];
            e = d;
            d = c;
            c = leftRotate(b, 30);
            b = a;
            a = temp;
        }

        h0 = h0 + a;
        h1 = h1 + b;
        h2 = h2 + c;
        h3 = h3 + d;
        h4 = h4 + e;
    }

    printf("%x%x%x%x%x\n\n", h0, h1, h2, h3, h4);
}

int main() {

    string text;

    while (true) {
        cout << "Enter text: ";
        cin >> text;
        sha1(text);
    }

    return 0;
}
