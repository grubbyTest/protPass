#include "ProtPas.h"
#pragma warning(disable : 4996)

//static std::vector<std::string> idents;
//static std::vector<std::string> ciph;
//static std::vector<std::string> cNums;
static std::vector<ProtPas> obj;

static int ID = 0;

ProtPas::ProtPas() {
	inStr = "";
	outStr = "";
	ident = "";
	login = "";
}

ProtPas::ProtPas(std::string str) {
	inStr = str;
	if(this->cipher()) std::cerr << "Ошибка в функции шифрования (конструктор)" << std::endl;
}

ProtPas::ProtPas(std::string strIdent, std::string strLog, std::string strIn) {
	this->ident = strIdent;
	this->login = strLog;
	this->inStr = strIn;
}

ProtPas::ProtPas(std::string strIdent, std::string strLog, std::string strIn, int num) {
	this->cNum = num;
	this->ident = strIdent;
	this->login = strLog;
	this->inStr = strIn;
}

int ProtPas::checkData() {
	return 0;
}

int ProtPas::_interface() {
	start();
	bool bisy = true;
	bool check;
	char n = ' ';
	int count = 0;
	char tempStr[LENSTR];
	ProtPas* ptrObj;
	ptrObj = new ProtPas;

	system("color 03");
	while (bisy) {
		
		system("cls");
		system("Strline.exe protect");
		system("Strline.exe password");

		std::cout << "\n";
		for (int i = 0; i < 75; i++) {
			std::cout << LINESYM;
		}

		std::cout << MENUNEWRUS << std::endl;
		std::cout << MENUUNLOCKRUS << std::endl;
		std::cout << MENUSETRUS << std::endl;
		std::cout << MENUEXITRUS << std::endl;

		for (int i = 0; i < 75; i++) {
			std::cout << LINESYM;
		}

		std::cin >> n;
		switch (n) {
		case '1':
			system("cls");
			system("Strline.exe cipher");
			system("Strline.exe password");
			std::cout << std::endl << NEWINPUT1RUS << std::endl;
			std::cin >> tempStr;
			ptrObj->login = tempStr;

			system("cls");
			system("Strline.exe cipher");
			system("Strline.exe password");
			std::cout << std::endl << NEWINPUT2RUS << std::endl;
			std::cin >> tempStr;
			ptrObj->inStr = tempStr;


			system("cls");
			system("Strline.exe cipher");
			system("Strline.exe password");
			std::cout << std::endl << NEWINPUT3RUS << std::endl;
			std::cin >> tempStr;
			ptrObj->ident = tempStr;


			system("cls");
			system("Strline.exe cipher");
			system("Strline.exe password");
			if (ptrObj->cipher()) {
				std::cout << std::endl << CIPHERACCEPT << std::endl;
			}else std::cout << std::endl << ERRCIPHER << std::endl;
			if (ptrObj->writeToFile()) {
				obj.push_back(*ptrObj);
				ID++;
				std::cout << std::endl << WRITEFILEOK << std::endl;
			}
			else std::cout << std::endl << ERRWRITING << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		case '2':
			check = true;
			if (ID != 0) {
				while (check) {
					system("cls");
					system("Strline.exe unlock");
					system("Strline.exe cipher");

					std::cout << "\n";
					for (int i = 0; i < 75; i++) {
						std::cout << LINESYM;
					}
					std::cout << "\n\t";
					for (int i = 0; i < obj.size(); i++) {
						for (int i = 0; i < 67; i++) {
							std::cout << LINESYM2;
						}
						std::cout << std::endl << "\t" << i + 1 << ". " << obj.at(i).ident << "\n\t";
					}

					std::cout << "\n";
					for (int i = 0; i < 75; i++) {
						std::cout << LINESYM;
					}

					std::cout << UNLOCKCIPH;

					std::cin >> count;
					
					if (count < 0 || count > ID) {
						std::cerr << "\tОшибка ввода! Указанный номер отсутствует.";
						std::cin.get();
						std::cin.get();
					}
					else { check = false; }
				}
				if (count == 0) break;
				count--;
				obj.at(count).decode();

				system("cls");
				system("Strline.exe succesfuly");
				system("Strline.exe unlocked");

				std::cout << "\n";
				for (int i = 0; i < 75; i++) {
					std::cout << LINESYM;
				}

				std::cout << "\n\n\tИДЕНТИФИКАТОР-> " << obj.at(count).ident;
				std::cout << "\n\n\tЛОГИН-> " << obj.at(count).login;
				std::cout << "\n\n\tПАРОЛЬ-> " << obj.at(count).inStr << std::endl << std::endl;

				for (int i = 0; i < 75; i++) {
					std::cout << LINESYM;
				}

				std::cout << INANYKEY;

				std::cin.get();
				std::cin.get();
			}
			else {
				std::cerr << "\n\n\t->ПРЕДМЕТЫ ШИФРА ОТСУТСТВУЮТ!<-";

				std::cin.get();
				std::cin.get();
			}
			break;
		case '3':
			system("cls");
			system("Strline.exe settings");
			//system("Strline.exe cipher");
			system("pause");

			break;
		case '0':
			bisy = false;
			break;
		default:
			break;
		}
	}
	return 1;
}

int ProtPas::initDir() {
	//std::filesystem::create_directory(DATADIR);
	std::fstream fin(IDENTFILE, std::ios::in);
	if (!fin) {
		std::cout << INITSTR << std::endl;
		std::cout << INITSTRFIRST << std::endl;
		std::fstream fout(IDENTFILE, std::ios::out);
		if (fout) {
			std::cout << IDENTFILESET;
			fout.close();
		}
		else {
			std::cerr << INITSTRFAIL << std::endl;
			return 1;
		}
		std::fstream fout1(CIPHFILE, std::ios::out);
		if (fout1) {
			std::cout << "\tФайл данных настроен.\n";
			fout1.close();
		}
		else {
			std::cerr << INITSTRFAIL << std::endl;
			return 1;
		}
		std::cout << "Настройка проведена успешно.";
		fin.close();
		return 0;
	}
	else {
		fin.close();
		if (!init()) std::cout << READFILEOK << std::endl;
		return 0;
	}
	

}

int ProtPas::init() {
	std::fstream fout(IDENTFILE, std::ios::binary | std::ios::in);
	std::fstream foutD(CIPHFILE, std::ios::binary | std::ios::in);
	
	if (!fout) {
		std::cerr << ERREADFILE << ' ' << IDENTFILE << std::endl;
		
		return 1;
	}
	if (!foutD) {
		std::cerr << ERREADFILE << ' ' << CIPHFILE << std::endl;

		return 1;
	}
	char temp[LENSTR] = "\0";
	char tempD[LENSTR] = "\0";
	char tempInt[4] = "\0";
	ProtPas tempObj;

	while (!fout.eof()) {
		fout.read(temp, LENSTR);
		if (temp[0] == EMPF) {
			break;
		}
		//idents.push_back(temp);
		tempObj.ident = temp;
		fout.read(temp, LENSTR);
		tempObj.login = temp;

		foutD.read(tempD, LENSTR);
		foutD.read(tempInt, 4);
		/*ciph.push_back(temp);
		cNums.push_back(tempInt);*/
		tempObj.outStr = tempD;
		tempObj.cNum = atoi(tempInt);
		ID++;
		obj.push_back(tempObj);
	}
	
	if (ID != 0) {
		obj.pop_back();
		ID--;
	}
	fout.close();
	foutD.close();
	return 0;
}

int ProtPas::cipher(int num) {               //аргумент num - уровень шифрования(пока на следующую версию)
	srand(time(0));
	this->cNum = rand() % 998;
	if (this->cNum % 2 != 0) this->cNum++;
	this->outStr = inStr;

	if (this->inStr.empty()) return -1;

	for (int i = 0; i < this->inStr.size(); i++) {
		this->outStr[i] = this->inStr[i] + char(this->cNum);
		
	}
	for (int i = 0; i < this->inStr.size(); i++) {
		outStr[i] = outStr[i] << (cNum % 2);
		
	}
	return 1;
}

int ProtPas::decode() {
	if (outStr.empty()) return -1;

	inStr = outStr;

	for (int i = 0; i != this->outStr.size(); i++) {
		outStr[i] = outStr[i] >> (cNum % 2);

	}
	for (int i = 0; i != this->outStr.size(); i++) {
		inStr[i] = outStr[i] - char(this->cNum);
		
	}
	
	return 1;
}

int ProtPas::writeToFile() {
	std::fstream fout(IDENTFILE, std::ios::binary | std::ios::app);
	std::fstream foutD(CIPHFILE, std::ios::binary | std::ios::app);

	if (!fout) {
		std::cerr << ERRWRITE << std::endl;
		return -1;
	}
	if (!foutD) {
		std::cerr << ERRWRITE << std::endl;
		return -1;
	}

	fout.write(this->ident.c_str(), LENSTR);
	fout.write(this->login.c_str(), LENSTR);
	

	foutD.write(this->outStr.c_str(), LENSTR);
	foutD.write(std::to_string(this->cNum).c_str(), 4);

	fout.close();
	foutD.close();

	return 1;
}