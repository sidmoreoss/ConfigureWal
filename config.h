#ifndef CONFIG_H
#define CONFIG_H

#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QFileDialog>
#include <QMap>

#define LIGHT_THEME_CODE "-l"
#define DARK_THEME_CODE ""

#define KDE_DESKTOP_CODE "kde"
#define GNOME_DESKTOP_CODE "gnome"

#define BE_SCHEMER2_CODE "schemer2"
#define BE_COLORTHIEF_CODE "colorthief"
#define BE_COLORZ_CODE "colorz"
#define BE_HAISHOKU_CODE "haishoku"
#define BE_WAL_CODE "wal"

#define COLOR_SCHEME_CONFIG_NAME "COLOR_SCHEME_MODE"
#define ACCENT_COLOR_CONFIG_NAME "ACCENT_COLOR_CODE"
#define WINDOW_MANAGER_CONFIG_NAME "WINDOW_MANAGER"
#define ENABLE_CONFIG_NAME "ENABLE_WAL"
#define WAL_BACKEND_NAME "WAL_BACKEND"

class Config
{
private:
    bool enabled;
    QString theme, desktopEnv, backEnd, accentColorCode;
public:
    Config();

    void setTheme(QString theme);
    void setAccentColorCode(QString code);
    void setDesktopEnv(QString de);
    void setBackEnd(QString BE);
    void enable(int enable);

    QString getTheme();
    QString getDesktopEnv();
    QString getAccentColorCode();
    QString getBackEnd();
    bool isEnabled();

    QString generateConfigFile();
};

#endif // CONFIG_H
