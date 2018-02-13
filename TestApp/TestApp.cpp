// TestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\printf_ex\printf_ex.h"
#include "..\printf_ex\to_string.h"
#include <array>

using namespace PrintF_ex;
using std::string;
using std::wstring;
using std::array;


void TestRun()
{
	Printl("Starting PrintF_ex tests...");

	string SEP(10, '=');

	Printl(SEP + " MESSEGES " + SEP);

	Printl("This is a messege. %d - %d", 123, 456);
	Printl("Here's a c string: %s", "Hello world");

	wstring printStrings{ L"Print messages stored in std strings!" };
	Printl(printStrings);

	Print("Start of a line... "); Print("-- %d --", 4321); Printl(" ...end of a line.");

	auto cutMsg = ToString("Don't print the rest of this message... asdasdasdsasdsasd", 35);
	Printl(cutMsg);

	Printl(L"This is a wide message");
	Print("\n");

	Printl(SEP + " ToString " + SEP);
	
	Print("\n");
	Printl("Printing numerics w/ ToString");
	Print("\n");

	string expected = "123.46";
	string actual = ToString(123.456, 2);

	Print("Expected: %s, Actual %s - ", expected, actual);
	ASSERT(expected == actual);
	Printl("Ok!");


	auto number = rand() / 2.3;
	Printl("A number is %s", ToString(number, 4));

	Print("\n");

	string customFmt;
	Format(customFmt, "Tps Reports:\n%d) %s\n%d) %s %s", 
		   1, "Needs a new tonner!", 
		   2, "Budget", ("$" + ToString(654.87452f, 3)) );

	Printl(customFmt);

	Print("\n\n");

	
	Printl("wchar_t * to string:");

	wchar_t * wcBefore = L"The wide cháràcter fõx jumpêd over the lazy dog.";
	auto strAfter = ToString(wcBefore, wcslen(wcBefore) + 1);

	Printl("- Before:\t%ls", wcBefore);
	Printl("- After:\t%s", strAfter);

	Print("\n\n");

	Printl("char * to wstring:");

	char* cBefore = "The wide cháràcter fõx jumpêd over the lazy dog.";
	auto wstrAfter = ToString(cBefore, strlen(cBefore) + 1);

	Printl("- Before:\t%s", cBefore);
	Printl(L"- After:\t%s", wstrAfter);

	Print("\n\n");

	// Some names
	array<string, 5> saleReps = 
	{
		"Fulano", "Ciclano",
		"Beltrano", "José",
		"Maria"
	};

	Printl("SALES REPORT\n");
	for (size_t i = 0; i < saleReps.size(); i++)
	{
		int salesNum = rand();

		Print("%-10s", saleReps[i]);
		Printl("%d items", salesNum);
	}

	Print("\n\n");

	Printl(SEP + "Define a custom endline!" + SEP);

	unsigned nlCount = 5;

	Print("Printing %d new lines after this message", Endl('\n', nlCount), nlCount);
}

int main()
{
	auto nlCount = 5;

	TestRun();

    return 0;
}

