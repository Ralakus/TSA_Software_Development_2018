#pragma once

class Noncopyable {
private:
    Noncopyable(const Noncopyable& Other) = delete;
public:
    Noncopyable() {}
    virtual ~Noncopyable() {}

};
