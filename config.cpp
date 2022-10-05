#include "config.h"

Config::Config(){
    this->theme = DARK_THEME_CODE;
    this->desktopEnv = KDE_DESKTOP_CODE;
    this->enable(true);
    this->accentColorCode = "color14";
    this->backEnd=BE_SCHEMER2_CODE;
}

void Config::setTheme(QString theme){
    this->theme = theme;
}

void Config::setAccentColorCode(QString code){
    this->accentColorCode = code;
}

void Config::setDesktopEnv(QString de){
    this->desktopEnv = de;
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

QString Config::getDesktopEnv(){
    return this->desktopEnv;
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
            QString(WINDOW_MANAGER_CONFIG_NAME) + "=\"" + this->getDesktopEnv() + "\"\n" +
            QString(WAL_BACKEND_NAME) + "=\"" + this->getBackEnd() + "\"\n" +
            QString(ENABLE_CONFIG_NAME) + "=\"" + QString::number(this->isEnabled()) + "\"";
}
