// TestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define ASSERT _ASSERTE


using namespace Red;
using std::string;
using std::wstring;
using std::array;

auto lorem_ipsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus velit quam, consequat a hendrerit non, tempor in elit. Quisque eu risus at neque eleifend posuere sed id odio.";


void TestRun()
{
	Printl("Starting PrintF_ex tests...");

	string const SEP(10, '=');

	Printl(SEP + " MESSEGES " + SEP);

	Printl("This is a messege. %d - %d", 123, 456);
	Printl("Here's a c string: %s", "Hello world");

	wstring printStrings{ L"Print messages stored in std strings!" };
	Printl(printStrings);

	Print("Start of a line... "); Print("-- %d --", 4321); Printl(" ...end of a line.");

	Printl(L"This is a wide message");
	Print("\n");

	Printl(SEP + " ToString " + SEP);
	
	Print("\nPrinting numerics w/ ToString", Endl('\n',2));

	string expected = "123.46";
	string actual = ToString(123.457, 2);

	Print("Expected: %s, Actual %s - ", expected, actual);
	ASSERT(expected == actual);
	Printl("Ok!");


	auto number = rand() / 2.3;
	Printl("A number is %s", ToString(number, 4));

	Print("\n");
	
	Printl("wchar_t * to string:");

	wchar_t * wcBefore = L"The wide cháràcter fõx jumpêd over the lazy dog.";
	auto strAfter = ToString(wcBefore);

	Printl("- Before:\t%ls", wcBefore);
	Printl("- After:\t%s", strAfter);

	Print("\n\n");

	Printl("char * to wstring:");

	char* cBefore = "The wide cháràcter fõx jumpêd over the lazy dog.";
	auto wstrAfter = ToWideString(cBefore);

	Printl("- Before:\t%s", cBefore);
	Printl(L"- After:\t%s", wstrAfter);

	Print("\n");
	Printl(SEP + " Padding " + SEP);
	Print("\n");

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

	Printl(SEP + " FormatString and FormatBuffer " + SEP);
	Printl("Use FormatString to formating a message to a std::string!");
	Print("\n");

	string customFmt;
	FormatString(customFmt, "Tps Reports:\n%d) %s\n%d) %s %.2f",
				 1, "Needs a new tonner!",
				 2, "Budget", 654.87452f);

	Print(customFmt, endline(3));

	Print("Or, if you need to format a c-style string, use FormatBuffer", endline(2));

	wchar_t customfmtraw[256];
	FormatBuffer(customfmtraw, 256, L"%S", lorem_ipsum);

	Printl("%ls", customfmtraw);

	Print("\n\n");


	Printl(SEP + "Define a custom endline!" + SEP);

	unsigned nlCount = 5;
	Print("Printing %d new lines after this message", endline(nlCount), nlCount);
}

int main()
{
	//system("chcp 65001");
	auto nlCount = 5;

	Print("Starting in... ");
	string fmt = "%d %d %d - %s";
	Printl(fmt, 3, 2, 1, "Go!");

	TestRun();

	// bad
	//wchar_t raw[150];
	//FormatBuffer(raw, 150, L"%S", lorem);

	return 0;
}

