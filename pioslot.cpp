#include "pioslot.h"

Slot::Slot(std::function<void(int,void*)> func)
{
    m_connected=0;
    m_function=func;
}

void Slot::execute(int argc, void* argv)
{
    m_function(argc, argv);

}

Slot::~Slot()
{

}

void Slot::addReceiver(Signal* sig)
{
    sig->addSlot(this);
    m_parents.push_back(sig);
    m_connected++;
}


void Slot::removeReceiver()
{
    m_connected--;
    if(m_connected<=0)
    {
        for(unsigned i=0; i<m_parents.size(); i++)
            m_parents.at(i)->removeFromVector(this);
        delete this;
    }
}

