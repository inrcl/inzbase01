//
// Created by inrcl on 3/13/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_m_fileProgressBar.h" resolved

#include "m_fileprogressbar.hpp"
#include "ui_m_fileprogressbar.h"

m_fileProgressBar::m_fileProgressBar(QWidget * parent)
        :
        QWidget(parent), ui(new Ui::m_fileProgressBar) {
    ui->setupUi(this);
}

m_fileProgressBar::~m_fileProgressBar() {
    delete ui;
}

//progress
void m_fileProgressBar::setRange(int minimun, int maxmun)
{
    ui->progressBar->setRange(minimun, maxmun);
}
void m_fileProgressBar::setMinimun(int minimun){ ui->progressBar->setMinimum(minimun); }
void m_fileProgressBar::setMaxmun(int maxmun){ui->progressBar->setMaximum(maxmun); }
void m_fileProgressBar::setValue(int val){ ui->progressBar->setValue(val); }
void m_fileProgressBar::reset(){ ui->progressBar->reset(); }

//label
void m_fileProgressBar::setText(const char *cp){ ui->label->setText(cp); }