#include "MyAccount.h"
#include "MyCall.h"

#include <QString>
#include <QDebug>

#include "MetaVoIP.h"

MyAccount::MyAccount(MetaVoIP *parent)
{
    this->parent = parent;
}

MyAccount::~MyAccount()
{
}

void MyAccount::onRegState(OnRegStateParam &prm) {
    AccountInfo ai = getInfo();
    qDebug() << (ai.regIsActive? "*** Register:" : "*** Unregister:")
             << " code=" << prm.code;

    parent->emitRegStateStarted(ai.regIsActive);
}

void MyAccount::onRegStarted(OnRegStartedParam &prm)
{
     AccountInfo ai = getInfo();
     qDebug() << (ai.regIsActive? "*** Register:" : "*** Unregister:")
              << " code=" << prm.renew;

     parent->emitRegStateChanged(ai.regIsActive);
}

void MyAccount::onIncomingCall(OnIncomingCallParam &iprm)
{
    qDebug() << "Incoming call with callId" << iprm.callId;

    parent->ring(iprm.callId);
}

