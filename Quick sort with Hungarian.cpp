
#include <iostream>                                                           // ссылка на видос https://www.youtube.com/watch?v=3San3uKKHgg   сортировки вообще тут https://proglib.io/p/sort-gif
using namespace std;



// Прототипы.
void showarr(int[],int);
void lehz(int ar[], int size, int hatmin, int hatmax);
void rehz(int ar[], int size, int hatmin, int hatmax);
void zapoln(int ar[], int size);
void randomer(int ar[], int size);

void Sort(int ar[], int size, int hatmin = 0, int hatmax = -10) {
    if (hatmax == -10)hatmax = size - 1;
    if (hatmax - hatmin < 1)return;
    rehz(ar, size, hatmin, hatmax );

}
void rehz(int ar[], int size, int hatmin, int hatmax) {
    for (int i = hatmax;i > hatmin;i--) {
        if (ar[hatmin] > ar[i]) {
            swap(ar[hatmin], ar[i]);
            showarr(ar, size);
            lehz(ar, size,hatmin+1,i);//                                                                 hatmin+1?
        }
    }
    Sort(ar, size, hatmin + 1, hatmax);           
}
void lehz(int ar[], int size, int hatmin, int hatmax) {
    for (int i = hatmin; i < hatmax; i++) {
        if (ar[i] > ar[hatmax]) {
            swap(ar[hatmax], ar[i]);
            showarr(ar, size);
            rehz(ar, size,i,hatmax-1);//                                                                 hatmax-1?
        }
    }
    Sort(ar, size, hatmin, hatmax-1);
}
int main()
{
    srand(time(NULL));
    const int SIZE = 10;                                                          // размер масива тут
    int array[SIZE]{ 3,0,1,8,7,2,5,4,9,6 };
    showarr(array, SIZE);
    Sort(array, SIZE);
    showarr(array, SIZE);
    cout << endl;
    //int const SIZE2 = 1000;
    //int arr[SIZE2];
    //zapoln(arr, SIZE2);
    //randomer(arr, SIZE2);
    //Sort(arr, SIZE2);
    //showarr(arr, SIZE2);
}
void zapoln(int ar[], int size) {
    for (int i = 0; i < size; i++) {
        ar[i] = i;
    }
}
void randomer(int ar[], int size) {
    for (int i = 0; i < size; i++) {
        swap(ar[i], ar[rand() % size]);
    }
}
void showarr(int ar[],int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << ar[i] << "\t";
    }
}




