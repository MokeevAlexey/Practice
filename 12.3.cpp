#include <iostream>
#include <cstdlib>
#include <ctime>

void create(int*& array, int size) {
	array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10;
	}
}

void copy(int* array, int size, int* array2, int& size2, int call_copy, int* array3) {
	for (int i = 0; i < size; i++) {
			array2[i] = array[i];
	}

	if (call_copy == 4) {
		for (int i = 0; i < size; i++) {
			std::cout << array3[i] << " ";
		}
		std::cout << std::endl;
	}
}

void increase(int*& array, int& size, int call_copy, int* array3) {
	int size2 = size;
	int* array2 = new int[size2];
	if (call_copy == 2) {
		size2 = size + 5;
		size = size2;
	}
	else if (call_copy == 3) {
		copy(array, size, array2, size2, call_copy, array3);
		for (int i = 0; i < size2; i++) {
			array3[i] = array2[i];
		}
	}
	else if (call_copy == 4) {
		copy(array, size, array2, size2, call_copy, array3);
	}
}

void decrease(int*& array, int& size) {
	if (size > 2) {
		int size2 = size - 2;
		size = size2;
		int* array2 = new int[size2];
		std::cout << "Размер массива уменьшен на 2! \nТекущий размер массива: " << size << "\n\n";
	}
	else {
		std::cout << "Вы больше не можете уменьшать размер массива\n";
		std::cout << "Текущий размер массива: " << size << "\n\n";
	}
}

int main()
{
	system("chcp 1251"); system("cls");
	srand(0);
	const int size3 = 100000;
	int size = 5;
	int* array = nullptr;
	int array3[size3]{ 0 };
	int call_copy = 1;
	bool exist = false;
	bool deleted = false;
	bool copied = false;
	std::cout << "Привет! \n";
	while (true) {
		int choice;
		std::cout << "Выбери что ты хочешь сделать \n1. Создать массив \n2. Заполнить массив (после первого заполнения будет *обновление* массива) \n3. Копировать массив \n4. Увеличить размер массива \n5. Уменьшить размер массива \n6. Вывести массив \n7. Удалить массив \n8. Вывести скопированный массив \n9. Выйти\n";
		if (call_copy == 1) {
			std::cout << "(базовый размер массива = 5)\n";
			call_copy += 1;
		}
		std::cout << "Твой выбор: ";  std::cin >> choice; std::cout << std::endl;
		if (choice == 9)
			exit(0);

		switch (choice) {
		case 1: {
			if (exist == true) {
				std::cout << "Массив уже существует, ты не можешь создать еще один\n\n";
			}
			else {
				create(array, size);
				std::cout << "Массив успешно создан!\n\n";
				exist = true;
				deleted = false;
			}
			break;
		}
		case 2: {
			if (deleted == true) {
				std::cout << "Ты не можешь заполнить массив, который только что удалил, попробуй не удалять его перед заполнением\n\n";
			}
			else if (exist == false) {
				std::cout << "Кажется, массив который ты хочешь заполнить не существует, попробуй сначала создать его!\n\n";
			}
			else {
				std::cout << "Заполняем массив";
				for (int i = 0; i < size; i++) {
					std::cout << "\nЧисло под индексом " << i << " будет: "; std::cin >> array[i];
				}
				std::cout << std::endl << "Массив заполнен!\n" << std::endl;
			}
			break;
		}
		case 3: {
			if (deleted == true) {
				std::cout << "Ты не можешь скопировать массив, который только что удалил, попробуй не удалять его перед копированием\n\n";
			}
			else if (exist == false) {
				std::cout << "Кажется, массив который ты хочешь скопировать не существует, попробуй сначала создать его!\n\n";
			}
			else {
				copied = true;
				call_copy = 3;
				increase(array, size, call_copy, array3);
				std::cout << "Массив успешно скопирован!\n\n";
				call_copy = 2;
			}
			break;
		}
		case 4: {
			increase(array, size, call_copy, array3);
			std::cout << "Размер массива увеличен на 5! \nТекущий размер массива: " << size << "\n\n";
			break;
		}
		case 5: {
			decrease(array, size);
			break;

		}
		case 6: {
			if (deleted == true) {
				std::cout << "Ты не можешь вывести массив, который только что удалил, попробуй не удалять его перед выводом\n";
			}
			else if (exist == false) {
				std::cout << "Массив, который ты хочешь вывести еще не существует, попробуй сначала создать его!\n";
			}
			else {
				for (int i = 0; i < size; i++) {
					std::cout << array[i] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
			break;
		}
		case 7: {
			if (exist == false) {
				std::cout << "Тебе еще нечего удалять, попробуй сначала создать массив что бы удалить его!\n\n";
			}
			else if (deleted == true) {
				std::cout << "Ты уже удалил массив, попробуй сначала создать его снова!\n\n";
			}
			else {
				delete[] array;
				array = nullptr;
				std::cout << "Массив успешно удален!\n\n";
				deleted = true;
				exist = false;
			}
			break;
		}
		case 8: {
			if (copied == false) {
				std::cout << "Ты пока что не скопировал ни одного массива!\n\n";
			}
			else {
				call_copy += 2;
				increase(array, size, call_copy, array3);
				std::cout << std::endl;
				call_copy -= 2;
			}
			break;
		}
		default: {
			std::cout << "Что-то не так...\n\n";
			break;
		}
		}
	}
	
	delete[] array;
	array = nullptr;
}