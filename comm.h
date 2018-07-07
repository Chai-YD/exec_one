#pragma once

#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define CLIENT_TYPE 1
#define SERVER_TYPE 2

#define PATHNAME "."
#define PROJ_ID 0X6666

struct msgbuf{
    long mtype;
    char mtext[1024];
};

int createMsgQueue();
int getMsgQueue();
int destroyMsgQueue(int msgid);
int sendMsg(int msgid,int who,char *msg);
int recvMsg(int msgid,int recvType,char out[]);
