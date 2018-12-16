#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cesar.hpp"
#include "inverso.hpp"
#include "inversogrupal.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_textEntrada_modificationChanged(bool arg1){
    QString text = ui->textEntrada->toPlainText();
    int sal = ui->numSaltos->value();
    int grup = ui->numGrupos->value();
    
    Cesar cifrarTexto (text,sal);
    Inverso cifrarInverso(text);
    IGrupal cifrarIGrupal(text,grup);

    
    ui->textCesar->setPlainText(cifrar);
    ui->textInversa->setPlainText(cifrar());
    ui->textIGrupo->setPlainText(cifrar())
}
