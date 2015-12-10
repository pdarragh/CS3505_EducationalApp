/********************************************************************************
** Form generated from reading UI file 'unenrollwarning.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNENROLLWARNING_H
#define UI_UNENROLLWARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_UnenrollWarning
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *UnenrollWarning)
    {
        if (UnenrollWarning->objectName().isEmpty())
            UnenrollWarning->setObjectName(QStringLiteral("UnenrollWarning"));
        UnenrollWarning->resize(415, 165);
        buttonBox = new QDialogButtonBox(UnenrollWarning);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(UnenrollWarning);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 341, 51));
        label->setWordWrap(true);
        label_2 = new QLabel(UnenrollWarning);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 10, 71, 51));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/error_filled.png")));

        retranslateUi(UnenrollWarning);
        QObject::connect(buttonBox, SIGNAL(accepted()), UnenrollWarning, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UnenrollWarning, SLOT(reject()));

        QMetaObject::connectSlotsByName(UnenrollWarning);
    } // setupUi

    void retranslateUi(QDialog *UnenrollWarning)
    {
        UnenrollWarning->setWindowTitle(QApplication::translate("UnenrollWarning", "Dialog", 0));
        label->setText(QApplication::translate("UnenrollWarning", "Warning: You are about to unenroll a student from your class.", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UnenrollWarning: public Ui_UnenrollWarning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNENROLLWARNING_H
