#pragma once
#include "Port.h"
class VintagePort :
    public Port
{
private:
    char* nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char *br, int b, const char* nn, int y);
    VintagePort(const VintagePort& vp);
    ~VintagePort() { delete[]nickname; }
    VintagePort& operator=(const VintagePort& );
    void Show() const;
    friend ostream& operator<<(ostream& is, const VintagePort& vp);
};

