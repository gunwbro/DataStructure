#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;
	
	TBLInit(&myTbl, MyHashFunc);

	// ������ �Է� //////////
	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(970624, "Jo", "Bundang");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(980331, "Jang", "Hongseong");
	TBLInsert(&myTbl, GetSSN(np), np);

	// ������ Ž�� //////////
	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 970624);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 980331);
	if (sp != NULL)
		ShowPerInfo(sp);

	// ������ ���� ///////////
	rp = TBLDelete(&myTbl, 900254);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 970624);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 980331);
	if (rp != NULL)
		free(rp);

	return 0;
}