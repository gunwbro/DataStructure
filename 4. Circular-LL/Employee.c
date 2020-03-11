#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Employee.h"

Employee* MakeEmployee(char* number, char* name)
{
	Employee* newEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(newEmp->number, number);
	strcpy(newEmp->name, name);
	
	return newEmp;
}