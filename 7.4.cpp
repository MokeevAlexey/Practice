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
		std::cout << "Вы не ввели ни одного четного числа";
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
			std::cout << "Вы не ввели ни одного отрицательного нечетного числа";
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

	std::cout << "Введите 5 чисел\n"; std::cin >> num1 >> num2 >> num3 >> num4 >> num5;

	std::cout << "Выберите что нибудь\n" << "1. Узнать сумму\n" << "2. Найти средн арифмет\n" << "3. Вывести все четные числа\n" << "4. Вывести все отрицательные нечетные числа\n" << "5. Сделать массив из введенных чисел\n" << "6. Выйти\n"; std::cin >> choice;

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
		std::cout << "Вы ввели что-то не то";
		exit(0);
	}
	}
}
// num1, num2, num3, num4, num5