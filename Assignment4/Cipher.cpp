#include "Cipher.h"
#include <iostream>
Cipher::Cipher() : Pointer_Dll(nullptr) {}

Cipher::~Cipher()
{
	unloadLibrary();
}

bool Cipher::loadLibrary()
{
	std::string dllPath = "D:\\ProgrammingProjects\\VisualStudioProjects\\Principlces_and_Paradigms\\Assignment3\\x64\\Debug\\Cipher.dll";
	Pointer_Dll = LoadLibraryA(dllPath.c_str());


	if (!Pointer_Dll) {
		std::cout << "Failed to load DLL: " << dllPath << std::endl;
		return false;
	}

	
	cipher_create_caesar   = (CreateCaesarFunc)GetProcAddress(Pointer_Dll, "cipher_create_caesar");
    cipher_create_vigenere = (CreateVigenereFunc)GetProcAddress(Pointer_Dll, "cipher_create_vigenere");
    cipher_encrypt         = (EncryptFunc)GetProcAddress(Pointer_Dll, "cipher_encrypt");
    cipher_decrypt         = (DecryptFunc)GetProcAddress(Pointer_Dll, "cipher_decrypt");
    cipher_destroy         = (DestroyFunc)GetProcAddress(Pointer_Dll, "cipher_destroy");
    cipher_free            = (FreeFunc)GetProcAddress(Pointer_Dll, "cipher_free");



	std::cout << "DLL loaded successfully!\n";
	return true;
}

void Cipher::unloadLibrary() {
	if (Pointer_Dll) {
		FreeLibrary(Pointer_Dll); 
		Pointer_Dll = nullptr;
		cipher_create_caesar = nullptr;
		cipher_create_vigenere = nullptr;
		cipher_encrypt = nullptr;
		cipher_decrypt = nullptr;
		cipher_destroy = nullptr;
		cipher_free = nullptr;
		std::cout << "DLL unloaded.\n";
	}
}

std::string Cipher::Encrypt(const std::string& text) 
{
	int choice;
	std::cout << "Enter encryption choice: (1- Caesar, 2- Vigenere)\n>";
	std::cin >> choice;
	switch (choice)
	{
		case 1:
		{
			int key;
			std::cout << "Enter key:\n>";
			std::cin >> key;
			void* myCipher = cipher_create_caesar(key);
			const char* result = cipher_encrypt(myCipher, text.c_str());
			std::string encryptedString(result);

			if (cipher_free) {
				cipher_free(result);    
			}
			if (cipher_destroy) {
				cipher_destroy(myCipher);  
			}
			return encryptedString;
		}
		case 2:
		{
			std::cin.ignore();
			std::string key;
			std::cout << "Enter key:\n>";
			std::getline(std::cin, key);
			void* myCipher = cipher_create_vigenere(key.c_str());
			const char* result = cipher_encrypt(myCipher, text.c_str());
			std::string encryptedString(result);

			if (cipher_free) {
				cipher_free(result);
			}
			if (cipher_destroy) {
				cipher_destroy(myCipher);
			}
			return encryptedString;
		}
		default:
			std::cout << "Could not encrypt\n";
			return text;
			break;
	}
	
	
	
}

std::string Cipher::Decrypt(const std::string& text) 
{
	int choice;
	std::cout << "Enter decryption choice: (1- Caesar, 2- Vigenere)\n>";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		int key;
		std::cout << "Enter key:\n>";
		std::cin >> key;
		void* myCipher = cipher_create_caesar(key);
		const char* result = cipher_decrypt(myCipher, text.c_str());
		std::string decryptedString = result;


		if (cipher_free) {
			cipher_free(result);
		}
		if (cipher_destroy) {
			cipher_destroy(myCipher);
		}
		
		return decryptedString;
	}
	case 2:
	{

		std::cin.ignore();
		std::string key;
		std::cout << "Enter key:\n>";
		std::getline(std::cin, key);
		void* myCipher = cipher_create_vigenere(key.c_str());
		const char* result = cipher_decrypt(myCipher, text.c_str());
		std::string decryptedString = result;

		if (cipher_free) {
			cipher_free(result);
		}
		if (cipher_destroy) {
			cipher_destroy(myCipher);
		}
		
		return decryptedString;
	}
	default:
		std::cout << "Could not decrypt\n";
		return text;
		break;
	}
}