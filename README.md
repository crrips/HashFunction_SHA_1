# SHA-1 Implementation

This repository contains a C++ implementation of the SHA-1 (Secure Hash Algorithm 1) algorithm.

## Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [SHA-1 Algorithm](#sha-1-algorithm)
- [References](#references)

## Introduction

SHA-1 is a cryptographic hash function that produces a 160-bit (20-byte) hash value known as the message digest. It is widely used in various security applications and protocols to ensure data integrity and authenticity.

This repository provides a simple implementation of the SHA-1 algorithm in C++. It includes the necessary functions to compute the SHA-1 hash for a given input string.

## Usage

To use this SHA-1 implementation, follow these steps:

1. Clone the repository or download the source code.
2. Compile the code using a C++ compiler, such as g++:
   ```sh
   g++ sha1.cpp -o sha1
   ```
3. Run the compiled executable:
   ```sh
   ./sha1
   ```
4. Enter the text for which you want to compute the SHA-1 hash.

The SHA-1 hash of the input text will be displayed in hexadecimal format.

## SHA-1 Algorithm

The SHA-1 algorithm consists of several steps, including message padding, processing blocks, and updating hash values. The provided code implements these steps to compute the SHA-1 hash for the given input.

For detailed information about the SHA-1 algorithm, refer to the [SHA-1 Algorithm Description](https://www.nist.gov/publications/secure-hash-standard) provided by NIST.

## References

- [NIST Secure Hash Standard (SHS)](https://www.nist.gov/publications/secure-hash-standard)
- [RFC 3174 - US Secure Hash Algorithm 1 (SHA-1)](https://datatracker.ietf.org/doc/html/rfc3174)
