#include <iostream>

int summ(int num1, int num2, int num3, int num4, int num5)
{
	int summ = num1 + num2 + num3 + num4 + num5;
	std::cout << summ;
	return summ;
}

int arithmetic_mean(int num1, int num2, int num3, int num4, int num5)
{
	int arithmetic_mean = (num1 + num2 + num3 + num4 + num5) / 5;
	std::cout << arithmetic_mean;
	return arithmetic_mean;
}

void parity(int num1, int num2, int num3, int num4, int num5)
{
	bool trueness = false;
	if (num1 % 2 == 0) {
		std::cout << num1 << std::endl;
		trueness = true;
	}
	if (num2 % 2 == 0) {
		std::cout << num2 << std::endl;
		trueness = true;
	}
	if (num3 % 2 == 0) {
		std::cout << num3 << std::endl;
		trueness = true;
	}
	if (num4 % 2 == 0) {
		std::cout << num4 << std::endl;
		trueness = true;
	}
	if (num5 % 2 == 0) {
		std::cout << num5 << std::endl;
		trueness = true;
	}

	if (trueness == false)
		std::cout << "�� �� ����� �� ������ ������� �����";
}

void negative_oddness(int num1, int num2, int num3, int num4, int num5)
{
	bool trueness = false;
	if (num1 % 2 != 0 && num1 * -1 > 0) {
			std::cout << num1 << std::endl;
			trueness = true;
	}
	if (num2 % 2 != 0 && num2 * -1 > 0) {
			std::cout << num2 << std::endl;
			trueness = true;
	}
	if (num3 % 2 != 0 && num3 * -1 > 0) {
			std::cout << num3 << std::endl;
			trueness = true;
	}
	if (num4 % 2 != 0 && num4 * -1 > 0) {
			std::cout << num4 << std::endl;
			trueness = true;
	}
	if (num5 % 2 != 0 && num5 * -1 > 0) {
			std::cout << num5 << std::endl;
			trueness = true;
	}

	if (trueness == false)
			std::cout << "�� �� ����� �� ������ �������������� ��������� �����";
}

void array(int num1, int num2, int num3, int num4, int num5)
{
	int basic_array[5];
	basic_array[0] = num1;
	basic_array[1] = num2;
	basic_array[2] = num3;
	basic_array[3] = num4;
	basic_array[4] = num5;

	for (int i = 0; i < 5; i++) {
		std::cout << basic_array[i] << " ";
	}
}

int main()
{
	system("chcp 1251");

	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	int choice;

	std::cout << "������� 5 �����\n"; std::cin >> num1 >> num2 >> num3 >> num4 >> num5;

	std::cout << "�������� ��� ������\n" << "1. ������ �����\n" << "2. ����� ����� �������\n" << "3. ������� ��� ������ �����\n" << "4. ������� ��� ������������� �������� �����\n" << "5. ������� ������ �� ��������� �����\n" << "6. �����\n"; std::cin >> choice;

	switch (choice) {
	case 1: {
		summ(num1, num2, num3, num4, num5);
		break;
	}
	case 2: {
		arithmetic_mean(num1, num2, num3, num4, num5);
		break;
	}
	case 3: {
		parity(num1, num2, num3, num4, num5);
		break;
	}
	case 4: {
		negative_oddness(num1, num2, num3, num4, num5);
		break;
	}
	case 5: {
		array(num1, num2, num3, num4, num5);
		break;
	}
	case 6: {
		exit(0);
	}
	default: {
		std::cout << "�� ����� ���-�� �� ��";
		exit(0);
	}
	}
}
// num1, num2, num3, num4, num5