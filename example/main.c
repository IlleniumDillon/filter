/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-06-24 19:52:30
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-06-26 19:26:49
 * @FilePath: \filter\example\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include "../include/filter.h"

int main()
{
    //filter_t t;
    //fl_butterLPFConfig(&t,0.005,31.4,80,1,80,1);
    //fl_secondOrderLPFConfig(&t,0.005,31.4,1,1);
    /*filter_kalman_t p;
    CREATE_NEW_MARTRIX(1,1,A,NULL);
    A.elements[0]=1;
    CREATE_NEW_MARTRIX(1,1,B,NULL);
    B.elements[0]=0;
    CREATE_NEW_MARTRIX(1,1,H,NULL);
    H.elements[0]=1;
    CREATE_NEW_MARTRIX(1,1,Q,NULL);
    Q.elements[0] = 1;
    CREATE_NEW_MARTRIX(1,1,R,NULL);
    R.elements[0] = 0.5;
    CREATE_NEW_MARTRIX(1,1,U,NULL);
    U.elements[0] = 0;
    CREATE_NEW_MARTRIX(1,1,Z,NULL);
    Z.elements[0] = 1;
    fl_initKalmanFilter(&p,&A,&B,&H,&Q,&R);*/
    /*filter_average_t y;
    fl_initAverageFilter(&y,10);*/
    filter_limit_t E;
    fl_initLimitFilter(&E,1,-1,0.5,-0.5);
    for(int i = 0; i < 100 ; i++)
    {
        //Z.elements[0] = 1+rand();
        //fl_kalmanFilterUpdate(&p,&U,&Z);
        printf("%f\n",fl_limitFilterUpdate(&E,i*3));
    }
    return 0;
}