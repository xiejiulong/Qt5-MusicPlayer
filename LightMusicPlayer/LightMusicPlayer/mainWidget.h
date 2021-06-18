#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMenu>
#include <QSystemTrayIcon>
#include "MusicList.h"
#include "LyricWidget.h"
#include <QCloseEvent>


namespace Ui {
class Widget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget() override;
    
private:
    Ui::Widget *ui;
    void paintEvent(QPaintEvent *event) override;
    
    //UI��������һЩ����
    void init_UI();
    
    //��ǰ������
    QMediaPlayer *player;
    //��ǰ�����б�
    QMediaPlaylist *playlist;
    //��ʼ��һЩ��Ա�����Լ�connect����
    void init_play();
    //���²�����Ϣ��أ����ȡ���Ϣ�ȣ�
    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void setPosition(int position);
    void updateInfo();
    void updatePlayBtn();
    
    //ϵͳ����
    QSystemTrayIcon *mySystemTray;
    QAction *action_systemTray_play;
    QAction *action_systemTray_playmode;
    //��Ӧϵͳ���̵Ķ�����˫���ȣ�
    void systemTrayIcon_activated(QSystemTrayIcon::ActivationReason reason);
    //�˳�Ӧ��
    void quitMusicPlayer();
    //ϵͳ���̳�ʼ��
    void init_systemTrayIcon();
    
    //���ݿ��ʼ��
    void init_sqlite();
    //���ó�ʼ���������ļ���ȡ��
    void init_settings();
    //���������֡�������ϲ�����ȸ赥�ĳ�ʼ��
    void init_musicList();
    
    //�赥
    vector<MusicList> musiclist;
    //���ڱ�ʶ����չʾ�����ĸ��赥
    int musiclist_index=-1;
    //����չʾ�赥���ֵ�listwidget
    void namelist_refresh();
    //���ڸ���չʾ�赥���ݵ�listwidget
    void musicListWidget_refresh();   
    
    /*�Ҽ��˵�*/
    //�˵���ĳ�ʼ��
    void init_actions();
    //����ǰ���š��б���Ҽ��˵�
    QMenu *menu_playlist;
    //���������֡��б���Ҽ��˵�
    QMenu *menu_locallist;
    //����ϲ�����б���Ҽ��˵�
    QMenu *menu_favorlist;
    //���赥���б����Ҽ��˵�
    QMenu *menu_namelist;
    //���赥չʾ�б����Ҽ��˵�
    QMenu *menu_musiclist;
    //����Ƥ���Ĳ˵�
    QMenu *menu_changeSkin; 

protected:
    //�����϶�ʱ��¼����ʼ��
    QPoint offset;
    /*��дWidget��һЩ����*/
    //ʵ�ִ��ڿ��϶�
    void mousePressEvent(QMouseEvent *event) override; 
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    //�ر�ʱ���˳������ǵ�ϵͳ����
    void closeEvent(QCloseEvent *event) override;
    //��ק�ļ�����
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;

private slots:
    /*�����Ҽ��˵����Ӧ�Ĳ���������ӦQAction���ӵĲۺ�����*/
    void playlist_removeMusic();//��ǰ�����б�-�Ҽ��˵� �Ƴ�����
    void play_to_favor();//�ӵ�ǰ������ӵ���ϲ��
    void local_to_favor();//�ӱ���������ӵ���ϲ��
    void local_to_playlist();//�ӱ���������ӵ���ǰ�����б�
    void favor_to_playlist();//����ϲ����ӵ���ǰ�����б�
    void namelist_delete();//�Ƴ��赥
    void musiclist_removeMusic();//�Ӹ赥չʾ�б��Ƴ�����
    void musiclist_to_favor();//�ӵ�ǰ�赥��ӵ���ϲ��
    void musiclist_to_playlist();//�ӵ�ǰ�赥��ӵ����ڲ���
    void background_to_default();//����Ĭ�ϱ���
    void background_setting();//�Զ��屳��
    
    /*һЩ����¼�����Ӧ��ʹ��.ui�еĲ�����ת���ۡ��Զ����ɣ�*/
    void on_btnCurMusic_clicked();
    void on_btnLocalMusic_clicked();
    void on_btnFavorMusic_clicked();
    void on_btnQuit_clicked();    
    void on_btnMin_clicked();    
    void on_btnPlay_clicked();
    void on_btnNext_clicked();
    void on_btnPre_clicked();
    void on_btnPlayMode_clicked();
    void on_btnAdd_clicked();
    void on_btnVolume_clicked();
    void on_volumeSlider_valueChanged(int value);
    void on_btnAddMusicList_clicked();
    void on_playListWidget_doubleClicked(const QModelIndex &index);
    void on_localMusicWidget_doubleClicked(const QModelIndex &index);
    void on_favorMusicWidget_doubleClicked(const QModelIndex &index);
    void on_playListWidget_customContextMenuRequested(const QPoint &pos);
    void on_localMusicWidget_customContextMenuRequested(const QPoint &pos);
    void on_favorMusicWidget_customContextMenuRequested(const QPoint &pos);
    void on_nameListWidget_customContextMenuRequested(const QPoint &pos);
    void on_nameListWidget_doubleClicked(const QModelIndex &index);
    void on_btnSkin_clicked();
    void on_btnAddtoMusicList_clicked();
    void on_musicListWidget_doubleClicked(const QModelIndex &index);
    void on_musicListWidget_customContextMenuRequested(const QPoint &pos);
    void on_btnAddtoFavor_clicked();
    void on_btnNeaten_clicked();//����赥��ť
    void on_btnNeaten_2_clicked();
    void on_btnNeaten_3_clicked();
    void on_btnTitle_clicked();
    void on_btnLyric_clicked();
    void on_btnClear_clicked();//���
    void on_btnClear_2_clicked();
    void on_btnClear_3_clicked();
    void on_btnClear_4_clicked();
    void on_btnAbout_clicked();
    void on_btnSortSinger_clicked();//�赥����
    void on_btnSortTitle_clicked();
    void on_btnSortDuration_clicked();
    void on_btnSortSinger_2_clicked();
    void on_btnSortTitle_2_clicked();
    void on_btnSortDuration_2_clicked();
    void on_btnSortSinger_4_clicked();
    void on_btnSortTitle_4_clicked();
    void on_btnSortDuration_4_clicked();
};

#endif // MAINWIDGET_H
