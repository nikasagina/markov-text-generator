#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void openFile(ifstream& infile);
unordered_map<string, vector<char> > readStats(ifstream& infile, int k);
string generateText(unordered_map<string, vector<char> > statistics);

int main() {
	srand(time(NULL));
	ifstream infile;
	openFile(infile);
	cout<<"Enter k (1-10 integer): ";
	int k;
	cin>>k;

	cout<<"processing..."<<endl;
	unordered_map<string,vector<char> > stats = readStats(infile,k);

	cout<<"generating..."<<endl;
	string text = generateText(stats);

	cout<<text<<endl;

    return 0;
}

// asks user for proper file and opens it
void openFile(ifstream& infile){
	string fileName;
	while(true){
		cout<<"Enter file path: ";
		cin>>fileName;

		infile.open(fileName.c_str());
		if(!infile.fail())
			break;
		infile.clear();
		cout<<"coultn't locate file. Try again."<<endl;
	}
}

// reads file and outputs Map with statistics in it
unordered_map<string, vector<char> > readStats(ifstream& infile, int k){
	unordered_map<string,vector<char> > statistics; // key - chunk, val - vector of characters after the chunk
	char nextChar;
	string sequence;

	// read first k number of chars
	for(int i = 0; i < k; i ++){
		sequence += infile.get();
	}

	// add sequence to the key and add next char to the value vector of sequence
	// remove first char from chunk and add next char every iteration

	while(true){
		nextChar = infile.get();
		if(nextChar == EOF) break;
		
		// create empty vector for sequence if non-existant
		if(statistics.find(sequence) == statistics.end()){
			vector<char> emptyVector;
			statistics[sequence] = emptyVector;
		}

		// add next char to the value of sequence
		vector<char> temp = statistics[sequence];
		temp.push_back(nextChar);
		statistics[sequence] = temp;
		
		sequence = sequence.substr(1,sequence.length()-1);
		sequence += nextChar;
	}
	return statistics;
}

// returns generated text 
string generateText(unordered_map<string, vector<char> > statistics){
	string text;

	// find largest sequence
	vector<char> largestValues;
	string largestSequence;
	for(auto& it: statistics){
		if(statistics[it.first].size() > largestValues.size()){
			largestValues = statistics[it.first];
			largestSequence = it.first;
		}
	}

	// add largest sequence to the text
	text+=largestSequence;


	string lastSequence = largestSequence;
	while(text.length() < 2000 ){
		// if no chars to chose from (the end of the file), stop
		if(statistics[lastSequence].size() == 0) break;

		// generate next character
		int randomIndex =  rand() % statistics[lastSequence].size();
		char nextCh = statistics[lastSequence][randomIndex];

		lastSequence = lastSequence.substr(1,lastSequence.length()-1);
		lastSequence +=nextCh;

		text+=nextCh;
	}
	return text;
}

