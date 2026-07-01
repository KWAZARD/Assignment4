#pragma once
#include <string>
#include <windows.h> 

class Cipher {
private:
    HMODULE Pointer_Dll; 

    typedef const char* (*CipherFunc)(const char*, int);

    

    typedef void* (*CreateCaesarFunc)(int key);
    typedef void* (*CreateVigenereFunc)(const char* key);
    typedef const char* (*EncryptFunc)(void* cipherInstance, const char* text);
    typedef const char* (*DecryptFunc)(void* cipherInstance, const char* text);
    typedef void (*DestroyFunc)(void* cipherInstance);
    typedef void (*FreeFunc)(const char* text);

    
    CreateCaesarFunc   cipher_create_caesar = nullptr;
    CreateVigenereFunc cipher_create_vigenere = nullptr;
    EncryptFunc        cipher_encrypt = nullptr;
    DecryptFunc        cipher_decrypt = nullptr;
    DestroyFunc        cipher_destroy = nullptr;
    FreeFunc           cipher_free = nullptr;

public:
    Cipher();
    ~Cipher();

    bool loadLibrary();
    void unloadLibrary();

    std::string Encrypt(const std::string& text);
    std::string Decrypt(const std::string& text);
};
