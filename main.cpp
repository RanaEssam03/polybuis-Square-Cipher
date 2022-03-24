#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
string key="" , txt="";
vector <int> keyList;
void getInput(string& txt,string& key);
void handleKey(string key, vector <int> & keyList);
void cipher(string txt);
void decipher(string cipheredTxt);

int main() {
    int option;
    bool end = false;
    cout << "\n\t\tThis program ciphers and deciphers text using Polybius_Square method\n";
    while (!end) {
        cout << "\nPlease pick one operation:\n1.cipher\n2.decipher\n3.exit\n-->";
        cin >> option;
        if (option == 1) {
            getInput(txt, key);
            handleKey(key, keyList);
            cout  << "ciphered message is: ";
            cipher(txt);
            cout << "\t\t\t------------------------------";
        } else if (option == 2) {
            getInput(txt, key);
            handleKey(key, keyList);
            cout << "plain message is: ";
            decipher(txt);
            cout <<"\n\t\t------------------------------";

        } else if (option == 3) {
            end = true;
        }
        else{
            cout << "Invalid option\nplease try again\n";
        }
    }
    return 0;
}

void getInput(string & txt, string& key){
    cout << "Dear user, please entre a key: ";
    cin >> key;
    cin.get();
    cout << "please entre a message:  ";
    getline(cin, txt);
}

void handleKey(string key, vector <int> & keyList){
    for (int i = 0; i <5 ; i++){
        keyList.push_back(key[i]-'0');
    }
}

void cipher(string txt){
    int num , row , col;
    string cipheredMessage = "";
    transform(txt.begin(), txt.end(), txt.begin(), ::toupper);
    for (int i= 0;  i < txt.size(); i++) {
        if (txt[i] != ' ') {
            if ((txt[i] + 0) <= 73) num = txt[i] - 64;
            else if ((txt[i] + 0) == 74) num = 9;
            else if ((txt[i] + 0) > 74) num = txt[i] - 65;

            if (num % 5 == 0) {
                row = num / 5 - 1;
                col = 4;
            } else if ((num + 1) % 5 == 0) {
                row = (num + 1) / 5 - 1;
                col = 3;
            } else if ((num + 2) % 5 == 0) {
                row = (num + 2) / 5 - 1;
                col = 2;
            } else if ((num + 3) % 5 == 0) {
                row = (num + 3) / 5 - 1;
                col = 1;
            } else if ((num + 4) % 5 == 0) {
                row = (num + 4) / 5 - 1;
                col = 0;
            }

            cout << keyList[row] << keyList[col];
        }
        else{
            cout << ' ';
        }
        }
}
void decipher(string cipheredTxt){
    int row=0, col=0, num;
    int i = 0;
    char letter;
    while (i < cipheredTxt.size()){
        if (cipheredTxt[i] != ' ') {
            auto ptr = find(keyList.begin(), keyList.end(), cipheredTxt[i] - '0');
            row = ptr - keyList.begin();
            auto ptr_2 = find(keyList.begin(), keyList.end(), cipheredTxt[i + 1] - '0');
            col = ptr_2 - keyList.begin();
            i += 2;
            num = 5*row +col +1;
            if (num <= 9) {
                cout << char(num + 64);
            } else {
                cout << char(num + 65);
            }
        }
        else{
            cout << ' ';
            i += 1;
        }
    }
}