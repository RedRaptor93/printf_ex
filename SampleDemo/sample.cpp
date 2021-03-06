#include "../printf_ex/printf_ex.h"
#include <array>
#include <random>

#if defined _MSC_VER
	#define FMT_WC_B4		L"- Before:\t%s"
	#define FMT_WC_AFTER	L"- After:\t%s"
	#define FMT_STR_IN_WIDE L"%S"
	#define TPS_REPORTS_W	L"Tps Reports:\n%d) %s\n%d) %s %.2f"
#elif defined __GNUG__
	#define FMT_WC_B4		L"- Before:\t%ls"
	#define FMT_WC_AFTER	L"- After:\t%ls"
	#define FMT_STR_IN_WIDE L"%s"
	#define TPS_REPORTS_W	L"Tps Reports:\n%d) %ls\n%d) %ls %.2f"
#endif // _MSC_VER

#define RAW_BUFFER 256

auto lorem_ipsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus velit quam, consequat a hendrerit non, tempor in elit. Quisque eu risus at neque eleifend posuere sed id odio.";
auto japa = L"菜祉視捌歯若";

using namespace Red;
using std::string;
using std::wstring;
using std::array;


void TestRun()
{
	Printl("Starting PrintF_ex tests...");

	string fmt = "%d %d %d - %s";
	Printl(fmt, 3, 2, 1, "Go!");
	
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
	
	Print("\nPrinting numerics w/ ToString\n\n");

	string expected = "123.46";
	string actual = ToString(123.457, 2);

	Print("Expected: %s, Actual %s - ", expected, actual);
	//PF_ASSERT(expected == actual);
	Printl("Ok!");

	Print("\n");
	
	auto wcBefore = L"The wide cháràcter fõx jumpêd over the lazy dog.";
	auto cBefore = "The wide cháràcter fõx jumpêd over the lazy dog.";
	
	auto strAfter = ToString(wcBefore);
	auto wstrAfter = ToWideString(cBefore);

	Printl("wchar_t * to string:");

	Printl(FMT_WC_B4, wcBefore);
	Printl("- After:\t%s", strAfter);

	Print("\n");

	Printl("char * to wstring:");


	Printl("- Before:\t%s", cBefore);
	Printl(FMT_WC_AFTER, wstrAfter);

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

	std::random_device rd;
	std::minstd_rand rng(rd());
	std::uniform_int_distribution<int> uni(0, 0x7fff);

	for (size_t i = 0; i < saleReps.size(); i++)
	{
		int salesNum = uni(rng);
		Printl("%-10s%8d %s", saleReps[i], salesNum, "items");
	}

	Print("\n\n");

	Printl(SEP + " FormatString and FormatBuffer " + SEP);
	Printl("Use FormatString to format a message to a std::string!");
	Print("\n\n");

	Print("Utf8:\n\n");

	string customFmt;
	FormatString(customFmt, "Tps Reports:\n%d) %s\n%d) %s %.2f",
				 1, "Needs a new tonner!",
				 2, "Budget", 654.87452f);

	Print(customFmt + "\n\n\n");
	Print("Utf16:\n\n");

	wstring customFmtWide;
	FormatString(customFmtWide, TPS_REPORTS_W,
				 1, L"Needs a new tonner!",
				 2, L"Budget", 654.87452f);

	customFmtWide += L"\n\n\n";
	Print(customFmtWide);

	Print("Or, if you need to format a c-style string, use FormatBuffer\n\n");

	wchar_t customfmtraw[RAW_BUFFER];
	FormatBuffer(customfmtraw, RAW_BUFFER, FMT_STR_IN_WIDE, lorem_ipsum);

	Printl("%ls", customfmtraw);
}

//void TestBadBuffers()
//{
//	wchar_t badbuffwide[150];
//	FormatBuffer(badbuffwide, 150, L"%S\n%d", lorem_ipsum, 42);
//}

int main()
{
	setlocale(LC_ALL, "");
	TestRun();
	//TestBadBuffers();
	return 0;
}
