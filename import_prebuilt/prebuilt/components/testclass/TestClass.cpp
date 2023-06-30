/*
 * TestClass.cpp
 *
 *  Created on: 30.06.2023
 *      Author: franz
 */

#include "TestClass.h"

extern const CStringDictionary::TStringId g_nStringIdMI = 7759;
extern const CStringDictionary::TStringId g_nStringIdQI = 8012;
extern const CStringDictionary::TStringId g_nStringIdQL = 8015;
extern const CStringDictionary::TStringId g_nStringIdQO = 8018;
extern const CStringDictionary::TStringId g_nStringIdQU = 8021;
extern const CStringDictionary::TStringId g_nStringIdQW = 8024;
extern const CStringDictionary::TStringId g_nStringIdQX = 8027;
extern const CStringDictionary::TStringId g_nStringIdDEAD = 979;
extern const CStringDictionary::TStringId g_nStringIdHYSTERESIS = 7543;
extern const CStringDictionary::TStringId g_nStringIdINPUT = 7602;

const CStringDictionary::TStringId TestClass::scm_anDataInputNames[] = {
		g_nStringIdQI, g_nStringIdMI, g_nStringIdDEAD, g_nStringIdHYSTERESIS,
		g_nStringIdINPUT };

const CStringDictionary::TStringId* TestClass::getDict(int i) {
	return &scm_anDataInputNames[i];
}
