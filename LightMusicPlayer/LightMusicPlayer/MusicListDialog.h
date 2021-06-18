#ifndef MUSICLISTDIALOG_H
#define MUSICLISTDIALOG_H

#include <QDialog>
#include "MusicList.h"
#include "MusicListWidget.h"

namespace Ui {
class MusicListDialog;
}

class MusicListDialog : public QDialog
{
    Q_OBJECT
    //��������
    int num; 
    //��Ÿ�����Ŀ�Ƿ�ѡ�����ڷ���ѡ������
    bool *selected_flag;
public:
    explicit MusicListDialog(QWidget *parent = nullptr);
    ~MusicListDialog();
    
    //�趨�Ի���չʾ���ĸ赥�Լ�ѡ������ŵĵط�
    void setMusicList(MusicList& ilist, bool *results);
    
private slots:
    
    void on_buttonBox_accepted();
    
private:
    Ui::MusicListDialog *ui;
};

#endif // MUSICLISTDIALOG_H
