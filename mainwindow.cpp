#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "piosignal.h"
#include "pioslot.h"
#include "piofunctionwrapper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Signal* b1 = new Signal(1);
    Signal* b2 = new Signal(2);
    Signal* b3 = new Signal(3);
    Signal* b4 = new Signal(4);

    Slot* s1 = new Slot(functionwrapper(ui->pushButton,ui->pushButton->ToggleState2));
    Slot* s2 = new Slot(functionwrapper(ui->pushButton_2,ui->pushButton_2->ToggleState2));
    Slot* s3 = new Slot(functionwrapper(ui->pushButton_3,ui->pushButton_3->ToggleState2));
    Slot* s4 = new Slot(functionwrapper(ui->pushButton_4,ui->pushButton_4->ToggleState2));

    b1->addSlot(s1);
    b1->addSlot(s2);
    b1->addSlot(s3);
    b1->addSlot(s4);

    b2->addSlot(s2);
    b2->addSlot(s3);
    b2->addSlot(s4);

    b3->addSlot(s3);
    b3->addSlot(s4);

    b4->addSlot(s4);

    ui->pushButton->setSignal(b1);
    ui->pushButton_2->setSignal(b1);
    ui->pushButton_3->setSignal(b2);
    ui->pushButton_4->setSignal(b3);


}

MainWindow::~MainWindow()
{
    delete ui;
}
