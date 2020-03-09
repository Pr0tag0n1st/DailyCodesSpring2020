#include <stdio.h>
void rotate_left(int* array, int n, int array_length);
int main() {
	const int arraysize = 5;
	int rotation = 0;
	printf("We are starting off with a five slot array. \nHow many times will you rotate the slots?\n");
	int samplearray[arraysize] = { 10, 7, 2, 9, 5 };
	scanf_s("%d", &rotation);
	printf("So you are rotating this array %d times.\n", rotation);
	printf("Starting out, the array was as follows:\n");
	for (int i = 0; i < arraysize; i++) {
		printf("%d\n", samplearray[i]);
	}
	rotate_left(samplearray, rotation, arraysize);
}
void rotate_left(int* array, int n, int array_length) {

	
}