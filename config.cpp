#include "config.h"
#include <QDebug>

Config::Config(){
    readDefaultConfig();
}

void Config::setTheme(QString theme){
    this->theme = theme;
}

void Config::setAccentColorCode(QString code){
    this->accentColorCode = code;
}

void Config::setBackEnd(QString BE){
    this->backEnd = BE;
}

void Config::enable(int enable){
    this->enabled = enable;
}

QString Config::getTheme(){
    return this->theme;
}

QString Config::getAccentColorCode(){
    return this->accentColorCode;
}

QString Config::getBackEnd(){
    return this->backEnd;
}

bool Config::isEnabled(){
    return this->enabled;
}

QString Config::generateConfigFile(){
    return QString(COLOR_SCHEME_CONFIG_NAME) + "=\"" + this->getTheme() + "\"\n" +
            QString(ACCENT_COLOR_CONFIG_NAME) + "=\"" + this->getAccentColorCode() + "\"\n" +
            QString(WAL_BACKEND_NAME) + "=\"" + this->getBackEnd() + "\"\n" +
            QString(ENABLE_CONFIG_NAME) + "=\"" + QString::number(this->isEnabled()) + "\"";
}

void Config::readDefaultConfig(){
    QFile file(QDir::homePath() + QString(DEFAULT_CONFIG_FILE_NAME));

    if (!file.open(QIODevice::ReadOnly)) {
        this->theme = DARK_THEME_CODE;
        this->enable(true);
        this->accentColorCode = "color14";
        this->backEnd=BE_SCHEMER2_CODE;
        return;
    }

    QStringList wordList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QString rhs = line.split('=')[1];

        QString property = line.split('=')[0];

        QString value = rhs.remove("\n", Qt::CaseInsensitive).remove("\"", Qt::CaseInsensitive);

        if(property == COLOR_SCHEME_CONFIG_NAME) setTheme(value);
        else if(property == ACCENT_COLOR_CONFIG_NAME) setAccentColorCode(value);
        else if(property == WAL_BACKEND_NAME) setBackEnd(value);
        else if(property == ENABLE_CONFIG_NAME) enable(value=="0" ? 0 : 1);

        qDebug( ) << value;
    }

    file.close();
}
