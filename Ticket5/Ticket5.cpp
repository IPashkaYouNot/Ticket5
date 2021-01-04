#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;


string Converting_to_16(int num);               // конвертація у 16 систему числення методом ділення та остачі

int Random_Generating(int min, int max);        // генерація числа у заданому діапазоні

int** Generated_Array(int& n);                  // генерація квадратної матриці

int Index_of_max_col(int** array, int n);       // пошук індексу стовпчика з найбільшим елементом

int* Product(int** array, int n, int ind);      // добуток відповідного стовпчика на рядки

string* Converted_to_16_arr(int* array, int n); // створення масиву з чисел у 16 системі

void Output_Arr(int** arr, int size);           // вивід матриці

void Output_Arr(int* arr, int size);            // перегрузка виводу

void Output_Arr(string* arr, int size);         // і ще один вивід


int main()
{
    int n;                                                  // розмір матриці
    int** array = Generated_Array(n);                       // згенерована матриця

    int ind_max_col = Index_of_max_col(array, n);           // індекс стовпця найбільшого елементу

    Output_Arr(array, n);

    int* prod_matr = Product(array, n, ind_max_col);        // масив із результатом множення стовпця на рядки

    Output_Arr(prod_matr, n);                               

    string* result = Converted_to_16_arr(prod_matr, n);     // масив з передевеними числами у 16 систему

    Output_Arr(result, n);

    //видалення масивів
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
    delete[] prod_matr;
    delete[] result;
}

string Converting_to_16(int num) {
    string s;
    do
    {
        int remainder = num % 16;
        switch (remainder)
        {
        case 10:
            s.insert(0, "A");       // insert(0, символ) - вставка символа у початок рядка
            break;
        case 11:
            s.insert(0, "B");
            break;
        case 12:
            s.insert(0, "C");
            break;
        case 13:
            s.insert(0, "D");
            break;
        case 14:
            s.insert(0, "E");
            break;
        case 15:
            s.insert(0, "F");
            break;
        default:
            s.insert(0, to_string(remainder));
            break;
        }
        num /= 16;
    } while (num > 0);
    return s;
}

int Random_Generating(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int** Generated_Array(int& n) {
    cout << "Type size of matrix: ";
    cin >> n;
    int** array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[n];
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = Random_Generating(0, 10);
        }
    }

    return array;
}

int Index_of_max_col(int** array, int n) {
    int ind = 0;
    int max = array[0][0];
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {       // прохожусь по стовпцям а не рядкам щоб
            if (array[i][j] >= max) {       // знайвлося декілька максимальних елементів
                max = array[i][j];          // обрався останній стовпець з таким елементои
                ind = j;
            }
        }
    }
    return ind;
}

int* Product(int** array, int n, int ind) {
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
        for (int j = 0; j < n; j++) {
            arr[i] += array[i][j] * array[j][ind];
        }
    }
    return arr;
}

string* Converted_to_16_arr(int* array, int n) {
    string* arr = new string[n];

    for (int i = 0; i < n; i++) {
        arr[i] = Converting_to_16(array[i]);
    }
    return arr;
}

void Output_Arr(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Output_Arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(3) << arr[i] << " ";
    }
    cout << endl;
}

void Output_Arr(string* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(3) << arr[i] << " ";
    }
    cout << endl;
}
