#pragma once
#include "Header.h"
class ProtPas
{
private:             //Переменные
	std::string ident;
	std::string login;
	std::string inStr;
	std::string outStr;
	int id = 0;
	int cNum = 0;
	
public:
	ProtPas();
	ProtPas(std::string);
	ProtPas(std::string, std::string, std::string);
	ProtPas(std::string, std::string, std::string, int);
private:
	static int checkData();
	static int initDir();
	static int init();
	int cipher(int num = 0);
	int decode();
	int writeToFile();
public:
	static int _interface();
	static int start() {
		if(initDir()) std::cerr << "Ошибка в функции инициализации.";
		return 0;
	}
};


