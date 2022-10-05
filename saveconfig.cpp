#include "saveconfig.h"

SaveConfig::SaveConfig(MainWindow *mainWindow, Config *config)
{
    this->mainWindow = mainWindow;
    this->config = config;
}


void SaveConfig::saveConfig(QString fn){
    QString fileName = fn;

    if (fileName.isEmpty()){
        fileName = QDir::homePath() + DEFAULT_FILE_NAME;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this->mainWindow, "Unable to save file", file.errorString());
        return;
    }
    QTextStream stream(&file);
    QString conf = config->generateConfigFile();
    stream << conf;

    file.close();

    this->mainWindow->setWindowTitle(mainWindow->windowTitle() + " (Config saved successfully)");
}
