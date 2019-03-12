

#include "pch.h"
#include <iostream>
#include <Windows.h>


struct footballPlayer {
	char secondName[32]; //Фамилия
	char role[10];       //Амплуа
	unsigned short age;  //Возраст
	unsigned short gameCount; //Количество игр
	unsigned short goalCount; //Количество голов
};

void getData(footballPlayer *M, int N){ //Ввод данных о футболистах 
	std::cin.ignore();
	for (int i = 0; i < N; i++)       
	{
		std::cout << "Фамилия: ";
		std::cin.getline(M[i].secondName, 30);
		std::cout << "Амплуа: ";
		std::cin.getline(M[i].role, 30);
		std::cout << "Возраст: ";
		std::cin >> M[i].age;
		std::cin.ignore();
		std::cout << "Количество игр: ";
		std::cin >> M[i].gameCount;
		std::cin.ignore();
		std::cout << "Количество голов: ";
		std::cin >> M[i].goalCount;
		std::cin.ignore();
		std::cout << std::endl;
	}
}

void bestForward(footballPlayer *M, int N) { //Поиск лучшего форварда
	int max = 0;
	for (int i = 0; i < N; i++){  //Цикл определения максимального количества голов
		if (M[i].goalCount >= max)
			max = M[i].goalCount;
	}
	for (int i = 0; i < N; i++) { //Цикл определения игрока, которому принадлежит большее количество голов
		if (M[i].goalCount == max) {
			std::cout << "Лучший форвард: " << M[i].secondName << std::endl;

		}
	}
}

void playedLessThan5Games(footballPlayer *M, int N) { // Поиск игроков сыгравших меньше 5 игр
	std::cout << "\nИгроки сыгравшие меньше 5 игр: " << std::endl << std::endl;
	for (int i = 0; i < N; i++){
		if (M[i].gameCount < 5){ // Вывод полной информации о игроке сыгравшем меньше 5 игр
			std::cout << "Фамилия: " << M[i].secondName << " Амплуа: " << M[i].role << " Возраст: " << M[i].age << std::endl;
			std::cout << "Количество игр: " << M[i].gameCount << " Количество голов: " << M[i].goalCount << std::endl << std::endl;
		}
	}
}

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "Rus");
	
	int N;      
	std::cout << "Введите количетсво игроков : ";
	std::cin >> N;

	footballPlayer *M = new footballPlayer[N];        
	getData(M, N);   //Ввод данных    
	bestForward(M, N);// Лучший форвард
	playedLessThan5Games(M, N); // Игроки сыгравшие меньше 5 игр
	
	delete[]M;  //Очистка динамической памяти   

	return 0;
}

