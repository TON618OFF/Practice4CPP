#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

void reverse(string& word) {
    reverse(word.begin(), word.end());
}

void removeVowels(string& word) {
    word.erase(remove_if(word.begin(), word.end(), [](char c) { return string("аеёиоуыэюяАЕЁИОУЫЭЮЯ").find(c) != string::npos; }), word.end());
}

void removeConsonants(string& word) {
    word.erase(remove_if(word.begin(), word.end(), [](char c) { return string("абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ").find(c) != string::npos; }), word.end());
}

void shuffle(string& word) {
    random_device rd;
    mt19937 g(rd());
    shuffle(word.begin(), word.end(), g);
}

int main() {
    setlocale(LC_ALL, "Russian");
    string word;
    int choice;

    cout << "Приветствую вас в программе, которая поможет применять разные опции к слову!\n";
    cout << "Пожалуйста, умоляю, введите слово: \n";
    cin >> word;

    cout << "Выберите опцию:\n";
    cout << "1. Перевернуть слово\n";
    cout << "2. Убрать гласные\n";
    cout << "3. Убрать согласные\n";
    cout << "4. Перемешать буквы в слове\n";
    cin >> choice;

    switch (choice) {
    case 1:
        reverse(word);
        break;
    case 2:
        removeVowels(word);
        break;
    case 3:
        removeConsonants(word);
        break;
    case 4:
        shuffle(word);
        break;
    default:
        cout << "Invalid choice\n";
        return 1;
    }
    cout << "Result: " << word << endl;

    return 0;
}
