#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //RunTest();
}

MainWidget::~MainWidget()
{
}

void MainWidget::RunTest()
{
    file.setFileName(file_name);
    qDebug() << file_name;
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Image Read Failed!";
    }
    qint64 file_size = file.size();
    qDebug()<<"File size : " << file_size;

    mmf = file.map(0,file_size);
    m_img.loadFromData(mmf, file_size, NULL);
    qDebug()<<m_img.size();
}

