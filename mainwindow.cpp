#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "piosignal.h"
#include "piosignals.h"
#include "pioslot.h"
#include "piofunctionwrapper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Signal* b1;
    Signal* b2;
    Signal* b3;
    Signal* b4;

    Signals::createEmitterFromID(1,b1);
    Signals::createEmitterFromID(2,b2);
    Signals::createEmitterFromID(3,b3);
    Signals::createEmitterFromID(4,b4);

    Slot* s1 = new Slot(functionwrapper(ui->pushButton,ToggleButton::ToggleState2));
    Slot* s2 = new Slot(functionwrapper(ui->pushButton_2,ToggleButton::ToggleState2));
    Slot* s3 = new Slot(functionwrapper(ui->pushButton_3,ToggleButton::ToggleState2));
    Slot* s4 = new Slot(functionwrapper(ui->pushButton_4,ToggleButton::ToggleState2));

    s1->addReceiver(b1);
    s1->addReceiver(b2);
    s1->addReceiver(b3);
    s1->addReceiver(b4);



    s2->addReceiver(b2);
    s2->addReceiver(b3);
    s2->addReceiver(b4);


    s3->addReceiver(b3);
    s3->addReceiver(b4);


    s4->addReceiver(b4);

    ui->pushButton->setSignal(b4);
    ui->pushButton_2->setSignal(b1);
    ui->pushButton_3->setSignal(b2);
    ui->pushButton_4->setSignal(b3);

    b1->removeEmitter(ui->pushButton_2->m_signal);


}

MainWindow::~MainWindow()
{
    delete ui;
}
