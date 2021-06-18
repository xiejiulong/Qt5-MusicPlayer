/*!
 * \file Music.cpp
 *
 * \author xiejiulong
 * \date 2021/06/18 16:22
 *
 * 
 */
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QMessageBox>
#include <QtSql>
#include "Music.h"

Music::Music(QUrl iurl)
{
	url = iurl;
	refreshInfo();
}

extern QString formatTime(qint64 timeMilliSeconds);
void Music::refreshInfo()
{
	QMediaPlayer tempPlayer;
	tempPlayer.setMedia(url);
	//Ԫ���ݵĽ�����Ҫʱ�䣬����������Ҫѭ���ȴ�����ͬʱ��Ҫ����Qt�¼�������������У�
	while (!tempPlayer.isMetaDataAvailable()) {
		QCoreApplication::processEvents();
	}
	QStringList list = tempPlayer.availableMetaData();//����ʱ�鿴����ЩԪ���ݿ���
	if (tempPlayer.isMetaDataAvailable()) {
		//������Ϣ
		author = tempPlayer.metaData(QStringLiteral("Author")).toStringList().join(",");
		//author = tempPlayer.metaData(QStringLiteral("Author")).toString(); //���ֲᷢ�֣����ﷵ�ص���StringList
		//author=tempPlayer.metaData(QStringLiteral("ContributingArtist")).toStringList().join(","); //��һ��Ԫ����
		title = tempPlayer.metaData(QStringLiteral("Title")).toString();
		albumTitle = tempPlayer.metaData(QStringLiteral("AlbumTitle")).toString();
		audioBitRate = tempPlayer.metaData(QStringLiteral("AudioBitRate")).toInt();
		duration = tempPlayer.duration();
	}
}

QString Music::getLyricFile()
{
	QString mp3FilePath = url.toLocalFile();
	mp3FilePath.replace(".mp3", ".lrc");
	mp3FilePath.replace(".flac", ".lrc");
	mp3FilePath.replace(".mpga", ".lrc");
	return mp3FilePath;
}

QString Music::getInfo() const
{
	return author + " - " + title + " [" + formatTime(duration) + "]";
}

void Music::detail()
{
	QString info("��������%1\n�����ң�%2\nʱ����%3\n��Ƭ����%4\n�����ʣ�%5\n�ļ�·����%6");
	info = info.arg(title, author, formatTime(duration), albumTitle, QString::number(audioBitRate) + "bps", url.toString());
	QMessageBox::about(Q_NULLPTR, "������Ϣ", info);
}

void Music::insertSQL(const QString& name)
{
	QSqlQuery sql_query;
	QString insert_sql = "insert into MusicInfo values (?, ?, ?, ?, ?, ?, ?)";
	sql_query.prepare(insert_sql);
	sql_query.addBindValue(name);
	sql_query.addBindValue(url.toString());
	sql_query.addBindValue(author);
	sql_query.addBindValue(title);
	sql_query.addBindValue(duration);
	sql_query.addBindValue(albumTitle);
	sql_query.addBindValue(audioBitRate);
	sql_query.exec();
}

bool MusicCompare::operator()(const Music& A, const Music& B)
{
	switch (key) {
	case TITLE:
		return A.title < B.title;
	case AUTHOR:
		return A.author < B.author;
	case DURATION:
		return A.duration < B.duration;
	case EQUALITY:
		return A.getUrl() == B.getUrl();
	default:
		return A.getInfo() < B.getInfo();
	}
}