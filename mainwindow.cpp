#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , config(new Config)
    , walColors(new WalColors)
{
    ui->setupUi(this);
    setWindowTitle(WINDOW_TITLE);
    this->initializeSlots();
    this->initializeWalColorPalette();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete config;
    delete walColors;
}

void MainWindow::renderWallpaper(){
    QPixmap wallpaper(walColors->getWallpaper());
    int height = ui->currentWallpaper->height();
    int width = ui->currentWallpaper->width();
    ui->currentWallpaper->setPixmap(wallpaper.scaled(width*5, height*5, Qt::KeepAspectRatio));
}

void MainWindow::copyToClipboard(QString text){
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(text);
}

void MainWindow::enableSaveButtons(bool enable){
    if(!enable) return;
    ui->saveButton->setDisabled(false);
    ui->saveAsButton->setDisabled(false);
    setWindowTitle(WINDOW_TITLE);
}

void MainWindow::updateWalColorPalette(){
    walColors->updateWalColors(this->config->getTheme(), this->config->getBackEnd());
    initializeWalColorPalette();
}

void MainWindow::setPlasmaAccentColor(QString color){
    QString program = "/usr/bin/plasma-apply-colorscheme";
    QStringList arguments;
    QProcess *plasmaApplyColorscheme = new QProcess();
    arguments << "--accent-color" << color;
    plasmaApplyColorscheme->start(program, arguments);
}
