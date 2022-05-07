/*****************************************************************************
 * homewidget.h
 *
 * Created: 07/05/2022 2022 by sinyx
 *
 * Copyright 2022 sinyx. All rights reserved.
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 *****************************************************************************/
#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class HomeWidget;
}

class HomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = nullptr);
    ~HomeWidget();

    Ui::HomeWidget *getUi() const;

private:
    Ui::HomeWidget *ui;
    QSqlTableModel* fireTypePokemonsModel;
    QSqlTableModel* waterTypePokemonsModel;
    QSqlTableModel* electrikTypePokemonsModel;
    QSqlTableModel* plantTypePokemonsModel;
};

#endif // HOMEWIDGET_H
