#pragma once

#include <string>
#include "IObservable.hpp"

class IObserver 
{
public: 
    virtual void onUpdate(const std::string& field, double value) = 0;
    //virtual void onSafetyEvent(const std::string& message, bool critical) = 0;
    //virtual void onRegistered(std::shared_ptr<IObservable> obs) = 0;
    virtual ~IObserver() = default;
};