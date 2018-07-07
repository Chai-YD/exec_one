#include"comm.h"

int main(){
    int msgid = createMsgQueue();
    char buf[1024];
    while(1){
        recvMsg(msgid,CLIENT_TYPE,buf);
        printf("client# %s\n",buf);

        printf("please enter#");
        fflush(stdout);
        size_t s = read(0,buf,sizeof(buf));
        if(s > 0){
            buf[s - 1] = 0;
            sendMsg(msgid,SERVER_TYPE,buf);
            printf("send done,wait recv...\n");
        }
    }
    destroyMsgQueue(msgid);
    return 0;
}
