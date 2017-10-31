#include "stdafx.h"
#include "Compare.h"
#include "WinOrientDoc.h"
#include "Reporter.h"
#include <qtextcodec.h>

using namespace std;

bool IsSimilarNames(QString s1, QString s2, int nFirstLettersCompareCount)
{
	int sz = min(s1.size(), s2.size());
	sz = min(sz, nFirstLettersCompareCount-1);

	for (int i = 0; i < sz; ++i)
		if (s1[i] != s2[i])
			return false;

	return true;
}

void ReplaceE(QString & s, QTextCodec * codec)
{
	s.replace(codec->toUnicode("¸"), codec->toUnicode("å"));
	s.replace(codec->toUnicode("¨"), codec->toUnicode("Å"));
}

void Compare( CDoc const & TestDoc, CDoc const & BaseDoc, SCompareSettings const & settings, IReporter & reporter)
{
	QTextCodec * codec = QTextCodec::codecForName("Windows-1251");
	for (size_t i =0; i< TestDoc.Data.size(); ++i)
	{
		bool bFound = false;
		size_t j =0;
		std::vector<CData> vrSimilarMembers;
		for (; j < BaseDoc.Data.size(); ++j)
		{
			QString sTestName = codec->toUnicode(TestDoc.Data[i].Name).simplified();
			QString sBaseName = codec->toUnicode(BaseDoc.Data[j].Name).simplified();
			ReplaceE(sTestName, codec);
			ReplaceE(sBaseName, codec);
			if (sTestName == sBaseName)
			{
				bFound = true;
				break;
			}
			else if (IsSimilarNames(sTestName, sBaseName, settings.nFirstLettersCompareCount))
				vrSimilarMembers.push_back(BaseDoc.Data[j]);
		}
		if (!bFound)
		{
			if (settings.ConsiderRank(TestDoc.Data[i].Kwal))
				reporter.Warning(SWarning(TestDoc.Data[i], SWarning::er_Absent_in_Base, vrSimilarMembers));
			continue;
		}

		if (TestDoc.Data[i].Kwal != BaseDoc.Data[j].Kwal)
			if (settings.ConsiderRank(TestDoc.Data[i].Kwal) || settings.ConsiderRank(BaseDoc.Data[j].Kwal))
				reporter.Warning(SWarning(TestDoc.Data[i], SWarning::er_DiffrentRanks, BaseDoc.Data[j]));
	}
}