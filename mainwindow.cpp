#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QMessageBox>
#include "alexlineedit.h"
#include "alexcombobox.h"
#include "alexradiobutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMinimum(10);
    ui->horizontalSlider->setMaximum(40);
    ui->horizontalSlider->setSingleStep(1);

    //Note: Use SIGNAL(editingFinished()), not SIGNAL(textChanged(QString)), otherwise, it will cause
    //circular dependency.
    //connect(ui->lineEditFamily,SIGNAL(textChanged(QString)),ui->lineEditFamily,SLOT(myTextChanged(QString)));
    connect(ui->lineEditFamily,SIGNAL(editingFinished()),ui->lineEditFamily,SLOT(myEditingFinished()));
    connect(ui->lineEditFamily,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),ui->comboBox,SLOT(myCurrentIndexChanged(QString)));
    connect(ui->comboBox,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->radioButton_A,SIGNAL(clicked()),ui->radioButton_A,SLOT(myStateChanged()));
    connect(ui->radioButton_A,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->radioButton_TNR,SIGNAL(clicked()),ui->radioButton_TNR,SLOT(myStateChanged()));
    connect(ui->radioButton_TNR,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->radioButton_CS,SIGNAL(clicked()),ui->radioButton_CS,SLOT(myStateChanged()));
    connect(ui->radioButton_CS,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->horizontalSlider,SIGNAL(valueChanged()),ui->horizontalSlider,SIGNAL(myValueChanged()));
    connect(ui->horizontalSlider,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));
}


int MainWindow::getSize(QString qs){
    if(qs == "small"){
        return (10);
//        ui->horizontalSlider->setSliderPosition(10);

    }
    if(qs == "Medium"){
        return (20);
//        ui->horizontalSlider->setSliderPosition(20);

    }
    if(qs == "Big"){
//        ui->horizontalSlider->setSliderPosition(40);
        return(40);

    }
    return 12;
}




void MainWindow::actByYourChange(QObject* senderObj){
    if(senderObj==ui->lineEditFamily){
        QFont font = ui->labelFox->font();
        int size = getSize(ui->comboBox->itemText(ui->comboBox->currentIndex()));
        font.setPointSize(size);
        ui->comboBox->setCurrentText(ui->lineEditFamily->text());
        ui->labelFox->setFont(font);
    }
    else if(senderObj==ui->comboBox){
        QFont font = ui->labelFox->font();
        int size = getSize(ui->comboBox->itemText(ui->comboBox->currentIndex()));
        ui->horizontalSlider->setValue(size);
//        ui->labelFox->setFont(font);
//        ui->lineEditFamily->setFont(font);

//        QFont font=ui->labelFox->font();
//      ui->labelFox->setFont(ui->comboBox->font().setPointSize(size));
//       font().setPointSize(size);
//        // font().setPointSize(ui->lineEditFamily->text().toInt());

//        //        QFont font=ui->labelFox->font();
//        //        font.setPointSize(ui->lineEditFamily->text().toInt());
//        //        ui->labelFox->setFont(font);



//        //        ui->labelFox->setPointSize(size);
//        //        font().setPointSize(ui->lineEditSize->text().toInt());
//        //        font.setPointSize(size);

//        //        QFont font=ui->labelFox->font();
//        //        font.setPointSize(size);
//        //        ui->labelFox->setFont(font);


    }
    else if(senderObj==ui->radioButton_A){

        int size = getSize(ui->comboBox->itemText(ui->comboBox->currentIndex()));
        QFont qfont("Arial", size);
        ui->labelFox->setFont(qfont);
        ui->comboBox->setCurrentText(ui->lineEditFamily->text());
    }
    else if(senderObj==ui->radioButton_TNR){

        int size = getSize(ui->comboBox->itemText(ui->comboBox->currentIndex()));
        QFont qfont("Times New Roman", size);
        ui->labelFox->setFont(qfont);
        ui->comboBox->setCurrentText(ui->lineEditFamily->text());
    }
    else if(senderObj==ui->radioButton_CS){

        int size = getSize(ui->comboBox->itemText(ui->comboBox->currentIndex()));
        QFont qfont("Comic Sans", size);
        ui->labelFox->setFont(qfont);
        ui->comboBox->setCurrentText(ui->lineEditFamily->text());
    }
    else if(senderObj==ui->horizontalSlider){
     //  int size = getSize(ui->comboBox->itemText(ui->comboBox->currentIndex()));
//        font.setPointSize(size);
//        ui->labelFox->setFont(font);
//        int size = getSize(ui->comboBox->itemText(ui->comboBox->currentIndex()));
//        ui->horizontalSlider->setSliderPosition(1);

        QFont font=ui->labelFox->font();
        font.setPointSize(ui->horizontalSlider->value());
        //ui->labelFox->setFont(font);


    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
