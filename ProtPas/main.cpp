#include "ProtPas.h"
#include "Windows.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ProtPas::_interface();

	return 0;
	

}