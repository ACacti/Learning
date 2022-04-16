/*
* @Author: ACacti
* @Date:   2022-04-16 14:00:04
* @Last Modified by:   shang
* @Last Modified time: 2022-04-16 15:36:03
*/
#ifndef CLASSIC_H
#define CLASSIC_H
#include "Cd.h"
class Classic: public Cd{
private:
    char * primaryName;
    void init(const char *pn);
public:
    Classic(const char *pn, const char *pf,
        const char * lb, const int st, const double pt);
    Classic(const Classic& c);
    virtual ~Classic();
    virtual Classic& operator=(const Classic &c);
    virtual void Report()const;

};


#endif