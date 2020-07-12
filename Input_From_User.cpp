
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void Rabin_Karp(char Text[],char Patt []) {
	int len_Text = strlen(Text), len_Patt = strlen(Patt), counter1 = 0, counter2 = 0;
	int Value_for_Patt = 0;
	int Value_for_Text = 0;
	int value = 1;

	for (counter1 = 0; counter1 < len_Patt - 1; counter1++)
		value = (value * 26);
	for (counter1 = 0; counter1 < len_Patt; counter1++){
		Value_for_Patt = (26 * Value_for_Patt + Patt[counter1]);
		Value_for_Text = (26 * Value_for_Text + Text[counter1]);
	}
	for (counter1 = 0; counter1 <= len_Text - len_Patt; counter1++){
		if (Value_for_Patt == Value_for_Text){
			for (counter2 = 0; counter2 < len_Patt; counter2++){
				if (Text[counter1 + counter2] != Patt[counter2])
					break;
			}
			if (counter2 == len_Patt)
				cout << "Pattern found at index " << counter1 + 1 << endl;
		}
		if (counter1 < len_Text - len_Patt){
			Value_for_Text = (26 * (Value_for_Text - Text[counter1] * value) + Text[counter1 + len_Patt]);
			if (Value_for_Text < 0)
				Value_for_Text = (Value_for_Text + 13);
		}
	}
}

int main() {
	char Text1 [50];
	char Patt1 [50];
	cout << "Example 1 : "<<endl;
	cout << "Input Text : " << endl;
	cin >> Text1;
	cout << "Input Pattern : " << endl;
	cin >> Patt1;
	Rabin_Karp(Text1,Patt1);

	char Text2[50];
	char Patt2[50];
	cout << "Example 2 : " << endl;
	cout << "Input Text : " << endl;
	cin >> Text2;
	cout << "Input Pattern : " << endl;
	cin >> Patt2;
	Rabin_Karp(Text2, Patt2);

	char Text3[50];
	char Patt3[50];
	cout << "Example 3 : " << endl;
	cout << "Input Text : " << endl;
	cin >> Text3;
	cout << "Input Pattern : " << endl;
	cin >> Patt3;
	Rabin_Karp(Text3, Patt3);

	char Text4[50];
	char Patt4[50];
	cout << "Example 4 : " << endl;
	cout << "Input Text : " << endl;
	cin >> Text4;
	cout << "Input Pattern : " << endl;
	cin >> Patt4;
	Rabin_Karp(Text4, Patt4);

	char Text5[50];
	char Patt5[50];
	cout << "Example 5 : " << endl;
	cout << "Input Text : " << endl;
	cin >> Text5;
	cout << "Input Pattern : " << endl;
	cin >> Patt5;
	Rabin_Karp(Text5, Patt5);
	return 0;
}
