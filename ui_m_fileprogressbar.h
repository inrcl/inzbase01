/********************************************************************************
** Form generated from reading UI file 'm_fileprogressbar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_FILEPROGRESSBAR_H
#define UI_M_FILEPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_m_fileProgressBar
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QWidget *m_fileProgressBar)
    {
        if (m_fileProgressBar->objectName().isEmpty())
            m_fileProgressBar->setObjectName(QString::fromUtf8("m_fileProgressBar"));
        m_fileProgressBar->resize(400, 66);
        verticalLayout = new QVBoxLayout(m_fileProgressBar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(m_fileProgressBar);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(m_fileProgressBar);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        retranslateUi(m_fileProgressBar);

        QMetaObject::connectSlotsByName(m_fileProgressBar);
    } // setupUi

    void retranslateUi(QWidget *m_fileProgressBar)
    {
        m_fileProgressBar->setWindowTitle(QCoreApplication::translate("m_fileProgressBar", "m_fileProgressBar", nullptr));
        label->setText(QCoreApplication::translate("m_fileProgressBar", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class m_fileProgressBar: public Ui_m_fileProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_FILEPROGRESSBAR_H
