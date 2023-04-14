#include <iostream>
#include <string>



const int SIZE = 8;
using namespace std;
int recursivMax(int arr[], int size) {
    size--;
    if (size == 0)return arr[0];
    int x = recursivMax(arr, size);
    if (arr[size] < x)return x;
    else return arr[size];
}
void zapoln(int ar[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            ar[i][j] = 1;
        }
    }
}
void PyatnaskovoePole(int desk[][SIZE]) {
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; i < SIZE; j++) {
            desk[i][j] = i*j;
        }
    }
}



void vivodscah(int desk[][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        cout << "\t" << SIZE-i;
        for (int j = 0; j < SIZE; j++) {
            cout << "\t" << desk[SIZE-1-i][j];
        }
        cout<< "\n\n";
    }
    cout << "\t\t";
    for (int i = 0; i < SIZE; i++) {
        cout << char(i+65) << "\t";
    }
}

void showASKI() {
    for (int i = 0; i < 256; i++) {
        cout << endl << char(i) << " - " << i;
    }
}
void PathHhower(string path[],int size) {
    cout << endl;
    for (int i = 1; i < size; i++) {
        cout << "\t" << path[i - 1] << " -->  " << path[i] << "\t";
        if (!(i % 5))cout << endl;
    }
}
int HowMuchAvalible(int x,int y,int desk[][SIZE]) {
    int count = 0;
    int newx , newy;
    newx = x + 2, newy = y + 1;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)count += desk[newx][newy];
    newx = x + 2, newy = y - 1;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)count += desk[newx][newy];
    newx = x - 2, newy = y + 1;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)count += desk[newx][newy];
    newx = x - 2, newy = y - 1;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)count += desk[newx][newy];
    newx = x + 1, newy = y + 2;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)count += desk[newx][newy];
    newx = x + 1, newy = y - 2;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)count += desk[newx][newy];
    newx = x - 1, newy = y + 2;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)count += desk[newx][newy];
    newx = x - 1, newy = y - 2;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)count += desk[newx][newy];
    return count;
}            
//  нахождение количества возможных шагов с этой координаты



void step(int& x, int& y, int desk[][SIZE]) {
    int arr[8][3]{};
    int newx, newy;
    newx = x + 2, newy = y + 1;
    arr[0][1] = newx;
    arr[0][2] = newy;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)arr[0][0] = HowMuchAvalible(newx, newy, desk)+1;
    newx = x + 2, newy = y - 1;
    arr[1][1] = newx;
    arr[1][2] = newy;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)arr[1][0] = HowMuchAvalible(newx, newy, desk)+1;
    newx = x - 2, newy = y + 1;
    arr[2][1] = newx;
    arr[2][2] = newy;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)arr[2][0] = HowMuchAvalible(newx, newy, desk)+1;
    newx = x - 2, newy = y - 1;
    arr[3][1] = newx;
    arr[3][2] = newy;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)arr[3][0] = HowMuchAvalible(newx, newy, desk)+1;
    newx = x + 1, newy = y + 2;
    arr[4][1] = newx;
    arr[4][2] = newy;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)arr[4][0] = HowMuchAvalible(newx, newy, desk)+1;
    newx = x + 1, newy = y - 2;
    arr[5][1] = newx;
    arr[5][2] = newy;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)arr[5][0] = HowMuchAvalible(newx, newy, desk)+1;
    newx = x - 1, newy = y + 2;
    arr[6][1] = newx;
    arr[6][2] = newy;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)arr[6][0] = HowMuchAvalible(newx, newy, desk)+1;
    newx = x - 1, newy = y - 2;
    arr[7][1] = newx;
    arr[7][2] = newy;
    if (newx < SIZE && newy < SIZE && newx >= 0 && newy >= 0 && desk[newx][newy] == 1)arr[7][0] = HowMuchAvalible(newx, newy, desk)+1;

    int min = 10, imin = 10;
    for (int i = 0; i < 8; i++) {

        if (arr[i][0] == 0)continue;

        if (arr[i][0] < min) {
            min = arr[i][0];
            imin = i;
        }
    }
    if (imin == 10) {
        cout << "\n\teror n1";
        cin >> min;
    }
    x = arr[imin][1];
    y = arr[imin][2];
    if (x >= SIZE || x < 0 || y >= SIZE || y < 0) {
        cout << "\n\teror n2";
        cin >> min;
    }
    
}
// меняет Х и У на следующий





int main()
{
    //cout << "Input any thing to continue";
    //char temp = 'x';
    //cin >> temp;
    system("cls");
    cout << endl;
    const int glubina = 1;
    int desk[SIZE][SIZE];
    zapoln(desk);
    string coordinate;
    string FirstCoordinate;
    vivodscah(desk);
    int x, y;
    cout << "\n Input first coordinate ";
    do {
        FirstCoordinate = "A1";
        cin >> FirstCoordinate;

        y = FirstCoordinate[0] - 65;
        x = FirstCoordinate[1] - 49;
        if (!(x < SIZE && y < SIZE && x >= 0 && y >= 0)) cout << "\n\t wrong coordinates\ntry again\n\t";
    } while (!(x < SIZE && y < SIZE && x >= 0 && y >= 0));
    string path[SIZE * SIZE];
    int pointofpath = 0;
    path[pointofpath++] = FirstCoordinate;
    desk[x][y] -= 1;
    cout << y << "   " << x;
    system("cls");
    vivodscah(desk);
    cout << "\n\tAvalible turns = " << HowMuchAvalible(x, y, desk) << "\n First path point - " << path[0];
    for (int i = 1; i < SIZE * SIZE; i++) {

        step(x, y, desk);
        if (x > SIZE || x<0 || y>SIZE || y < 0) {
            cout << "\neror;";
            cin >> x;
        }
        desk[x][y] -= 1;
        char rif = char(y + 65);
        char ces = char(x + 49);
        string nextstep{ rif,ces };
        path[pointofpath++] = nextstep;
        system("cls");
        vivodscah(desk);
        cout << "\n\tAvalible turns = " << HowMuchAvalible(x, y, desk);
        PathHhower(path, i + 1);

    }
    cout << "\n\tvse\n";
    //PathHhower(path, SIZE * SIZE);
    cout << "\n\t konez";

}
