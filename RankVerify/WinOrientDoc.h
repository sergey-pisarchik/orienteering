#ifndef RV_WINORIENTDOC
#define RV_WINORIENTDOC

#include "Data.h"
#include <iostream>
#include <vector>

#define RANK_BR			0
#define RANK_UR1		1
#define	RANK_UR2		2

#define RANK_R1			4
#define RANK_R2			5
#define RANK_R3			6
#define RANK_KMS		7
#define RANK_MS			8


class CDoc
{
public:
void readData(std::istream & ar);
std::vector<CData> Data;
std::vector<CKoll> Koll;
std::vector<CGrup> Grup;
std::vector<CDist> Dist;
std::vector<CFin> Fin;
std::vector<CCp> Cp;
std::vector<CSi> Si;
CInfo Info;
};

#endif