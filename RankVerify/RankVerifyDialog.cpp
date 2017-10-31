#include "stdafx.h"
#include "RankVerifyDialog.h"

#include <QFileDialog>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <QPushButton>
#include <QTextCodec>

#include "Reporter.h"
#include "WinOrientDoc.h"
#include "Compare.h"
#include <qnamespace.h>

using namespace std;
using namespace Qt;

void Message(QString const & s)
{
	QMessageBox msgBox;
	msgBox.setText(s);
	msgBox.exec();
}

bool ReadDoc(QString const& sFileName, CDoc & doc)
{
	string s = sFileName.toStdString();

	wstring std_filename = sFileName.toStdWString();
	ifstream iFile;
	iFile.open (std_filename.c_str(), ios_base::in | ios_base::binary );
	if (!iFile.good())
		return false;
	doc.readData(iFile);
	return true;
}

RankVerifyDialog::RankVerifyDialog(QWidget *parent) : QDialog(parent) { 
	ui.setupUi(this);
	ui.cb_MS->setCheckState(Checked);
	ui.cb_KMS->setCheckState(Checked);
	ui.cb_1r->setCheckState(Unchecked);
	ui.cb_2r->setCheckState(Unchecked);

	QObject::connect(ui.OpenFileButton_1, SIGNAL(released()),
		this, SLOT(OpenBaseDoc()));
	QObject::connect(ui.OpenFileButton_2, SIGNAL(released()),
		this, SLOT(OpenTestDoc()));

	QObject::connect(ui.cb_MS, SIGNAL(stateChanged(int)),
		this, SLOT(CompareDocs()));
	QObject::connect(ui.cb_KMS, SIGNAL(stateChanged(int)),
		this, SLOT(CompareDocs()));
	QObject::connect(ui.cb_1r, SIGNAL(stateChanged(int)),
		this, SLOT(CompareDocs()));
	QObject::connect(ui.cb_2r, SIGNAL(stateChanged(int)),
		this, SLOT(CompareDocs()));

	QTextCodec * codec = QTextCodec::codecForName("Windows-1251");
	QString s = codec->toUnicode("WBD\\ÁÄ ÁÔÀ.wdb");
	if (ReadDoc(s, m_BaseDoc))
		ui.FileNameEdit_1->setText(s);
}

void RankVerifyDialog::OpenBaseDoc()
{
	QTextCodec * codec = QTextCodec::codecForName("Windows-1251");
	QString fileName = QFileDialog::getOpenFileName(this,
		codec->toUnicode("Âûבונטעו WinOrient פאיכ"), "", tr("WinOrient Files (*.wdb)"));
	ui.FileNameEdit_1->setText(fileName);
	ReadDoc(fileName, m_BaseDoc);
	CompareDocs();
}
void RankVerifyDialog::OpenTestDoc()
{
	QTextCodec * codec = QTextCodec::codecForName("Windows-1251");
	QString fileName = QFileDialog::getOpenFileName(this,
		codec->toUnicode("Âûבונטעו WinOrient פאיכ"), "", tr("WinOrient Files (*.wdb)"));
	ui.FileNameEdit_2->setText(fileName);
	ReadDoc(fileName, m_TestDoc);
	CompareDocs();
}

void RankVerifyDialog::CompareDocs()
{
	CStringReporter reporter;
	SCompareSettings settings;
	GetSettings(settings);
	Compare(m_TestDoc, m_BaseDoc, settings,reporter);
	ui.TextEdit->setPlainText(reporter.getMessage());
}

void RankVerifyDialog::GetSettings( SCompareSettings & rSettings )
{
	rSettings.m_RanksToCompare.clear();
	if (ui.cb_MS->checkState() == Checked)
		rSettings.m_RanksToCompare.insert(RANK_MS);
	if (ui.cb_KMS->checkState() == Checked)
		rSettings.m_RanksToCompare.insert(RANK_KMS);
	if (ui.cb_1r->checkState() == Checked)
		rSettings.m_RanksToCompare.insert(RANK_R1);
	if (ui.cb_2r->checkState() == Checked)
	{
		rSettings.m_RanksToCompare.insert(RANK_R2);
		rSettings.m_RanksToCompare.insert(RANK_R3);
		rSettings.m_RanksToCompare.insert(RANK_UR1);
		rSettings.m_RanksToCompare.insert(RANK_UR2);
		rSettings.m_RanksToCompare.insert(RANK_BR);
	}
	rSettings.nFirstLettersCompareCount = 5;
}