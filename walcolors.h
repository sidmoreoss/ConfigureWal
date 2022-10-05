#ifndef WALCOLORS_H
#define WALCOLORS_H

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDir>

#define WAL_COLORS_FILE_NAME "/.cache/wal/colors.json"

class WalColors
{
private:
    QStringList walColors;
    QString walWallpaper;
public:
    WalColors();
    QJsonObject readWalColorsJson();
    QStringList getColors();
    QString getWallpaper();
};

#endif // WALCOLORS_H
