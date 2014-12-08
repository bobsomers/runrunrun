#pragma once

namespace ngn {

class App
{
public:
    virtual ~App() {}
    virtual void run() = 0;
};

typedef App* CreateAppFunc();
typedef void DestroyAppFunc(App*);

} // namespace ngn
