/************************************************************************
 * File: Form.cpp
 * Author: 楊鈞安
 * Create Date: 2023-04-13
 * Editor: 楊鈞安
 * Update Date:2023-04-13
 * Description: Form Word Game
 ************************************************************************/
#include "Form.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

//input word
string word;
//file word
string file;
//output words
vector<string> words;
//Intent:set input word 
//Pre:input string
//Post:set input word inputWod to word
void Form::SetInputWord(string inputWord)
{
	word = inputWord;
}
//Intent:convert input word to tolower
//Pre:need input word word
//Post:convert input word to tolower
void Form::ProcessInputWord()
{
	transform(word.begin(), word.end(), word.begin(), tolower);
}
//Intent:set the open file name to fileName
//Pre:need string fileName
//Post:file = fileName
void Form::SetFileName(string fileName)
{
	file = fileName;
}
//Intent:compare word if the file word is input word converted save file word
//Pre:open the file and get the line string
//Post:save the file word
void Form::Load_CompareWord()
{	
	//open the file
	ifstream input(file);
	string line;
	int wordTimes[26] = { 0 };
	//save the word times
	for (int i = 0; i < word.size(); i++)
	{
		wordTimes[word[i]-'a']++;
	}
	while (getline(input, line))
	{	
		bool valid = true;
		int lineTimes[26] = { 0 };
		//save word times
		for (int i = 0; i < line.size(); i++)
		{
			lineTimes[line[i]-'a']++;
		}
		//if lineTImes >wordTimes 代表不是由輸入組成，valid is false
		for (int i = 0; i < line.size(); i++)
		{
			if (lineTimes[line[i] - 'a'] > wordTimes[line[i] - 'a'] )
			{	
				valid = false;
				break;
			}
		}
		//if valid is true save word to words
		if (valid)words.push_back(line);
	}
}
//Intent:print the words
//Pre:need words
//Post:print the words
void Form::PrintFoundWords()
{
	for (auto &w : words)
	{
		cout << w << endl;
	}
}