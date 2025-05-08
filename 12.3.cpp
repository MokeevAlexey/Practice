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
		std::cout << "������ ������� �������� �� 2! \n������� ������ �������: " << size << "\n\n";
	}
	else {
		std::cout << "�� ������ �� ������ ��������� ������ �������\n";
		std::cout << "������� ������ �������: " << size << "\n\n";
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
	std::cout << "������! \n";
	while (true) {
		int choice;
		std::cout << "������ ��� �� ������ ������� \n1. ������� ������ \n2. ��������� ������ (����� ������� ���������� ����� *����������* �������) \n3. ���������� ������ \n4. ��������� ������ ������� \n5. ��������� ������ ������� \n6. ������� ������ \n7. ������� ������ \n8. ������� ������������� ������ \n9. �����\n";
		if (call_copy == 1) {
			std::cout << "(������� ������ ������� = 5)\n";
			call_copy += 1;
		}
		std::cout << "���� �����: ";  std::cin >> choice; std::cout << std::endl;
		if (choice == 9)
			exit(0);

		switch (choice) {
		case 1: {
			if (exist == true) {
				std::cout << "������ ��� ����������, �� �� ������ ������� ��� ����\n\n";
			}
			else {
				create(array, size);
				std::cout << "������ ������� ������!\n\n";
				exist = true;
				deleted = false;
			}
			break;
		}
		case 2: {
			if (deleted == true) {
				std::cout << "�� �� ������ ��������� ������, ������� ������ ��� ������, �������� �� ������� ��� ����� �����������\n\n";
			}
			else if (exist == false) {
				std::cout << "�������, ������ ������� �� ������ ��������� �� ����������, �������� ������� ������� ���!\n\n";
			}
			else {
				std::cout << "��������� ������";
				for (int i = 0; i < size; i++) {
					std::cout << "\n����� ��� �������� " << i << " �����: "; std::cin >> array[i];
				}
				std::cout << std::endl << "������ ��������!\n" << std::endl;
			}
			break;
		}
		case 3: {
			if (deleted == true) {
				std::cout << "�� �� ������ ����������� ������, ������� ������ ��� ������, �������� �� ������� ��� ����� ������������\n\n";
			}
			else if (exist == false) {
				std::cout << "�������, ������ ������� �� ������ ����������� �� ����������, �������� ������� ������� ���!\n\n";
			}
			else {
				copied = true;
				call_copy = 3;
				increase(array, size, call_copy, array3);
				std::cout << "������ ������� ����������!\n\n";
				call_copy = 2;
			}
			break;
		}
		case 4: {
			increase(array, size, call_copy, array3);
			std::cout << "������ ������� �������� �� 5! \n������� ������ �������: " << size << "\n\n";
			break;
		}
		case 5: {
			decrease(array, size);
			break;

		}
		case 6: {
			if (deleted == true) {
				std::cout << "�� �� ������ ������� ������, ������� ������ ��� ������, �������� �� ������� ��� ����� �������\n";
			}
			else if (exist == false) {
				std::cout << "������, ������� �� ������ ������� ��� �� ����������, �������� ������� ������� ���!\n";
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
				std::cout << "���� ��� ������ �������, �������� ������� ������� ������ ��� �� ������� ���!\n\n";
			}
			else if (deleted == true) {
				std::cout << "�� ��� ������ ������, �������� ������� ������� ��� �����!\n\n";
			}
			else {
				delete[] array;
				array = nullptr;
				std::cout << "������ ������� ������!\n\n";
				deleted = true;
				exist = false;
			}
			break;
		}
		case 8: {
			if (copied == false) {
				std::cout << "�� ���� ��� �� ���������� �� ������ �������!\n\n";
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
			std::cout << "���-�� �� ���...\n\n";
			break;
		}
		}
	}
	
	delete[] array;
	array = nullptr;
}