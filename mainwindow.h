#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QFileDialog>
#include <config.h>
#include <walcolors.h>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QProcess>

#define WINDOW_TITLE "Configure wal"

#define ACCENT_COLOR_LABEL "Accent color"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void enableSaveButtons(bool enable);

    void setWalColorPalette();

    void renderWallpaper();

    void setPlasmaAccentColor(QString color);

private slots:
    void on_kdeRadioButton_clicked();

    void on_gnomeRadioButton_clicked();

    void on_saveButton_clicked();

    void on_saveAsButton_clicked();

    void on_cancelButton_clicked();

    void on_darkThemeRadioButton_clicked();

    void on_lightThemeRadioButton_clicked();

    void on_enableConfigCheckbox_stateChanged(int arg1);

    void on_colorthiefBERadioButton_clicked();

    void on_colorzBERadioButton_clicked();

    void on_haishokuBERadioButton_clicked();

    void on_schemer2BERadioButton_clicked();

    void on_walBERadioButton_clicked();

    void colorPressed();

private:
    Ui::MainWindow *ui;
    Config *config;
    WalColors *walColors;
};
#endif // MAINWINDOW_H
