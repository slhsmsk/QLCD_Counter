
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QListWidget>
#include <QSpinBox>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QLabel>
#include <QTextEdit>
#include<LCDNumber.h>

int main(int argc, char *argv[]){


    //QApplication app(argc, argv);
    QApplication uygulama(argc,argv);

    QMainWindow *window = new QMainWindow();

    window->setWindowTitle(QString::fromUtf8("QLCD Number Sayac"));
    window->resize(800,300);

    QWidget *centerWd = new QWidget();

    QVBoxLayout *yrlsm =  new QVBoxLayout();
    centerWd->setLayout(yrlsm);
    
      LCDNumber *sayi = new LCDNumber(yrlsm,window,5,0);

       sayi->setFixedSize(800,280);
       sayi->setDigitCount(9);

       window->setCentralWidget(centerWd);//ortalamak için yazılan
       window->show();

       sayi->zamanlayici->setInterval(1);
       sayi->zamanlayici->start();



    return uygulama.exec();
}

