# Information security (TC-2027)
[![time tracker](https://wakatime.com/badge/github/angeltrevinov/Ciphers.svg)](https://wakatime.com/badge/github/angeltrevinov/Ciphers)
## Homework 05

In this homework, you will implement some classical ciphers. In all cases, assume that any symbol used in the plaintext/ciphertext that is not contained in the alphabet must be co- pied as it is, without any transformation. To implement these ciphers, feel free to use the programming language of your preference.
Please note that you are required to include your name and student ID, as comments, in all your source codes. Failing to do so may affect your grade.

- ### Shift Cipher
  - Encryption: It shifts each of the letters in the plain text n positions to         the right, n being the key provided, wrapping back around the first symbol when the shift reaches the last symbol in the alphabet provided
  - Decryption: It shifts each of the letters in the plain text n positions to the left, n being the key provided, wrapping back around the first symbol when the shift reaches the last symbol in the alphabet provided
- ### Substitution Cipher
  - Encryption: It changes the letters from the original alphabet to the same position of the cipher alphabet
  - Decryption: It Changes the letters from the cipher alphabet to the same position of the original alphabet
