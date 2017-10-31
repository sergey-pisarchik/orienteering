#ifndef RV_REPORTER_H
#define RV_REPORTER_H

 #include <QString>
#include "Data.h"
#include <vector>

struct SWarning
{
	enum EWarning{
		er_Absent_in_Base, // нет в эталонной базе
		er_DiffrentRanks // не совпадает ранг
	};
	SWarning(CData const & dataTest, EWarning err, CData const & dataBase)
		:m_dataTest(dataTest), m_dataBase(dataBase), m_err(err){}
	SWarning(CData const & dataTest, EWarning err, std::vector<CData> const & vrSimilarPersons)
		:m_dataTest(dataTest), m_vrSimilarPersons(vrSimilarPersons), m_err(err){}
	CData m_dataTest;
	EWarning m_err;
	CData m_dataBase;
	std::vector<CData> m_vrSimilarPersons;
};


class IReporter
{
public:
	virtual void Warning(SWarning const & war)=0;
};

class CStringReporter :public IReporter
{
public:
	CStringReporter();
	virtual void Warning(SWarning const & war);
	QString getMessage();
private:
	
	QString GetRank(int i);
	std::vector<SWarning> m_warnings;
	QTextCodec * codec;
};
#endif // RV_REPORTER_H