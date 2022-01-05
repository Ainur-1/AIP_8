#include <iostream>

using namespace std;

int ex_1();
int ex_3();

int main() {

	setlocale(LC_ALL, "rus");

	ex_1();
	ex_3();

	return 0;
}

// -------------------------------------------------------------------------------------

void init_arr(char la[], int DIM);
void bits(char la[], int DIM);

int ex_1() {
	const int DIM = 8;
	char a[DIM];

	init_arr(a, DIM);
	bits(a, DIM);

	printf("%n");
	return 0;
};

void init_arr(char la[], int DIM) {
	for (int i = 0; i < DIM; i++)
	{
		la[i] = char(pow(2, i)) + 5;
		printf("\n la[%d] = %d", i, la[i]);
	}
}
void bits(char la[], int DIM) {

	int j, kbit, i;
	int temp = 0;

	for (i = 0; i < DIM; i++) {
		kbit = 0;

		for (j = 0; j < 8 * sizeof(char); j++)
			if ((la[i] & (char(1) << j)) == 0) {
				temp++;
				if (temp == 3) printf("\n la[%d] = %d", i, la[i]);
			}
			else temp = 0;
	}
}

// --------------------------------------------------------------------------------------
void balls_creation(int& x, int& y);
int hit_calculation(int x, int y);

int ex_3() {
	int x, y, k;
	int tag = 1;

	while (tag != 0) {
		balls_creation(x, y);
		cout << "Ball(" << x << ',' << y << ")\n";
		k = hit_calculation(x, y);

		if (k > 0) cout << "Промах!";
		else cout << "Попадание!";

		cout << "\nВведите любое число, чтобы продолжить, либо 0, чтобы закончить>>";
		cin >> tag;

	}
	return 0;
};

void balls_creation(int& x, int& y) {
	int a1 = -3, a2 = 8, b1 = -5, b2 = 5;
	x = a1 + rand() % a2 + 1;
	y = b1 + rand() % b2 + 1;
}

int hit_calculation(int x, int y) {
	if ((y * y + (x - 4) * (x - 4) > 16) or (x > 6)) return 1;
	else return 0;
}
	
