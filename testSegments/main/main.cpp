#include <stdio.h>


#include "TestClass.h"

/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{


	TestClass * t = new TestClass();
	CStringDictionary::TStringId u = *t->getDict(0);
	printf("u = %li /n", u);

}
