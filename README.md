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
- ### Vigenère Cipher
  - Encryption: It's the same as the shift cipher, but instead of providing a int key, we receive a string key, where the character of our keyword is gonna shift n times to the right, being n the position of the character of the key in the same position of our keyword their position in the alphabet.
  - Decryption: It's the same as the shift cipher, but instead of providing a int key, we receive a string key, where the character of our keyword is gonna shift n times to the left, being n the position of the character of the key in the same position of our keyword their position in the alphabet.
- ### Permutation Cipher
  - Encryption: The key gives where the letter is going to be at the result of our cipher
  - Decryption: It returns the letter to the original position from the plain text
- ### Transposition CIPHER
  - Encryption: You put the keyword inside a matrix, where the key is the number of columns and the rows are how many times does the key can fit inside the string.
  - Decryption: Its the same but this time the key is the number of rows. 
