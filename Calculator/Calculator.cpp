#include "Calculator.h"

void BeginProgram()
{
	Menu();
}

void Menu()
{
	vector <int> nums;
	vector <char> operations;
	while (true)
	{
		cout << "Enter the num:\n";
		EnterNum(nums);
		cout << "Enter the operation:\n";
		EnterOperation(nums, operations);
	}
	
}

void EnterNum(vector<int> & nums)
{
	int num;
	cin >> num;
	nums.push_back(num);
}

void EnterOperation(vector<int>& nums, vector<char>& operations)
{
	char ch;
	cin >> ch;
	if (CheckOperations(ch))
		operations.push_back(ch);
	else if(ch == 61)
	{
		Operations(nums, operations);
	}
	else
	{
		cout << "Incorrect operation";
		exit(-1);
	}
		
}

bool CheckOperations(char ch)
{
	if (ch == 42 || ch == 43 || ch == 45 || ch == 47)
		return true;
	return false;
}

bool IsHavePriorityOperation(vector<char>& operations)
{
	for (size_t i = 0; i < operations.size(); i++)
	{
		if (operations[i] == 42 || operations[i] == 47)
			return true;
	}
	return false;
}

void Operations(vector<int>& nums, vector<char>& operations)
{
	int result = 0;
	if (IsHavePriorityOperation(operations))
	{
		//int count = operations.size();
		for (int i = 0; i < operations.size(); i++)
		{
			switch (operations[i])
			{
			case 42: nums[i] = Multiplication(nums[i], nums[i + 1]); 
				nums.erase(nums.begin() + i + 1);
				operations.erase(operations.begin() + i);
				continue;
			//case '43': Plus(nums[i], nums[i + 1]);
			//case '45': Minus(nums[i], nums[i + 1]);
			case 47: 
				nums[i] = Division(nums[i], nums[i + 1]); 
				nums.erase(nums.begin() + i + 1);
				operations.erase(operations.begin() + i);
				continue;
			default:
				continue;
			}
		}
	}

	for (int i = 0; i < operations.size(); i++)
	{
		switch (operations[i])
		{
		//case '42': Multiplication(nums[i], nums[i + 1]);
		case 43: nums[i] = Plus(nums[i], nums[i + 1]); 
			nums.erase(nums.begin() + i + 1); 
			operations.erase(operations.begin() + i);
			continue;
		case 45: nums[i] = Minus(nums[i], nums[i + 1]); 
			nums.erase(nums.begin() + i + 1); 
			operations.erase(operations.begin() + i);
			continue;
		//case '47': Division(nums[i], nums[i + 1]);
		default:
			continue;
		}
	}
	result = nums[0];
	cout << " = " << result << "\n";
	Sleep(5000);
	nums.clear();
	operations.clear();
	system("cls");

	//cout << "Operation " << nums[0] << " " << operations[0] << " " << nums[1] << " = " << (nums[0] / nums[1]) << "\n";
}

int Plus(int& num1, int& num2)
{
	return num1 + num2;
}

int Minus(int& num1, int& num2)
{
	return num1 - num2;
}

int Multiplication(int& num1, int& num2)
{
	return num1 * num2;
}

int Division(int& num1, int& num2)
{
	try
	{
		if (num2 == 0)
		{
			throw "Can not divided by zero!\n";
		}
		return num1 / num2;
	}
	catch (const char* exception)
	{
		cout << exception;
		exit(0);
	}
}
