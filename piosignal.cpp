#include "piosignal.h"

Signal::Signal(int id)
{
    m_id=id;

    if(id==-1)
    {
        // give a random id;
    }

}


void Signal::addSlot(Slot* val)
{
    m_slots.push_back(val);
}

void Signal::cemit(int argc, void * argv)
{
    for(unsigned i=0; i<m_slots.size(); i++)
    {
        m_slots.at(i)->execute(argc,argv);
    }
}

void Signal::addEmitter()
{
    m_connected++;
}

void Signal::removeFromVector(Slot* slot)
{
    unsigned pos;
    for(unsigned i=0; i<m_slots.size(); i++)
        (m_slots.at(i)==slot) ? pos=i : 0;
    m_slots.at(pos)=m_slots.at(m_slots.size()-1);
    m_slots.pop_back();
}

void Signal::removeEmitter(Signal*& sig)
{
    m_connected--;
    sig=NULL;
    if(m_connected<=0)
    {
        Signals::removeSignalFromVec(this);
        for(unsigned i=0; i<m_slots.size(); i++)
            m_slots.at(i)->removeReceiver();
        delete this;
    }
}

Signal::~Signal()
{

}

