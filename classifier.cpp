#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <map>

using namespace std;

vector<string> message;
map <string , double> ham , spam;

int main() {
	ifstream myfile , training_file;
	string word, str;
	myfile.open("message.txt");
	while( myfile >>word ){
		message.push_back(word);
	}
	myfile.close();

	double ham_probab = 0, spam_probab = 0;

	training_file.open("both_probability.txt");
	double prob_ham , prob_spam;

	//training_file >> prob_ham >> prob_spam;

	while( training_file >> str ){
		string msg;
		double prob;
		training_file >> msg >> prob;
		if( str == "ham" )
			ham[msg] = prob;
		else
			spam[msg] = prob;
	}

	training_file.close();

	map<string, double> :: iterator it;
	for ( int i = 0 ; i < message.size() - 1 ; i ++ ) {
		string word1, word2, word3;
		word1 = message[i], word2 = message[i + 1];
		word3 = word1 + word2;

		it = spam.find(word1);
		if ( it != spam.end() ) {
			spam_probab += log10(it -> second);
		}

		it = spam.find(word3);
		if ( it != spam.end() ) {
			spam_probab += log10(it -> second);
		}

		it = ham.find(word1);
		if ( it != ham.end() ) {
			ham_probab += log10(it -> second);
		}

		it = ham.find(word3);
		if ( it != ham.end() ) {
			ham_probab += log10(it -> second);
		}
	}

	word = message[message.size() - 1];
	it = spam.find(word);
	if ( it != spam.end() )	{
		spam_probab += log10(it -> second);
	}

	it = ham.find(word);
	if ( it != ham.end() ) {
		ham_probab += log10(it -> second);
	}

	spam_probab += log10(0.86);
	ham_probab += log10(0.14);

	if ( spam_probab < ham_probab )	{
		cout << "SPAM DETECTED\n";
	}
	else{
		cout << "THE EMAIL IS A HAM\n";
	}
	return 0;
}
