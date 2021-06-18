#ifndef MUSICLIST_H
#define MUSICLIST_H
#include<vector>
using namespace std; 

#include"Music.h"
#include <QMediaPlaylist>
#include <QListWidget> 

class MusicListWidget;
//�����б�
class MusicList
{    
    //�赥��
    QString name;
    //���洢�ĸ���
    vector<Music> music;
    
    //�����Ƿ���Ҫ�����ݿ⽻�������磺��ǰ�����б�ĸ赥ɾ������ʱ����Ҫ�������ݿ⣬ֻ����ʱ�ģ�
    bool sql_flag=true;
    
    friend class MainWidget;
public:
    MusicList(){}
    MusicList(const QList<QUrl>& urls,QString iname="");
    //�趨�赥��
    void setName(const QString& iname){name=iname;}
    QString getName(){ return name; }
    //�趨���ݿ��־
    void setSQL(bool on){ sql_flag=on; }
    //��url��Ӹ���
    void addMusic(const QList<QUrl>& urls);
    //���һ�׸���
    void addMusic(const Music& iMusic);
    //��ȡָ��λ�õĸ���
    Music getMusic(int pos);
    //�����赥���벥���б�
    void addToPlayList(QMediaPlaylist *playlist);
    //�赥���ӻ�
    void addToListWidget(MusicListWidget *listWidget);
    //�Ƴ�ָ���ĸ���
    void removeMusic(int pos);
    //���ļ����д�
    void showInExplorer(int pos);
    //��ʾָ��������ϸ��Ϣ
    void detail(int pos);
    //���ݿ����Ƴ�ȫ�����赥�ĸ���
    void remove_SQL_all();
    //���赥�еĸ���ȫ��д�����ݿ�
    void insert_SQL_all();
    //�������лָ����赥
    void read_fromSQL();
    //�����б��еĸ�������
    void sort_by(COMPARE key);
    //����赥�����赥�е��ظ�����ȥ��������
    void neaten();
    //��ձ��赥
    void clear();
};

#endif // MUSICLIST_H
