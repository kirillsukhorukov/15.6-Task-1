#include <iostream>
#include <vector>

using namespace std;

//Функция нахождения суммы элементов вектора между заданными индексами
int sum (const vector <int> &array, const int &iLeft, const int &iRight)
{
    int sum=0;
    for (int i=iLeft; i<=iRight; i++) sum+=array[i];
    return sum;
}

//Функция определения индексов вектора мужду котороми сумма элементов максимальна и суммы этих элементов
int max_sum (const vector <int> &array, int &iLeft, int &iRight)
{
    int maxSum=0;
    for (int i=0; i<array.size(); i++)
    {
        for (int j=i; j<array.size(); j++)
        {
            int curSum = sum(array,i,j);
            if (curSum>maxSum)
            {
                maxSum=curSum;
                iLeft=i;
                iRight=j;
            }
        }

    }
    return maxSum;
}

int main()
{
    //Инициализация вектора с данными
    vector <int> arr = {15, -209, 2, 1099, -207, -5, 85, 7, 0, 3, -208, 9, 8};
    //Инициализация границ диапазона с максимальной суммой элементов вектора
    int iLeft=0, iRight=(int)arr.size()-1;
    //Вывод результата
    std::cout << "Sum=" << max_sum(arr, iLeft, iRight) << "; Left index=" << iLeft << "; Right index=" << iRight  << endl;
    return 0;
}