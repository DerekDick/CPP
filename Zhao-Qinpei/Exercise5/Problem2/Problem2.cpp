/*
This program is used to display the algorithms of the encryption and decryption of Caesar cipher
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "caesar.h"

using namespace std;

int main(int argc, char* argv[]) {
	//The plain text
	string plainText1 = "This is plain text";
	cout << "##The plain text1## : " << endl << plainText1 << endl;

	//Encryption
	string cipher1;
	encode(cipher1, plainText1, 5);
	cout << "##The Caesar cipher1## : " << endl << cipher1 << endl;

	cout << "-------------------------------" << endl;

	//The Caesar cipher
	string cipher2 = cipher1;
	cout << "##The Caesar cipher2## : " << endl << cipher2 << endl;

	//Decryption
	string plainText2;
	decode(plainText2, cipher2, 5);
	cout << "##The plain text2## : " << endl << plainText2 << endl;

	cout << "-------------------------------" << endl;

	//Decryption "sxccohv duh ixq"
	string cipher = "sxccohv duh ixq";
	cout << "##cipher## : " << cipher << endl;
	string plainText;
	for (int i = 1; i < 26; i++) {
		decode(plainText, cipher, i);
		cout << "N = " << i << " : " << plainText << endl;
	}

	cout << "----------------------------------" << endl;

	//A long plain text
	string longPlainText = "I stand here today humbled by the task before us, "
		"grateful for the trust you have bestowed, "
		"mindful of the sacrifices borne by our ancestors. "
		"I thank President Bush for his service to our nation, "
		"as well as the generosity and cooperation he has shown throughout this transition.";
	cout << "##The plain text## : " << endl << longPlainText << endl;
	
	//Encrypt the long plain text with a random Key
	srand(time(0));
	int randKey = rand() % 25 + 1;
	string longCipher;
	encode(longCipher, longPlainText, randKey);
	cout << "##The cipher## : " << endl << longCipher << endl;

	//Decrypt the cipher without knowing the key
	int key = getKey(longCipher);
	string result;
	cout << "key = " << key << endl;
	cout << "##The decoded result## : " << endl << decode(result, longCipher, key) << endl;

	//Dealing with files
	ifstream plainfile("plaintext.txt");
	ofstream outfile1("cipher.txt");
	encrypt(outfile1, plainfile, rand() % 25 + 1);
	outfile1.close();
	ofstream outfile2("decryption_result.txt");
	ifstream cipherfile("cipher.txt");
	decrypt(outfile2, cipherfile);

	return 0;
}
