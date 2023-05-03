#include "emailsender.h"
#include <QUrl>
#include <QUrlQuery>
#include <QDateTime>
#include <QFileInfo>
#include <QFile>
#include <QNetworkRequest>
#include <QtNetwork/QNetworkReply>



EmailSender::EmailSender(QObject *parent) : QObject(parent)
{

    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &EmailSender::replyFinished);
}

void EmailSender::sendEmail(QString to, QString subject, QString body, QString attachmentFilePath)
{
    QUrl url("https://api.mailgun.net/v3/<yourdomain>/messages");
    QUrlQuery params;
    params.addQueryItem("from", "Rania Touihri <raniatouihri412@gmail.com>");

       params.addQueryItem("to", to);
       params.addQueryItem("subject", subject);
       params.addQueryItem("text", body);

    if (!attachmentFilePath.isEmpty()) {
        QFileInfo fileInfo(attachmentFilePath);
        QFile file(attachmentFilePath);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray data = file.readAll();
            params.addQueryItem("attachment", QString::fromLatin1(data.toBase64()));
            params.addQueryItem("attachment-name", fileInfo.fileName());
            file.close();
        }
    }

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", "Basic <yourbase64encodedapikey>");

    m_manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
}

void EmailSender::replyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        emit emailFailed(reply->errorString());
    } else {
        emit emailSent();
    }
    reply->deleteLater();
}
