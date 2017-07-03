/*****************************************************************************
   模块名      : 新方案业务
   文件名      : evmcu.h
   相关文件    : 
   文件实现功能: 新方案业务MCU内部消息定义
   作者        : 李屹
   版本        : V0.9  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   修改记录:
   日  期      版本        修改人      修改内容
   2002/07/24  0.9         李屹        创建
******************************************************************************/
#ifndef _EV_MCU_H_
#define _EV_MCU_H_

#include "osp.h"
#include "eventid.h"

/**********************************************************
 以下为业务MCU内部消息（28001-29000）
**********************************************************/

///////////////////////////////////////////////////////////
//同一MCU内部消息

//MCU自身发起创建会议请求，消息体为结构TConfFullInfo，表示对应会议信息
OSPEVENT( MCU_CREATECONF_FROMFILE,			EV_MCU_BGN + 1 );
//发给MCU内部会议实例通知某下级MT登记成功，消息体为结构TMt
//OSPEVENT( MCU_MTCONNECTED_NOTIF,			EV_MCU_BGN + 2 );
//发给MCU内部会议实例通知某下级MT断链，消息体为结构TMt
//OSPEVENT( MCU_MTDISCONNECTED_NOTIF,		EV_MCU_BGN + 3 );

//MCU 从N+1备份创建会议
OSPEVENT( MCU_CREATECONF_NPLUS,             EV_MCU_BGN + 3 );

//MCU 通知会话 断链 相应实例, zgc, 2007/04/29
OSPEVENT( MCU_DISCONNECT_CMD,		EV_MCU_BGN + 4 );
//MCU 通知会话 重联MPCB 相应实例, zgc, 2007/04/30
OSPEVENT( MCU_CONNECTMPCB_CMD,		EV_MCU_BGN + 5 );

//发给MCU内部会议实例通知外设建链成功，消息体为TPeriEqpRegReq
OSPEVENT( MCU_EQPCONNECTED_NOTIF,			EV_MCU_BGN + 11 );
//发给MCU内部会议实例通知外设断链，消息体为TEqp
OSPEVENT( MCU_EQPDISCONNECTED_NOTIF,		EV_MCU_BGN + 12 );
//发给MCU内部会议实例通知DCS建链成功, 消息体为 CDcsMcuRegReqPdu
OSPEVENT( MCU_DCSCONNCETED_NOTIF,			EV_MCU_BGN + 13 );
//发给MCU内部会议实例通知DCS断链, 消息体为 CDcsMcuRegReqPdu
OSPEVENT( MCU_DCSDISCONNECTED_NOTIF,		EV_MCU_BGN + 14 );

//发给MCU内部会议实例通知会控建链成功，消息体为单字节会控实例号+CVcCtrlRegReq
//mcu业务不需要感知ACS连接，此消息暂不使用
OSPEVENT( MCU_ACSCONNECTED_NOTIF,			EV_MCU_BGN + 21 );
//发给MCU内部会议实例通知会控断链，消息体为单字节会控实例号
OSPEVENT( MCU_ACSDISCONNECTED_NOTIF,		EV_MCU_BGN + 22 );

//发给MCU内部 MCU重新注册GK 通知，消息体：NULL
OSPEVENT( MCU_MCUREREGISTERGK_NOITF,        EV_MCU_BGN + 23 );

//申请频率
OSPEVENT( MCU_NMS_SENDNMSMSG_CMD,           EV_MCU_BGN + 30 );

//发给MCU内部会议实例通知BAS建链成功，消息体为TPeriEqpRegReq
OSPEVENT( MCU_BASCONNECTED_NOTIF,			EV_MCU_BGN + 31 );
//发给MCU内部会议实例通知BAS断链，消息体为TEqp
OSPEVENT( MCU_BASDISCONNECTED_NOTIF,		EV_MCU_BGN + 32 );

//发给MCU内部会议实例通知PRS建链成功，消息体为TPeriEqpRegReq
OSPEVENT( MCU_PRSCONNECTED_NOTIF,			EV_MCU_BGN + 35 );
//发给MCU内部会议实例通知PRS断链，消息体为TEqp
OSPEVENT( MCU_PRSDISCONNECTED_NOTIF,		EV_MCU_BGN + 36 );

//发给MCU内部会议实例通知REC断链建链成功，消息体为TPeriEqpRegReq
OSPEVENT( MCU_RECCONNECTED_NOTIF,           EV_MCU_BGN + 40 );
//发给MCU内部会议实例通知REC断链，消息体为TEqp
OSPEVENT( MCU_RECDISCONNECTED_NOTIF,		EV_MCU_BGN + 41 );

//发给MCU内部会议实例通知Mixer建链成功，消息体为TEqp
OSPEVENT( MCU_MIXERCONNECTED_NOTIF,		    EV_MCU_BGN + 42 );
//发给MCU内部会议实例通知Mixer断链，消息体为TEqp
OSPEVENT( MCU_MIXERDISCONNECTED_NOTIF,		EV_MCU_BGN + 43 );

//发给MCU内部会议实例通知Vmp建链成功，消息体为TPeriEqpRegReq
OSPEVENT( MCU_VMPCONNECTED_NOTIF,		    EV_MCU_BGN + 44 );
//发给MCU内部会议实例通知Vmp断链，消息体为TEqp
OSPEVENT( MCU_VMPDISCONNECTED_NOTIF,		EV_MCU_BGN + 45 );

//发给MCU内部会议实例通知VmpTw建链成功，消息体为TPeriEqpRegReq
OSPEVENT( MCU_VMPTWCONNECTED_NOTIF,		    EV_MCU_BGN + 46 );
//发给MCU内部会议实例通知VmpTw断链，消息体为TEqp
OSPEVENT( MCU_VMPTWDISCONNECTED_NOTIF,		EV_MCU_BGN + 47 );

//tvwall 2
//发给MCU内部会议实例通知TvWall建链成功，消息体为TPeriEqpRegReq
OSPEVENT( MCU_TVWALLCONNECTED_NOTIF,		EV_MCU_BGN + 48 );
//发给MCU内部会议实例通知Tvwall断链，消息体为TEqp
OSPEVENT( MCU_TVWALLDISCONNECTED_NOTIF,		EV_MCU_BGN + 49 );

// Mcu发给自己的从文件恢复会议,消息体为TConfInfo
OSPEVENT( MCU_WAITEQP_CREATE_CONF_NOTIFY,   EV_MCU_BGN + 50 );

//MCU的GUARD模块向其它模块发的测试请求消息
OSPEVENT( MCU_APPTASKTEST_REQ,				EV_MCU_BGN + 51 );
//MCU的其它模块向GUARD模块发的测试回应消息
OSPEVENT( MCU_APPTASKTEST_ACK,				EV_MCU_BGN + 52 );
//MCU停止GUARD内部定时器
OSPEVENT( MCU_STOPGUARDTIMER_CMD,           EV_MCU_BGN + 53 );
//MCU开启GUARD内部定时器
OSPEVENT( MCU_STARTGUARDTIMER_CMD,          EV_MCU_BGN + 54 );

//MCU初始化地址簿完成通告
OSPEVENT( MCU_ADDRINITIALIZED_NOTIFY,       EV_MCU_BGN + 55 );

//NU会话通知MCU断链
OSPEVENT( MCU_NU_DISCONNECTED_NOTIFY,		EV_MCU_BGN + 56 );

//VCS将会议模板变为即时会议
OSPEVENT( MCU_SCHEDULE_VCSCONF_START,       EV_MCU_BGN + 59 );
//预约会议变为即时会议
OSPEVENT( MCU_SCHEDULE_CONF_START,			EV_MCU_BGN + 60 );

OSPEVENT( MCU_ADDRBOOK_GETENTRYLIST_NOTIF,  EV_MCU_BGN + 61 );
OSPEVENT( MCU_ADDRBOOK_GETGROUPLIST_NOTIF,  EV_MCU_BGN + 62 );

//Mcu Guard timer id
OSPEVENT( MCUGD_GETLICENSE_DATA,            EV_MCU_BGN + 63 );	        // license加密数据 
OSPEVENT( MCUGD_SCHEDULED_CHECK_TIMER,      EV_MCU_BGN + 65 );	        // 定时检查
//OSPEVENT( MCUGD_PASSIVE_CHECK_TIMER,      EV_MCU_BGN + 66 );			// 被动检查
OSPEVENT( MCUGD_FEEDDOG_TIMER,              EV_MCU_BGN + 66 );	        // 定时喂狗 


//McuVc timer id
OSPEVENT( MCUVC_APPLYEQPRESOURCE_CHECK_TIMER,     EV_MCU_BGN + 68 );		//Mcu 创会申请资源定时
OSPEVENT( MCUVC_APPLYFREQUENCE_CHECK_TIMER,     EV_MCU_BGN + 69 );          //卫星会议，mcu向网管服务器申请频率检查
OSPEVENT( MCUVC_SENDFLOWCONTROL_TIMER,          EV_MCU_BGN + 70 );          //mcu发给双流发起终端flowcontrol时的定时器
OSPEVENT( MCUVC_WAIT_CONNECT_MIX_TIMER,			EV_MCU_BGN + 71 );          //MCU等待mix上线恢复
OSPEVENT( MCUVC_WAIT_START_MIX_TIMER,	        EV_MCU_BGN + 72 );          //MCU等待MIXER应答定时     
OSPEVENT( MCUVC_SCHEDULED_CHECK_TIMER,          EV_MCU_BGN + 73 );	        //预约会议定时检查
OSPEVENT( MCUVC_ONGOING_CHECK_TIMER,            EV_MCU_BGN + 74 );			//进行中会议定时检查
OSPEVENT( MCUVC_INVITE_UNJOINEDMT_TIMER,        EV_MCU_BGN + 75 );			//定时邀请未与会终端
OSPEVENT( MCUVC_POLLING_CHANGE_TIMER,           EV_MCU_BGN + 76 );			//轮询改变时钟
//OSPEVENT( MCUVC_TWPOLLING_CHANGE_TIMER,         EV_MCU_BGN + 77 );			//电视墙轮询改变时钟  
OSPEVENT( MCUVC_VMPPOLLING_CHANGE_TIMER,        EV_MCU_BGN + 77 );			//轮询改变时钟
OSPEVENT( MCUVC_WAIT_MPREG_TIMER,               EV_MCU_BGN + 78 );			//等待Mp注册时钟     
OSPEVENT( MCUVC_REFRESH_MCS_TIMER,              EV_MCU_BGN + 79 );			//刷新会控时钟          
OSPEVENT( MCUVC_MCUSRC_CHECK_TIMER,             EV_MCU_BGN + 80 );			//mcu源通知           
OSPEVENT( MCUVC_CHANGE_VMPCHAN_SPEAKER_TIMER,   EV_MCU_BGN + 81 );            
OSPEVENT( MCUVC_CHANGE_VMPCHAN_CHAIRMAN_TIMER,  EV_MCU_BGN + 82 );
OSPEVENT( MCUVC_CHANGE_VMPPARAM_TIMER,          EV_MCU_BGN + 83 );
OSPEVENT( MCUVC_RECREATE_DATACONF_TIMER,        EV_MCU_BGN + 84 );			//重新创建数据会议
OSPEVENT( MCU_SMCUOPENDVIDEOCHNNL_TIMER,		EV_MCU_BGN + 85 );			//下级mcu等待打开双流通道定时器
OSPEVENT( MCUVC_WAIT_CASCADE_CHANNEL_TIMER,     EV_MCU_BGN + 86 );          //等待打开下级MCU的级联通道
OSPEVENT( MCUVC_WAIT_MPOVERLOAR_TIMER,          EV_MCU_BGN + 87 );          //等待 发会控的MP超限消息的 定时器
OSPEVENT( MCUVC_AUTOSWITCH_TIMER,               EV_MCU_BGN + 88 );          //Rad级联轮询KedaMcu本地终端SetOut定时器
//OSPEVENT( MCUVC_HDUPOLLING_CHANGE_TIMER,        EV_MCU_BGN + 89 );          //hdu轮询改变时钟

// xliang [12/12/2008] vmp hd通道抢占中，要抢占的终端进行抢占定时
OSPEVENT( MCUVC_MTSEIZEVMP_TIMER,				EV_MCU_BGN + 90 );
// xliang [12/22/2008] VMP 批量轮询定时
OSPEVENT( MCUVC_VMPBATCHPOLL_TIMER,				EV_MCU_BGN + 91 );

// hdu批量轮询定时
OSPEVENT( MCUVC_HDUBATCHPOLLI_CHANGE_TIMER,     EV_MCU_BGN + 92 );          //hdu批量轮询改变时钟

OSPEVENT( MCUVC_VCMTOVERTIMER_TIMER,            EV_MCU_BGN + 93 );          //调度终端超时定时器
OSPEVENT( MCUVC_VCS_CHAIRPOLL_TIMER,            EV_MCU_BGN + 94 );          //VCS主席论询定时器

//MCU等待适配器应答定时, 因为bas有5种类型，要预留5个空间
OSPEVENT( MCUVC_WAITBASRRSP_TIMER,			    EV_MCU_BGN + 95 );
//MCU给终端发FASTUPDATE的定时器组 留199的空间
OSPEVENT( MCUVC_FASTUPDATE_TIMER_ARRAY,	        EV_MCU_BGN + 100 );
// +101 -- + 297  不能用，都用作申请关键帧的特殊处理！！！！！

//MCU内部MP交换能力满 通知消息
OSPEVENT( MCUVC_MPOVERLOAD_NOTIF,               EV_MCU_BGN + 298 );
//MCU给终端发双流FASTUPDATE的定时器
OSPEVENT( MCUVC_SECVIDEO_FASTUPDATE_TIMER,  	EV_MCU_BGN + 299 );

//MCU会议开始自动录像定时器，
OSPEVENT( MCUVC_CONFSTARTREC_TIMER,             EV_MCU_BGN + 300 ); 
//MCU开始放像定时器, zgc, 2008-03-27
OSPEVENT( MCUVC_RECPLAY_WAITMPACK_TIMER,		EV_MCU_BGN + 301 );
//MCU每天凌晨0点，设置该定时器，用它来刷新该天的自动录像定时器, pengjie, 20091225
OSPEVENT( MCUVC_UPDATA_AUTOREC_TIMER,		EV_MCU_BGN + 302 );

//双流放像，mcu定时发令牌环的定时器 [pengjie 2010/2/26]
OSPEVENT( MCUVC_NOTIFYMCUH239TOKEN_TIMER, 	EV_MCU_BGN + 303 );

// [pengjie 2010/9/29] 检查会议是否有广播源
OSPEVENT( MCUVC_CHECK_CONFBRDSRC_TIMER,		EV_MCU_BGN + 304 );

//MCU等待HD主视频适配器应答定时, 因为会议hd-bas主视频适配最多有4路，要预留3个空间（从0开始）
OSPEVENT( MCUVC_WAITHDVIDBASRSP_TIMER,			EV_MCU_BGN + 305 );
//MCU等待HD双流适配器应答定时, 因为会议hd-bas双流适配最多有1路
OSPEVENT( MCUVC_WAITHDDVIDBASRSP_TIMER,			EV_MCU_BGN + 310 );

//卫星会议主控的部分定时
OSPEVENT( TIMER_SCHEDULED_CHECK,                EV_MCU_BGN + 311 );
OSPEVENT( TIMER_DELAYCONF,                      EV_MCU_BGN + 312 );
OSPEVENT( TIMER_RESCHED,                        EV_MCU_BGN + 313 );
OSPEVENT( TIMER_ADDMT,                          EV_MCU_BGN + 314 );
OSPEVENT( TIMER_DELMT,                          EV_MCU_BGN + 315 );
OSPEVENT( TIMER_INVITE_UNJOINEDMT,              EV_MCU_BGN + 316 );
OSPEVENT( TIMER_SCHEDCONF,                      EV_MCU_BGN + 317 );

//卫星会议，定时刷新; 卫星会议终端链路的KeepAlive基于本消息处理
OSPEVENT( MCUVC_CONFINFO_MULTICAST_TIMER,		EV_MCU_BGN + 318 );

//发给MCU内部会议实例通知Hdu建链成功，消息体为TPeriEqpRegReq
OSPEVENT( MCU_HDUCONNECTED_NOTIF,		        EV_MCU_BGN + 350 );
//发给MCU内部会议实例通知Hdu断链，消息体为TEqp
OSPEVENT( MCU_HDUDISCONNECTED_NOTIF,		    EV_MCU_BGN + 351 );
//mcucfg等待DSC修改配置结束超时定时器, zgc, 2007-06-23
OSPEVENT( MCUCFG_DSCCFG_WAITINGCHANGE_OVER_TIMER,	EV_MCU_BGN + 352 );
//会控会话通知mcucfg断链消息, zgc, 2007-11-09
//消息体：无
OSPEVENT( MCSSSN_MCUCFG_MCSDISSCONNNECT_NOTIFY,		EV_MCU_BGN + 353 );

// [11/14/2011 liuxu]缓冲发送AllMtInfoToAllMcs的timer
OSPEVENT( MCUVC_SENDALLMT_ALLMCS_TIMER,	        EV_MCU_BGN + 354 );

// [11/14/2011 liuxu]缓冲发送AllMtInfoToAllMcs的timer
OSPEVENT( MCUVC_SEND_SMCUMTSTATUS_TIMER,	    EV_MCU_BGN + 355 );


OSPEVENT( MCUVC_REG_MTMGR_TIMER,				EV_MCU_BGN + 356 );		//Mcu 创会申请终端管理资源定时

OSPEVENT( MCUVC_CHAIRPOLLING_CHANGE_TIMER,      EV_MCU_BGN + 357 );			//主席轮询改变时钟

OSPEVENT( MCUVC_MMCUSPYPOLLING_CHANGE_TIMER,    EV_MCU_BGN + 358 );			//上传轮询改变时钟

//MCU给外设发FASTUPDATE的定时器组 留48个空间 _(+360 ～+408)
//不考虑HDU、Tvwall、Recorder、Mixer、Prs，只考虑bas/hdbas，vmp/hdvmp，vmptw，暂不区分其通道ID
OSPEVENT( MCUVC_FASTUPDATE_TIMER_ARRAY4EQP,     EV_MCU_BGN + 360 );


/*
*	Special For Satellate MCU
*/
OSPEVENT( MCU_MULTICAST_MSG,				    EV_MCU_BGN + 410 );

OSPEVENT( MCU_MULTICAST_CONFLIST,				EV_MCU_BGN + 411 );

/////////////////////////////////////////////////////////////////////////
//mcu内部消息
//电视墙多通道轮询定时器(包括所有dec5, hdu)预留80个空间(412 ~ 491)
OSPEVENT(MCUVC_TWPOLLING_CHANGE_TIMER ,		    EV_MCU_BGN + 412 );

//////////////////////////////////////////////////////////////////////////
//  mcuhdu内部消息
//
//  通知hdu开始交换码流
//  消息体  THduSwitchInfo
OSPEVENT( MCUVC_STARTSWITCHHDU_NOTIFY,		  EV_MCU_BGN + 492 );
 
///////////////////////////////////////////////////////////
// mcuvcs内部消息
// 上级MCU释放对下级调度会议控制的权限      消息体:无(消息头中含有指定会议的CONFID)
OSPEVENT( MCUVC_VCSSN_MMCURLSCTRL_CMD,	 EV_MCU_BGN + 493 );
// 上级MCU开始接管对会议的调度权限          消息体:无
OSPEVENT( MCUVC_MMCUGETCTRL_CMD,             EV_MCU_BGN + 494 );

///////////////////////////////////////////////////////////
// 媒体资源回调定时器
// 视频新资源上报定时检测timer
OSPEVENT( MCUVC_VIDRES_SAFETIMER,	EV_MCU_BGN + 495 );
// 音频新资源上报定时检测timer
OSPEVENT( MCUVC_AUDRES_SAFETIMER,	EV_MCU_BGN + 496 );

///////////////////////////////////////////////////////////
//主备位板MCU之间的主备倒换的通讯消息

//主备倒换监守模块启动消息
OSPEVENT( MCU_MSEXCHANGER_POWERON_CMD,	EV_MCU_BGN + 500 );

//备位板MCU向主位板MCU 的连接定时器
OSPEVENT( MCU_MCU_CONNECT_TIMER,		EV_MCU_BGN + 501 );
//备位板MCU向主位板MCU 的注册定时器
OSPEVENT( MCU_MCU_REGISTER_TIMER,		EV_MCU_BGN + 502 );

//vxworks下检测主备用状态的定时器
OSPEVENT( MCU_MCU_CEHCK_MSSTATE_TIMER,	EV_MCU_BGN + 503 );

//主用板MCU向备用板MCU 的数据倒换定时器
OSPEVENT( MCU_MCU_SYN_TIMER,		    EV_MCU_BGN + 504 );

//MCU之间 等待对端的请求应答 的超时定时器
OSPEVENT( MCU_MCU_WAITFORRSP_TIMER,	    EV_MCU_BGN + 505 );

//主MCU向备mcu发重启命令
OSPEVENT( MCU_MCU_REBOOT_CMD,	        EV_MCU_BGN + 506 );
//主MCU向备mcu发升级重启命令
OSPEVENT( MCU_MCU_UPDATE_CMD,	        EV_MCU_BGN + 509 );

//mcuagt向备mcu发送重启备份mcu的命令
OSPEVENT( MCUAGT_MCU_REBOOT_CMD,	    EV_MCU_BGN + 507 );

//MCU之间 ROUNDTRIP链路检测 的超时定时器
OSPEVENT( MCU_MCU_ROUNDTRIP_TIMER,	    EV_MCU_BGN + 508 );

//备位板MCU向主位板MCU 的注册请求 消息体: u32 dwLocalIp
OSPEVENT( MCU_MCU_REGISTER_REQ,			EV_MCU_BGN + 511 );
//备位板MCU向主位板MCU 的注册请求接受
OSPEVENT( MCU_MCU_REGISTER_ACK,			EV_MCU_BGN + 512 );
//备位板MCU向主位板MCU 的注册请求拒绝
OSPEVENT( MCU_MCU_REGISTER_NACK,		EV_MCU_BGN + 513 );

//MCU之间 通知 对方 本地MCU的主备位类型及当前的主备使用状态，进行主备用协商 消息体: u8 LocalMSType + u8 CurMSState
OSPEVENT( MCU_MCU_MS_DETERMINE,			EV_MCU_BGN + 516 );
//MCU之间 通知 对方 本地MCU的协商的主备使用结果 消息体: u8 CurMSState
OSPEVENT( MCU_MCU_MS_RESULT,			EV_MCU_BGN + 517 );

//主用板MCU向备用板MCU 请求 开始数据倒换 消息体: TMSSynInfoReq
OSPEVENT( MCU_MCU_START_SYN_REQ,		EV_MCU_BGN + 521 );
//备用板MCU向主用板MCU 接受 开始数据倒换 消息体: TMSSynInfoRsp
OSPEVENT( MCU_MCU_START_SYN_ACK,		EV_MCU_BGN + 522 );
//备位板MCU向主位板MCU 配置信息同步请求拒绝 消息体: TMSSynState
OSPEVENT( MCU_MCU_START_SYN_NACK,		EV_MCU_BGN + 523 );
//主用板MCU向备用板MCU 结束数据倒换 通知
OSPEVENT( MCU_MCU_END_SYN_NTF,			EV_MCU_BGN + 524 );

//主位板MCU向备位板MCU 实际切包组包的数据倒换 同步 请求 消息体: TMSSynDataReqHead
OSPEVENT( MCU_MCU_SYNNING_DATA_REQ,		EV_MCU_BGN + 526 );
//备位板MCU向主位板MCU 实际切包组包的数据倒换 同步 回应 消息体: TMSSynDataRsp
OSPEVENT( MCU_MCU_SYNNING_DATA_RSP,		EV_MCU_BGN + 527 );

//备用板升级为主用板时 通知业务和各个会话模块主备用状态变更，消息体: u8是否切换成功
OSPEVENT( MCU_MSSTATE_EXCHANGE_NTF,		EV_MCU_BGN + 531 );

//主备探测消息
OSPEVENT( MCU_MCU_PROBE_REQ,            EV_MCU_BGN + 532 );
OSPEVENT( MCU_MCU_PROBE_ACK,            EV_MCU_BGN + 533 );  
OSPEVENT( MCU_MCU_PROBE_NACK,            EV_MCU_BGN + 534 ); 

//备mcu向主mcu发LED灯显的notify。消息体：TBrdLedState
OSPEVENT( MCU_MCU_LEDSTATUS_NOTIFY,	    EV_MCU_BGN + 535 );

OSPEVENT( EV_MCU_OPENSECVID_TIMER,		EV_MCU_BGN + 536 );//目前只针对polycom

//画面合成单通道轮询定时器，预留30个消息号，537--566，周广程，2014-11-24
OSPEVENT( MCUVC_VMPSINGLECHNPOLL_TIMER_START, EV_MCU_BGN + 537 );
OSPEVENT( MCUVC_VMPSINGLECHNPOLL_TIMER_END,   EV_MCU_BGN + 566 );

//会议支持多vmp，vmp相关Timer需扩为16份，预留32个(608-639)
//包含MCUVC_VMP_WAITVMPRSP_TIMER与MCUVC_WAIT_ALLVMPPRESETIN_ACK_TIMER
OSPEVENT( MCUVC_VMP_WAITVMPRSP_TIMER,        EV_MCU_BGN + 608 );
OSPEVENT( MCUVC_WAIT_ALLVMPPRESETIN_ACK_TIMER,  EV_MCU_BGN + 624 );

//MCU注册NU链接定时器
OSPEVENT( MTADPSSN_CONNECTNU_TIMER,			EV_MCU_BGN + 630 );
//MCU注册NU注册定时器
OSPEVENT( MTADPSSN_REGISTNU_TIMER,			EV_MCU_BGN + 631 );

//N+1模式 MCU内部消息
OSPEVENT( NPLUS_VC_DATAUPDATE_NOTIF,        EV_MCU_BGN + 640 );
//mcu业务发给主mcu备份管理模块消息
OSPEVENT( VC_NPLUS_MSG_NOTIF,               EV_MCU_BGN + 641 );
//通知N+1备份服务器重置，停止备份服务，但不断开连接的客户端
OSPEVENT( VC_NPLUS_RESET_NOTIF,             EV_MCU_BGN + 642 );

//N+1模式 mcu间消息
//连接定时器
OSPEVENT( MCU_NPLUS_CONNECT_TIMER,          EV_MCU_BGN + 650 );

//注册定时器
OSPEVENT( MCU_NPLUS_REG_TIMER,              EV_MCU_BGN + 651 );

//链路检测超时定时器
OSPEVENT( MCU_NPLUS_RTD_TIMER,              EV_MCU_BGN + 652 );

//注册消息，消息体：TCMcuRegInfo
OSPEVENT( MCU_NPLUS_REG_REQ,                EV_MCU_BGN + 700 );
OSPEVENT( MCU_NPLUS_REG_ACK,                EV_MCU_BGN + 701 );
OSPEVENT( MCU_NPLUS_REG_NACK,               EV_MCU_BGN + 702 );

//链路检测消息，消息体：无
OSPEVENT( MCU_NPLUS_RTD_REQ,                EV_MCU_BGN + 703 );
OSPEVENT( MCU_NPLUS_RTD_RSP,                EV_MCU_BGN + 704 );

//mcu会议信息通知消息（创建/结束会议时通知），消息体：u8(NPLUS_CONF_START, NPLUS_CONF_RELEASE)+TConfInfo
OSPEVENT( MCU_NPLUS_CONFINFOUPDATE_REQ,     EV_MCU_BGN + 705 );
OSPEVENT( MCU_NPLUS_CONFINFOUPDATE_ACK,     EV_MCU_BGN + 706 );
OSPEVENT( MCU_NPLUS_CONFINFOUPDATE_NACK,    EV_MCU_BGN + 707 );

//mcu用户组信息通知消息 （注册成功和用户组信息变化时或会议回滚时通知），消息体：CUsrGrpsInfo
OSPEVENT( MCU_NPLUS_USRGRPUPDATE_REQ,         EV_MCU_BGN + 708 );
OSPEVENT( MCU_NPLUS_USRGRPUPDATE_ACK,         EV_MCU_BGN + 709 );
OSPEVENT( MCU_NPLUS_USRGRPUPDATE_NACK,        EV_MCU_BGN + 710 );

//与会终端信息通知（与会终端有变化时通知），消息体：TMtInfo[]
OSPEVENT( MCU_NPLUS_CONFMTUPDATE_REQ,       EV_MCU_BGN + 711 );
OSPEVENT( MCU_NPLUS_CONFMTUPDATE_ACK,       EV_MCU_BGN + 712 );
OSPEVENT( MCU_NPLUS_CONFMTUPDATE_NACK,      EV_MCU_BGN + 713 );

//主席终端通知，消息体：TMtAlias
OSPEVENT( MCU_NPLUS_CHAIRUPDATE_REQ,        EV_MCU_BGN + 714 );
OSPEVENT( MCU_NPLUS_CHAIRUPDATE_ACK,        EV_MCU_BGN + 715 );
OSPEVENT( MCU_NPLUS_CHAIRUPDATE_NACK,       EV_MCU_BGN + 716 );

//发言终端通知，消息体：TMtAlias
OSPEVENT( MCU_NPLUS_SPEAKERUPDATE_REQ,      EV_MCU_BGN + 717 );
OSPEVENT( MCU_NPLUS_SPEAKERUPDATE_ACK,      EV_MCU_BGN + 718 );
OSPEVENT( MCU_NPLUS_SPEAKERUPDATE_NACK,     EV_MCU_BGN + 719 );

//VMP，消息体：TNPlusVmpInfo+TVMPParam
OSPEVENT( MCU_NPLUS_VMPUPDATE_REQ,          EV_MCU_BGN + 720 );
OSPEVENT( MCU_NPLUS_VMPUPDATE_ACK,          EV_MCU_BGN + 721 );
OSPEVENT( MCU_NPLUS_VMPUPDATE_NACK,         EV_MCU_BGN + 722 );

//ConfData通知消息（注册成功时或会议回滚时通知），消息体：TNPlusConfData + N字节扩展数据+MAXNUM_SUB_MCU*TSmcuCallInfo
OSPEVENT( MCU_NPLUS_CONFDATAUPDATE_REQ,       EV_MCU_BGN + 723 );
OSPEVENT( MCU_NPLUS_CONFDATAUPDATE_ACK,       EV_MCU_BGN + 724 );
OSPEVENT( MCU_NPLUS_CONFDATAUPDATE_NACK,      EV_MCU_BGN + 725 );

//用户信息通知消息（注册成功时或会议回滚时通知），消息体：CExUsrInfo[]，需要考虑切包
OSPEVENT( MCU_NPLUS_USRINFOUPDATE_REQ,        EV_MCU_BGN + 726 );
OSPEVENT( MCU_NPLUS_USRINFOUPDATE_ACK,        EV_MCU_BGN + 727 );
OSPEVENT( MCU_NPLUS_USRINFOUPDATE_NACK,       EV_MCU_BGN + 728 );

//会议信息回滚
OSPEVENT( MCU_NPLUS_CONFROLLBACK_REQ,        EV_MCU_BGN + 729 );
OSPEVENT( MCU_NPLUS_CONFROLLBACK_ACK,        EV_MCU_BGN + 730 );
OSPEVENT( MCU_NPLUS_CONFROLLBACK_NACK,       EV_MCU_BGN + 731 );

//用户信息回滚
OSPEVENT( MCU_NPLUS_USRROLLBACK_REQ,        EV_MCU_BGN + 732 );
OSPEVENT( MCU_NPLUS_USRROLLBACK_ACK,        EV_MCU_BGN + 733 );
OSPEVENT( MCU_NPLUS_USRROLLBACK_NACK,       EV_MCU_BGN + 734 );

//用户组信息回滚
OSPEVENT( MCU_NPLUS_GRPROLLBACK_REQ,        EV_MCU_BGN + 735 );
OSPEVENT( MCU_NPLUS_GRPROLLBACK_ACK,        EV_MCU_BGN + 736 );
OSPEVENT( MCU_NPLUS_GRPROLLBACK_NACK,       EV_MCU_BGN + 737 );

//GK实体注册通知消息，消息体：TRASInfo
OSPEVENT( MCU_NPLUS_RASINFOUPDATE_REQ,      EV_MCU_BGN + 738 );
OSPEVENT( MCU_NPLUS_RASINFOUPDATE_ACK,      EV_MCU_BGN + 739 );
OSPEVENT( MCU_NPLUS_RASINFOUPDATE_NACK,     EV_MCU_BGN + 740 );

//AutoMix，消息体：BOOL32
OSPEVENT( MCU_NPLUS_AUTOMIXUPDATE_REQ,          EV_MCU_BGN + 741 );
OSPEVENT( MCU_NPLUS_AUTOMIXUPDATE_ACK,          EV_MCU_BGN + 742 );
OSPEVENT( MCU_NPLUS_AUTOMIXUPDATE_NACK,         EV_MCU_BGN + 743 );

//同步下级MCU呼叫信息 消息体：TSmcuCallInfo[]数组
OSPEVENT( MCU_NPLUS_SMCUINFOUPDATE_REQ,         EV_MCU_BGN + 744 );
OSPEVENT( MCU_NPLUS_SMCUINFOUPDATE_ACK,			EV_MCU_BGN + 745 );
OSPEVENT( MCU_NPLUS_SMCUINFOUPDATE_NACK,		EV_MCU_BGN + 746 );

//外设基本能力通知，消息体：TNPlusEqpCap
OSPEVENT( MCU_NPLUS_EQPCAP_NOTIF,           EV_MCU_BGN + 750 );

//MCU接收VCS发送的分组信息定时器 留MAXNUM_MCU_CONF+MAXNUM_MCU_TEMPLATE(128个 +800 -- +927)
OSPEVENT( MCUVC_PACKINFO_TIMER,             EV_MCU_BGN + 800);

// [1/7/2011 xliang] 短消息分批发送定时
OSPEVENT( MCUVC_SMSPACK_TIMER,				EV_MCU_BGN + 950);

// [pengjie 2011/5/18]消息951~953在其它流上已经被占用，考虑到功能合并等问题，这里将其预留

// [pengjie 2011/5/19] 有vcsssn普通instan发给daemon的开启定时命令，消息体为 u8 byTimeIdx 定时器Id
OSPEVENT( MCUVC_STARTRELEASECONFTIMER_CMD,			EV_MCU_BGN + 954);
// [pengjie 2011/5/18] vcs断链延迟结会定时器，需要占用16个timer( 955 ~ 971 )
OSPEVENT( MCUVC_RELEASECONF_TIMER,			EV_MCU_BGN + 955);

// END (EV_MCU_BGN + 971)
//终端请求H239token等待开双流通道定时器
OSPEVENT( MCUVC_WAITOPENDSCHAN_TIMER,           EV_MCU_BGN + 972 );
//调整画面合成成员如果改变的所有的成员都为下级终端（级联多回传），扩到16个
//OSPEVENT( MCUVC_WAIT_ALLVMPPRESETIN_ACK_TIMER,			    EV_MCU_BGN + 973 );
//主备环境，主板重启后需要恢复会议后，需要给备板同步数据
OSPEVENT( MCUVC_RECOVERCONF_SYN_TIMER,           EV_MCU_BGN + 974 );
//多回传，点名与被点名人模式下，点下级终端的时候需要等待下级终端会ack才认为可以点下个终端
OSPEVENT( MCUVC_WAIT_LASTVMPROLLCALLFINISH_TIMER,           EV_MCU_BGN + 975 );
//主备备份会议数据的时候，给instance设置（ongoing或schedule）状态后，起等待会议数据timer
OSPEVENT( MCUVC_WAITMSCONFDATA_TIMER,           EV_MCU_BGN + 976 );

//zyq50
OSPEVENT( MCUVC_OCCUPYMP_CMD, EV_MCU_BGN + 977  );
OSPEVENT( MCUVC_APPLYMPSUC_NTF, EV_MCU_BGN + 978  );
OSPEVENT( MCUVC_MPDISCONNECT_NTF, EV_MCU_BGN + 979  );

//mcu上资源池定时器
OSPEVENT( MCURESPOOL_CONNZK_TIMER, EV_MCU_BGN + 980  );

//自动结会定时器
//无终端自动结会定时器-1min
OSPEVENT( MCUVC_RELEASECONFNOMT_TIMER,          EV_MCU_BGN + 981 );
//无在线终端自动结会定时器-5min
OSPEVENT( MCUVC_RELEASECONFNOJOINEDMT_TIMER,    EV_MCU_BGN + 982 );
//在线终端仅一个，自动结会定时器-10min
OSPEVENT( MCUVC_RELEASECONFONLYONEMT_TIMER,     EV_MCU_BGN + 983 );

OSPEVENT( MCURESPOOL_UPDATEZKSTATUS_TIMER,		EV_MCU_BGN + 984  );

//多回传队列释放超时的队列timer
OSPEVENT( MCUVC_RELEASETIMEOUTSPY_TIMER,		EV_MCU_BGN + 985 );
///////////////////////////////////////////////////////////

/********** wy[2014/09/22]解析MAU与MCU交互信令(29001-29900)---复用终端内部业务消息 bgn *******/

//MAU向MCU连接请求
OSPEVENT( MAU_MCU_CONNECT_REQ,                  EV_MCU_BGN + 1000 );
OSPEVENT( MCU_MAU_CONNECT_ACK,                  EV_MCU_BGN + 1001 );
OSPEVENT( MCU_MAU_CONNECT_NACK,                 EV_MCU_BGN + 1002 );

// 创会信令
//消息体: TReqHeadInfo+TConfInfo + 2 byte(网络序,TMtAlias数组打包长度,即下面的n)
//                  + n byte(TMtAlias数组打包,每包为 1byte(类型)+1byte(长度)+xbyte(字符串)+2byte(呼叫码率) 
//                            第1字节为TMtAlias类型,第2字节为长度x,下面的x字节为TMtAlias内容)
//                  + TTvWallModule(可选字段，由会议属性中的是否有电视墙模板决定) 
//                  + TVmpModule(可选字段，由会议属性中的是否有画面合成墙模板决定)  
//					+ TPollModule
//					+ TMixModule 
//                  + 2 byte(主机序,即下面的n)
//                  + n*TMTAlias
OSPEVENT( MAU_MCU_CREATECONF_REQ,               EV_MCU_BGN + 1003 );
OSPEVENT( MCU_MAU_CREATECONF_ACK,               EV_MCU_BGN + 1004 );
OSPEVENT( MCU_MAU_CREATECONF_NACK,              EV_MCU_BGN + 1005 );

//MAU请求MCU添加终端，消息体: TReqHeadInfo+TMcu+byAddMtNum(u8)+TAddMtInfo
OSPEVENT( MAU_MCU_ADDMT_REQ,				    EV_MCU_BGN + 1006 );
OSPEVENT( MCU_MAU_ADDMT_ACK,				    EV_MCU_BGN + 1007 );
OSPEVENT( MCU_MAU_ADDMT_NACK,				    EV_MCU_BGN + 1008 );

//CM请求MCU添加终端，消息体: TReqHeadInfo+TMcu+byAddMtNum(u8)+TAddMtInfo*byAddMtNum
OSPEVENT( CM_MCU_ADDMT_REQ,				        EV_MCU_BGN + 1009 );
OSPEVENT( MCU_CM_ADDMT_ACK,				        EV_MCU_BGN + 1010 );
OSPEVENT( MCU_CM_ADDMT_NACK,				    EV_MCU_BGN + 1011 );

//CM请求MCU删除终端，消息体: TReqHeadInfo+wMtNum(u16)+TMt*wMtNum
OSPEVENT( CM_MCU_DELMT_REQ,                     EV_MCU_BGN + 1012 );
OSPEVENT( MCU_CM_DELMT_ACK,                     EV_MCU_BGN + 1013 );
OSPEVENT( MCU_CM_DELMT_NACK,                    EV_MCU_BGN + 1014 );

//CM请求MCU呼叫终端，消息体: TReqHeadInfo+wMtNum(u16)+TMt*wMtNum
OSPEVENT( CM_MCU_CALLMT_REQ,				    EV_MCU_BGN + 1015 );
OSPEVENT( MCU_CM_CALLMT_ACK,				    EV_MCU_BGN + 1016 );
OSPEVENT( MCU_CM_CALLMT_NACK,				    EV_MCU_BGN + 1017 );

//CM请求MCU挂断终端，消息体: TReqHeadInfo+wMtNum(u16)+TMt*wMtNum
OSPEVENT( CM_MCU_DROPMT_REQ,				    EV_MCU_BGN + 1018 );
OSPEVENT( MCU_CM_DROPMT_ACK,				    EV_MCU_BGN + 1019 );
OSPEVENT( MCU_CM_DROPMT_NACK,				    EV_MCU_BGN + 1020 );

//MAU命令MCU结束会议，消息体: TReqHeadInfo
OSPEVENT( MAU_MCU_RELEASECONF_CMD,			    EV_MCU_BGN + 1021 );

//MCU会议结束通知
OSPEVENT( MCU_MAU_RELEASECONF_NTF,			    EV_MCU_BGN + 1022 );

//终端列表通知
//消息体：u8*16(会议e164)+u8*64(会议名称)+u8(终端数量)+[ TJsonMtIdentify+TJsonMtDesc+u16(CallBitrate, 网络序)+u8(IsOnline)+
//		  u32(主视频发送通道数量，网络序)+[TMtMgrVidSndChnStatus]+
//		  u32(主视频接收通道数量，网络序)+[TMtMgrVidRcvChnStatus]+
//		  u32(双流视频发送通道数量，网络序)+[TMtMgrDVidSndChnStatus]+
//		  u32(双流视频接收通道数量，网络序)+[TMtMgrDVidRcvChnStatus]+
//		  u32(音频发送通道数量，网络序)+[TMtMgrAudSndChnStatus+u8(是否哑音)]+
//		  u32(音频接收通道数量，网络序)+[TMtMgrAudRcvChnStatus+u8(是否静音)] 
//        ]
OSPEVENT( MCU_CM_MTLIST_NTF,                    EV_MCU_BGN + 1023 );

//会场哑音，消息体: TReqHeadInfo+启停标示(u8：1-设置 0-取消)+静/哑音标示(u8：1-静音 0-哑音)
OSPEVENT( CM_MCU_CONFMUTE_REQ,                  EV_MCU_BGN + 1024 );
OSPEVENT( MCU_CM_CONFMUTE_ACK,                  EV_MCU_BGN + 1025 );
OSPEVENT( MCU_CM_CONFMUTE_NACK,                 EV_MCU_BGN + 1026 );

//会场静音，消息体: TReqHeadInfo+启停标示(u8：1-设置 0-取消)+静/哑音标示(u8：1-静音 0-哑音)
OSPEVENT( CM_MCU_CONFSILENCE_REQ,               EV_MCU_BGN + 1027 );
OSPEVENT( MCU_CM_CONFSILENCE_ACK,               EV_MCU_BGN + 1028 );
OSPEVENT( MCU_CM_CONFSILENCE_NACK,              EV_MCU_BGN + 1029 );

//取消会场哑音，消息体: TReqHeadInfo+启停标示(u8：1-设置 0-取消)+静/哑音标示(u8：1-静音 0-哑音)
OSPEVENT( CM_MCU_CANCELCONFMUTE_REQ,            EV_MCU_BGN + 1030 );
OSPEVENT( MCU_CM_CANCELCONFMUTE_ACK,            EV_MCU_BGN + 1031 );
OSPEVENT( MCU_CM_CANCELCONFMUTE_NACK,           EV_MCU_BGN + 1032 );

//取消会场静音，消息体: TReqHeadInfo+启停标示(u8：1-设置 0-取消)+静/哑音标示(u8：1-静音 0-哑音)
OSPEVENT( CM_MCU_CANCELCONFSILENCE_REQ,         EV_MCU_BGN + 1033 );
OSPEVENT( MCU_CM_CANCELCONFSILENCE_ACK,         EV_MCU_BGN + 1034 );
OSPEVENT( MCU_CM_CANCELCONFSILENCE_NACK,        EV_MCU_BGN + 1035);

// 延长会议，消息体: TReqHeadInfo+wDelay(u16)
OSPEVENT( CM_MCU_DELAYCONF_REQ,                 EV_MCU_BGN + 1036 );
OSPEVENT( MCU_CM_DELAYCONF_ACK,                 EV_MCU_BGN + 1037 );
OSPEVENT( MCU_CM_DELAYCONF_NACK,                EV_MCU_BGN + 1038 );

// 开始轮询，消息体: TPollInfo+TMtPollParam*wMtNum(u16)
OSPEVENT( CM_MCU_STARTPOLL_CMD,                 EV_MCU_BGN + 1039 );

// 停止轮询
OSPEVENT( CM_MCU_STOPPOLL_CMD,                  EV_MCU_BGN + 1040 );

// 暂停轮询
OSPEVENT( CM_MCU_PAUSEPOLL_CMD,                 EV_MCU_BGN + 1041 );

// 继续轮询
OSPEVENT( CM_MCU_RESUMEPOLL_CMD,                EV_MCU_BGN + 1042 );

// 指定轮询位置，消息体: TReqHeadInfo+TMt
OSPEVENT( CM_MCU_SPECPOLLPOS_REQ,               EV_MCU_BGN + 1043 );
OSPEVENT( MCU_CM_SPECPOLLPOS_ACK,               EV_MCU_BGN + 1044 );
OSPEVENT( MCU_CM_SPECPOLLPOS_NACK,              EV_MCU_BGN + 1045 );

// 修改轮询参数，消息体: TPollInfo+TMtPollParam*wMtNum(u16)
OSPEVENT( CM_CMU_CHANGEPOLLPARAM_CMD,           EV_MCU_BGN + 1046);

// 设置终端静音，消息体: TReqHeadInfo+TMt+启停标示(u8：1-设置 0-取消)+静/哑音标示(u8：1-静音 0-哑音)
OSPEVENT( CM_MCU_MTSILENCE_REQ,                 EV_MCU_BGN + 1047 );
OSPEVENT( MCU_CM_MTSILENCE_ACK,                 EV_MCU_BGN + 1048 );
OSPEVENT( MCU_CM_MTSILENCE_NACK,                EV_MCU_BGN + 1049 );

// 取消终端静音，消息体: TReqHeadInfo+TMt+启停标示(u8：1-设置 0-取消)+静/哑音标示(u8：1-静音 0-哑音)
OSPEVENT( CM_MCU_CANCELMTSILENCE_REQ,           EV_MCU_BGN + 1050 );
OSPEVENT( MCU_CM_CANCELMTSILENCE_ACK,           EV_MCU_BGN + 1051 );
OSPEVENT( MCU_CM_CANCELMTSILENCE_NACK,          EV_MCU_BGN + 1052 );

// 设置终端哑音，消息体: TReqHeadInfo+TMt+启停标示(u8：1-设置 0-取消)+静/哑音标示(u8：1-静音 0-哑音)
OSPEVENT( CM_MCU_MTMUTE_REQ,                    EV_MCU_BGN + 1053 );
OSPEVENT( MCU_CM_MTMUTE_ACK,                    EV_MCU_BGN + 1054 );
OSPEVENT( MCU_CM_MTMUTE_NACK,                   EV_MCU_BGN + 1055 );

// 取消终端哑音，消息体: TReqHeadInfo+TMt+启停标示(u8：1-设置 0-取消)+静/哑音标示(u8：1-静音 0-哑音)
OSPEVENT( CM_MCU_CANCELMTMUTE_REQ,              EV_MCU_BGN + 1056 );
OSPEVENT( MCU_CM_CANCELMTMUTE_ACK,              EV_MCU_BGN + 1057 );
OSPEVENT( MCU_CM_CANCELMTMUTE_NACK,             EV_MCU_BGN + 1058 );

// 设置会议安全，消息体: TReqHeadInfo+ConfPwd(len:32)+OpenMode(u8)
OSPEVENT( CM_MCU_SETCONFSAFE_REQ,               EV_MCU_BGN + 1059 );
OSPEVENT( MCU_CM_SETCONFSAFE_ACK,               EV_MCU_BGN + 1060 );
OSPEVENT( MCU_CM_SETCONFSAFE_NACK,              EV_MCU_BGN + 1061 );

// 设置主席，消息体: TReqHeadInfo+TMt
OSPEVENT( CM_MCU_SETCHAIRMAN_REQ,               EV_MCU_BGN + 1062 );
OSPEVENT( MCU_CM_SETCHAIRMAN_ACK,               EV_MCU_BGN + 1063 );
OSPEVENT( MCU_CM_SETCHAIRMAN_NACK,              EV_MCU_BGN + 1064 );

// 取消主席，消息体: TReqHeadInfo
OSPEVENT( CM_MCU_CANCELCHAIRMAN_REQ,            EV_MCU_BGN + 1065 );
OSPEVENT( MCU_CM_CANCELCHAIRMAN_ACK,            EV_MCU_BGN + 1066 );
OSPEVENT( MCU_CM_CANCELCHAIRMAN_NACK,           EV_MCU_BGN + 1067 );

// 设置发言人，消息体: TReqHeadInfo+TMt
OSPEVENT( CM_MCU_SETSPEAKER_REQ,                EV_MCU_BGN + 1068 );
OSPEVENT( MCU_CM_SETSPEAKER_ACK,                EV_MCU_BGN + 1069 );
OSPEVENT( MCU_CM_SETSPEAKER_NACK,               EV_MCU_BGN + 1070 );

// 取消发言人，消息体: TReqHeadInfo
OSPEVENT( CM_MCU_CANCELSPEAKER_REQ,             EV_MCU_BGN + 1071 );
OSPEVENT( MCU_CM_CANCELSPEAKER_ACK,             EV_MCU_BGN + 1072 );
OSPEVENT( MCU_CM_CANCELSPEAKER_NACK,            EV_MCU_BGN + 1073 );

// 设置强制广播，消息体: TReqHeadInfo+byForceBrd(u8)
OSPEVENT( CM_MCU_FORCEBRD_CMD,                  EV_MCU_BGN + 1074 );
// 强制广播通知，消息体：byForceBrd(u8)
OSPEVENT( MCU_CM_FORCEBRD_NTF,					EV_MCU_BGN + 1075 );

// 终端选看，消息体: TReqHeadInfo+TSwitchInfo
OSPEVENT( CM_MCU_STARTSEEMT_REQ,                EV_MCU_BGN + 1077 );
OSPEVENT( MCU_CM_STARTSEEMT_ACK,                EV_MCU_BGN + 1078 );
OSPEVENT( MCU_CM_STARTSEEMT_NACK,               EV_MCU_BGN + 1079 );

// 停止终端选看，消息体: TReqHeadInfo+TSwitchInfo
OSPEVENT( CM_MCU_STOPSEEMT_REQ,                 EV_MCU_BGN + 1080 );
OSPEVENT( MCU_CM_STOPSEEMT_ACK,                 EV_MCU_BGN + 1081 );
OSPEVENT( MCU_CM_STOPSEEMT_NACK,                EV_MCU_BGN + 1082 );

// 呼叫全部离线终端，消息体: TReqHeadInfo+wMtNum(u16) 向VC发送CM_MCU_CALLLEFTMT_REQ，wMtNum为0
OSPEVENT( CM_MCU_CALLLEFTMT_REQ,                EV_MCU_BGN + 1083 );
OSPEVENT( MCU_CM_CALLLEFTMT_ACK,                EV_MCU_BGN + 1084 );
OSPEVENT( MCU_CM_CALLLEFTMT_NACK,               EV_MCU_BGN + 1085 );


//会议完整信息通知
OSPEVENT( MCU_CM_CONFINFO_NOTIF,                EV_MCU_BGN + 1086 );

//与MAU保活定制器
OSPEVENT( MAUSSN_HEADBEAR_TIMER,                EV_MCU_BGN + 1087 );

//MAU请求会议完整信息，消息体: TReqHeadInfo
OSPEVENT( MAU_MCU_CONFINFO_REQ,                 EV_MCU_BGN + 1088 );
OSPEVENT( MCU_MAU_CONFINFO_ACK,                 EV_MCU_BGN + 1089 );
OSPEVENT( MCU_MAU_CONFINFO_NACK,                EV_MCU_BGN + 1090 );

//轮询参数通知
OSPEVENT( MCU_CM_POLLPARAM_NTF,                 EV_MCU_BGN + 1091 );

//会议安全信息通知
OSPEVENT( MCU_CM_CONFSAGEINFO_NTF,              EV_MCU_BGN + 1092 );

//会议持续时间通知
OSPEVENT( MCU_CM_CONFDURATION_NTF,              EV_MCU_BGN + 1093 );

//终端申请成为发言人通知
OSPEVENT( MCU_CM_APPLYSPEAKER_NTF,				EV_MCU_BGN + 1094 );

//终端申请成为主席通知
OSPEVENT( MCU_CM_APPLYCHAIRMAN_NTF,				EV_MCU_BGN + 1095 );

//终端离会通知
OSPEVENT( MCU_CM_DELMT_NTF,						EV_MCU_BGN + 1096 );

//延长会议请求(终端或会控)
OSPEVENT( MCU_MAU_DELAYCONF_REQ,				EV_MCU_BGN + 1097 );
OSPEVENT( MAU_MCU_DELAYCONF_ACK,				EV_MCU_BGN + 1098 );
OSPEVENT( MAU_MCU_DELAYCONF_NACK,				EV_MCU_BGN + 1099 );

//mcu同步会议缓存信息到mau
OSPEVENT( MCU_MAU_CONFSYN_NTF,					EV_MCU_BGN + 1100 );

//CM请求会议详情cmd
OSPEVENT( CM_CMU_CONFDETAIL_CMD,				EV_MCU_BGN + 1101 );

//会议简单信息通知，注：用于通知会管，携带TBasicConfInfo，后续复用此消息，需自定义结构体XStruct，buf:TBasicConfInfo+XStruct
OSPEVENT( MCU_CM_SIMCONFINFO_NTF,               EV_MCU_BGN + 1102 );

//CM请求开启画面合成，消息体：TReqHeadInfo+TVMPParam+u8+[TVmpChnPollParam...]
OSPEVENT( CM_MCU_STARTVMP_REQ,				    EV_MCU_BGN + 1103 );
//CM开启画面合成成功回应，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_STARTVMP_ACK,				    EV_MCU_BGN + 1104 );
//CM开启画面合成失败回应，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_STARTVMP_NACK,				    EV_MCU_BGN + 1105 );

//CM请求停止画面合成，消息体：TReqHeadInfo
OSPEVENT( CM_MCU_STOPVMP_REQ,				    EV_MCU_BGN + 1106 );
//CM停止画面合成成功回应，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_STOPVMP_ACK,				    EV_MCU_BGN + 1107 );
//CM停止画面合成失败回应，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_STOPVMP_NACK,				    EV_MCU_BGN + 1108 );

//CM请求修改画面合成参数，消息体：TVMPParam+u8+[TVmpChnPollParam...]
OSPEVENT( CM_MCU_CHANGEVMPPARAM_REQ,			EV_MCU_BGN + 1109 );
//CM修改画面合成成功回应，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_CHANGEVMPPARAM_ACK,			EV_MCU_BGN + 1110 );
//CM修改画面合成失败回应，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_CHANGEVMPPARAM_NACK,			EV_MCU_BGN + 1111 );

//画面合成参数通知，消息体：TJsonVMPParam
OSPEVENT( MCU_CM_VMPPARAM_NTF,                  EV_MCU_BGN + 1112 );

//CM请求开启终端自主画面合成
//消息体：TMtIdentifyToCM(目标终端)+MtChnId+TVMPParam (VmpMode为CONF_VMPMODE_AUTO时才需要填写)
OSPEVENT( CM_MCU_STARTMTVMP_REQ,				    EV_MCU_BGN + 1113 );
//CM开启画面合成成功回应，消息体：TMtIdentifyToCM(目标终端)
OSPEVENT( MCU_CM_STARTMTVMP_ACK,				    EV_MCU_BGN + 1114 );
//CM开启画面合成失败回应，消息体：TMtIdentifyToCM(目标终端)
OSPEVENT( MCU_CM_STARTMTVMP_NACK,				    EV_MCU_BGN + 1115 );

//CM请求停止终端自主画面合成，消息体：TMtIdentifyToCM(目标终端)
OSPEVENT( CM_MCU_STOPMTVMP_REQ,				    EV_MCU_BGN + 1116 );
//CM停止画面合成成功回应，消息体：TMt(目标终端)
OSPEVENT( MCU_CM_STOPMTVMP_ACK,				    EV_MCU_BGN + 1117 );
//CM停止画面合成失败回应，消息体：TMt(目标终端)
OSPEVENT( MCU_CM_STOPMTVMP_NACK,				    EV_MCU_BGN + 1118 );

//CM请求修改终端自主画面合成参数
//消息体：TMtIdentifyToCM(目标终端)0+u8 MtChn +TVMPParam (VmpMode为CONF_VMPMODE_AUTO时才需要填写)
OSPEVENT( CM_MCU_CHANGEMTVMPPARAM_REQ,				    EV_MCU_BGN + 1119 );
//CM开启画面合成成功回应，消息体：TMtIdentifyToCM(目标终端)
OSPEVENT( MCU_CM_CHANGEMTVMPPARAM_ACK,				    EV_MCU_BGN + 1120 );
//CM开启画面合成失败回应，消息体：TMtIdentifyToCM(目标终端)
OSPEVENT( MCU_CM_CHANGEMTVMPPARAM_NACK,				    EV_MCU_BGN + 1121 );

//终端自主合成参数通知，消息体：TMtIdentifyToCM(目标终端)+u8 MtChn+TVMPParamToCM
OSPEVENT( MCU_CM_MTVMPPARAM_NTF,						EV_MCU_BGN + 1122 );

// Vip列表消息 add by mxm
// 设置Vip列表	消息体：TReqHeadInfo+TMt*n
OSPEVENT( CM_MCU_SETVIPLIST_REQ,				EV_MCU_BGN + 1123 );
OSPEVENT( MCU_CM_SETVIPLIST_ACK,				EV_MCU_BGN + 1124 );
OSPEVENT( MCU_CM_SETVIPLIST_NACK,				EV_MCU_BGN + 1125 );
//Vip列表通知	消息体：TMt*n
OSPEVENT( MCU_CM_VIPLIST_NTF,					EV_MCU_BGN + 1126 );

// 获取Vip列表
OSPEVENT( CM_MCU_GETVIPLIST_REQ,			    EV_MCU_BGN + 1127 );
//消息体：TMt*n
OSPEVENT( MCU_CM_GETVIPLIST_ACK,				EV_MCU_BGN + 1128 );
OSPEVENT( MCU_CM_GETVIPLIST_NACK,				EV_MCU_BGN + 1129 );

// 开启混音
OSPEVENT( CM_MCU_STARTMIX_REQ,                  EV_MCU_BGN + 1130 );
OSPEVENT( MCU_CM_STARTMIX_ACK,                  EV_MCU_BGN + 1131 );
OSPEVENT( MCU_CM_STARTMIX_NACK,                 EV_MCU_BGN + 1132 );
OSPEVENT( MCU_CM_MIXPARAM_NTF,                  EV_MCU_BGN + 1133 ) ;

// 结束混音
OSPEVENT( CM_MCU_STOPMIX_REQ,                   EV_MCU_BGN + 1134 );
OSPEVENT( MCU_CM_STOPMIX_ACK,                   EV_MCU_BGN + 1135 );
OSPEVENT( MCU_CM_STOPMIX_NACK,                  EV_MCU_BGN + 1136 );

// 开启语音激励
OSPEVENT( CM_MCU_STARTVAC_REQ,					EV_MCU_BGN + 1137 );
OSPEVENT( MCU_CM_STARTVAC_ACK,					EV_MCU_BGN + 1138 );
OSPEVENT( MCU_CM_STARTVAC_NACK,					EV_MCU_BGN + 1139 );

// 结束语音激励
OSPEVENT( CM_MCU_STOPVAC_REQ,                   EV_MCU_BGN + 1140 );
OSPEVENT( MCU_CM_STOPVAC_ACK,                   EV_MCU_BGN + 1141 );
OSPEVENT( MCU_CM_STOPVAC_NACK,                  EV_MCU_BGN + 1142 );

// 添加混音成员CMD
OSPEVENT( CM_MCU_ADDMIXMEMBER_CMD,              EV_MCU_BGN + 1143 );
// 删除混音成员CMD
OSPEVENT( CM_MCU_REMOVEMIXMEMBER_CMD,           EV_MCU_BGN + 1144 );

// 开启点名  (EV_MCU_BGN + 1132 预留给后续可能添加的点名NTF)
// 开启点名，消息体：TReqHeadInfo+u8(点名mode)+TMt(点名人)+TMt(被点名人)
OSPEVENT( CM_MCU_STARTROLLCALL_REQ,             EV_MCU_BGN + 1145 );
// 开启点名成功，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_STARTROLLCALL_ACK,             EV_MCU_BGN + 1146 );
// 开启点名失败，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_STARTROLLCALL_NACK,            EV_MCU_BGN + 1147 );

// 点名模式及mt通知
OSPEVENT( MCU_CM_ROLLCALL_NTF,					EV_MCU_BGN + 1148 );

// 关闭点名，消息体：无
OSPEVENT( CM_MCU_STOPROLLCALL_REQ,              EV_MCU_BGN + 1149 );
// 关闭点名成功，消息体：无
OSPEVENT( MCU_CM_STOPROLLCALL_ACK,              EV_MCU_BGN + 1150 );
// 关闭点名失败，消息体：无
OSPEVENT( MCU_CM_STOPROLLCALL_NACK,             EV_MCU_BGN + 1151 );

// 修改点名参数，消息体：TReqHeadInfo+TMt(点名人)+TMt(被点名人)
OSPEVENT( CM_MCU_CHANGEROLLCALL_REQ,            EV_MCU_BGN + 1152 );
// 修改点名参数成功，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_CHANGEROLLCALL_ACK,            EV_MCU_BGN + 1153 );
// 修改点名参数失败，消息体：TReqHeadInfo
OSPEVENT( MCU_CM_CHANGEROLLCALL_NACK,           EV_MCU_BGN + 1154 );

// MAU向MCU下发BMC入网的终端信息
OSPEVENT( MAU_MCU_MTLIST_NTF,                   EV_MCU_BGN + 1155 );

// MAU向MCU下发BMC入网的域信息
OSPEVENT( MAU_MCU_DOMAINLIST_NTF,               EV_MCU_BGN + 1156 );

//画面合成单通道轮询时某一轮询通道参数通知
//消息体：u8(参数数量)+[TVmpChnPollParam...]
OSPEVENT( MCU_CM_VMPCHNPOLLPARAM_NTF,           EV_MCU_BGN + 1157 );

// 开启电视墙单通道选看	消息体：TReqHeadInfo+u8(风格)+u8(成员个数)+THduSwitchInfo(数组，个数为前一个u8)
OSPEVENT( CM_CMU_STARTHDUSWITCH_REQ,			EV_MCU_BGN + 1158 );
// 开启电视墙单通道选看成功	消息体：TReqHeadInfo	
OSPEVENT( CMU_CM_STARTHDUSWITCH_ACK,			EV_MCU_BGN + 1159 );
// 开启电视墙单通道选看失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STARTHDUSWITCH_NACK,			EV_MCU_BGN + 1160 );

// 停止电视墙单通道选看	消息体：TReqHeadInfo+u8(风格)+u8(成员个数)+THduSwitchInfo(数组，个数为前一个u8)
OSPEVENT( CM_CMU_STOPHDUSWITCH_REQ,				EV_MCU_BGN + 1161 );
// 停止电视墙单通道选看成功	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUSWITCH_ACK,				EV_MCU_BGN + 1162 );
// 停止电视墙单通道选看失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUSWITCH_NACK,			EV_MCU_BGN + 1163 );

// 电视墙单通道选看通知 消息体： TMsgHduInfo
OSPEVENT( CMU_CM_HDUSWITCH_NTF,					EV_MCU_BGN + 1164 );

// 开启电视墙单通道轮询	消息体：TReqHeadInfo+TTvWallPollParam
OSPEVENT( CM_CMU_STARTHDUPOLL_CMD,				EV_MCU_BGN + 1165 );
// 停止电视墙单通道轮询	消息体：TReqHeadInfo+u8+u8
OSPEVENT( CM_CMU_STOPHDUPOLL_CMD,				EV_MCU_BGN + 1166 );
// 暂停电视墙单通道轮询	消息体：TReqHeadInfo+u8+u8
OSPEVENT( CM_CMU_PAUSETHDUPOLL_CMD,				EV_MCU_BGN + 1167 );
// 恢复电视墙单通道轮询	消息体：TReqHeadInfo+u8+u8
OSPEVENT( CM_CMU_RESUMEHDUPOLL_CMD,				EV_MCU_BGN + 1168 );
// 修改电视墙单通道轮询	消息体：TReqHeadInfo+TTvWallPollParam
OSPEVENT( CM_CMU_CHANGEHDUPOLL_CMD,				EV_MCU_BGN + 1169 );

// 电视墙单通道轮询通知 消息体： TTvWallPollParam
OSPEVENT( CMU_CM_HDUPOLL_NTF,					EV_MCU_BGN + 1170 );

// 开启电视墙自主画面合成	消息体：TReqHeadInfo+u8+u8+TVMPParam
OSPEVENT( CM_CMU_STARTHDUVMP_REQ,				EV_MCU_BGN + 1171 );
// 开启电视墙成功	消息体：TReqHeadInfo	
OSPEVENT( CMU_CM_STARTHDUVMP_ACK,				EV_MCU_BGN + 1172 );
// 开启电视墙失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STARTHDUVMP_NACK,				EV_MCU_BGN + 1173 );

// 修改电视墙自主画面合成	消息体：TReqHeadInfo+u8+u8+TVMPParam
OSPEVENT( CM_CMU_CHANGEHDUVMP_REQ,				EV_MCU_BGN + 1174 );
// 修改电视墙自主画面合成成功	消息体：TReqHeadInfo	
OSPEVENT( CMU_CM_CHANGEHDUVMP_ACK,				EV_MCU_BGN + 1175 );
// 修改电视墙自主画面合成失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_CHANGEHDUVMP_NACK,				EV_MCU_BGN + 1176 );

// 停止电视墙自主画面合成	消息体：TReqHeadInfo+u8+u8
OSPEVENT( CM_CMU_STOPHDUVMP_REQ,				EV_MCU_BGN + 1177 );
// 停止电视墙自主画面合成成功	消息体：TReqHeadInfo	
OSPEVENT( CMU_CM_STOPHDUVMP_ACK,				EV_MCU_BGN + 1178 );
// 停止电视墙自主画面合成失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUVMP_NACK,				EV_MCU_BGN + 1179 );

// 电视墙自主画面合成通知 消息体： u8+u8+TVMPParam
OSPEVENT( CMU_CM_HDUVMP_NTF,					EV_MCU_BGN + 1180 );

// 开启电视墙批量轮询	消息体：TReqHeadInfo+THduPollSchemeInfo
OSPEVENT( CM_CMU_STARTHDUBATCHPOLL_REQ,			EV_MCU_BGN + 1181 );
// 开启电视墙批量轮询成功	消息体：TReqHeadInfo	
OSPEVENT( CMU_CM_STARTHDUBATCHPOLL_ACK,			EV_MCU_BGN + 1182 );
// 开启电视墙批量轮询失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STARTHDUBATCHPOLL_NACK,		EV_MCU_BGN + 1183 );

// 停止电视墙批量轮询	消息体：TReqHeadInfo
OSPEVENT( CM_CMU_STOPHDUBATCHPOLL_REQ,			EV_MCU_BGN + 1184 );
// 停止电视墙批量轮询成功	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUBATCHPOLL_ACK,			EV_MCU_BGN + 1185 );
// 停止电视墙批量轮询失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUBATCHPOLL_NACK,			EV_MCU_BGN + 1186 );

// 暂停电视墙批量轮询	消息体：TReqHeadInfo
OSPEVENT( CM_CMU_PAUSEHDUBATCHPOLL_REQ,			EV_MCU_BGN + 1187 );
// 暂停电视墙批量轮询成功	消息体：TReqHeadInfo	
OSPEVENT( CMU_CM_PAUSEHDUBATCHPOLL_ACK,			EV_MCU_BGN + 1188 );
// 暂停电视墙批量轮询失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_PAUSEHDUBATCHPOLL_NACK,		EV_MCU_BGN + 1189 );

// 恢复电视墙批量轮询	消息体：TReqHeadInfo
OSPEVENT( CM_CMU_RESUMEHDUBATCHPOLL_REQ,		EV_MCU_BGN + 1190 );
// 恢复电视墙批量轮询成功	消息体：TReqHeadInfo	
OSPEVENT( CMU_CM_RESUMEHDUBATCHPOLL_ACK,		EV_MCU_BGN + 1191 );
// 恢复电视墙批量轮询失败	消息体：TReqHeadInfo
OSPEVENT( CMU_CM_RESUMEHDUBATCHPOLL_NACK,		EV_MCU_BGN + 1192 );

// 电视墙批量轮询通知 消息体： THduPollSchemeInfo
OSPEVENT( CMU_CM_HDUBATCHPOLL_NTF,				EV_MCU_BGN + 1193 );

// 传统会议改变电视墙通道风格（1风格和4风格互切） 消息体：TReqHeadInfo+u8+u8+u8+u8
OSPEVENT( CM_CMU_CHANGEHDUVMPMODE_CMD,			EV_MCU_BGN + 1194 );
// 传统会议改变电视墙通道风格通知	TReqHeadInfo+u8+u8+u8+u8
OSPEVENT( CMU_CM_CHANGEHDUVMPMODE_NTF,			EV_MCU_BGN + 1195 );

// 设置是否显示电视墙通道台标 消息体：TReqHeadInfo+u8+u8+u8+u8
OSPEVENT( CM_CMU_SETHDUDISPALIAS_CMD,			EV_MCU_BGN + 1196 );

// 录像相关 : 
// 开始录像 消息体:TReqHeadInfo + IsMerge(u8) + 录像名（(KDV_NAME_MAX_LENGTH + 1) * s8） + TRecStartPara + TMtAlias + u16(N) + N * TRecMt
// N = 0 会议录像  N = 1 终端录像  N > 1 合并录像
OSPEVENT( CM_CMU_STARTREC_REQ,			        EV_MCU_BGN + 1197 );
// 开始录像成功 消息体：TReqHeadInfo + 录像名（(KDV_NAME_MAX_LENGTH + 1) * s8） + TRecStartPara + TMtAlias + u16(N) + N * TRecMt
OSPEVENT( CMU_CM_STARTREC_ACK,			        EV_MCU_BGN + 1198 );
// 开始录像失败 消息体: TReqHeadInfo + 录像名（(KDV_NAME_MAX_LENGTH + 1) * s8） +　TRecStartPara + TMtAlias + u16(N) + N * TRecMt
OSPEVENT( CMU_CM_STARTREC_NACK,			        EV_MCU_BGN + 1199 );
// 暂停录像 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CM_CMU_PAUSEREC_REQ, 			        EV_MCU_BGN + 1200 );
// 暂停录像成功 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_PAUSEREC_ACK, 			        EV_MCU_BGN + 1201 );
// 暂停录像失败 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_PAUSEREC_NACK,		         	EV_MCU_BGN + 1202 );
// 恢复录像 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CM_CMU_RESUMEREC_REQ,			        EV_MCU_BGN + 1203 );
// 恢复录像成功 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_RESUMEREC_ACK,			        EV_MCU_BGN + 1204 );
// 恢复录像失败 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_RESUMEREC_NACK,			    EV_MCU_BGN + 1205 );     
// 停止录像失败 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CM_CMU_STOPREC_REQ,			        EV_MCU_BGN + 1206 );
// 停止录像失败 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_STOPREC_ACK,			        EV_MCU_BGN + 1207 );
// 停止录像失败 消息体：TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_STOPREC_NACK, 			        EV_MCU_BGN + 1208 );
// 录像进度通知 消息体：recid(u8)
OSPEVENT( CM_CMU_GETRECPROG_CMD, 			    EV_MCU_BGN + 1209 );   
// 录像进度通知 消息体：recid(u8) + TRecProg
OSPEVENT( CMU_CM_RECPROG_NTF, 			        EV_MCU_BGN + 1210 );   
// 录像进度通知 消息体：recid(u8)
OSPEVENT( CM_CMU_GETRECSTATUS_CMD,              EV_MCU_BGN + 1211 );
// 录像状态通知 消息体：TMtAlias + tCMVrsRecChnStatus
OSPEVENT( CMU_CM_RECORDRECSTATUS_NTF,			EV_MCU_BGN + 1212 ); 
// 录放像异常通知 消息体：u8(TYPE_RECOED/TYPE_PLAY) + recid(u8)
OSPEVENT( CMU_CM_RECORDEREXCEPT_NTF,			    EV_MCU_BGN + 1213 ); 

OSPEVENT( CMU_CM_HDUSWITCH_FAIL_NTF,                EV_MCU_BGN + 1214);
// 放像相关：
// 开始放像 消息体：TReqHeadInfo + TPlayEqpAttrib + TMtAlias 
OSPEVENT( CM_CMU_STARTPLAY_REQ,					EV_MCU_BGN + 1215 );
// 开始放像成功 消息体：TReqHeadInfo + TPlayEqpAttrib + TMtAlias
OSPEVENT( CMU_CM_STARTPLAY_ACK,					EV_MCU_BGN + 1216 );
// 开始放像失败 消息体：TReqHeadInfo + TPlayEqpAttrib + TMtAlias
OSPEVENT( CMU_CM_STARTPLAY_NACK,				EV_MCU_BGN + 1217 ); 
// 暂停放像 消息体：TReqHeadInfo
OSPEVENT( CM_CMU_PAUSEPLAY_REQ,					EV_MCU_BGN + 1218 );
// 暂停放像成功 消息体：TReqHeadInfo 
OSPEVENT( CMU_CM_PAUSEPLAY_ACK,					EV_MCU_BGN + 1219 );
// 暂停放像失败 消息体：TReqHeadInfo 
OSPEVENT( CMU_CM_PAUSEPLAY_NACK,				EV_MCU_BGN + 1220 );
// 恢复放像 消息体：TReqHeadInfo
OSPEVENT( CM_CMU_RESUMEPLAY_REQ,				EV_MCU_BGN + 1221 );
// 恢复放像成功 消息体：TReqHeadInfo
OSPEVENT( CMU_CM_RESUMEPLAY_ACK,				EV_MCU_BGN + 1222 );
// 恢复放像失败 消息体：TReqHeadInfo
OSPEVENT( CMU_CM_RESUMEPLAY_NACK,				EV_MCU_BGN + 1223 );
// 停止放像 消息体：TReqHeadInfo
OSPEVENT( CM_CMU_STOPPLAY_REQ,					EV_MCU_BGN + 1224 );
// 停止放像成功 消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STOPPLAY_ACK,					EV_MCU_BGN + 1225 );
// 停止放像失败 消息体：TReqHeadInfo
OSPEVENT( CMU_CM_STOPPLAY_NACK,					EV_MCU_BGN + 1226 );
// 调整放像进度 消息体：TReqHeadInfo + TRecProg
OSPEVENT( CM_CMU_SEEK_REQ,						EV_MCU_BGN + 1227 );
// 调整放像进度成功 消息体：TReqHeadInfo + TRecProg
OSPEVENT( CMU_CM_SEEK_ACK,						EV_MCU_BGN + 1228 );
// 调整放像进度失败 消息体：TReqHeadInfo + TRecProg
OSPEVENT( CMU_CM_SEEK_NACK,						EV_MCU_BGN + 1229 );
// 查询放像进度	消息体：TReqHeadInfo
OSPEVENT( CM_CMU_GETPLAYPROG_CMD,				EV_MCU_BGN + 1330 );
// 放像进度通知 消息体：TRecProg
OSPEVENT( CMU_CM_PLAYPROG_NTF,					EV_MCU_BGN + 1331 );
// 放像状态通知 消息体：TMtAlias + TVrsRecChnnlStatus
OSPEVENT( CMU_CM_PLAYORDPLAYSTATUS_NTF,			EV_MCU_BGN + 1332 );
// 查询放像机状态 消息体：TReqHeadInfo
OSPEVENT( CM_CMU_GETPLAYSTATUS_CMD,				EV_MCU_BGN + 1333 );

// 发送短消息
OSPEVENT( CM_MCU_SENDMSG_CMD,					EV_MCU_BGN + 1334 );
// 终端选看通知
// 消息体: TMtIdentifyToCM(选看目的)+u8(目的接收通道)+u8(选看模式)+u8(选看源主类型:TYPE_MT...)+u8(选看源子类型:MT_TYPE_MT...)
//         +[TMtIdentifyToCM(选看源终端)+u8(源发送通道)]
OSPEVENT( MCU_CM_MTSELECTVIEW_NTF,				EV_MCU_BGN + 1335 );


//终端申请插话通知
OSPEVENT( MCU_CM_APPLYMIX_NTF,				EV_MCU_BGN + 1336 );

//修改终端音量，消息体： TMtIdentifyToCM + u8(chnidx) + u8(codectype:1- 解码, 2 - 编码) + u8(volume)
OSPEVENT( CM_MCU_MODMTVOLUME_CMD,			EV_MCU_BGN + 1337 );
//终端音量通知，消息体： s8[7](会议E164)+TMtIdentifyToCM + u8(chnidx) + u8(codectype:1- 解码, 2 - 编码) + u8(volume)
OSPEVENT( MCU_CM_MTVOLUME_NTF,				EV_MCU_BGN + 1338 );

// 下级会议操作相关：
// 结束下级会议
OSPEVENT( CM_CMU_ENDSUBCONF_CMD,				EV_MCU_BGN + 1340 );

// 所有下级MCU列表通知
// 消息体：u8(列表是否完整：0-否，1-是)+u8(SMCU数量)+[TMtIdentifyToCM+TMtDescToCM]...
OSPEVENT( CMU_CM_ALLSMCULIST_NTF,				EV_MCU_BGN + 1342 );
// 指定某个下级会议的下级会议列表通知
// 消息体：u8(列表是否完整：0-否，1-是)+TMtIdentifyToCM(指定的下级会议)+u8(SMCU数量)+[TMtIdentifyToCM+TMtDescToCM]...
OSPEVENT( CMU_CM_SMCULISTOFSMCU_NTF,			EV_MCU_BGN + 1343 );
// 指定某个下级会议的终端列表通知
// 消息体：u8(列表是否完整：0-否，1-是)+TMtIdentifyToCM(指定的下级会议)+u8(终端数量)+[TMtIdentifyToCM+TMtDescToCM+TMcuMcuMtInfo]...
OSPEVENT( CMU_CM_MTLISTOFSMCU_NTF,				EV_MCU_BGN + 1344 );
// 增加下级会议节点
// 消息体：TMtIdentifyToCM+TMtDescToCM
OSPEVENT( CMU_CM_ADDSMCU_NTF,					EV_MCU_BGN + 1345 );
// 删除下级会议节点
// 消息体：TMtIdentifyToCM
OSPEVENT( CMU_CM_REMOVESMCU_NTF,				EV_MCU_BGN + 1346 );

//会议即将结束通知会管
OSPEVENT( MCU_CM_CONFWILLEND_NTF,				EV_MCU_BGN + 1347 );

//会议状态变更通知，通知css修改缓存信息
OSPEVENT( MCU_MAU_CONFSTATECHANGE_NTF,			EV_MCU_BGN + 1348 );

//mpc请求缩短会议运行时间，消息体:TReqHeadInfo+u16(wDelayTime)
OSPEVENT( MCU_MAU_SUBCONFDURATION_REQ,          EV_MCU_BGN + 1349 );
OSPEVENT( MAU_MCU_SUBCONFDURATION_ACK,	        EV_MCU_BGN + 1350 );
OSPEVENT( MAU_MCU_SUBCONFDURATION_NACK,	        EV_MCU_BGN + 1351 );

//会管指定上传终端
//消息体：TMtIdentifyToCM(被指定的终端)
OSPEVENT( CM_MCU_SPECSRCOFMMCU_REQ,				EV_MCU_BGN + 1352 );
//会管指定上传终端成功响应
OSPEVENT( MCU_CM_SPECSRCOFMMCU_ACK,				EV_MCU_BGN + 1353 );
//会管指定上传终端失败响应
OSPEVENT( MCU_CM_SPECSRCOFMMCU_NACK,			EV_MCU_BGN + 1354 );
//会管取消上传终端
OSPEVENT( CM_MCU_CANCELSRCOFMMCU_CMD,			EV_MCU_BGN + 1355 );
//上传终端通知: TReqHeadInfo+TMtIdentifyToCM
OSPEVENT( MCU_CM_SRCOFMMCU_NTF,					EV_MCU_BGN + 1356 );
// 上传终端轮询状态通知: TPollInfo +  TOperObjToCM[]
OSPEVENT( MCU_CM_MMCUSRCPOLL_NTF,				EV_MCU_BGN + 1357 );
// 开始上传终端轮询: TPollInfo+TMtPollParam*wMtNum(u16)
OSPEVENT( CM_MCU_STARTMMCUSRCPOLL_CMD,			EV_MCU_BGN + 1358 );
// 暂停上传终端轮询
OSPEVENT( CM_MCU_PAUSEMMCUSRCPOLL_CMD,			EV_MCU_BGN + 1359 );
// 停止上传终端轮询
OSPEVENT( CM_MCU_STOPMMCUSRCPOLL_CMD,			EV_MCU_BGN + 1360 );
// 修改会议双流发起模式: u8(0 - 主讲人模式，1 - 任意人模式 )
OSPEVENT( CM_MCU_CHANGEDUALMODE_CMD,			EV_MCU_BGN + 1361 );
// 指定会议双流发起方: TMtIdentifyToCM
OSPEVENT( CM_MCU_SPECDUALSRC_CMD,				EV_MCU_BGN + 1362 );
// 取消会议双流发起方: TMtIdentifyToCM
OSPEVENT( CM_MCU_CANCELDULASRC_CMD,				EV_MCU_BGN + 1363 );



OSPEVENT( CM_CMU_MTCAMERA_MOV_CMD,				EV_MCU_BGN + 1364 );
OSPEVENT( CM_CMU_MTCAMERA_STOP_CMD,				EV_MCU_BGN + 1365 );
OSPEVENT( CM_CMU_MTCAMERA_RCENABLE_CMD,			EV_MCU_BGN + 1366 );
OSPEVENT( CM_CMU_MTCAMERA_SAVETOPOS_CMD,		EV_MCU_BGN + 1367 );
OSPEVENT( CM_CMU_MTCAMERA_MOVETOPOS_CMD,		EV_MCU_BGN + 1368 );

// 告警通知
OSPEVENT( CMU_CM_ALARMINFO_NTF,					EV_MCU_BGN + 1369 );
// 选看失败通知
OSPEVENT( CMU_CM_STARTSEE_FAIL_NTF,				EV_MCU_BGN + 1370 );

//会议剩余时间通知 css--cmu
OSPEVENT( MAU_MCU_CONFTIMELEFT_NTF,				EV_MCU_BGN + 1371 );
//会议持续时间通知 css--cmu
OSPEVENT( MAU_MCU_CONFDURATION_NTF,				EV_MCU_BGN + 1372 );
//vmp开启失败通知
OSPEVENT( CMU_CM_STARTVMP_FAIL_NTF,				EV_MCU_BGN + 1373 );
OSPEVENT( CMU_CM_STARTMTVMP_FAIL_NTF,			EV_MCU_BGN + 1374 );
OSPEVENT( CMU_CM_STARTHDUVMP_FAIL_NTF,			EV_MCU_BGN + 1375 );

OSPEVENT( CMU_CM_STARTMIX_FAIL_NTF,				EV_MCU_BGN + 1376 );

// 恢复上传终端轮询   增加时，后补的该消息 见1358
OSPEVENT( CM_MCU_RESUMEMMCUSRCPOLL_CMD,			EV_MCU_BGN + 1377 );
// 指定上传轮询pos req  TReqHeadInfo + TOperObjToCM + byPollMode
OSPEVENT( CM_CMU_MMCUSRCPOLLPOS_REQ,			EV_MCU_BGN + 1378 );
OSPEVENT( CMU_CM_MMCUSRCPOLLPOS_ACK,			EV_MCU_BGN + 1379 );
OSPEVENT( CMU_CM_MMCUSRCPOLLPOS_NACK,			EV_MCU_BGN + 1380 );
// 改变上传轮询成员cmd
OSPEVENT( CM_CMU_CHANGEMMCUSRCPOLLPARAM_CMD,	EV_MCU_BGN + 1381 );


//会管开始普通监控
OSPEVENT( CM_CMU_STARTMONITORING_REQ,			EV_MCU_BGN + 1382 );
OSPEVENT( CMU_CM_STARTMONITORING_ACK,			EV_MCU_BGN + 1383 );
OSPEVENT( CMU_CM_STARTMONITORING_NACK,			EV_MCU_BGN + 1384 );

//会管开始广播监控
OSPEVENT( CM_CMU_STARTBRDMONITORING_REQ,		EV_MCU_BGN + 1385 );
OSPEVENT( CMU_CM_STARTBRDMONITORING_ACK,		EV_MCU_BGN + 1386 );
OSPEVENT( CMU_CM_STARTBRDMONITORING_NACK,		EV_MCU_BGN + 1387 );

//会管开始双流监控
OSPEVENT( CM_CMU_STARTDVIDMONITORING_REQ,		EV_MCU_BGN + 1388 );
OSPEVENT( CMU_CM_STARTDVIDMONITORING_ACK,		EV_MCU_BGN + 1389 );
OSPEVENT( CMU_CM_STARTDVIDMONITORING_NACK,		EV_MCU_BGN + 1390 );

// 会议开始监控通知
OSPEVENT( CMU_CM_STARTMONITORING_NTF,			EV_MCU_BGN + 1391 );

//会管停止监控
OSPEVENT( CM_CMU_STOPMONITORING_CMD,			EV_MCU_BGN + 1392 );

//会管请求关键帧
OSPEVENT( CM_CMU_NEEDIFRAME_CMD,				EV_MCU_BGN + 1393 );

//会管请求指定终端关键帧
OSPEVENT( CM_CMU_NEEDSPECMTIFRAME_CMD,			EV_MCU_BGN + 1394 );

//会管请求指定终端关键帧
OSPEVENT( CM_CMU_GETCURRENTBRDSRC_REQ,			EV_MCU_BGN + 1395 );
OSPEVENT( CMU_CM_GETCURRENTBRDSRC_ACK,			EV_MCU_BGN + 1396 );
OSPEVENT( CMU_CM_GETCURRENTBRDSRC_NACK,			EV_MCU_BGN + 1397 );

//会议停止监控通知, 消息体：TSwitchDstInfo
OSPEVENT( CMU_CM_STOPMONITORING_NTF,			EV_MCU_BGN + 1398 );

//请求修改会议别名，消息体:TReqHeadInfo+u16(wConfNameLen)+s8[confName]
OSPEVENT( MCU_MAU_MODIFYCONFNAME_REQ,           EV_MCU_BGN + 1399 );
OSPEVENT( MAU_MCU_MODIFYCONFNAME_ACK,	        EV_MCU_BGN + 1400 );
OSPEVENT( MAU_MCU_MODIFYCONFNAME_NACK,	        EV_MCU_BGN + 1401 );

//获取指定终端状态请求
OSPEVENT( CM_CMU_GETMTSTATUS_REQ,	        EV_MCU_BGN + 1402 );
OSPEVENT( CMU_CM_GETMTSTATUS_ACK,	        EV_MCU_BGN + 1403 );
OSPEVENT( CMU_CM_GETMTSTATUS_NACK,	        EV_MCU_BGN + 1404 );

// 界面定制api功能需求
OSPEVENT( CM_CMU_GETMTLIST_REQ,						EV_MCU_BGN + 1405 );
//消息体：u8*16(会议e164)+u8*64(会议名称)+u8(终端数量)+[ TJsonMtIdentify+TJsonMtDesc+u16(CallBitrate, 网络序)+u8(IsOnline)+
//		  u32(主视频发送通道数量，网络序)+[TMtMgrVidSndChnStatus]+
//		  u32(主视频接收通道数量，网络序)+[TMtMgrVidRcvChnStatus]+
//		  u32(双流视频发送通道数量，网络序)+[TMtMgrDVidSndChnStatus]+
//		  u32(双流视频接收通道数量，网络序)+[TMtMgrDVidRcvChnStatus]+
//		  u32(音频发送通道数量，网络序)+[TMtMgrAudSndChnStatus+u8(是否哑音)]+
//		  u32(音频接收通道数量，网络序)+[TMtMgrAudRcvChnStatus+u8(是否静音)] 
//        ]
OSPEVENT( CMU_CM_GETMTLIST_ACK,						EV_MCU_BGN + 1406 );
OSPEVENT( CMU_CM_GETMTLIST_NACK,                    EV_MCU_BGN + 1407 );

//呼叫终端通知TMT + bySuccess
OSPEVENT( MCU_CM_CALLMT_NTF,						EV_MCU_BGN + 1408 );

//获取终端预置位信息
OSPEVENT( CM_CMU_MTCAMERA_GETPOSINFO_CMD,           EV_MCU_BGN + 1409 );
//终端预置位信息上报
OSPEVENT( CMU_CM_MTCAMERA_POSINFO_NTF,                EV_MCU_BGN + 1410 );

OSPEVENT( MAU_MCU_RESTORECONF_REQ,               EV_MCU_BGN + 1411 );
OSPEVENT( MAU_MCU_RESTORECONF_ACK,               EV_MCU_BGN + 1412 );
OSPEVENT( MAU_MCU_RESTORECONF_NACK,              EV_MCU_BGN + 1413 );

/********** wy[2014/09/22]解析MAU与MCU交互信令(29001-30000)---复用终端内部业务消息 end *******/



/********** rnn[2015/01/19]解析MCU/MAU内部与网管相关交互信令(29901-30000)---复用终端内部业务消息 bgn *******/
//创建多点会议通知 消息体：TMcuConfInfo
OSPEVENT( MCU_ADP_CONFCREATE_NTF,				EV_MCU_BGN + 1900 );
//销毁多点会议通知 消息体：TMcuConfInfo
OSPEVENT( MCU_ADP_CONFDESTROY_NTF,				EV_MCU_BGN + 1901 );
//终端入会通知 消息体：TMtInfoInConf
OSPEVENT( MCU_ADP_MTADD_NTF,					EV_MCU_BGN + 1902 );
//终端离会通知 消息体：TMtInfoInConf
OSPEVENT( MCU_ADP_MTDEL_NTF,					EV_MCU_BGN + 1903 );
//ADP上线通知 消息体：TMtInfoInConf
OSPEVENT( MCU_ADP_ADPONELINE_NTF,               EV_MCU_BGN + 1904 );


/********** rnn[2015/01/19]解析MCU/MAU内部与网管相关交互信令(29901-30000)---复用终端内部业务消息 end *******/



/********** VC与INTERACT交互信令(30001-30200)---复用RECORDER内部业务消息 bgn *******/
//初始化交换模块,消息体TInterActInitInfo
OSPEVENT( MCU_INTERACT_INIT_CMD,				EV_REC_BGN );
//交换模块正对MCUVC操作后的结果通知
OSPEVENT( MCU_INTERACT_ADDONETOONE_CMD,			EV_REC_BGN + 1 );
//交换模块正对MCUVC操作后的结果通知
OSPEVENT( MCU_INTERACT_ADDNTON_CMD,				EV_REC_BGN + 2 );
//交换模块正对MCUVC操作后的结果通知
OSPEVENT( MCU_INTERACT_ADDONETON_CMD,			EV_REC_BGN + 3 );
//交换模块正对MCUVC操作后的结果通知
OSPEVENT( MCU_INTERACT_CHANGENTON_CMD,			EV_REC_BGN + 4 );
//交换模块正对MCUVC操作后的结果通知
OSPEVENT( MCU_INTERACT_ADDVIEWERS_CMD,			EV_REC_BGN + 5 );

OSPEVENT( MCU_INTERACT_INITACTORSWITCH_CMD,		EV_REC_BGN + 6 );

OSPEVENT( MCU_INTERACT_INITVIEWERSWITCH_CMD,	EV_REC_BGN + 7 );
//预申请资源 消息体:TConfResDemand
OSPEVENT( MCU_INTERACT_APPLYMEDIARESOURCE_CMD,			EV_REC_BGN + 8 );

//设置actor对应所有音频选看交换
OSPEVENT( MCU_INTERACT_SETACTORSELECTSWITCHMUTE_CMD,	EV_REC_BGN + 9 );

//资源上线通知 消息体:u8 MediaMode
OSPEVENT( MCU_INTERACT_MEDIAEQPONLINE_NTF,		EV_REC_BGN + 10 );

// actor对应业务交换，执行哑音拆建命令 u8 byIsRmv + u8 actorNum + actor*N 
OSPEVENT( MCU_INTERACT_ACOTRSWITCHMUTE_CMD,		EV_REC_BGN + 11 );
// viewer对应业务交换，执行静音拆建命令 u8 byIsRmv + u8 viewerNum + viewer*N 
OSPEVENT( MCU_INTERACT_VIEWERSWITCHMUTE_CMD,	EV_REC_BGN + 12 );


OSPEVENT( MCU_INTERACT_RELEASEACTORSWITCH_CMD,	EV_REC_BGN + 22 );
//交换模块正对MCUVC操作后的结果通知
OSPEVENT( MCU_INTERACT_RELEASEVIEWERSWITCH_CMD,	EV_REC_BGN + 23 );

//交换模块正对MCUVC操作后的结果通知
OSPEVENT( MCU_INTERACT_MSGRES_RSP,				EV_REC_BGN + 24 );

OSPEVENT( MCU_INTERACT_EQPRES_RSP,				EV_REC_BGN + 25 );

OSPEVENT( MCU_INTERACT_DELINTERACT_CMD,			EV_REC_BGN + 26 );

OSPEVENT( MCU_INTERACT_DELVIEWERS_CMD,			EV_REC_BGN + 27 );

OSPEVENT( MCU_INTERACT_CLEAR_CMD,				EV_REC_BGN + 28 );
//交换模块正对MCUVC操作后的结果通知
OSPEVENT( INTERACT_MCU_RLT_NTF,					EV_REC_BGN + 29 );

// 向媒体资源外设进行关键帧请求，消息体：INTERACTIONID(u32)+CViewer+byMediaMode(u8)
OSPEVENT( MCU_INTERACT_IFRAME_CMD,              EV_REC_BGN + 30 );
// 切换HDU通道风格 消息体 TInteractionHduPicStyleParam
OSPEVENT( MCU_INTERACT_CHGHDUPICSTYLE_CMD,      EV_REC_BGN + 31 );
// 切换风格结果通知 TInteractionHduPicStyleParam （ERROR != 0失败） 
OSPEVENT( INTERACT_MCU_CHGHDUPICSTYLE_NTF,      EV_REC_BGN + 32 );
// 修改One2One交换
OSPEVENT( MCU_INTERACT_CHANGEONETOONE_CMD,      EV_REC_BGN + 33);

//	u8 byCBChlNum + byCBChlNum*( tParam + wErrCode )
OSPEVENT( INTERACT_MCU_HDURESRVE_NTF,         EV_REC_BGN + 34 );
// 设置HDU通道台标 消息体 TInteractionHduDispAliasParam 无需回复
OSPEVENT( MCU_INTERACT_SETHDUDISPALIAS_CMD,     EV_REC_BGN + 35 );
// 交换模块正对端口掉线后处理的结果通知
OSPEVENT( INTERACT_MCU_MEDIAPORTRLT_NTF,        EV_REC_BGN + 36 );

// 预占HDU通道(只支持单通道预占，四风格子通道不支持) 消息体 u8 byNum + TCtrHduInfo*byNum + BooL32 bReserve
OSPEVENT( MCU_INTERACT_RESERVEHDUCHL_CMD,		EV_REC_BGN + 37 );

//交换模块正对MCUVC操作后的结果通知
OSPEVENT( MCU_INTERACT_CHANGEONETON_CMD,		EV_REC_BGN + 38 );

OSPEVENT( MCU_INTERACT_BACHRESERVEHDUCHL_TIME,  EV_REC_BGN + 39 );

// 外厂商终端自环命令，buf：
OSPEVENT( MCU_INTERACT_ACTORMEDIALOOP_CMD,	   EV_REC_BGN + 40 );
/********** VC与INTERACT交互信令(30001-30041)---复用RECORDER内部业务消息 end *******/

/********** INTERACT与MTMGR交互信令(30041-30200)---复用RECORDER内部业务消息 begin *******/
// 申请编解码码资源命令:CViewer+u32(dwPariID)+u8(0:申请解码资源 1:申请编码资源)+TPortEncDecCap编解码能力
OSPEVENT( INTERACT_MTMGR_APPLYDECENCRES_CMD,        EV_REC_BGN + 41 );
// 释放编解码码资源命令:HMEDIARES(编解码句柄)+u8(0:释放解码资源 1:释放编码资源)
OSPEVENT( INTERACT_MTMGR_RELEASEDECENCRES_CMD,        EV_REC_BGN + 42 );
// 申请编解码资源通知:CViewer+u32(dwPariID)+u8(0:申请解码资源 1:申请编码资源)+HMEDIARES(编解码句柄)
OSPEVENT( MTMGR_INTERACT_APPLYENCRES_NTF,        EV_REC_BGN + 43 );
//调整bas 编码参数 cActor + cViewer + TSimCapSet
OSPEVENT( MCU_INTERACT_ADJUSTBASENCPARAM_CMD,  EV_REC_BGN + 44 );

//MCU侧,录放像定时器 共16个,预留16个  。录播没有按时成功，删除录播及相关vc侧数据,
OSPEVENT( MCUVC_MC_RECORD_TIMER,       EV_REC_BGN + 45 );
// vrs 占用 16个定时器，之后EV_REC_BGN + 61 开始
 
/********** INTERACT与MTMGR交互信令(30041-30200)---复用RECORDER内部业务消息 end *******/

/********** VC与MtMgr交互信令[非透传](30201-30400) ---复用混音器内部业务消息 begin******/
/*-------
注册相关
--------*/
//VC注册MTMGR，	VCApp->MtMgrApp,	消息体：TConfInfo4Call
OSPEVENT(VC_MTMGR_REG_REQ,						EV_MIXER_BGN );
//MtMgr回应VC注册，MtMgrApp->VCApp,	消息体：无
OSPEVENT(MTMGR_VC_REG_ACK,						EV_MIXER_BGN + 1 );
OSPEVENT(MTMGR_VC_REG_NACK,						EV_MIXER_BGN + 2 );
//注销MTMGR		VCApp->MtMgrApp,	消息体：无
OSPEVENT(VC_MTMGR_UNREG_CMD,					EV_MIXER_BGN + 3 );
/*-----------
呼叫挂断相关
------------*/
//添加终端，	VCApp->MtMgrApp，	消息体：u8(num) + TAddMtInfo[] + u8(是否要立即呼叫) + u8(是否是开会是呼叫)
OSPEVENT(VC_MTMGR_ADDMT_REQ,					EV_MIXER_BGN + 4 );
//添加终端，	VCApp->MtMgrApp，	消息体：u8(num) + TAddMtInfo[] + u8(是否要立即呼叫) + u8(是否是开会是呼叫) + num*sizeof(TMT)
//											没有添加成功的终端用空的TMt填充
OSPEVENT(MTMGR_VC_ADDMT_ACK,					EV_MIXER_BGN + 5 );
OSPEVENT(MTMGR_VC_ADDMT_NACK,					EV_MIXER_BGN + 6 );
//呼叫终端,		VcApp->MtMgrApp,	消息体：TMt	  (要呼的终端，若要呼所有终端则TMt进行SetNull)	+
//											BOOL32(是否向级联mcu发送Alert呼叫通知)				+
//											BOOL32(是否向所有mcu广播此Alert呼叫通知或者只是回复重邀端mcu)	+
//											u8	  (呼叫类型: 呼叫请求[VCS_FORCECALL_REQ] 呼叫强拆命令[VCS_FORCECALL_CMD])	
OSPEVENT(VC_MTMGR_CALLMT_CMD,					EV_MIXER_BGN + 7 );
//呼叫终端失败通知
OSPEVENT(MTMGR_VC_CALLMTFAIL_NTF,				EV_MIXER_BGN + 8 );
//终端成功入会通知
OSPEVENT(MTMGR_VC_CALLMTOK_NTF,					EV_MIXER_BGN + 9 );

// OSPEVENT(VC_MTMGR_DEMAND_DSRCVCAP_CMD,		EV_MCUMT_STD_BGN + 306 );
// 双流能力通告，					消息体：Null
OSPEVENT(MTMGR_VC_DSRCVCAP_NTF,					EV_MIXER_BGN + 10 );
//VC业务请求打开双流通道，			消息体：TLogicChannel
OSPEVENT(VC_MTMGR_DSFWD_OLC_CMD,				EV_MIXER_BGN + 11 );

//后向逻辑通道成功打开通知,MtMgrApp->VcApp, 消息体：byChannelmode
OSPEVENT(MTMGR_VC_BWD_OLCOK_NTF,				EV_MIXER_BGN + 12 );
//前向逻辑通道成功打开通知,MtMgrApp->VcApp, 消息体：byChannelmode
OSPEVENT(MTMGR_VC_FWD_OLCOK_NTF,				EV_MIXER_BGN + 13 );
//修改呼叫模式，VcApp->MtMgrApp,	消息体：byCallMode
OSPEVENT(VC_MTMGR_CHGCALLMODE_CMD,				EV_MIXER_BGN + 14 );

//挂断终端，	VcApp->MtMgrApp,	消息体：byDel(是否删除)
OSPEVENT(VC_MTMGR_DROPMT_CMD,					EV_MIXER_BGN + 15 );
//终端删除/挂断处理后通知VC，		消息体：TMtAlias + byDel(是否删除)
OSPEVENT(MTMGR_VC_DROPMT_NTF,					EV_MIXER_BGN + 16 );   //处理自动结会定时器

//前向逻辑通道成功打开通知,MtMgrApp->VcApp, 消息体：byChannelmode
OSPEVENT(MTMGR_VC_FWD_OLCFAIL_NTF,				EV_MIXER_BGN + 17 );

//前向逻辑通道成功打开通知,VcApp->MtMgrApp, 消息体：tMT+TLogicalChannel_HasChnIdx
OSPEVENT(VC_MTMGR_BWD_OLCOK_NTF,				EV_MIXER_BGN + 18 );
OSPEVENT(VC_MTMGR_BWD_OLCFAIL_NTF,				EV_MIXER_BGN + 19 );

/*--------------------------------------------
VC业务控制终端动作系列 VcApp->MtMgrApp
---------------------------------------------*/
//让终端准备收码流
OSPEVENT(VC_MTMGR_MTRCV_CMD,					EV_MIXER_BGN + 20 );
//让终端准备发码流
OSPEVENT(VC_MTMGR_MTSND_CMD,					EV_MIXER_BGN + 21 );
//向终端请求关键帧,		消息体：u8(byMode: v/secv) + u8(byChnIdx) + BOOL32 bDirectApplyMt(是否直接向终端请求)
OSPEVENT(VC_MTMGR_REQIFRAME_CMD ,				EV_MIXER_BGN + 22 );
//控制终端接收的码率,	消息体：tLogicChannel
OSPEVENT(VC_MTMGR_MTRCVBRCTRL_CMD ,				EV_MIXER_BGN + 23 );
//控制终端发送的码率,	消息体：tLogicChannel
OSPEVENT(VC_MTMGR_MTSNDBRCTRL_CMD,				EV_MIXER_BGN + 24 );
//关逻辑通道命令,		消息体：u8(byFwd) + u8(ChannelType:V,A...)
OSPEVENT(VC_MTMGR_CLC_CMD,						EV_MIXER_BGN + 25 );
//调整终端编码分辨率,	消息体：u8(byRes) + u8(mode: MODE_VIDEO) + u8(byChnIdx)
OSPEVENT(VC_MTMGR_MTRESCTRL_CMD,				EV_MIXER_BGN + 26 );
//调整终端编码帧率,		消息体：u8(byFps) + u8(mode: MODE_VIDEO) + u8(byChnIdx)
OSPEVENT(VC_MTMGR_MTFPSCTRL_CMD,				EV_MIXER_BGN + 27 );
//终端改变接收码率通知
OSPEVENT(VC_MTMGR_MTRCVBRCHG_NTF,				EV_MIXER_BGN + 28 );
//终端恢复编解码资源通知
OSPEVENT(VC_MTMGR_MTENCDECRES_RESUME_NTF,		EV_MIXER_BGN + 29 );

/*---------------------------------
终端变化通知VC	MtMgrApp->VcApp
----------------------------------*/
//在线状态改变通知,		消息体：BOOL(bOnline)+u8(byReason)
OSPEVENT(MTMGR_VC_OnLineST_NTF,					EV_MIXER_BGN + 30 );
//终端关闭逻辑通道通知,	消息体：TLogicChannel + u8(byFwd) 
OSPEVENT(MTMGR_VC_CLC_NTF,						EV_MIXER_BGN + 31 );
//终端改变发送码率通知,	消息体：u16(wBitrate)
OSPEVENT(MTMGR_VC_MTSNDBRCHG_NTF,				EV_MIXER_BGN + 32 );
//终端改变接收码率通知,	消息体：u16(wBitrate)
OSPEVENT(MTMGR_VC_MTRCVBRCHG_NTF,				EV_MIXER_BGN + 33 );

//释放双流令牌
OSPEVENT(VC_MTMGR_RELEASEH239TOKEN_CMD,			EV_MIXER_BGN + 34 );

//终端呼叫模式改变通知
OSPEVENT(VC_MTMGR_MODMTCALLMODE_CMD,			EV_MIXER_BGN + 35 );
OSPEVENT(MTMGR_VC_MTCALLMODE_NOTIF,				EV_MIXER_BGN + 36 );

//终端状态改变通知,		消息体：TMtStatus
OSPEVENT(VC_MTMGR_MTSTATUS_CMD,					EV_MIXER_BGN + 37 );
OSPEVENT(MTMGR_VC_MTSTATUS_NOTIF,				EV_MIXER_BGN + 38 );

//其他通知
OSPEVENT(VC_MTMGR_MPDISCONNECTED_NTF,   		EV_MIXER_BGN + 39 );



/*---------------------------------
VRS交互	MtMgrApp <-> VcApp
----------------------------------*/
// MsgBody: TStartRecMsgInfo + u16 wMtDialRate + u8 byCallMode
OSPEVENT(VC_MTMGR_ADDREC_REQ,   				EV_MIXER_BGN + 40 );		// 添加录像终端
OSPEVENT(MTMGR_VC_ADDREC_ACK,   				EV_MIXER_BGN + 41 );
OSPEVENT(MTMGR_VC_ADDREC_NACK,   				EV_MIXER_BGN + 42 );
// MsgBody: TMtAlias呼叫别名 + TPlayEqpAttrib + u16 wMtDialRate + u8 byCallMode
OSPEVENT(VC_MTMGR_ADDPLAY_REQ,   				EV_MIXER_BGN + 43 );		// 添加放像终端
OSPEVENT(MTMGR_VC_ADDPLAY_ACK,   				EV_MIXER_BGN + 44 );
OSPEVENT(MTMGR_VC_ADDPLAY_NACK,   				EV_MIXER_BGN + 45 );

//zjj20150521 mtmgr告知interaction端口回调信息，现在主要是端口掉线信息
//因为hdu用的端口和会控监控用的端口在interaction中管理
OSPEVENT(MTMGR_INTERACT_CBPORTMGR_NTF,   	EV_MIXER_BGN + 46 );

//会管修改会议密码，免打扰等属性通知mtmgr更新
OSPEVENT(VC_MTMGR_CONFINFO_NTF,   				EV_MIXER_BGN + 47 );

//停双流mtmgr恢复所有终端的接收和发送码率通知
OSPEVENT(MTMGR_VC_STOPSECVIDEOBRDOK_NTF,   				EV_MIXER_BGN + 48 );

//MtMgr根据E164号查找NU信息
OSPEVENT(MTMGR_UPU_FINDNUBYE164NO_CMD,   				EV_MIXER_BGN + 49 );

//upu定时查询所有平台域nu信息 一分钟一次
OSPEVENT(UPUSSN_REFRESHNUINFO_TIMER,   			     	EV_MIXER_BGN + 50 );

//Upu返回让MtMgr呼叫终端
OSPEVENT(UPU_MTMGR_ADDMTWITHNU_CMD,                     EV_MIXER_BGN + 51 );

//Upuapp让upussn注册NU
OSPEVENT(UPUDATA_UPUSSN_REGISTNU_CMD,                   EV_MIXER_BGN + 52 );

//更新查询事件
OSPEVENT(UPUSSN_REFRESHFINDLIST_TIMER,                 EV_MIXER_BGN + 53 );

//多回传利旧，vc收到spynotify后，通知mtmanager模拟开通mmcu接收通道消息
OSPEVENT(VC_MTMGR_SPYFWD_OPENLOGICCHNNL_CMD,			EV_MIXER_BGN + 54 );
//多回传利旧，vc发送spynotify后，通知mtmanager模拟开通smcu发送通道消息
OSPEVENT(VC_MTMGR_SPYBWD_OPENLOGICCHNNL_CMD,			EV_MIXER_BGN + 55 );
//多回传利旧，// mtid + Fwd + logicalChnl 
OSPEVENT(VC_MTMGR_SPY_CLOSELOGICCHNNL_CMD,			EV_MIXER_BGN + 56 );

//多回传利旧 建立到远端rtcp地址的交换 u8 ChnIdx + u8 byMode + TTransportAddr
OSPEVENT(VC_MTMGR_SPYMT_STARTRTCP_CMD,					EV_MIXER_BGN + 57 );
OSPEVENT(VC_MTMGR_SPYMT_STOPRTCP_CMD,					EV_MIXER_BGN + 58 );

//多回传利旧 多回传终端请求关键帧  TMt + Mode + Chnidx
OSPEVENT(VC_MTMGR_SPYMT_FASTUPDATE_CMD,					EV_MIXER_BGN + 59 );

// 界面设置终端音量
OSPEVENT(VC_MTMGR_SETMTVOLUME_CMD,						EV_MIXER_BGN + 60 );
/********** VC与MtMgr交互信令[非透传](30201-30400) ---复用混音器内部业务消息 end********/

/********** InterAct与InterAct内部交互信令((30401-30500)) ---复用电视墙内部业务消息 bgn********/
// 批量申请媒体资源回调通知
OSPEVENT( INTERACT_INTERACT_CBALLMEDIARES_NTF,  EV_TVWALL_BGN );

// 端口VMP操作回调通知
OSPEVENT( INTERACT_INTERACT_CBMULTIPICMGR_NTF,  EV_TVWALL_BGN + 1 );

// 传统VMP操作回调通知
OSPEVENT( INTERACT_INTERACT_CBVMPMGR_NTF,       EV_TVWALL_BGN + 2 );

// Mixer操作回调通知
OSPEVENT( INTERACT_INTERACT_CBMIXERMGR_NTF,     EV_TVWALL_BGN + 3 );

// BAS操作回调通知
OSPEVENT( INTERACT_INTERACT_CBBASMGR_NTF,       EV_TVWALL_BGN + 4 );

// HDU操作回调通知
OSPEVENT( INTERACT_INTERACT_CBHDUMGR_NTF,       EV_TVWALL_BGN + 5 );

// 端口操作回调通知
OSPEVENT( INTERACT_INTERACT_CBPORTMGR_NTF,       EV_TVWALL_BGN + 6 );
/********** InterAct与InterAct内部交互信令((30401-30500)) ---复用电视墙内部业务消息 end********/


#endif /* _EV_MCU_H_ */


