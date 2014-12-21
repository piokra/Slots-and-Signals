#ifndef TOGGLEBUTTON_H
#define TOGGLEBUTTON_H

#include <QPushButton>
#include "piosignal.h"




class ToggleButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ToggleButton(QWidget *parent = 0);
    ~ToggleButton();
    void setSignal(Signal* );
    void ToggleState2(int, void*);
    Signal* m_signal;


signals:

public slots:
    void toggleState();
    void emitsignal();
    void emitsignal(int argc, void *argv);
private:
    int state;

};

#endif // TOGGLEBUTTON_H
