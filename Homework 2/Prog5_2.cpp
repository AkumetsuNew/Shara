#include <iostream>
#include <vector>

// ���������� ��� ������������� �������
void PrimeChecker(int* &primes2, int& primesFound, int numberChecked)
{
	bool isPrime = true;

	// ��������� ��������� �� ��� ����� �������� ������� �����
	for (auto j = 0; j < primesFound; j++)
		if (numberChecked % primes2[j] == 0)
		{
			isPrime = false;
			break;
		}

	// ��������� ��������� ������� ����� � ������� �������
	if (isPrime)
	{
		primes2[primesFound] = numberChecked;
		primesFound++;
	}
}

void PrimeChecker(std::vector<int> &primes, int &primesFound, int numberChecked)
{
	bool isPrime = true;

	// ��������� ��������� �� ��� ����� �������� ������� �����
	for (auto j = 0; j < primesFound; j++)
		if (numberChecked % primes[j] == 0)
		{
			isPrime = false;
			break;
		}

	// ��������� ��������� ������� ����� � ������� �������
	if (isPrime)
	{
		primes[primesFound] = numberChecked;
		primesFound++;
	}
}

void Prog5_2() 
{
	int upperBound, method, primesFound = 1;
	std::vector<int> primes;

	// ���� ������
	std::cout << "�������� ������ ���������� ��� ������ ������� ����� � ��������� �� 2 �� ���������.\n" << std::endl;
	std::cout << "������� �����, �� �������� ����� ������� �����:" << std::endl;
	std::cin >> upperBound;

	// �������� �����
	if (upperBound <= 1)
	{
		std::cout << "����� ������ ���� ������ �������!" << std::endl;
		return;
	}

	std::cout << "����� �������� ������?"
		<< "\n1. ����� �������"
		<< "\n2. ����� ������������ �������" << std::endl;
	std::cin >> method;
	
	switch (method)
	{
	case 1:
		// ������� ������� ������� � ������� ��������
		primes.resize(ceil((double)upperBound / 2));
		primes[0] = 2;


		// ����� �������
		for (auto number = 3; number <= upperBound; number++)
			PrimeChecker(primes, primesFound, number);

		// �����
		for (auto i = 0; i < primesFound; i++)
			std::cout << std::endl << i + 1 << ". " << primes[i];
		
		primes.clear();
		break;

	case 2:
	{
		// ������� ������� ������� � ������� ��������
		int* primes2 = new int[ceil((double)upperBound / 2)];
		primes2[0] = 2;

		// ����� �������
		for (auto number = 3; number <= upperBound; number++)
			PrimeChecker(primes2, primesFound, number);

		// �����
		for (auto i = 0; i < primesFound; i++)
			std::cout << std::endl << i + 1 << ". " << primes2[i];

		delete[] primes2;
		break;
	}
	default:
		std::cout << "����� ������������ ����� �������." << std::endl;
	}
	return;
}