#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include<QListWidget>
#include<MusicList.h>

class MusicListWidget:public QListWidget
{
    Q_OBJECT
    //��ǰ�����б��洢���Ǹ�����Ϣ��
    MusicList musicList;
    //��ǰչʾ�б���ʹ�õ�ͼ��
    QIcon icon=QIcon(":/image/image/image/music.png");
public:
    MusicListWidget(QWidget *parent = Q_NULLPTR);
    //ˢ����ʾ����musicList�����仯ʱ����Ҫ���ã�
    void refresh();
    //���ø����б�
    void setMusicList(const MusicList& music);
    //���ò����б�
    void setMusicList_playing(const MusicList& music);
    //�Ƴ�����
    void removeMusic();
    //���ļ����д�
    void showInExplorer();
    //��������
    void detail();
    //����/��ȡͼ��Icon
    void setIcon(QIcon iicon){ icon=iicon; }
    QIcon getIcon(){ return icon; }
    
    friend class MainWidget;
private:
    
};

#endif // MYLISTWIDGET_H
