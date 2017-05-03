//发布
#include <px4_config.h>
#include <px4_tasks.h>
#include <px4_posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>
#include <math.h>

#include <uORB/uORB.h>
#include <uORB/topics/ca_trajectory.h> //第一次编译会生成Mytest.h，需要添加到头文件中

__EXPORT int ca_trajectory_main(int argc, char *argv[]);

int ca_trajectory_main(int argc, char *argv[])
{
    /*在Mytest.h中会生成Mytest_s结构体*/
    struct ca_trajectory_s orbtest;

    memset(&orbtest,0,sizeof(orbtest));

    /*第一步：公告主题*/
    orb_advert_t pub_fd=orb_advertise(ORB_ID(ca_trajectory),&orbtest);

    while(1)
    {

    	 orbtest.time_start_usec=rand();
    	    orbtest.time_stop_usec=rand();
    	    for(int i=0;i<28;i++)
    	    {
    	    	orbtest.coefficients[i]=rand();
    	    }
    	    orbtest.seq_id=rand();

    	    /*第二步：发布主题*/
    	    orb_publish(ORB_ID(ca_trajectory),pub_fd,&orbtest);

    	   /* PX4_INFO("DATA:\t%4.2f\t%4.2f\t%4.2f",//\t%4.2f",
    	    	            (double)orbtest.time_start_usec,
    	    	            (double)orbtest.time_stop_usec,
    	    	            (double)orbtest.seq_id);*/
    	    sleep(2);

    }

    return 0;
}

