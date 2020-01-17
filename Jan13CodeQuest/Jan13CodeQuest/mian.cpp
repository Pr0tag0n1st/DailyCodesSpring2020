#include <iostream>
#include <string>
using namespace std;

int main() {//start of main
	int trials = 0;//Number of test cases
	int Cipherkey = 0;//Space between encrypted and unencrypted number
	string Encryptedmessage = "qmbdfipmefs";//Message to be unencrypted
	string Unencryptedmessage = "placeholder";
	char Alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };//Holds the alphabet in an array
	char Replace1;
	char Replace2;
	cout << "Input trial number:" << endl;//Requests test case number
	cin >> trials;//Inputs test case number

	for (int t = 0; t < trials; t++) {//Loop based on test case number
//		Encryptedmessage.clear();//Clears the encrypted message
//		Unencryptedmessage.clear();//Clears the deciphered message
		cout << "Input Key number:" << endl;//Requests the cipher's key
		cin >> Cipherkey;//Inputs cipher's key
		cout << "Input Encrypted message:" << endl;//Requests encrypted message
		getline(cin, Encryptedmessage);//Inputs encrypted message
		getline(cin, Encryptedmessage);//For some reason needs another getline
		Unencryptedmessage = Encryptedmessage;

		cout << "Now to decipher:" << Encryptedmessage << endl;//Checks for encrypted message
		for (int i = 0; i != Encryptedmessage.size(); i++){
			cout << "Flag1" << endl;
			for (int j = 0; j < 26; j++) {//Searches each slot of the alphabet for each slot in the message
				if (Encryptedmessage[i] == Alphabet[j]) {//Checks each letter in the string and compares it to a letter in the alphabet
					if ((j - Cipherkey) < 0) { Cipherkey -= 26; }//Makes sure the cipher doesn't pass too far back beyond the alphabet
					Unencryptedmessage[i] = Alphabet[((j - Cipherkey) % 26)];//Should change the letter to a letter Cipherkey slots after itself
					cout << "Character changed" << endl;
				}
			}
		}
		cout << "The unencrypted message reads: " << Unencryptedmessage << endl;//Should print the unencrypted message
		Encryptedmessage.clear();
		Unencryptedmessage.clear();
	}
}
