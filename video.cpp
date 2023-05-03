#include "video.h"
#include "ui_video.h"

Video::Video(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Video)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);

    slider = new QSlider(this);
    bar = new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);
//affichage
    ui->statusbar->addPermanentWidget(slider);
    ui->statusbar->addPermanentWidget(bar);
//relation video-slider
    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

}

Video::~Video()
{
    delete ui;
}

void Video::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();
}

void Video::on_actionPlay_triggered()
{
    player->play();
    ui->statusbar->showMessage("Playing");
}

void Video::on_actionPause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("Paused...");
}

void Video::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stopped");
}

