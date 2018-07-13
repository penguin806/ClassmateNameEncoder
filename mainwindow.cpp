#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    this->TextBox = new QPlainTextEdit(this);
    this->EncodeButton = new QPushButton("Encode",this);
    this->DecodeButton = new QPushButton("Decode",this);
    this->VboxLayout = new QVBoxLayout(this);
    this->VboxLayout->addWidget(this->TextBox);
    this->VboxLayout->addWidget(this->EncodeButton);
    this->VboxLayout->addWidget(this->DecodeButton);
    this->setLayout(this->VboxLayout);

    connect(this->EncodeButton,SIGNAL(clicked(bool)),this,SLOT(OnEncodeButtonClicked()));
    connect(this->DecodeButton,SIGNAL(clicked(bool)),this,SLOT(OnDecodeButtonClicked()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::OnEncodeButtonClicked()
{

}

void MainWindow::OnDecodeButtonClicked()
{

}
