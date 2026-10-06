#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <codecvt>
#include <stdlib.h>

#define IDENTFILE "ident.pty"
#define CIPHFILE "cData.pty"

#define INITSTR "Выполняется проверка данных"
#define INITSTRFIRST "Настройка первого запуска..."
#define INITSTRCOMP "Выполняется проверка данных"
#define INITSTRFAIL "Ошибка инициализации."
#define ERREADFILE "Ошибка чтения файла"
#define READFILEOK "Успешное чтение файлов"
#define ERRWRITE "Ошибка операции при записи файлов"
#define ERRCIPHER "Ошибка шифрования данных"
#define ERRWRITING "\tОшибка записи данных в файл"
#define IDENTFILESET "\tФайл идентификаторов настроен.\n"
#define INANYKEY "\n\n\n\n\n\tНАЖМИТЕ 'Enter' ДЛЯ ПРОДОЛЖЕНИЯ...\n"

#define EMPF '\0'

#define CIPHERACCEPT "\tШифрование данных выполнено успешно!"
#define WRITEFILEOK "\tЗапись в файл выполнена успешно!"

#define LENSTR 50
#define LINESYM '='
#define LINESYM2 '_'


/////////////////////////INTERFACE///////////////////////
#define MENUNEWRUS "\n\n\t\t1 - НОВЫЙ ШИФР\n"
#define MENUUNLOCKRUS "\t\t2 - РАСШИФРОВАТЬ\n"
#define MENUSETRUS "\t\t3 - НАСТРОЙКИ\n"
#define MENUEXITRUS "\t\t0 - ВЫХОД\n"

#define NEWINPUT1RUS "\t\tВВЕДИТЕ ЛОГИН:"
#define NEWINPUT2RUS "\t\tВВЕДИТЕ ПАРОЛЬ:"
#define NEWINPUT3RUS "\t\tВВЕДИТЕ ИДЕНТИФИКАТОР:"

#define UNLOCKCIPH "\n\n\n\tВВЕДИТЕ НОМЕР ИДЕНТИФИКАТОРА(или 0 для выхода) И НАЖМИТЕ КЛАВИШУ 'Enter': "





