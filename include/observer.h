#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void notify(int total);
    virtual void useBonusPoint();
};

#endif