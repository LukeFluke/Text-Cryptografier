#include <iostream>
#include <string>

using namespace std;

void encode(string);
void decode(string);

int main() {
	string input;
	bool validInput = false;
	while (!validInput) {
		cout << "Encode(1) or Decode(2)?: ";
		cin >> input;
		if (input.size() == 1) {
			if (input == "1" || input == "2")
				validInput = true;
		}
		else
			cout << "Invalid Input" << endl;
	}
	string inputText;
	cout << "What's your text?: ";
	cin.ignore();
	getline(cin, inputText);
	//Encode
	if (input == "1")
	{
		cout << "Encoding text..." << endl;
		encode(inputText);
	}
	//Decode
	if (input == "2")
	{
		cout << "Decoding text...";
		decode(inputText);
	}
	cout << endl;
	system("pause");
}

const string b64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encode(string text) {
	string result = "";
	string padding = "";
	int pad_count = text.size() % 3;

	if (pad_count > 0) {
		while(pad_count < 3) {
			padding += '=';
			text += '\0';
			pad_count++;
		}
	}

	for (int i = 0; i < text.size(); i += 3) {

		if (i > 0 && (i / 3 * 4) % 76 == 0) {
			result += "\r\n";
		}

		int num = (text[i] << 16) + (text[i + 1] << 8) + (text[i + 2]);

		int num1 = (num >> 18) & 63;
		int num2 = (num >> 12) & 63;
		int num3 = (num >> 6) & 63;
		int num4 = num & 63;

		result += b64chars[num1];
		result += b64chars[num2];
		result += b64chars[num3];
		result += b64chars[num4];
	}
	result = result.substr(0, result.size() - padding.size());
	result += padding;

	cout << "Your encoded string is:\n";
	cout << result;
}

void decode(string text) {

}