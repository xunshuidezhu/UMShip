#ifndef _PTHREADPOOL_H_
#define _PTHREADPOOL_H_

#include <iostream>
#include <map>
#include <string.h>
#include <unistd.h>
#include <vector>

#define MAX_NUM 3

using namespace std;

//��ž�������
typedef struct work {
    void* (*process)(void* arg);
    void* arg;
} ThreadWork;

class PthreadPool {
public:
    void Pthreadinit();
    void Addwork(void* (*process)(void* arg), void* arg); //���߳����������
    int DestroyPthread();
    static void* func(void* arg); //�߳��е��õĻص�����
    static void* myprocess(void* arg); //���幤���ĺ���

private:
    static pthread_mutex_t queue_lock;
    static pthread_cond_t queue_cond;
    static vector<ThreadWork*> m_vec; //��������
    static int cur_num; //��ǰ�������������������Ҳ����ȡ����vector�Ĵ�С�жϡ�
    static pthread_t* threadid; //�߳̾��
    static int isshutdown; //�߳��Ƿ�������������0 ������1 ����
};

#endif
