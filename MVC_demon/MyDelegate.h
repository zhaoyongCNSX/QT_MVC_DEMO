#ifndef __MY_DELEGATE_H__
#define __MY_DELEGATE_H__

#include <QStyledItemDelegate>

class MyDelegate: public QStyledItemDelegate
{
	Q_OBJECT
public:
	MyDelegate();
	~MyDelegate();

public:
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
	virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index)const Q_DECL_OVERRIDE;
};

#endif //__MY_DELEGATE_H__