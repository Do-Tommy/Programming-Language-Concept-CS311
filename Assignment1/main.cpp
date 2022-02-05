#include <iostream>
#include <string>
#include <map>

using namespace std;

string keywords[5]  = {"if", "then", "else", "int", "char", "string"
};

string numbers[10] = { "0", "1", "2","3","4","5","6","7","8","9"
};

string delimiter[16] = { " ", "+", "-", "=","*","/", ",",";",">","<","(",")","[","]","{","}"
};



bool isKeyword(string s) {
    for(int i = 0; i < 4;i++) {
        if (s == keywords[i]) {
            return true;
        }
    }
    return false; 

}

bool isNumber(string s) {
    for(int i = 0; i < 9;i++) {
        if (s == numbers[i]) {
            return false;
        }
    }
    return true; 
}

bool isDelimiter(string s) {
    for(int i = 0; i < 15;i++) {
        if (s == delimiter[i]) {
            return true;
        }
    }
    return false; 
}

bool isChar(string s) {
    if(s.length == 1 && !isNumber(s)) {
        return true
    }
    return false;
}


int main(int argc, char* argv[]) {
    string filename;
    
    map<string,int> keywordList;
    map<string,int> identifierList;
    map<string,int> numberList;
    map<string,int> delimiterList;
    map<string,int> characterList;
    if(argc < 2) {
        cout << "missing filename";

    }
    else {
        filename = argv[1];
        printf("filename : %s\n", filename);

    }
    
    fstream file;
    file.open(filename.c_str());
    while (file >> word)
    {
        if (isKeyword(word) ) {
            if(keywordList[word]){
                keywordList[word] += 1;
            }
            else {
                keywordList.insert(pair<string,int>(word,1));
            }
            
            

        }
        else if(!isNumber(word[0])) {
                if(identifierList[word]){
                    identifierList[word] += 1;
                }
                else {
                    identifierList.insert(pair<string,int>(word,1));
            }
                
            }
        
        else if (isDelimiter(word)){
                if(delimiterList[word]) {
                    delimiterList[word] += 1;
                }
                else {
                    delimiterList.insert(pair<string,int>(word,1));

                }
        }
        else if (isNumber(word)) {
                if(numberList[word]) {
                    numberList[word] += 1;
                }
                else {
                    numberList.insert(pair<string,int>(word,1));
                }

        }
        else if (isChar(word)) {
                if(characterList[word]) {
                    characterList[word] += 1;
                }
                else {
                    characterList.insert(pair<string,int>(word,1));
                }

        }

    }
    map<string,int>:: iterator it;
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;


    return 0;

}