#ifndef __MY_LISTVIEW_H__
#define __MY_LISTVIEW_H__

#include <QListView>

class MyListView: public QListView
{
	Q_OBJECT
public:
	MyListView(QWidget *parent = NULL);
	~MyListView();

protected:
	virtual void currentChanged(const QModelIndex &current, const QModelIndex &previous) Q_DECL_OVERRIDE;
};

#endif //__MY_LISTVIEW_H__
