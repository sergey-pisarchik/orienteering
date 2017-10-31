#include "stdafx.h"
#include "Reporter.h"
#include <QTextCodec>
#include "WinOrientDoc.h"
#include <algorithm>

#define T(x) codec->toUnicode(x)

class doCompare
{
public:
	bool operator()(SWarning const & war1, SWarning const & war2) const
	{
		if (war1.m_err == war2.m_err)
		{
			if (war1.m_err == SWarning::er_Absent_in_Base)
			{
				return war1.m_dataTest.Kwal < war2.m_dataTest.Kwal;
			}
			if (war1.m_err == SWarning::er_DiffrentRanks)
			{
				return war1.m_dataBase.Kwal < war2.m_dataBase.Kwal;
			}
		}
		return war1.m_err < war2.m_err;
	}
};

namespace
{
	QString GetName(QString const & sName)
	{
		QString res = sName.simplified();
		while (res.length() < 25)
			res += " ";
		return res;
	}
}

QString CStringReporter::getMessage()
{
	QString s;
	std::sort(m_warnings.begin(), m_warnings.end(), doCompare());
	for (size_t i =0; i<m_warnings.size(); ++i)
	{
		SWarning const & war = m_warnings[i];
		switch (war.m_err)
		{
		case SWarning::er_Absent_in_Base:
			{
				/*if (war.m_dataTest.Kwal < 7)
					break;*/
				s += T("��� � ��������� ���� ");
				s += GetName(T(war.m_dataTest.Name));
				s += T(" ���� ");
				s += GetRank(war.m_dataTest.Kwal);
				s += T("\n");

				if (war.m_vrSimilarPersons.empty())
				{
					//s += T("    � �������� ���� ����� � ������� ������ ���.\n");
				}
				else
				{
					s += T("    ������ ����� � ��������� ���� � �������� �������: \n");
					for (int j =0; j < war.m_vrSimilarPersons.size(); ++j)
					{
						s += T("      - ");
						s += GetName(T(war.m_vrSimilarPersons[j].Name));
						s += T(" ���� ");
						s += GetRank(war.m_vrSimilarPersons[j].Kwal);
						s += T("\n");
					}
				}

				break;
			}
			
		case SWarning::er_DiffrentRanks:
			/*if (war.m_dataTest.Kwal < 7 && war.m_dataBase.Kwal < 7)
				break;*/
			s += T("���� ");
			s += GetName(T(war.m_dataTest.Name));

			s += T(" ������ ���� ") + GetRank(war.m_dataBase.Kwal) + T(" � ������ ��� ") + GetRank(war.m_dataTest.Kwal) + T(" \n");
			break;
		}
	}
	return s;
}

QString CStringReporter::GetRank(int i)
{
	switch (i)
	{
	case RANK_BR: return T("�/�");
	case RANK_UR1: return T("1 �.�.");
	case RANK_UR2: return T("2 �.�.");
	
	case RANK_R1: return T("1 �");
	case RANK_R2: return T("2 �");
	case RANK_R3: return T("3 �");
	case RANK_KMS: return T("���");
	case RANK_MS: return T("��");
	}
	return "";
}



void CStringReporter::Warning( SWarning const & war )
{
	m_warnings.push_back(war);
}

CStringReporter::CStringReporter()
{
	codec = QTextCodec::codecForName("Windows-1251");
}