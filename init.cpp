#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::initializeSlots(){
    this->initializeThemeRadioButtons();
    this->initializeBackendRadioButtons();
    this->initializeEnableCheckbox();
    this->initializeSaveAndCloseButtons();
}

void MainWindow::initializeEnableCheckbox(){
    QCheckBox * checkbox = ui->enableConfigCheckbox;
    checkbox->setChecked(this->config->isEnabled());

    if(!this->config->isEnabled()) ui->mainStackedWidget->setDisabled(true);

    CHECK_TRUE(connect(checkbox, SIGNAL(clicked()), this, SLOT(enableCheckboxClicked())));
}

void MainWindow::initializeThemeRadioButtons(){
    QRadioButton *darkThemeRadioButton = MainWindow::findChild<QRadioButton *>("darkThemeRadioButton");
    QRadioButton *lightThemeRadioButton = MainWindow::findChild<QRadioButton *>("lightThemeRadioButton");

    if(this->config->getTheme() == DARK_THEME_CODE){
        darkThemeRadioButton->setChecked(true);
        lightThemeRadioButton->setChecked(false);
    }
    else{
        lightThemeRadioButton->setChecked(true);
        darkThemeRadioButton->setChecked(false);
    }

    CHECK_TRUE(connect(darkThemeRadioButton, SIGNAL(clicked()), this, SLOT(themeRadioButtonClicked())));
    CHECK_TRUE(connect(lightThemeRadioButton, SIGNAL(clicked()), this, SLOT(themeRadioButtonClicked())));
}

void MainWindow::initializeWalColorPalette(){
    QStringList colors = walColors->getColors();
    for(int i=0; i<colors.size(); i++){
        QPushButton *colorLabel = MainWindow::findChild<QPushButton *>("color" + QString::number(i));
        colorLabel->setStyleSheet("QPushButton{background-color:" + colors[i] + ";}QPushButton:active{background-color:" + colors[i] + ";}");
        colorLabel->setText(QString::number(i));
        CHECK_TRUE(connect(colorLabel, SIGNAL(released()), this, SLOT(colorClicked())));
    }
    ui->accentColorLabel->setText(QString(ACCENT_COLOR_LABEL) + ": " + this->config->getAccentColorCode());
}

void MainWindow::initializeBackendRadioButtons(){
    for(int i=0; i<5; i++){
        QRadioButton * button = MainWindow::findChild<QRadioButton *>("backend" + QString::number(i));

        QString label = button->text();
        if(label == this->config->getBackEnd()){
            button->setChecked(true);
        }

        CHECK_TRUE(connect(button, SIGNAL(clicked()), this, SLOT(backendRadioButtonClicked())));
    }
}

void MainWindow::initializeSaveAndCloseButtons(){
    CHECK_TRUE(connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked())));
    CHECK_TRUE(connect(ui->saveAsButton, SIGNAL(clicked()), this, SLOT(saveAsButtonClicked())));
    CHECK_TRUE(connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonClicked())));
}
