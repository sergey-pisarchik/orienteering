/********************************************************************************
** Form generated from reading UI file 'RankVerify.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKVERIFY_H
#define UI_RANKVERIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label;
    QCheckBox *cb_MS;
    QCheckBox *cb_KMS;
    QCheckBox *cb_2r;
    QCheckBox *cb_1r;
    QPlainTextEdit *TextEdit;
    QPushButton *AboutButton;
    QPushButton *HelpButton;
    QLineEdit *FileNameEdit_2;
    QPushButton *OpenFileButton_2;
    QLineEdit *FileNameEdit_1;
    QPushButton *OpenFileButton_1;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QStringLiteral("MainDialog"));
        MainDialog->resize(528, 536);
        gridLayout_2 = new QGridLayout(MainDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame = new QFrame(MainDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        cb_MS = new QCheckBox(frame);
        cb_MS->setObjectName(QStringLiteral("cb_MS"));

        gridLayout->addWidget(cb_MS, 1, 0, 1, 1);

        cb_KMS = new QCheckBox(frame);
        cb_KMS->setObjectName(QStringLiteral("cb_KMS"));

        gridLayout->addWidget(cb_KMS, 2, 0, 1, 1);

        cb_2r = new QCheckBox(frame);
        cb_2r->setObjectName(QStringLiteral("cb_2r"));

        gridLayout->addWidget(cb_2r, 2, 1, 1, 2);

        cb_1r = new QCheckBox(frame);
        cb_1r->setObjectName(QStringLiteral("cb_1r"));

        gridLayout->addWidget(cb_1r, 1, 1, 1, 2);


        gridLayout_2->addWidget(frame, 1, 0, 3, 1);

        TextEdit = new QPlainTextEdit(MainDialog);
        TextEdit->setObjectName(QStringLiteral("TextEdit"));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        TextEdit->setFont(font);

        gridLayout_2->addWidget(TextEdit, 6, 0, 1, 3);

        AboutButton = new QPushButton(MainDialog);
        AboutButton->setObjectName(QStringLiteral("AboutButton"));

        gridLayout_2->addWidget(AboutButton, 1, 2, 1, 1);

        HelpButton = new QPushButton(MainDialog);
        HelpButton->setObjectName(QStringLiteral("HelpButton"));

        gridLayout_2->addWidget(HelpButton, 2, 2, 1, 1);

        FileNameEdit_2 = new QLineEdit(MainDialog);
        FileNameEdit_2->setObjectName(QStringLiteral("FileNameEdit_2"));
        FileNameEdit_2->setReadOnly(true);

        gridLayout_2->addWidget(FileNameEdit_2, 5, 0, 1, 1);

        OpenFileButton_2 = new QPushButton(MainDialog);
        OpenFileButton_2->setObjectName(QStringLiteral("OpenFileButton_2"));

        gridLayout_2->addWidget(OpenFileButton_2, 5, 2, 1, 1);

        FileNameEdit_1 = new QLineEdit(MainDialog);
        FileNameEdit_1->setObjectName(QStringLiteral("FileNameEdit_1"));
        FileNameEdit_1->setReadOnly(true);

        gridLayout_2->addWidget(FileNameEdit_1, 4, 0, 1, 1);

        OpenFileButton_1 = new QPushButton(MainDialog);
        OpenFileButton_1->setObjectName(QStringLiteral("OpenFileButton_1"));

        gridLayout_2->addWidget(OpenFileButton_1, 4, 2, 1, 1);


        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "Rank Verify - \320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \321\200\320\260\320\267\321\200\321\217\320\264\320\276\320\262", 0));
        label->setText(QApplication::translate("MainDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        cb_MS->setText(QApplication::translate("MainDialog", "\320\234\320\241", 0));
        cb_KMS->setText(QApplication::translate("MainDialog", "\320\232\320\234\320\241", 0));
        cb_2r->setText(QApplication::translate("MainDialog", "2 \321\200  \320\270 \320\275\320\270\320\266\320\265", 0));
        cb_1r->setText(QApplication::translate("MainDialog", "1 \321\200", 0));
        AboutButton->setText(QApplication::translate("MainDialog", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        HelpButton->setText(QApplication::translate("MainDialog", "\320\237\320\276\320\274\320\276\321\211\321\214", 0));
        OpenFileButton_2->setText(QApplication::translate("MainDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273 \n"
"\320\264\320\273\321\217 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270", 0));
        OpenFileButton_1->setText(QApplication::translate("MainDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\215\321\202\320\260\320\273\320\276\320\275\320\275\321\213\320\271\n"
" \321\204\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKVERIFY_H
