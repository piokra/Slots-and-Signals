#include "piosignals.h"
std::vector<Signal*> Signals::m_signals;


int Signals::createEmitterFromID(int id, Signal*& refptr)
{
    unsigned pos = findPosFromID(id);
    if(pos!=-1)
    {
        m_signals.at(pos)->addEmitter();
        refptr=m_signals.at(pos);
        return id;
    }
    else
    {
        Signal* sig = new Signal(id);
        m_signals.push_back(sig);
        sig->addEmitter();
        refptr=sig;
        return sig->m_id;

    }


}

unsigned Signals::findPosFromID(int id)
{
    for(unsigned i=0; i<m_signals.size(); i++)
    {
        if(m_signals.at(i)->m_id==id) return i;
    }
    return -1;
}

void Signals::removeSignalFromVec(Signal* sig)
{
    unsigned pos = findPosFromID(sig->m_id);
    if(pos!=-1)
    {
        m_signals.at(pos)=m_signals.at(m_signals.size()-1);
        m_signals.pop_back();
    }
}

