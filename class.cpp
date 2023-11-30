#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Class_s
{
public:
    float x, y;
    float lb1(float x)
    {
        if (x >= -7 && x <= -3)
        {
            y = x + 7;
        }
        else if (x < -2)
        {
            y = 4;
        }
        else if (x <= 2)
        {
            y = x * x;
        }
        else if (x <= 4)
        {
            y = -2 * x + 8;
        }
        else if (x > -9 && x < -7 || x > 4 && x < 7)
        {
            y = 0;
        }
        return y;
    }
    void out1()
    {
        lb1(x);
        cout << "y = " << y << endl;
    }

    void lb2()
    {
        int rows;
        int cols;

        cout << "Введите количетво строк: ";
        cin >> rows;
        cout << "Введите количество столбцов: ";
        cin >> cols;

        int **arr = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = rand() % 20;
                cout << arr[i][j] << '\t';
            }
            cout << endl;
        }

        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }

    void lb3()
    {
        ifstream fin("file1.txt");  // вывод данных из файл
        ofstream fout("file1.txt"); // ввод данных в файла
        string a;
        string b;

        cout << "txt: ";
        cin >> a;

        fout << a;
        fout.close();

        getline(fin, b);
        cout << b << endl;

        fin.close(); // закрываем файл
    }

    void lb3arr()
    {

        ifstream fin("file.txt");  // вывод данных из файл
        ofstream fout("file.txt"); // ввод данных в файла
        int b;

        for (int x = -9; x < 7; x++)
        {

            lb1(x);
            fout << y;
            fout << "\n";
        }

        fout.close();

        fout.close();
        vector<int> arr;
        while (fin >> b)
        {
            arr.push_back(b);
        }
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        fin.close(); // закрываем файл
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    setlocale(LC_ALL, ".UTF8");

    Class_s clas_s;
    cout << "Введите x: ";
    cin >> clas_s.x;
    clas_s.out1();
    clas_s.lb2();
    clas_s.lb3();
    clas_s.lb3arr();
}