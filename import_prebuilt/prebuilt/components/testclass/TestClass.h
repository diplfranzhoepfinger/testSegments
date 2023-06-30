/*
 * TestClass.h
 *
 *  Created on: 30.06.2023
 *      Author: franz
 */

#ifndef COMPONENTS_TESTCLASS_TESTCLASS_H_
#define COMPONENTS_TESTCLASS_TESTCLASS_H_


#include "stringdict.h"

class TestClass final
{

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];



public:
  const CStringDictionary::TStringId* getDict(int i);

};

#endif /* COMPONENTS_TESTCLASS_TESTCLASS_H_ */
