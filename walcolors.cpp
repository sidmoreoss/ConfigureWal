#include "walcolors.h"

WalColors::WalColors()
{
    QJsonObject walColorsJson = readWalColorsJson();

    this->walWallpaper = walColorsJson.value("wallpaper").toString();

    QJsonObject colorObj = walColorsJson.value("colors").toObject();

    this->walColors.clear();
    for(int i=0; i<16; i++){
        this->walColors.push_back(colorObj.value("color" + QString::number(i)).toString());
    }
}


QJsonObject WalColors::readWalColorsJson()
{
    QFile file(QDir::homePath() + QString(WAL_COLORS_FILE_NAME));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    return d.object();
}

QStringList WalColors::getColors(){
    return this->walColors;
}

QString WalColors::getWallpaper(){
    return this->walWallpaper;
}
