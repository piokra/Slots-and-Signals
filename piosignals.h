#ifndef SIGNALS_H
#define SIGNALS_H

#include "piosignal.h"
#include <vector>
#include "piosignal.h"

class Signal;


class Signals
{
    friend class Signal;
public:

    static int getFreeID();
    static Signal* getSignalFromID();
    static int createEmitterFromID(int id, Signal*&);
    static void emitSignalFromID(int id, int argc, void* argv);
protected:
    static unsigned findPosFromID(int id);
    static void removeSignalFromVec(Signal*);
private:
    static std::vector<Signal*> m_signals;

};

#endif // SIGNALS_H
