#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "saveconfig.h"

void MainWindow::enableCheckboxClicked()
{
    bool checked = ui->enableConfigCheckbox->isChecked();
    ui->mainStackedWidget->setEnabled(checked);
    this->enableSaveButtons(true);
    this->config->enable(checked);
}

void MainWindow::themeRadioButtonClicked(){
    QRadioButton * themeRadioButton = (QRadioButton *)sender();
    QString theme = themeRadioButton->objectName();

    if(theme == "darkThemeRadioButton"){
        this->config->setTheme(DARK_THEME_CODE);
        ui->lightThemeRadioButton->setChecked(false);
    }
    else {
        this->config->setTheme(LIGHT_THEME_CODE);
        ui->darkThemeRadioButton->setChecked(false);
    }

    themeRadioButton->setChecked(true);

    updateWalColorPalette();

    enableSaveButtons(true);
}

void MainWindow::colorClicked(){
    QPushButton * colorLabel = (QPushButton *)sender();
    QString name = colorLabel->objectName();
    config->setAccentColorCode(name);
    enableSaveButtons(true);

    QStringList colors = walColors->getColors();
    QString index = colorLabel->text();
    setPlasmaAccentColor(colors[index.toInt()]);

    ui->accentColorLabel->setText(QString(ACCENT_COLOR_LABEL) + ": " + this->config->getAccentColorCode());

    copyToClipboard(colors[index.toInt()]);
}

void MainWindow::backendRadioButtonClicked(){
    QRadioButton * button = (QRadioButton *)sender();

    button->setChecked(true);

    this->config->setBackEnd(button->text());

    updateWalColorPalette();

    enableSaveButtons(true);
}

void MainWindow::saveButtonClicked()
{
    // create a file with the configuration set by the user and save it to default location
    SaveConfig save(this, config);
    save.saveConfig("");

    ui->saveButton->setDisabled(true);
}

void MainWindow::saveAsButtonClicked()
{
    // create a file with the configuration set by the user and save it to user selected location
    QString fileName = QFileDialog::getSaveFileName(this, "Save as", QDir::homePath(), "Config files(*.conf)");

    SaveConfig save(this, config);
    save.saveConfig(fileName);

    ui->saveButton->setDisabled(true);
    ui->saveAsButton->setDisabled(true);
}

void MainWindow::cancelButtonClicked()
{
    // quit the application
    QApplication::quit();
}
