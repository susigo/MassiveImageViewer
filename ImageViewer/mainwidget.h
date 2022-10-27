#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QImageReader>
#include <QFile>
#include <QDebug>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
public:
    void RunTest();
private:
    const unsigned char *mmf;
    QImageReader reader;
    QImage m_img;
    std::string file_str= "E:/Downloads/wallpaper/wall4.jpg";
    QString file_name = "E:/Downloads/wallpaper/wall4.jpg";
    QFile file;
};
#endif // MAINWIDGET_H
