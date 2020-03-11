#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

typedef struct __employee
{
	char number[32];
	char name[32];
} Employee;

Employee* MakeEmployee(char* number, char* name);

#endif