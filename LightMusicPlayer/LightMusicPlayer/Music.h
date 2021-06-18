#ifndef MUSIC_H
#define MUSIC_H
#include <QString>
#include <QUrl>


//������
class Music
{
private:
	//������Դ��ַ
	QUrl url;
	//����
	QString author;
	//������
	QString title;
	//ʱ��
	qint64 duration;
	//��Ƭ��
	QString albumTitle;
	//������
	int audioBitRate;

	//���ݸ���url��ø�����Ϣ
	void refreshInfo();

	friend class MusicCompare;
public:
	Music() {}
	Music(QUrl iurl);

	//���ظ���Url
	QUrl getUrl() const { return url; }
	//���ظ�������Ϣ
	QString getInfo() const;
	//������ʾ������Ϣ
	void detail();
	//�������ݿ�
	void insertSQL(const QString& name);
	//�����ļ�������ȡ���·��
	QString getLyricFile();

	friend class MusicList;
};


//����Ŀ�ѡ����
enum COMPARE { DEFAULT, TITLE, AUTHOR, DURATION, EQUALITY };

//���ڸ�������ĺ�������
class MusicCompare
{
	COMPARE key;
public:
	MusicCompare() { key = DEFAULT; }
	MusicCompare(COMPARE ikey) { key = ikey; }
	bool operator()(const Music& A, const Music& B);
};

#endif // MUSIC_H
