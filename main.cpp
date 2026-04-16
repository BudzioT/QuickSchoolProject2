#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

bool isNumberInSet(const vector<int>& singleDraw, int number) {
    for (int i = 0; i < singleDraw.size(); i++) {
        if (singleDraw[i] == number) {
            return true;
        }
    }
    return false;
}

void generateDraws(vector<vector<int>>& draws, int numDraws) {
    for (int i = 0; i < numDraws; ++i) {
        vector<int> currentDraw;

        while (currentDraw.size() < 6) {
            int randomNum = rand() % 49 + 1;

            if (!isNumberInSet(currentDraw, randomNum)) {
                currentDraw.push_back(randomNum);
            }
        }
        draws.push_back(currentDraw);
    }
}

void displayDraws(const vector<vector<int>>& draws) {
    cout << "Zestawy wylosowanych liczb:" << endl;
    for (int i = 0; i < draws.size(); ++i) {
        cout << "Losowanie " << i + 1 << ": ";
        for (int j = 0; j < draws[i].size(); ++j) {
            cout << draws[i][j] << " ";
        }
        cout << endl;
    }
}

void countAndDisplayOccurrences(const vector<vector<int>>& draws) {
    vector<int> counts(50, 0);

    for (int i = 0; i < draws.size(); ++i) {
        for (int j = 0; j < draws[i].size(); ++j) {
            int number = draws[i][j];
            counts[number]++;
        }
    }

    for (int i = 1; i <= 49; ++i) {
        cout << "Wystapienia liczby " << i << ": " << counts[i] << endl;
    }
}

int main() {
    setlocale(LC_ALL, "polish");

    srand(time(NULL));

    int numDraws;
    cout << "Ile wygenerowac losowan?" << endl;

    while (!(cin >> numDraws) || numDraws <= 0) {
        cout << "Blad! Podaj poprawna liczbe calkowita wieksza od 0:" << endl;
        cin.clear();
        while (cin.get() != '\n'); // czyszczenie bufora
    }

    vector<vector<int>> draws;

    generateDraws(draws, numDraws);
    displayDraws(draws);
    countAndDisplayOccurrences(draws);

    return 0;
}