#pragma once

#include <string>
#include "IObservable.hpp"

// Forward declaration of IObservable
class IObservable;

class IObserver 
{
public: 
    virtual void onUpdate(IObservable* source, const std::string& field, double value) = 0;
    virtual ~IObserver() = default;
};