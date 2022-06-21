#pragma once
#include "/Step/C++/Training/AllLibraries.h"

void BeginProgram();
void Menu();
void EnterNum(vector<int>& nums);
void EnterOperation(vector<int>& nums, vector<char>& operations);
bool CheckOperations(char ch);
bool IsHavePriorityOperation(vector<char>& operations);
void Operations(vector<int>& nums, vector<char>& operations);
int Plus(int& num1, int& num2);
int Minus(int& num1, int& num2);
int Multiplication(int& num1, int& num2);
int Division(int& num1, int& num2);