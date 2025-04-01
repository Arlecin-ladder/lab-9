#include <iostream>
#include <windows.h> 
#include <ctime>     
using namespace std;

const int ROWS = 5; 
const int COLS = 6; 

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0)); 
    int arr[ROWS][COLS]; 
    double avgArr[ROWS];  

    cout << "Початковий двовимірний масив:\n";
    for (int i = 0; i < ROWS; i++) {
        double sum = 0;
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 21 - 10; 
            sum += arr[i][j];
            cout << arr[i][j] << "\t";
        }
        avgArr[i] = sum / COLS; 
        cout << endl;
    }

    cout << "\nКількість елементів, кратних 5, у рядках із хоча б одним нулем:\n";
    for (int i = 0; i < ROWS; i++) {
        bool hasZero = false;
        int countMultiplesOf5 = 0;

        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == 0) {
                hasZero = true;
            }
        }

        if (hasZero) {
            for (int j = 0; j < COLS; j++) {
                if (arr[i][j] % 5 == 0) {
                    countMultiplesOf5++;
                }
            }
            cout << "Рядок " << i + 1 << ": " << countMultiplesOf5 << " елемент(ів)\n";
        }
    }

    cout << "\nОдновимірний масив середніх арифметичних значень рядків:\n";
    for (int i = 0; i < ROWS; i++) {
        cout << avgArr[i] << "\t";
    }
    cout << endl;

    return 0;
}
