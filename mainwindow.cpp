#include "mainwindow.h"
#include "saveconfig.h"
#include "ui_mainwindow.h"

#ifndef QT_NO_DEBUG
#define CHECK_TRUE(instruction) Q_ASSERT(instruction)
#else
#define CHECK_TRUE(instruction) (instruction)
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , config(new Config)
    , walColors(new WalColors)
{
    ui->setupUi(this);
    ui->gnomeRadioButton->setDisabled(true);
    ui->kdeRadioButton->setChecked(true);
    ui->darkThemeRadioButton->setChecked(true);
    ui->enableConfigCheckbox->setChecked(true);
    ui->schemer2BERadioButton->setChecked(true);
    setWindowTitle(WINDOW_TITLE);

    this->setWalColorPalette();
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

void MainWindow::setWalColorPalette(){
    QStringList colors = walColors->getColors();
    for(int i=0; i<colors.size(); i++){
        QPushButton *colorLabel = MainWindow::findChild<QPushButton *>("color" + QString::number(i));
        colorLabel->setStyleSheet("QPushButton{background-color:" + colors[i] + ";}QPushButton:active{background-color:" + colors[i] + ";}");
        colorLabel->setText(QString::number(i));
        CHECK_TRUE(connect(colorLabel, SIGNAL(released()), this, SLOT(colorPressed())));
    }
}

void MainWindow::colorPressed(){
    QPushButton * colorLabel = (QPushButton *)sender();
    QString name = colorLabel->objectName();
    ui->accentColorLabel->setText(QString(ACCENT_COLOR_LABEL) + ": " + name);
    config->setAccentColorCode(name);
    enableSaveButtons(true);

    QStringList colors = walColors->getColors();
    QString index = colorLabel->text();
    setPlasmaAccentColor(colors[index.toInt()]);
}

void MainWindow::enableSaveButtons(bool enable){
    if(!enable) return;
    ui->saveButton->setDisabled(false);
    ui->saveAsButton->setDisabled(false);
    setWindowTitle(WINDOW_TITLE);
}


void MainWindow::on_darkThemeRadioButton_clicked()
{
    this->ui->darkThemeRadioButton->setChecked(true);

    this->config->setTheme(DARK_THEME_CODE);

    ui->lightThemeRadioButton->setChecked(false);

    this->enableSaveButtons(true);
}

void MainWindow::on_lightThemeRadioButton_clicked()
{
    this->ui->lightThemeRadioButton->setChecked(true);

    this->config->setTheme(LIGHT_THEME_CODE);

    ui->darkThemeRadioButton->setChecked(false);

    this->enableSaveButtons(true);
}

void MainWindow::on_colorthiefBERadioButton_clicked()
{
    this->config->setBackEnd(BE_COLORTHIEF_CODE);

    this->enableSaveButtons(true);
}


void MainWindow::on_colorzBERadioButton_clicked()
{
    this->config->setBackEnd(BE_COLORZ_CODE);

    this->enableSaveButtons(true);
}


void MainWindow::on_haishokuBERadioButton_clicked()
{
    this->config->setBackEnd(BE_HAISHOKU_CODE);

    this->enableSaveButtons(true);
}


void MainWindow::on_schemer2BERadioButton_clicked()
{
    this->config->setBackEnd(BE_SCHEMER2_CODE);

    this->enableSaveButtons(true);
}


void MainWindow::on_walBERadioButton_clicked()
{
    this->config->setBackEnd(BE_WAL_CODE);

    this->enableSaveButtons(true);
}

void MainWindow::on_gnomeRadioButton_clicked()
{
    this->config->setDesktopEnv(GNOME_DESKTOP_CODE);

    ui->kdeRadioButton->setChecked(false);
    ui->gnomeRadioButton->setChecked(true);

    this->enableSaveButtons(true);
}

void MainWindow::on_kdeRadioButton_clicked()
{
    this->config->setDesktopEnv(KDE_DESKTOP_CODE);

    ui->gnomeRadioButton->setChecked(false);
    ui->kdeRadioButton->setChecked(true);

    this->enableSaveButtons(true);
}

void MainWindow::on_saveButton_clicked()
{
    // create a file with the configuration set by the user and save it to default location
    SaveConfig save(this, config);
    save.saveConfig("");

    ui->saveButton->setDisabled(true);
}

void MainWindow::on_saveAsButton_clicked()
{
    // create a file with the configuration set by the user and save it to user selected location
    QString fileName = QFileDialog::getSaveFileName(this, "Save as", QDir::homePath(), "Config files(*.conf)");

    SaveConfig save(this, config);
    save.saveConfig(fileName);

    ui->saveButton->setDisabled(true);
    ui->saveAsButton->setDisabled(true);
}

void MainWindow::on_cancelButton_clicked()
{
    // quit the application
    QApplication::quit();
}

void MainWindow::on_enableConfigCheckbox_stateChanged(int arg1)
{
    ui->mainStackedWidget->setEnabled(arg1);
    this->enableSaveButtons(true);
    this->config->enable(arg1);
}

void MainWindow::setPlasmaAccentColor(QString color){
    QString program = "/usr/bin/plasma-apply-colorscheme";
    QStringList arguments;
    QProcess *plasmaApplyColorscheme = new QProcess();
    arguments << "--accent-color" << color;
    plasmaApplyColorscheme->start(program, arguments);
}
