//
// Created by inrcl on 3/13/21.
//

#ifndef NETDISKT_ORDERCLI_M_FILEPROGRESSBAR_HPP
#define NETDISKT_ORDERCLI_M_FILEPROGRESSBAR_HPP

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class m_fileProgressBar; }
QT_END_NAMESPACE

class m_fileProgressBar : public QWidget {
Q_OBJECT

public:
    explicit m_fileProgressBar(QWidget * parent = nullptr);
    ~m_fileProgressBar() override;
    
    //progress
    void setRange(int, int);
    void setMinimun(int);
    void setMaxmun(int);
    void setValue(int);
    void reset();
    
    //label
    void setText(const char *);

private:
    Ui::m_fileProgressBar * ui;
};

#endif //NETDISKT_ORDERCLI_M_FILEPROGRESSBAR_HPP
