#pragma once

#include <QApplication>

class Application : public QApplication
{
public:
    Application(int argc, char *argv[]);

private:
    void initStyle();
    void initImageRes();
};
