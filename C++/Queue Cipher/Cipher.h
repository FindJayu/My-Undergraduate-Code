// Jack Carson
// CPSC 1070
// Project 3
// 25 October 2021

# ifndef CIPHER_H
# define CIPHER_H

/* Cipher class is the child class of Queue, and is also a 
composed class as it contains Queue objects cipher and decode. */
class Cipher : public Queue {
    private:
        Queue cipher; 
        Queue decode; 
        int cipherSize; 
    public:
/* Constructors for default cipher, and a specific cipher size.
Function definitions are also provided below */
        Cipher() {
            this->cipherSize = 0;
        }
        Cipher(int size) {
            this->cipherSize = size;
        };

        void getCipher();
        void setCipher(int, int[]);
        std::string encodeMessage(std::string);
        std::string decodeMessage(std::string);
};

# endif