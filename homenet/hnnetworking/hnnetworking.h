#ifndef HNNETWORKING_H
#define HNNETWORKING_H

class HNNetworking;

#include <QTcpServer>
#include <QObject>

#include <vector>

#include "log/log.h"
#include "hnclient.h"

class HNNetworking : public QObject {
Q_OBJECT
public:
    HNNetworking();

    void                                    startListening(int port);

    friend class                            HNClient;
private:
    QTcpServer*                             _server;
    QList<HNClient*>                        _clients;

    std::thread*                            _t_listen;
    bool                                    _listen;
    void                                    p_listen();
};

#endif // HNNETWORKING_H
