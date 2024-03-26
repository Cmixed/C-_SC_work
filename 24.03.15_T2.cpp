#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    int sto[10][2];
    int k = 0;

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i]%10 == 3) {
            sto[k][0] = arr[i];
            sto[k][1] = i;
            ++k;
        }
    }
//    for (int i = 0; i < k; i++) {
//    	cout << sto[i][0] << "||||" << sto[i][1] << "Line22" << endl ;
//	}
    int MIN = 0, MIN_T = 0;
    MIN = sto[0][0]; MIN_T = sto[0][1];
    for (int i = 0; i < k-1; i++) {
        if (MIN > sto[i+1][0]) {
            MIN = sto[i+1][0];
            MIN_T = sto[i+1][1];
        }
    }
    
    cout << MIN << endl << MIN_T;

    return 0;
}