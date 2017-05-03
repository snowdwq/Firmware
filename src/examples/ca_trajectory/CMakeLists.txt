px4_add_module(  
    MODULE examples__ca_trajectory  
    MAIN ca_trajectory  
    STACK_MAIN 2000  
    SRCS  
        ca_trajectory.c  
    DEPENDS  
        platforms__common  
    )  
# vim: set noet ft=cmake fenc=utf-8 ff=unix :   