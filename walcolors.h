#ifndef WALCOLORS_H
#define WALCOLORS_H

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDir>
#include <QProcess>

#define WAL_COLORS_JSON_FILE_NAME "/.cache/wal/colors.json"
#define DEFAULT_COLORS {"#020202", "#ff0000", "#ffa500", "#ffff00", "#008000", "#0000ff", "#4b0082", "#ee82ee", \
                        "#020202", "#ff0000", "#ffa500", "#ffff00", "#008000", "#0000ff", "#4b0082", "#ee82ee"}

class WalColors
{
private:
    QStringList colors;
    QString wallpaper;
    void readAndUpdateColors();
public:
    WalColors();
    QJsonObject readWalColorsJson();
    QStringList getColors();
    QString getWallpaper();
    void updateWalColors(QString theme, QString backend);
};

#endif // WALCOLORS_H
