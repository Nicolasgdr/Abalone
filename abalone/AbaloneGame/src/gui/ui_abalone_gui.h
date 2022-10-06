/********************************************************************************
** Form generated from reading UI file 'abalone_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABALONE_GUI_H
#define UI_ABALONE_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_abalone_gui
{
public:
    QWidget *centralwidget;
    QPushButton *apply_move;
    QRadioButton *move_alone;
    QRadioButton *move_group;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *message_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *abalone_gui)
    {
        if (abalone_gui->objectName().isEmpty())
            abalone_gui->setObjectName(QString::fromUtf8("abalone_gui"));
        abalone_gui->resize(1252, 941);
        centralwidget = new QWidget(abalone_gui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        apply_move = new QPushButton(centralwidget);
        apply_move->setObjectName(QString::fromUtf8("apply_move"));
        apply_move->setGeometry(QRect(960, 800, 141, 71));
        move_alone = new QRadioButton(centralwidget);
        move_alone->setObjectName(QString::fromUtf8("move_alone"));
        move_alone->setGeometry(QRect(510, 820, 115, 24));
        move_group = new QRadioButton(centralwidget);
        move_group->setObjectName(QString::fromUtf8("move_group"));
        move_group->setGeometry(QRect(740, 820, 115, 24));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 1171, 711));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        message_label = new QLabel(centralwidget);
        message_label->setObjectName(QString::fromUtf8("message_label"));
        message_label->setGeometry(QRect(0, 750, 1251, 41));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        message_label->setFont(font);
        message_label->setLayoutDirection(Qt::LeftToRight);
        message_label->setAlignment(Qt::AlignCenter);
        abalone_gui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(abalone_gui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1252, 23));
        abalone_gui->setMenuBar(menubar);
        statusbar = new QStatusBar(abalone_gui);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        abalone_gui->setStatusBar(statusbar);

        retranslateUi(abalone_gui);

        QMetaObject::connectSlotsByName(abalone_gui);
    } // setupUi

    void retranslateUi(QMainWindow *abalone_gui)
    {
        abalone_gui->setWindowTitle(QApplication::translate("abalone_gui", "abalone_gui", nullptr));
        apply_move->setText(QApplication::translate("abalone_gui", "GO", nullptr));
        move_alone->setText(QApplication::translate("abalone_gui", "move_alone", nullptr));
        move_group->setText(QApplication::translate("abalone_gui", "move_group", nullptr));
        message_label->setText(QApplication::translate("abalone_gui", "Hello Welcome to abalone Game click on a choice below to defined the move you want to apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class abalone_gui: public Ui_abalone_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABALONE_GUI_H
