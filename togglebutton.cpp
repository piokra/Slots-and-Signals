#include "togglebutton.h"


ToggleButton::ToggleButton(QWidget *parent) : QPushButton(parent)
{
    m_signal=NULL;
    connect(this,SIGNAL(released()),this,SLOT(emitsignal()));
    setText("This is a toggle button");
}

ToggleButton::~ToggleButton()
{

}

void ToggleButton::setSignal(Signal* signal)
{
    m_signal=signal;
}

void ToggleButton::ToggleState2(int, void *)
{
    state+=1;
    state%=2;
    setText("0");
    if(state==1) setText("1");
}

void ToggleButton::toggleState()
{
    state+=1;
    state%=2;
    setText("0");
    if(state==1) setText("1");
}

void ToggleButton::emitsignal()
{
    if(m_signal!=NULL) m_signal->cemit(0,0);
}

void ToggleButton::emitsignal(int argc, void* argv)
{
    if(m_signal!=NULL) m_signal->cemit(argc,argv);
}

