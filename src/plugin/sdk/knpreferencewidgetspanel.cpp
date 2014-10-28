/*
 * Copyright (C) Kreogist Dev Team <kreogistdevteam@126.com>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */
#include <QLabel>
#include <QBoxLayout>

#include "preference/knpreferenceitemglobal.h"
#include "preference/knpreferenceitembase.h"

#include "knpreferencewidgetspanel.h"

#include <QDebug>

using namespace PreferenceItemGlobal;

KNPreferenceWidgetsPanel::KNPreferenceWidgetsPanel(QWidget *parent) :
    QScrollArea(parent)
{
    //Set properties.
    setContentsMargins(0,0,0,0);
    setFrameShape(QFrame::NoFrame);
    setWidgetResizable(true);

    //Initial the container.
    m_container=new QWidget(this);
    //Set container properties.
    m_container->setContentsMargins(0,0,0,0);
    setWidget(m_container);

    //Initial the layout.
    m_mainLayout=new QBoxLayout(QBoxLayout::TopToBottom,
                                this);
    m_mainLayout->setContentsMargins(0,0,0,0);
    m_mainLayout->setSpacing(0);
    m_container->setLayout(m_mainLayout);

    //Add strectch at the end of the layout.
    m_mainLayout->addStretch();
}

void KNPreferenceWidgetsPanel::addTitle(QLabel *titleWidget,
                                        const bool &isAdvanced)
{
    //Change parent relationship.
    titleWidget->setParent(this);
    //Check is advanced item. If yes, linked to advanced signal.
    if(isAdvanced)
    {
        setAdvancedItem(titleWidget);
    }
    //Add title widget.
    m_mainLayout->insertWidget(m_mainLayout->count()-1,
                               titleWidget);
}

void KNPreferenceWidgetsPanel::addItem(KNPreferenceItemBase *item,
                                       const bool &isAdvanced)
{
    //Change parent relationship.
    item->setParent(this);
    //Check is advacned item. If yes, linked to advanced signal.
    if(isAdvanced)
    {
        setAdvancedItem(item);
    }
    //Add widget to layout.
    m_mainLayout->insertWidget(m_mainLayout->count()-1,
                               item);
}

QString KNPreferenceWidgetsPanel::panelCaption() const
{
    return m_panelCaption;
}

void KNPreferenceWidgetsPanel::setPanelCaption(const QString &panelCaption)
{
    m_panelCaption = panelCaption;
}

bool KNPreferenceWidgetsPanel::advancedMode() const
{
    return m_advancedMode;
}

void KNPreferenceWidgetsPanel::setAdvancedMode(bool advancedMode)
{
    m_advancedMode=advancedMode;
    emit requireSetAdvancedVisible(m_advancedMode);
}

void KNPreferenceWidgetsPanel::setAdvancedItem(QWidget *item)
{
    connect(this, &KNPreferenceWidgetsPanel::requireSetAdvancedVisible,
            item, &QWidget::setVisible);
    item->setVisible(m_advancedMode);
}

void KNPreferenceWidgetsPanel::setNormalMode(bool normalMode)
{
    setAdvancedMode(!normalMode);
}