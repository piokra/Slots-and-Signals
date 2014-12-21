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


signals:

public slots:
    void toggleState();
    void emitsignal();
    void emitsignal(int argc, void *argv);
private:
    int state;
    Signal* m_signal;
};

#endif // TOGGLEBUTTON_H
