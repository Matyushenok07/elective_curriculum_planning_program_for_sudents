#pragma once

class Exception {
protected:
    int code;
public:
    explicit Exception(int code = 0) { this->code = code; }
    virtual void ErrorText(){};
};


