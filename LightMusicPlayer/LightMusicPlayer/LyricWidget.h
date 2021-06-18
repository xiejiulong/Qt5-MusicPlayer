#ifndef LYRICWIDGET_H
#define LYRICWIDGET_H

#include<QWidget>
#include<QLabel>
#include<QFile>
#include<vector>
using namespace std;

//��ʾһ�и�ʣ�һ��ʱ���+��Ӧ�ĸ���ı���
class LyricLine
{
public:
    qint64 time;
    QString text;
    LyricLine(qint64 time, QString text):time(time), text(text){}    
};

bool operator <(const LyricLine& A, const LyricLine& B);

namespace Ui {
class LyricWidget;
}

class LyricWidget : public QWidget
{
    Q_OBJECT
    
    //�������и��
    vector<LyricLine> lines;    
public:
    explicit LyricWidget(QWidget *parent = nullptr);
    ~LyricWidget();

    //������ļ������ݴ���Ϊ��ʽṹ��QList
    bool process(QString filePath); 
    //����ʱ���ҵ���Ӧλ�õĸ��
    int getIndex(qint64 position);
    //��ʾ��ǰ���Ž��ȵĸ��
    void show(qint64 position);
    //�����±��ø������
    QString getLyricText(int index);
    //��ո��Label
    void clear();
    
private:
    Ui::LyricWidget *ui;
};

#endif // LYRICWIDGET_H
