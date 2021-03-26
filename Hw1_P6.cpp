/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 6
    We have received a secret message encoded with a Vigenere cipher (​wiki​). 
    We know that the key is 32 digits long and a brute force attack would take us a long time (​see here​). 
    We do not know any “tricks” how to break a Vigenere cipher, but we do know how it works. 
    Instead we are going to test random possible solutions and use a feature function to evaluate the possible solution. 
    We will collect solutions that pass a certain threshold and mutate those solutions with some low probability, 
    hopefully getting closer to the ‘true solution”. We will also use recombination (​see here​) , with some low 
    probability, continually increasing our threshold as we narrow in on a solution. 
    Create a program that does this, paying special attention to the data structure you wish to manage 
    your possible solutions.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// function that converts char to int values.
int convertChar(char a) 
{
    if (a == 'A' || a == 'a') return 0;
    if (a == 'B' || a == 'b') return 1;
    if (a == 'C' || a == 'c') return 2;
    if (a == 'D' || a == 'd') return 3;
    if (a == 'E' || a == 'e') return 4;
    if (a == 'F' || a == 'f') return 5;
    if (a == 'G' || a == 'g') return 6;
    if (a == 'H' || a == 'h') return 7;
    if (a == 'I' || a == 'i') return 8;
    if (a == 'J' || a == 'j') return 9;
    if (a == 'K' || a == 'k') return 10;
    if (a == 'L' || a == 'l') return 11;
    if (a == 'M' || a == 'm') return 12;
    if (a == 'N' || a == 'n') return 13;
    if (a == 'O' || a == 'o') return 14;
    if (a == 'P' || a == 'p') return 15;
    if (a == 'Q' || a == 'q') return 16;
    if (a == 'R' || a == 'r') return 17;
    if (a == 'S' || a == 's') return 18;
    if (a == 'T' || a == 't') return 19;
    if (a == 'U' || a == 'u') return 20;
    if (a == 'V' || a == 'v') return 21;
    if (a == 'W' || a == 'w') return 22;
    if (a == 'X' || a == 'x') return 23;
    if (a == 'Y' || a == 'y') return 24;
    if (a == 'Z' || a == 'z') return 25;
}

// function that converts int to char values
char convertInt(int a) 
{
    if (a == 0) return 'A';
    if (a == 1) return 'B';
    if (a == 2) return 'C';
    if (a == 3) return 'D';
    if (a == 4) return 'E';
    if (a == 5) return 'F';
    if (a == 6) return 'G';
    if (a == 7) return 'H';
    if (a == 8) return 'I';
    if (a == 9) return 'J';
    if (a == 10) return 'K';
    if (a == 11) return 'L';
    if (a == 12) return 'M';
    if (a == 13) return 'N';
    if (a == 14) return 'O';
    if (a == 15) return 'P';
    if (a == 16) return 'Q';
    if (a == 17) return 'R';
    if (a == 18) return 'S';
    if (a == 19) return 'T';
    if (a == 20) return 'U';
    if (a == 21) return 'V';
    if (a == 22) return 'W';
    if (a == 23) return 'X';
    if (a == 24) return 'Y';
    if (a == 25) return 'Z';
}

//Encode function that takes a text and key vectors of ints & shifts each text by key letter, mod 26
vector<int> Encode(vector<int> t, vector<int> k) 
{
    vector <int> tempVec;
    auto keyIt = k.begin();
    for (auto textIt = t.begin(); textIt != t.end(); ++textIt) 
    {
        tempVec.push_back((*textIt + *keyIt) % 26);
        ++keyIt;
        if (keyIt == k.end()) keyIt = k.begin();
    }
    return tempVec;
}

// Decode function that takes vector on ints and gets the difference of the key char from the text char, adds 26 if negative value
vector<int> Decode(vector<int> t, vector <int> k) 
{
    vector <int> tempVec;
    auto keyIt = k.begin();
    for (auto i = t.begin(); i != t.end(); ++i) 
    {
        if ((*i - *keyIt) >= 0) 
        {
            tempVec.push_back(*i - *keyIt);
        }
        else 
        {
            tempVec.push_back(26 + *i - *keyIt);
        }
        ++keyIt;
        if (keyIt == k.end()) keyIt = k.begin();
    }
    return tempVec;
}

//uses the frequencies of letters in the english language to test whether a key decodes ciphertext into English-like text and returns a score

double scoreCalc(vector<int> t, vector<int> k) 
{
    vector<int> tempVec = Decode(t, k);
    double count = 0.0;
    double frequency[26] = { 8.2, 1.5, 2.8, 4.3, 13, 2.2, 2, 6.1, 7, 0.15, 0.77, 4, 2.4, 6.7, 7.5, 1.9, 0.095, 6, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2, 0.074 };
    double alphabet[26];
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 0.0;
    }
    for (auto tempVecIt = tempVec.begin(); tempVecIt != tempVec.end(); ++tempVecIt) {
        for (int i = 0; i < 26; i++) {
            if ((*tempVecIt) == i) alphabet[i] = alphabet[i] + 1.0;
        }
        count = count + 1.0;
    }
    double sum = 0.0;
    for (int i = 0; i < 26; i++) {
        sum = sum + ((alphabet[i] * frequency[i]) / count);
    }
    return sum;
}

// scoreEle function that uses the frequecies as the keyScore and returns the sum
double scoreEle(vector<int> t, vector<int> k, int pos) 
{
    vector<int> tempVec = Decode(t, k);
    double c = 0.0;
    double freq[26] = { 8.2, 1.5, 2.8, 4.3, 13, 2.2, 2, 6.1, 7, 0.15, 0.77, 4, 2.4, 6.7, 7.5, 1.9, 0.095, 6, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2, 0.074 };
    double alpha[26];
    for (int i = 0; i < 26; i++) 
    {
        alpha[i] = 0.0;
    }
    for (int x = pos; x < tempVec.size(); x = x + k.size()) 
    {
        for (int i = 0; i < 26; i++) 
        {
            if (tempVec[x] == i) alpha[i] = alpha[i] + 1.0;
        }
        c = c + 1.0;
    }
    double sum = 0.0;
    for (int i = 0; i < 26; i++) 
    {
        sum = sum + ((alpha[i] * freq[i]) / c);
    }
    return sum;
}

int main()
{
    string message = "Hello world"; // providing a string
    //converting the string to a vector of integers (0-25) for each letter
    vector <int> vec;
    for (int i = 0; i < message.size(); i++) 
    {
        if (convertChar(message[i]) != -1) 
        {
            vec.push_back(convertChar(message[i]));
        }
    }

    //generating the key
    vector <int> Key;
    srand(time(NULL));
    for (int i = 0; i < message.size(); i++)
    {
        Key.push_back(rand() % 26);
    }

    //encoding vector 'vec' with the secret key
    vec = Encode(vec, Key);

    //creating a list of keys that continually increases the threshold accroding to the key score
    vector<vector<int> > listKeys;
    while (listKeys.size() != 30) {
        vector<int> tempVec;
        for (int i = 0; i < message.size(); i++) {
            tempVec.push_back(rand() % 26);
        }
        if (scoreCalc(vec, tempVec) > 4.2) listKeys.push_back(tempVec);
    }

    //print the keys generated
    for (auto i = listKeys.begin(); i != listKeys.end(); ++i) {
        for (auto j = (*i).begin(); j != (*i).end(); ++j) {
            cout << *j << ' ';
        }
        cout << "\t Key Score: " << scoreCalc(vec, *i);
        cout << "\n";
    }
    
    // creating a vector that takes the element with the best score from each position from listKeys
    vector<int> bestKey;
    for (int i = 0; i < message.size(); i++) 
    {
        int el = 0;
        double max = 0.0;
        for (int j = 0; j < listKeys.size(); j++) 
        {
            double val = scoreEle(vec, listKeys[j], i);
            if (max < val) 
            {
                max = val;
                el = listKeys[j][i];
            }
        }
        bestKey.push_back(el);
    }

    cout << "\nBest Key: ";
    for (auto x = bestKey.begin(); x != bestKey.end(); ++x) 
    {
        cout << *x << ' ';
    }

    cout << "Key Score: " << scoreCalc(vec, bestKey) ;

    cout << "\nSecret Key: ";
    for (auto x = Key.begin(); x != Key.end(); ++x) {
        cout << *x << ' ';
    }

    cout << "Key Score: " << scoreCalc(vec, Key) << endl;

    return 0;
}

