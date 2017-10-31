#include "stdafx.h"

#include <QObject>
#include <QApplication.h>
#include "RankVerifyDialog.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

 	RankVerifyDialog ui;
 	ui.show();

	return app.exec();
}

