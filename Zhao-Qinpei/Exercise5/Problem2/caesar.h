/*caesar.h
*Several functions for encryption and decrytion by Caesar cipher
****************************************************************/
#ifndef CAESAR_H
#define CAESAR_H

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

string encode(string &cipher, string plainText, int key);
string decode(string &plainText, string cipher, int Key);
char shiftRight(char &c, int key);
char shiftLeft(char &c, int key);
void edcrypt(ofstream &outfile, ifstream &infile, int key);
void decrypt(ofstream &outfile, ifstream &infile);

string encode(string &cipher, string plainText, int key) {
	/*This function is used to encode a string plainText and store the cipher into string cipher*/
	cipher = plainText;
	int length = cipher.length();
	for (int i = 0; i < length; i++) {
		cipher[i] = shiftRight(cipher[i], key);
	}

	return cipher;
}

string decode(string &plainText, string cipher, int Key) {
	/*This function is used to decode a string cipher and store the plain text into string plainText*/
	plainText = cipher;
	int length = plainText.length();
	for (int i = 0; i < length; i++) {
		plainText[i] = shiftLeft(plainText[i], Key);
	}

	return plainText;
}

char shiftRight(char &c, int key) {
	/*This function is used to Shift a letter to Right by key letters*/
	if (isalpha(c)) {
		if (isupper(c)) {
			c += ((c > 'Z' - key) ? (key - 26) : key);
		}
		else {
			c += ((c > 'z' - key) ? (key - 26) : key);
		}
	}

	return c;
}

char shiftLeft(char &c, int key) {
	/*This function is used to Shift a letter to Left by key letters*/
	if (isalpha(c)) {
		if (isupper(c)) {
			c -= ((c < 'A' + key) ? (key - 26) : key);
		}
		else {
			c -= ((c < 'a' + key) ? (key - 26) : key);
		}
	}

	return c;
}

int getKey(string cipher) {
	/*This function is used to get the key of the Caesar cipher*/
	//Store the letter frequency in the map letterFre
	map<char, int> letterFre;
	char current;
	int length = cipher.length();
	for (int i = 0; i < length; i++) {
		current = cipher[i];
		if (isalpha(current)) {
			letterFre[tolower(current)]++; //All letters recorded in lowercase!
		}
	}

	//Calculate the value of key
	int key;
	vector<int> frequency;
	for (map<char, int>::iterator iter = letterFre.begin(); iter != letterFre.end(); iter++) {
		frequency.push_back(iter->second);
	}
	sort(frequency.begin(), frequency.end(), greater<int>());
	int greatest = frequency[0];
	for (map<char, int>::iterator iter = letterFre.begin(); iter != letterFre.end(); iter++) {
		if (iter->second == greatest) {
			key = ((iter->first >= 'e') ? (iter->first - 'e') : (iter->first + 26 - 'e'));
		}
	}

	return key;
}

void decrypt(ofstream &outfile, ifstream &infile) {
	/*This function is used to decrypt an ifstream encrypted by Caesar cipher*/
	string cipher;
	char c;
	int count = 0;
	while ((infile >> noskipws >> c) && (count < 100)) {
		cipher += c;
		count++;
	}
	int key = getKey(cipher);

	infile.seekg(0); //Rewind the infile
	while (infile >> noskipws >> c) {
		outfile << shiftLeft(c, key);
	}
	outfile.close();

	return;
}

void encrypt(ofstream &outfile, ifstream &infile, int key) {
	/*This function is used to encrypt an ifstream with key by Caesar cipher*/
	char c;
	while (infile >> noskipws >> c) {
		outfile << shiftRight(c, key);
	}
	outfile.close();

	return;
}

#endif
