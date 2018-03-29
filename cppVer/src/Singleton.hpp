#pragma once

#include "Noncopyable.hpp"

template<class DerivedClass>
class Singleton : public Noncopyable {
protected:

    Singleton<DerivedClass>() {}
    virtual ~Singleton<DerivedClass>() {}

public:
    static DerivedClass& Instance() {

        static DerivedClass m_Instance;

        return m_Instance;

    }
};
