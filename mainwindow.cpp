#include "mainwindow.h"
#include <QDebug>
#include <QRandomGenerator>

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

    this->MyClassmateCollectionA << u8"伍芳兰" << u8"张敏" << u8"张玥" << u8"杨涵" << u8"申波" << u8"杨名" << u8"阙继婷"
                           << u8"李昌和" << u8"薛有缘" << u8"王位" << u8"陈泽南" << u8"曾伟康" << u8"王帅旗"
                           << u8"刘伟康" << u8"王端举" << u8"阮书琪" << u8"李亚军" << u8"张露云" << u8"刘湘川"
                           << u8"任海清" << u8"易智隆";   //Total: 21 (For text encoding)
    this->MyClassmateCollectionB << u8"尹红爱" << u8"向健" << u8"童方超"; //For separating words
}

MainWindow::~MainWindow()
{

}

void MainWindow::OnEncodeButtonClicked()
{
    QString EditBoxText = this->TextBox->toPlainText();
    QByteArray ByteArray = EditBoxText.toUtf8();
    char *p = ByteArray.data();

    QByteArray HexValueArray;
    if(*p == 0)
    {
        qDebug() << "Error: bytearray is empty";
        return;
    }
    while(*p)     // Convert 8-bit char to 2 4-bit hex value.
    {
        HexValueArray.append(((*p) >> 4) & 0x0f);
        HexValueArray.append(*p & 0x0f);
        p++;
    }

    QString EncodedString;
    for(int i=0;i<HexValueArray.size();i++)
    {
        if(HexValueArray.at(i) < 0x0 || HexValueArray.at(i) > 0xf)
        {
            qDebug() << "Error: invalid value";
            return;
        }
        if(HexValueArray.at(i) < 4) //0x0 ~ 0xf: 17 number 21-17=4
        {
            int OneOrZero = QRandomGenerator::global()->generate() % 2;
            if(OneOrZero == 0)
            {
                EncodedString += MyClassmateCollectionA.at(17 + HexValueArray.at(i));
            }
            else
            {
                EncodedString += MyClassmateCollectionA.at(HexValueArray.at(i));
            }
        }
        else
        {
            EncodedString += MyClassmateCollectionA.at(HexValueArray.at(i));
        }

        int TwoOrOneOrZero = QRandomGenerator::global()->generate() % 3;
        EncodedString += MyClassmateCollectionB.at(TwoOrOneOrZero); // Select a separator randomly
    }

    this->TextBox->setPlainText(EncodedString);
}

void MainWindow::OnDecodeButtonClicked()
{

}
