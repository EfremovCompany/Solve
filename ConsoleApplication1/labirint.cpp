// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "labirint.h"

bool FileTest(){
	//FILE **pFile;
	//fopen_s(pFile, "input_test.txt", "rb");
	//if (pFile == NULL){ 
	//	printf("File opening error\n");   
	//	return 1; 
	//}
	//// Переменная ch должна иметь тип int, а не char   
	//int ch;  
	//// Цикл чтения продолжается пока код считанного символа не станет равен EOF (-1)  
	//while ((ch = fgetc(*pFile)) != EOF){   
	//	putchar(ch);  
	//}  
	//fclose(*pFile);  
	//pFile = NULL;
	return true;
}

bool CheckInt(const char* str)
{
	char *inString;
	inString = (char*)str;
	int symbols = 0;
	int digits = 0;
	while (*inString != 0)
	{
		symbols++;
		if ((isdigit(*inString++)) || (*inString++ == '.'))
			digits++;
	}
	if (symbols == digits)
		return true;
	else
		return false;
}

bool CheckParam(int numberOfParam, const char* roots[]){
	if (numberOfParam < 3 || numberOfParam > 5){
		std::cout << "Wrong number of parameters!" << std::endl;
		return false;
	}
	if (numberOfParam == 4){
		if (CheckInt(roots[1]) && CheckInt(roots[2]) && CheckInt(roots[3])){
			return true;
		}
	}
	else if (CheckInt(roots[1]) && CheckInt(roots[2])){
			return true;
		}
	/*else{
		std::cout << "Input error!" << std::endl;
		return false;
	}*/
}

int equation(double A, double B, double C){
	double D = pow(B, 2) - 4 * A * C;
	std::cout << "D = " << D << std::endl;
	if (D < 0){
		std::cout << "There is no real root." << std::endl;
	}
	else if (D == 0){
		double x = -B / (2 * A);
		std::cout << "x = " << x << std::endl;
	}
	else{
		double x1 = (-B + sqrt(D)) / (2 * A);
		double x2 = (-B - sqrt(D)) / (2 * A);
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x2 << std::endl;
	}
	return 0;
}

int main(int argc, const char* argv[])
{
	std::cout << "Do you want make test in files (0 - no, any another symbols - yes)" << std::endl;
	if (getchar() != '0'){
		if (FileTest()){
			std::cout << "Works" << std::endl;
		}
		else{
			std::cout << "Error!" << std::endl;
		}
	}
	if (CheckParam(argc, argv)){
		double C;
		if (argc == 3){
			C = 0;
			std::cout << "C = 0" << std::endl;
		}
		else{
			C = atof(argv[3]);
		}
		double A = atof(argv[1]);
		double B = atof(argv[2]);
		if (A != 0){
			equation(A, B, C);
		}
		else{
			std::cout << "A can't = 0!" << std::endl;
		}
	}
	system("pause");
	return 0;
}

