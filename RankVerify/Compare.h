#ifndef RV_COMPARE
#define RV_COMPARE
/********************************************************************
	created:	2010/05/19
	created:	19:5:2010   17:22
	filename: 	d:\Orienteering\RankVerify\Compare.h
	file path:	d:\Orienteering\RankVerify
	file base:	Compare
	file ext:	h
	author:		PSP
	
	purpose:	
*********************************************************************/
class CDoc;
class IReporter;

#include <set>

struct SCompareSettings
{
	bool ConsiderRank(int rank) const { 
		return m_RanksToCompare.count(rank) == 1;
	}
	std::set<int> m_RanksToCompare;
	int nFirstLettersCompareCount;
};

void Compare(CDoc const & TestDoc, CDoc const & BaseDoc, SCompareSettings const & settings, IReporter & reporter);
#endif // RV_COMPARE