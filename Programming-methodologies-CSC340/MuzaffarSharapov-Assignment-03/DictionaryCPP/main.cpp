#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include <list>
#include <ctype.h>
#include <cctype>

using namespace std;

class encapsulationT { //to store our dictioary's data, each keyword, part of speech, definition separately we use this data structure

private: //// to keep data both safe from outside interference and misuse we want to use private strings to have proper encapsulation thus we'll create class instead of struct to store data from Data.CS.SFSU.txt. Also struct is not secure and cannot hide its implementation details from the end-user while a class is secure and can hide its programming and designing details
    //string keyWord;
    vector<string> partOfSpeech;
    vector<string> valueDefinition;

public:
    encapsulationT() {

    }
    encapsulationT(const encapsulationT& original) {
        //keyWord = original.keyWord;
        partOfSpeech = original.partOfSpeech;
        valueDefinition = original.valueDefinition;
    }

    /*
    string getKeyWord() {
        return keyWord;
    }

    void setKeyWord(string StringName) {
        keyWord = StringName;
    }*/

    vector<string> getPartOfSpeech() {
        return partOfSpeech;
    }

    void setPartOfSpeech(vector<string> dataPOS) {
        partOfSpeech = dataPOS;
    }
    vector<string> getValueDefinition() {
        return valueDefinition;
    }

    void setValueDefinition(vector<string> value) {
        valueDefinition = value;
    }
};


map<string,encapsulationT> readDataFromTextFile(string data)
{

    //ifstream reader(data);//open relative path
    map<string,encapsulationT> source;
    size_t partOfSpeechIndexNumber = 0;
    string subString;
    string oneStringOfPOSAndDefAtCurrentKeyWord;
    string verticalSlash = "|";
    string afterPOSDelimiter = " -=>> ";
    string temptPartOfSpeech;
    string keyWordTemp1;
    string pos;
    bool newWordBool;;
    cout << "! Loading data..." << endl;
/*
    while (getline(reader, oneStringOfPOSAndDefAtCurrentKeyWord)) { // this iterates through every line in the text file and turns it into a string 'oneStringOfPOSAndDefAtCurrentKeyWord'
//        encapsulationT newEntry;
//        stringstream ss(oneStringOfPOSAndDefAtCurrentKeyWord);
//        getline(ss, keyWordTemp1, '|');
//
//       // newEntry.setKeyWord(keyWordTemp1);
        encapsulationT newEntry;
        newWordBool = true; // here we set true as we start from the new word, another line from text file
        while ((partOfSpeechIndexNumber = oneStringOfPOSAndDefAtCurrentKeyWord.find(verticalSlash)) != string::npos) { // while | has a position inside the string, do this
            subString = oneStringOfPOSAndDefAtCurrentKeyWord.substr(0, partOfSpeechIndexNumber);//temptPartOfSpeech + def
            cout << subString << endl;

            oneStringOfPOSAndDefAtCurrentKeyWord.erase(0, partOfSpeechIndexNumber + verticalSlash.length());//erase what we've already used
            if (newWordBool) { // check if new line from the text file
                newEntry.setKeyWord(subString);
                newWordBool = false; // set false to not come back here
            }
            else {
                newEntry.setValueDefinition(subString); // if the first word is true then we get all definition of the keyWord
            }
            if ((partOfSpeechIndexNumber = oneStringOfPOSAndDefAtCurrentKeyWord.find(afterPOSDelimiter)) != string::npos) {// we can find POS by finding positing index -=>> delimeter as part of temptPartOfSpeech is before delimter -=>>
                temptPartOfSpeech = oneStringOfPOSAndDefAtCurrentKeyWord.substr(0, partOfSpeechIndexNumber - 1);//to get speech word from oneString

                newEntry.setPartOfSpeech(temptPartOfSpeech); // set
                oneStringOfPOSAndDefAtCurrentKeyWord.erase(0, partOfSpeechIndexNumber + temptPartOfSpeech.length()); // to remove temptPartOfSpeech word from oneWordString then get to difintion
            }
        }
        //cout << newEntry.getKeyWord() << " " << newEntry.getPartOfSpeech() << endl;
        newEntry.setValueDefinition(oneStringOfPOSAndDefAtCurrentKeyWord);// set remainder Definition

        source.push_back(newEntry); // push to vector sourse
    }
*/
    ifstream file(data);
    string str;
    while (std::getline(file, str))
    {
        encapsulationT newEntry;
        int i=0;
        string keyword;
        vector<string> nonkeyword;
        size_t pos = 0;
        string token;
        while ((pos = str.find(verticalSlash)) != string::npos) {
            token = str.substr(0, pos);
            if(i == 0)
            {
                keyword = token;
            }
            else
            {
                nonkeyword.push_back(token);
            }
            str.erase(0, pos + verticalSlash.length());
            i++;
        }
        nonkeyword.push_back(str);
        vector<string> partOfSpeech, valueDefinition;
        //cout << keyword << endl;
        for(i=0;i<nonkeyword.size();i++)
        {
            str = nonkeyword.at(i);
            //cout << str << endl;
            pos = 0;
            token = "";
            if ((pos = str.find(afterPOSDelimiter)) != string::npos) {
                token = str.substr(0, pos);
                partOfSpeech.push_back(token);
                str.erase(0, pos + afterPOSDelimiter.length());
            }
            valueDefinition.push_back(str);
        }

        newEntry.setPartOfSpeech(partOfSpeech);
        newEntry.setValueDefinition(valueDefinition);
        source[keyword] = newEntry;
    }
    cout << "! Loading completed..." << endl;
    cout << "! Closing data file... " << data << "\n" << endl;
    file.close();
    //reader.close();// stop reading the text file
    return source;
}


void toShowHowTo() {
    cout << "       |\n" << "    PARAMETER HOW-TO, please enter:\n"
         << "       1. A search key - then 2. An optional part of partOfSpeech - then" << endl
         << "       3. An optional 'distinct' - then 4. An optional 'reverse'" << endl;
}

void toShowNotFound() {
    cout << "       <NOT FOUND> To be considered for the next release. Thank you." << endl
         << "       |" << endl;;
}

void toShowNotValid(int i,string word) {
    string str_i = "";
    if(i == 2)
        str_i = "2nd";
    else if(i == 3)
        str_i = "3rd";
    else if(i == 4)
        str_i = "4th";
    cout << "       |\n";
    if(i == 2)
        cout << "       <The entered "<< str_i <<" parameter \'"<< word << "\' is NOT a part of speech.>" << endl;
    if(i <= 3)
        cout << "       <The entered "<< str_i <<" parameter \'"<< word << "\' is NOT \'distinct\'.>" << endl;
    cout << "       <The entered "<< str_i <<" parameter \'"<< word << "\' is NOT \'reverse\'.>" << endl;
    cout << "       <The entered "<< str_i <<" parameter \'"<< word << "\' was disregarded.>" << endl;
    if(i == 2)
        cout << "       <The "<< str_i <<" parameter should be a part of speech or \'distinct\' or \'reverse\'.>" << endl;
    if(i == 3)
        cout << "       <The "<< str_i <<" parameter should be \'distinct\' or \'reverse\'.>" << endl;
    if(i == 4)
        cout << "       <The "<< str_i <<" parameter should be \'reverse\'.>" << endl;
}

string tolowerstring(string input) {
    string output = "";
    for(int i=0;i<input.size();i++)
    {
        output += tolower(input[i]);
    }
    return output;
}

string tocapital(string input) {
    if(tolowerstring(input) == "csc220")
    {
        return "CSC220";
    }
    else if(tolowerstring(input) == "csc340")
    {
        return "CSC340";
    }
    else
    {
        string output = "";
        output += toupper(input[0]);
        for(int i=1;i<input.size();i++)
        {
            output += input[i];
        }
        return output;
    }
}

vector<string> toSplitInputIfMultWords() { //
    /*
    vector<string> separateInputVectorString;
    string tempString;
    for (auto &ch : input) {
        if (ch == ' ') {
            cout << tempString << endl;
            separateInputVectorString.push_back(tempString);
            tempString.clear();
        } else {
            tempString = tempString + ch;
        }
    }
    separateInputVectorString.push_back(tempString);
    return separateInputVectorString;
    */
    string s;
    vector<string> words;
    getline(cin, s);
    string delimiter = " ";

    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        words.push_back(tolowerstring(token));
        s.erase(0, pos + delimiter.length());
    }
    if(s != "")
        words.push_back(tolowerstring(s));
    return words;
}


int main()
{

    string relativePath = "./Data.CS.SFSU.txt"; // string that is what we want the user to input
    cout << "! Opening data file... " << relativePath;
    try {
        //open absolute path
        ifstream reader(relativePath); //syntax: ifStream keyWord(string). it reads the string on the inside to see if it is a valid data file to read, which it then opens

    }
    catch (...) {
        cout << "Error caught"<< endl;
    }

    bool fileOpen = false;
    map<string,encapsulationT> source;
    int total_definition = 0;
    while (!fileOpen) {
        try {
            source = readDataFromTextFile(relativePath);
            map<string, encapsulationT>::iterator it;
            for (it = source.begin(); it != source.end(); it++)
            {
                total_definition += it->second.getPartOfSpeech().size();
            }
            fileOpen = true;
        }
        catch (...) {
            cout << "Could not find the path to .txt file directory" << endl;
        }
    }

    /*multimap<string, encapsulationT> keyWordDictionaryMultiMap;
    multimap<string, encapsulationT>::iterator mutiMapIterator;
    int numDefinitions = 0;
    string temp;
    for (vector<encapsulationT> ::iterator it = source.begin(); it != source.end(); it++) { // loops through sourse until end
        encapsulationT current = *it;//// IMPORTANT: CURRENT equal to value pointed to by IT
        numDefinitions += current.getValueDefinition().size(); // increment numDefitnions size
        keyWordDictionaryMultiMap.emplace(current.getKeyWord(), current); // we use emplace because it takes the arguments necessary to construct an object in place istead of insert
    }*/

    cout << "====== DICTIONARY 340 C++ ====="
         << "\n------Keywords: " << source.size()
         << "\n------Definitions: " << total_definition << "\n" << endl;

    int searchCount = 1; // to track how many times we searched
    bool distinctBool;
    bool reverseBool;
    string out;
    list<string> listString;

    while (true) {
        string input;
        distinctBool = false;
        reverseBool = false;
        string partOfSpeech = "";
        cout << "Search [" << searchCount << "]: ";
        //getline(cin, input);
        //for (size_t i = 0; i < input.size(); i++) { // loop through input
        //    input[i] = tolower(input[i]);//make lowercase
        //}
        vector<string> inputVector = toSplitInputIfMultWords(); //if there are more that two words then split and saved in vectors
        searchCount++; // To show search[number]
        string searchInput;
        if (inputVector.empty()) {//enter key edge case
            searchInput = "!help";
        }
        else {
            searchInput = inputVector[0];
        }
        if (searchInput == "!q" || searchInput == "quit") {//exit
            cout << "-----THANK YOU-----" << endl;
            exit(0);
        }
        if (inputVector.size() > 4) {
            toShowHowTo();
            cout << "       |" << endl;
            continue;
        }
        if (searchInput == "!help") {
            toShowHowTo();
            cout << "       |" << endl;
            continue;
        }
        for(int i=1;i<inputVector.size();i++)
        {
            bool isInputValid = false;
            if(i <= 2)
            {
                if (inputVector.at(i) == "distinct") {
                    distinctBool = !distinctBool;
                    isInputValid = true;
                }
            }

            if (inputVector.at(i) == "reverse") {
                reverseBool = !reverseBool;
                isInputValid = true;
            }

            if(i == 1)
            {
                if (inputVector.at(i).compare("noun") == 0 || inputVector.at(i).compare("adjective") == 0 || inputVector.at(i).compare("adverb") == 0 || inputVector.at(i).compare("pronoun") == 0 || inputVector.at(i).compare("preposition") == 0 || inputVector.at(i).compare("conjunction") == 0 || inputVector.at(i).compare("interjection") == 0) {
                    partOfSpeech = inputVector.at(1);
                    isInputValid = true;
                }
            }

            if(!isInputValid)
            {
                toShowNotValid(i+1,inputVector.at(i));
                cout << "       |" << endl;
            }
        }

        cout << "       |" << endl;
        //here we make a pair of multimap
        /*pair<multimap<string, encapsulationT>::iterator, multimap<string, encapsulationT>::iterator> range = keyWordDictionaryMultiMap.equal_range(searchInput); //to find matching the searchInput
        for (mutiMapIterator = range.first; mutiMapIterator != range.second; ++mutiMapIterator) {
            string mapKey = mutiMapIterator->first;
            for (size_t i = 0; i < mutiMapIterator->second.getValueDefinition().size(); i++) { // loop through as many times as the size of getValueDefintion
                out = "    " + tocapital(searchInput) + " [" + mutiMapIterator->second.getPartOfSpeech() + "] : " + mutiMapIterator->second.getValueDefinition()[i]; // getPartOfSpeech is always noun
                listString.push_back(out); // to include the formatted sentence to list
            }
        }*/
        if(source.find(searchInput) != source.end())
        {
            encapsulationT encap = source[searchInput];
            for (int i = 0;i < encap.getPartOfSpeech().size(); i++)
            {
                if(partOfSpeech.compare("") == 0 || partOfSpeech.compare(encap.getPartOfSpeech()[i]) == 0)
                {
                    out = "        " + tocapital(searchInput) + " [" + encap.getPartOfSpeech()[i] + "] : " + tocapital(encap.getValueDefinition()[i]);
                    listString.push_back(out);
                }
            }
        }
        if(listString.size() == 0)
        {
            toShowNotFound();
            toShowHowTo();
            cout << "       |" << endl;
            continue;
        }

        listString.sort(); // here we sort the list

        if (distinctBool) { // if distinct bool true
            listString.unique(); // then remove duplicates
        }
        if (reverseBool) { // if reverse is true
            listString.reverse(); // reverse func loops through the list ,inside the loop it swaps it create two pointer next and
        }

//        if (!partOfSpeech.empty()) { // if there is POP in the search then check if partOfSpeech contains in the front list if yes then pop
//            while (!listString.empty()) {
//                if (listString.front().find(partOfSpeech)) {
//                    cout << listString.front() << endl;
//                }
//                listString.pop_front();
//            }
//
//            cout << "    |" << endl;
//            continue;
//        }

        while (!listString.empty()) { // loop through list until we pop all of it
            cout << listString.front() << endl; // here we print out our list of result
            listString.pop_front(); // here we remove front one at a time
        }
        cout << "       |" << endl;
    }

}
