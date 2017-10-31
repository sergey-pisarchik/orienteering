#pragma once
#include "ui_RankVerify.h" 
#include "QDialog.h"
#include "WinOrientDoc.h"

struct SCompareSettings;

class RankVerifyDialog : public QDialog
{
	Q_OBJECT

public:
	RankVerifyDialog(QWidget *parent = 0);

	void Init();

	void ParseFile(QString const & fileName);

public slots:
	void OpenBaseDoc();
	void OpenTestDoc();
	void CompareDocs();

private:
	void GetSettings(SCompareSettings & rsettings);

	CDoc m_BaseDoc;
	CDoc m_TestDoc;
	Ui::MainDialog ui;
};