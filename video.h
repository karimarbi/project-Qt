#ifndef VIDEO_H
#define VIDEO_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

namespace Ui {
class Video;
}

class Video : public QMainWindow
{
    Q_OBJECT

public:
    explicit Video(QWidget *parent = nullptr);
    ~Video();

private slots:
    void on_actionOpen_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionPlay_triggered();

private:
    Ui::Video *ui;
    QMediaPlayer* player;
        QVideoWidget* vw;
        QProgressBar* bar;
        QSlider* slider;
};

#endif // VIDEO_H
