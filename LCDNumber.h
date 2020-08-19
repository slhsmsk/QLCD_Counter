#ifndef MYWINDOW_H
#define MYWINDOW_H
#include<QMainWindow>
#include<QMessageBox>
#include<QKeyEvent>
#include<QWidget>
#include<QtGui>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLCDNumber>

class LCDNumber:public QLCDNumber
{
    Q_OBJECT

public:
    QTimer* zamanlayici;
    QTime* zamansaat;
    QPushButton* buton1;
    QPushButton* buton2;

public:
    LCDNumber(QVBoxLayout *& verticalLayout,QMainWindow *window,int minutes,int seconds)
    {
        zamanlayici = new QTimer();
        zamansaat =   new QTime(0,minutes,seconds,0);

      QPushButton *buton1 = new QPushButton(QString::fromUtf8("Başla"));
      QPushButton *buton2 = new QPushButton(("Dur"));

        buton1->setAutoExclusive(true);//bu özelliği kazandır.
        buton2->setAutoExclusive(true);

        buton1->setCheckable(true);//kazandırdığıö özelliği kulllanabilmek için atıyorum.
        buton2->setCheckable(true);

        verticalLayout->addWidget(this);
        verticalLayout->addWidget(buton1);
        verticalLayout->addWidget(buton2);

        this->display(zamansaat->toString(QString("mm:ss.zzz")));

        QObject::connect(zamanlayici,SIGNAL(timeout()),this,SLOT(setDisplay()));
        QObject::connect(buton1,SIGNAL(pressed()),this,SLOT(start()));
        QObject::connect(buton2,SIGNAL(pressed()),this,SLOT(stop()));

    }
    ~LCDNumber(){};

    public slots:

    void setDisplay(){
        this->zamansaat->setHMS(0,this->zamansaat->addMSecs(-1).minute(),
                                  this->zamansaat->addMSecs(-1).second(),
                                  this->zamansaat->addMSecs(-1).msec());

        this->display(this->zamansaat->toString(QString("mm::ss,zzz")));


    }

    void start()
    {
        this->zamanlayici->start();
    }

    void stop()
    {
        this->zamanlayici->stop();
    }
};

#endif // MYWINDOW_H
