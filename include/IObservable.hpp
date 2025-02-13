#pragma once

#include <memory>
#include "IObserver.hpp"

class IObservable 
{
public:
    virtual void registerObserver(std::shared_ptr<IObserver> obs) = 0;
    virtual void removeObserver(std::shared_ptr<IObserver> obs) = 0;
    virtual void notifyObservers(const std::string& field, double newValue) = 0;
    virtual ~IObservable() = default;
};