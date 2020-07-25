#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

#ifdef max
#define _TEMP_MACRO_ max
#undef max
#endif

ofstream lol;

struct Feck
{
	int x = 0;
	string link;
	string a = "y";
    string prompt = "Press enter to continue...";
};

void dumpsterfire() {

	if (remove("command.bat") != 0)
		perror("File not found :( ");
	else
		puts("File deleted very nice :) ");
}

void download (string link) {

	lol << "@echo off\nyoutube-dl.exe " << link << endl << "pause\nexit";
	lol.close();
	system("start command.bat");

}

void pause(string prompt) {
	cin.clear();

	if (cin.rdbuf()->in_avail())
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << prompt;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*template<typename T, typename P>
T erase_space(T beg, T end, P pred) {

	T dest = beg;
	for (T itr = beg; itr != end; ++itr)     //i need to fix this someday lol (deletes spaces)
		if (!pred(*itr))                       edit: just use classic cin to remove spaces
			*(dest++) = *itr;
	return dest;

}*/

#ifdef _Temp_MACRO_
#define max _TEMP_MACRO_
#undef _TEMP_MACRO_
#endif

int main() {
	Feck fuck;
	/*Feck *f;    use this if you want to use pointers
	f = &fuck;*/

	if (fuck.x == 0)
		dumpsterfire();

		while (fuck.a.compare("y") == 0) {
			lol.open("command.bat");
			cout << "1. Just download the vidya" << endl;
			cout << "2. if you want to download a playlist or smth" << endl;
			cout << "3. If you want it to be converted to mp3 lol" << endl;
			cout << "4. If you want to update youtube-dl.exe \n";
			cout << "Enter your choice: ";
			cin >> fuck.x;
			cin.ignore();
			switch (fuck.x) {

			case 1:
				cout << "Enter link pls: ";
				cin >> fuck.link;
				//fuck->link.erase(erase_space(fuck->link.begin(), fuck->link.end(), isspace), fuck->link.end());
				download(fuck.link);
				break;

			case 2:
				cout << "Enter playlist link: ";
				getline(cin, fuck.link);
				cin.ignore();
				fuck.link.insert(0, "--yes-playlist ");
				download(fuck.link);
				break;

			case 3:
				cout << "Enter link to be converted to mp3: ";
				getline(cin, fuck.link);
				cin.ignore();
				fuck.link.insert(0, "-x --audio-format mp3 --audio-quality 0 ");
				download(fuck.link);
				break;

			case 4:
			fuck.link = "-U";
			download(fuck.link);
			break;
			}

			pause(fuck.prompt);

			dumpsterfire();
			cout << "Wanna give it another go? - y - / - n -" << endl;
			cin >> fuck.a;
		}

		return 0;
}