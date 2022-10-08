#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef QT_NO_DEBUG
#define CHECK_TRUE(instruction) Q_ASSERT(instruction)
#else
#define CHECK_TRUE(instruction) (instruction)
#endif

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
#include <QClipboard>
#include <QGuiApplication>

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

private slots:
    void enableCheckboxClicked();
    void themeRadioButtonClicked();
    void colorClicked();
    void backendRadioButtonClicked();

    void saveButtonClicked();
    void saveAsButtonClicked();
    void cancelButtonClicked();

private:
    Ui::MainWindow *ui;
    Config *config;
    WalColors *walColors;
    void updateWalColorPalette();
    void copyToClipboard(QString text);

    void initializeSlots();
    void initializeThemeRadioButtons();
    void initializeBackendRadioButtons();
    void initializeEnableCheckbox();
    void initializeSaveAndCloseButtons();
    void initializeWalColorPalette();

    void enableSaveButtons(bool enable);
    void renderWallpaper();
    void setPlasmaAccentColor(QString color);
};
#endif // MAINWINDOW_H
