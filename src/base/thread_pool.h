/**********************************************************************************
 * @author XuHuanyu
 * @data 2019/6/18
 * @brief the threadpool based on the posix
 * it can be used in the unix/linux
 * the basic api : pthread_create, pthread_mutex_init.......
 * 
 * 
 * 
 * *********************************************************************************/

#ifndef _PTHREADPOOL_H_
#define _PTHREADPOOL_H_

#include <iostream>
#include <map>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>
#include "base/uncopyable.h"

#define MAX_NUM 3

using namespace std;

//��ž�������
typedef struct work {
    void* (*process)(void* arg);
    void* arg;
} ThreadWork;

class PthreadPool : public uncopyable {
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
