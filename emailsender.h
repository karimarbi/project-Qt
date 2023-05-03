#ifndef EMAILSENDER_H
#define EMAILSENDER_H
#include <QtNetwork/QNetworkAccessManager>

#include <QObject>

class EmailSender : public QObject
{
    Q_OBJECT
public:
    explicit EmailSender(QObject *parent = nullptr);

    void sendEmail(QString to, QString subject, QString body, QString attachmentFilePath = "");

private:
    QNetworkAccessManager *m_manager;


signals:
    void emailSent();
    void emailFailed(QString errorString);
private slots:
    void replyFinished(QNetworkReply *reply);



};

#endif // EMAILSENDER_H
