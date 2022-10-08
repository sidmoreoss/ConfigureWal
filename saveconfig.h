#ifndef SAVECONFIG_H
#define SAVECONFIG_H



#include <QString>
#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QFileDialog>
#include <mainwindow.h>

class SaveConfig
{
public:
    SaveConfig(MainWindow *mainWindow, Config *config);

    void saveConfig(QString fileName);
private:
    MainWindow *mainWindow;
    Config *config;
};

#endif // SAVECONFIG_H
