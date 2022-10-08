#include "walcolors.h"
#include "config.h"

WalColors::WalColors()
{
    readAndUpdateColors();
}

void WalColors::readAndUpdateColors(){
    QJsonObject walColorsJson = readWalColorsJson();

    this->wallpaper = walColorsJson.value("wallpaper").toString();

    QJsonObject colorObj = walColorsJson.value("colors").toObject();

    if(colorObj.size() == 0) {
        colors = QStringList(DEFAULT_COLORS);
        return;
    }

    this->colors.clear();

    for(int i=0; i<colorObj.size(); i++){
        this->colors.push_back(colorObj.value("color" + QString::number(i)).toString());
    }
}

void WalColors::updateWalColors(QString theme, QString backend){
    QString program = "/usr/bin/wal";
    QStringList arguments;
    QProcess *wal = new QProcess();

    arguments << "--backend" << backend;
    arguments << "-i" << wallpaper;
    if(theme == LIGHT_THEME_CODE){
        arguments << "-l";
    }

    wal->start(program, arguments);

    wal->waitForFinished();

    readAndUpdateColors();
}


QJsonObject WalColors::readWalColorsJson()
{
    QFile file(QDir::homePath() + QString(WAL_COLORS_JSON_FILE_NAME));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    return d.object();
}

QStringList WalColors::getColors(){ return this->colors; }

QString WalColors::getWallpaper(){ return this->wallpaper; }
