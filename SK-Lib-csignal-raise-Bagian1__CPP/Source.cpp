#include <iostream>
#include <csignal>
#include <conio.h>

/*
	Source by GeeksForGeeks
	Modified For Learn by RK
	I.D.E : VS2019
*/

using namespace std;

void signal_handler(int signal_num) {
	cout << "Interrupt signal is (" << signal_num << ").\n";

	// terminate program
	exit(signal_num);
}

int main() {
	int count = 0;
	signal(SIGSEGV, signal_handler);
	// register signal SIGSEGV and signal handler

	while (++count) {
		cout << "Halo pengguna..." << endl;

		if (count == 5) {
			raise(SIGSEGV);
		}
	}

	_getch();
	return 0;
}
