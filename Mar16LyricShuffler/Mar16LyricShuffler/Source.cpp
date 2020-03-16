#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
int main() {

	srand(time(NULL));
	string lyric;
	vector<string>lyrics;
	vector<string>::iterator lyriter;
	cout << "enter the words of your favorite song: (Use OVER to quit)" << endl;
	while (lyric.compare("OVER") != 0) {
		getline(cin, lyric);
		if (lyric.compare("OVER") != 0) {
			lyrics.push_back(lyric);
		}
		else if (lyric.compare("OVER") == 0) {
			cout << "Alright, we're done here then." << endl;
		}
	}

	random_shuffle(lyrics.begin(), lyrics.end());
	for (lyriter = lyrics.begin(); lyriter != lyrics.end(); lyriter++) {
		cout << (*lyriter) << " ";
	}
}