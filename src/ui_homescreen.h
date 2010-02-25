/********************************************************************************
** Form generated from reading ui file 'homescreen.ui'
**
** Created: Wed Feb 24 19:33:59 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HOMESCREEN_H
#define UI_HOMESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homescreen
{
public:
    QLabel *label;
    QToolButton *btnMusic;
    QToolButton *btnSettings;

    void setupUi(QWidget *homescreen)
    {
        if (homescreen->objectName().isEmpty())
            homescreen->setObjectName(QString::fromUtf8("homescreen"));
        homescreen->resize(800, 480);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        homescreen->setPalette(palette);
        label = new QLabel(homescreen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 801, 81));
        QFont font;
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        btnMusic = new QToolButton(homescreen);
        btnMusic->setObjectName(QString::fromUtf8("btnMusic"));
        btnMusic->setGeometry(QRect(10, 90, 381, 381));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnMusic->sizePolicy().hasHeightForWidth());
        btnMusic->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(26);
        btnMusic->setFont(font1);
        btnMusic->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/resources/images/Nuvola_music.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnMusic->setIcon(icon);
        btnMusic->setIconSize(QSize(256, 256));
        btnMusic->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnSettings = new QToolButton(homescreen);
        btnSettings->setObjectName(QString::fromUtf8("btnSettings"));
        btnSettings->setGeometry(QRect(410, 90, 381, 381));
        btnSettings->setFont(font1);
        btnSettings->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/resources/images/Gears.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnSettings->setIcon(icon1);
        btnSettings->setIconSize(QSize(256, 256));
        btnSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        retranslateUi(homescreen);

        QMetaObject::connectSlotsByName(homescreen);
    } // setupUi

    void retranslateUi(QWidget *homescreen)
    {
        homescreen->setWindowTitle(QApplication::translate("homescreen", "homescreen", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("homescreen", "mcar", 0, QApplication::UnicodeUTF8));
        btnMusic->setText(QApplication::translate("homescreen", "Music", 0, QApplication::UnicodeUTF8));
        btnSettings->setText(QApplication::translate("homescreen", "Settings", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(homescreen);
    } // retranslateUi

};

namespace Ui {
    class homescreen: public Ui_homescreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREEN_H
