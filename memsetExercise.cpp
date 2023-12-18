// memset exercise

#include <iostream>
#include <vector>
#include <cstring> // memset header

using namespace std;

int main()
{
	int arr[10][10];

	// The value is passed as an int
	// but the function fills the block of memory using the unsigned char conversion of this value.
	// memset은 0 혹은 NULL, false로 만 초기화 가능
	for (int i = 0; i < 10; i++) memset(arr[i], 0, sizeof(arr[i])); // sizeof(int) * 10

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}