/********************************************************
*
* CPU INFORMER is GPLv3 licenced source code.
*
* (C) Vertver, 2018
*
* CPU INFORMER Source Code is free software:
* You can redistribute it and/or modify it.
*
* main.h - main point with int main().
* Need for print on screen a list of instructions
*
*********************************************************/

#include "stdafx.h"

/***********************************************
* int main() - main method for init application
* and run other methods
***********************************************/

int main()
/*int WINAPI WinMain (
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
	*/
{


#ifdef INSTRUCTIONS_COUNT
	//const bool instructions = strstr(lpCmdLine, "-instructions");
	//const bool stressCPU = strstr(lpCmdLine, "-stress");
	//if (instructions) 
	//{
		auto& outstream = std::cout;

		// More easily then use printf()
		auto support_message = [&outstream](
			std::string isa_feature,
			bool is_supported)
		{
			outstream << isa_feature << (
				is_supported ?
				" supported"
				: " not supported"
				)
				<< std::endl;
		};

		// Header
		printf("Welcome to CPU INFORMER! Your CPU");
		putchar('\n');

		// Searching a string of CPU
		if (CPUID::AMD())
			printf("(AMD) ");
		else
			printf("(Intel) ");
		std::cout << CPUID::Vendor() << std::endl;
		std::cout << CPUID::ModelCPU() << std::endl;

		putchar('\n');
		printf("Supported or Unsupported instructions");
		putchar('\n');

		printf("MMX instructions");
		putchar('\n');

		support_message("MMX", CPUID::MMX());
		support_message("MMXEXT", CPUID::MMXEXT());

		putchar('\n');

		printf("3DNow! instructions");
		putchar('\n');

		support_message("3DNOW", CPUID::_3DNOW());
		support_message("3DNOWEXT", CPUID::_3DNOWEXT());

		putchar('\n');

		printf("SSE instructions");
		putchar('\n');

		support_message("SSE", CPUID::SSE());
		support_message("SSE2", CPUID::SSE2());
		support_message("SSE3", CPUID::SSE3());
		support_message("SSSE3", CPUID::SSSE3());
		support_message("SSE4.1", CPUID::SSE41());
		support_message("SSE4.2", CPUID::SSE42());
		support_message("SSE4a", CPUID::SSE4a());

		putchar('\n');

		printf("AVX instructions");
		putchar('\n');

		support_message("AVX", CPUID::AVX());
		support_message("AVX2", CPUID::AVX2());
		support_message("AVX512CD", CPUID::AVX512CD());
		support_message("AVX512ER", CPUID::AVX512ER());
		support_message("AVX512F", CPUID::AVX512F());
		support_message("AVX512PF", CPUID::AVX512PF());

		putchar('\n');

		printf("FMA3 instructions");
		putchar('\n');

		support_message("FMA3", CPUID::FMA());

		putchar('\n');

		printf("Monitor instructions");
		putchar('\n');

		support_message("MONITOR", CPUID::MONITOR());
		support_message("TM2", CPUID::TM2());

		putchar('\n');

		printf("Clock instructions");
		putchar('\n');

		// Pentium CPU Clock 
		support_message("RDTSCP", CPUID::RDTSCP());

		putchar('\n');

		// Other instructions
		printf("Other instructions");
		putchar('\n');

		support_message("RTM", CPUID::RTM());
		support_message("SHA", CPUID::SHA());
		support_message("AES", CPUID::AES());
		support_message("SYSCALL", CPUID::SYSCALL());


		putchar('\n');

	//}
#endif

#ifdef CPUSTRESS 
	//if (stressCPU) 
#endif
	system("pause");
    return 0;
}
