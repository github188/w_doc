/*****************************************************************************
   ģ����      : �·���ҵ��
   �ļ���      : evmcu.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: �·���ҵ��MCU�ڲ���Ϣ����
   ����        : ����
   �汾        : V0.9  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2002/07/24  0.9         ����        ����
******************************************************************************/
#ifndef _EV_MCU_H_
#define _EV_MCU_H_

#include "osp.h"
#include "eventid.h"

/**********************************************************
 ����Ϊҵ��MCU�ڲ���Ϣ��28001-29000��
**********************************************************/

///////////////////////////////////////////////////////////
//ͬһMCU�ڲ���Ϣ

//MCU�����𴴽�����������Ϣ��Ϊ�ṹTConfFullInfo����ʾ��Ӧ������Ϣ
OSPEVENT( MCU_CREATECONF_FROMFILE,			EV_MCU_BGN + 1 );
//����MCU�ڲ�����ʵ��֪ͨĳ�¼�MT�Ǽǳɹ�����Ϣ��Ϊ�ṹTMt
//OSPEVENT( MCU_MTCONNECTED_NOTIF,			EV_MCU_BGN + 2 );
//����MCU�ڲ�����ʵ��֪ͨĳ�¼�MT��������Ϣ��Ϊ�ṹTMt
//OSPEVENT( MCU_MTDISCONNECTED_NOTIF,		EV_MCU_BGN + 3 );

//MCU ��N+1���ݴ�������
OSPEVENT( MCU_CREATECONF_NPLUS,             EV_MCU_BGN + 3 );

//MCU ֪ͨ�Ự ���� ��Ӧʵ��, zgc, 2007/04/29
OSPEVENT( MCU_DISCONNECT_CMD,		EV_MCU_BGN + 4 );
//MCU ֪ͨ�Ự ����MPCB ��Ӧʵ��, zgc, 2007/04/30
OSPEVENT( MCU_CONNECTMPCB_CMD,		EV_MCU_BGN + 5 );

//����MCU�ڲ�����ʵ��֪ͨ���轨���ɹ�����Ϣ��ΪTPeriEqpRegReq
OSPEVENT( MCU_EQPCONNECTED_NOTIF,			EV_MCU_BGN + 11 );
//����MCU�ڲ�����ʵ��֪ͨ�����������Ϣ��ΪTEqp
OSPEVENT( MCU_EQPDISCONNECTED_NOTIF,		EV_MCU_BGN + 12 );
//����MCU�ڲ�����ʵ��֪ͨDCS�����ɹ�, ��Ϣ��Ϊ CDcsMcuRegReqPdu
OSPEVENT( MCU_DCSCONNCETED_NOTIF,			EV_MCU_BGN + 13 );
//����MCU�ڲ�����ʵ��֪ͨDCS����, ��Ϣ��Ϊ CDcsMcuRegReqPdu
OSPEVENT( MCU_DCSDISCONNECTED_NOTIF,		EV_MCU_BGN + 14 );

//����MCU�ڲ�����ʵ��֪ͨ��ؽ����ɹ�����Ϣ��Ϊ���ֽڻ��ʵ����+CVcCtrlRegReq
//mcuҵ����Ҫ��֪ACS���ӣ�����Ϣ�ݲ�ʹ��
OSPEVENT( MCU_ACSCONNECTED_NOTIF,			EV_MCU_BGN + 21 );
//����MCU�ڲ�����ʵ��֪ͨ��ض�������Ϣ��Ϊ���ֽڻ��ʵ����
OSPEVENT( MCU_ACSDISCONNECTED_NOTIF,		EV_MCU_BGN + 22 );

//����MCU�ڲ� MCU����ע��GK ֪ͨ����Ϣ�壺NULL
OSPEVENT( MCU_MCUREREGISTERGK_NOITF,        EV_MCU_BGN + 23 );

//����Ƶ��
OSPEVENT( MCU_NMS_SENDNMSMSG_CMD,           EV_MCU_BGN + 30 );

//����MCU�ڲ�����ʵ��֪ͨBAS�����ɹ�����Ϣ��ΪTPeriEqpRegReq
OSPEVENT( MCU_BASCONNECTED_NOTIF,			EV_MCU_BGN + 31 );
//����MCU�ڲ�����ʵ��֪ͨBAS��������Ϣ��ΪTEqp
OSPEVENT( MCU_BASDISCONNECTED_NOTIF,		EV_MCU_BGN + 32 );

//����MCU�ڲ�����ʵ��֪ͨPRS�����ɹ�����Ϣ��ΪTPeriEqpRegReq
OSPEVENT( MCU_PRSCONNECTED_NOTIF,			EV_MCU_BGN + 35 );
//����MCU�ڲ�����ʵ��֪ͨPRS��������Ϣ��ΪTEqp
OSPEVENT( MCU_PRSDISCONNECTED_NOTIF,		EV_MCU_BGN + 36 );

//����MCU�ڲ�����ʵ��֪ͨREC���������ɹ�����Ϣ��ΪTPeriEqpRegReq
OSPEVENT( MCU_RECCONNECTED_NOTIF,           EV_MCU_BGN + 40 );
//����MCU�ڲ�����ʵ��֪ͨREC��������Ϣ��ΪTEqp
OSPEVENT( MCU_RECDISCONNECTED_NOTIF,		EV_MCU_BGN + 41 );

//����MCU�ڲ�����ʵ��֪ͨMixer�����ɹ�����Ϣ��ΪTEqp
OSPEVENT( MCU_MIXERCONNECTED_NOTIF,		    EV_MCU_BGN + 42 );
//����MCU�ڲ�����ʵ��֪ͨMixer��������Ϣ��ΪTEqp
OSPEVENT( MCU_MIXERDISCONNECTED_NOTIF,		EV_MCU_BGN + 43 );

//����MCU�ڲ�����ʵ��֪ͨVmp�����ɹ�����Ϣ��ΪTPeriEqpRegReq
OSPEVENT( MCU_VMPCONNECTED_NOTIF,		    EV_MCU_BGN + 44 );
//����MCU�ڲ�����ʵ��֪ͨVmp��������Ϣ��ΪTEqp
OSPEVENT( MCU_VMPDISCONNECTED_NOTIF,		EV_MCU_BGN + 45 );

//����MCU�ڲ�����ʵ��֪ͨVmpTw�����ɹ�����Ϣ��ΪTPeriEqpRegReq
OSPEVENT( MCU_VMPTWCONNECTED_NOTIF,		    EV_MCU_BGN + 46 );
//����MCU�ڲ�����ʵ��֪ͨVmpTw��������Ϣ��ΪTEqp
OSPEVENT( MCU_VMPTWDISCONNECTED_NOTIF,		EV_MCU_BGN + 47 );

//tvwall 2
//����MCU�ڲ�����ʵ��֪ͨTvWall�����ɹ�����Ϣ��ΪTPeriEqpRegReq
OSPEVENT( MCU_TVWALLCONNECTED_NOTIF,		EV_MCU_BGN + 48 );
//����MCU�ڲ�����ʵ��֪ͨTvwall��������Ϣ��ΪTEqp
OSPEVENT( MCU_TVWALLDISCONNECTED_NOTIF,		EV_MCU_BGN + 49 );

// Mcu�����Լ��Ĵ��ļ��ָ�����,��Ϣ��ΪTConfInfo
OSPEVENT( MCU_WAITEQP_CREATE_CONF_NOTIFY,   EV_MCU_BGN + 50 );

//MCU��GUARDģ��������ģ�鷢�Ĳ���������Ϣ
OSPEVENT( MCU_APPTASKTEST_REQ,				EV_MCU_BGN + 51 );
//MCU������ģ����GUARDģ�鷢�Ĳ��Ի�Ӧ��Ϣ
OSPEVENT( MCU_APPTASKTEST_ACK,				EV_MCU_BGN + 52 );
//MCUֹͣGUARD�ڲ���ʱ��
OSPEVENT( MCU_STOPGUARDTIMER_CMD,           EV_MCU_BGN + 53 );
//MCU����GUARD�ڲ���ʱ��
OSPEVENT( MCU_STARTGUARDTIMER_CMD,          EV_MCU_BGN + 54 );

//MCU��ʼ����ַ�����ͨ��
OSPEVENT( MCU_ADDRINITIALIZED_NOTIFY,       EV_MCU_BGN + 55 );

//NU�Ự֪ͨMCU����
OSPEVENT( MCU_NU_DISCONNECTED_NOTIFY,		EV_MCU_BGN + 56 );

//VCS������ģ���Ϊ��ʱ����
OSPEVENT( MCU_SCHEDULE_VCSCONF_START,       EV_MCU_BGN + 59 );
//ԤԼ�����Ϊ��ʱ����
OSPEVENT( MCU_SCHEDULE_CONF_START,			EV_MCU_BGN + 60 );

OSPEVENT( MCU_ADDRBOOK_GETENTRYLIST_NOTIF,  EV_MCU_BGN + 61 );
OSPEVENT( MCU_ADDRBOOK_GETGROUPLIST_NOTIF,  EV_MCU_BGN + 62 );

//Mcu Guard timer id
OSPEVENT( MCUGD_GETLICENSE_DATA,            EV_MCU_BGN + 63 );	        // license�������� 
OSPEVENT( MCUGD_SCHEDULED_CHECK_TIMER,      EV_MCU_BGN + 65 );	        // ��ʱ���
//OSPEVENT( MCUGD_PASSIVE_CHECK_TIMER,      EV_MCU_BGN + 66 );			// �������
OSPEVENT( MCUGD_FEEDDOG_TIMER,              EV_MCU_BGN + 66 );	        // ��ʱι�� 


//McuVc timer id
OSPEVENT( MCUVC_APPLYEQPRESOURCE_CHECK_TIMER,     EV_MCU_BGN + 68 );		//Mcu ����������Դ��ʱ
OSPEVENT( MCUVC_APPLYFREQUENCE_CHECK_TIMER,     EV_MCU_BGN + 69 );          //���ǻ��飬mcu�����ܷ���������Ƶ�ʼ��
OSPEVENT( MCUVC_SENDFLOWCONTROL_TIMER,          EV_MCU_BGN + 70 );          //mcu����˫�������ն�flowcontrolʱ�Ķ�ʱ��
OSPEVENT( MCUVC_WAIT_CONNECT_MIX_TIMER,			EV_MCU_BGN + 71 );          //MCU�ȴ�mix���߻ָ�
OSPEVENT( MCUVC_WAIT_START_MIX_TIMER,	        EV_MCU_BGN + 72 );          //MCU�ȴ�MIXERӦ��ʱ     
OSPEVENT( MCUVC_SCHEDULED_CHECK_TIMER,          EV_MCU_BGN + 73 );	        //ԤԼ���鶨ʱ���
OSPEVENT( MCUVC_ONGOING_CHECK_TIMER,            EV_MCU_BGN + 74 );			//�����л��鶨ʱ���
OSPEVENT( MCUVC_INVITE_UNJOINEDMT_TIMER,        EV_MCU_BGN + 75 );			//��ʱ����δ����ն�
OSPEVENT( MCUVC_POLLING_CHANGE_TIMER,           EV_MCU_BGN + 76 );			//��ѯ�ı�ʱ��
//OSPEVENT( MCUVC_TWPOLLING_CHANGE_TIMER,         EV_MCU_BGN + 77 );			//����ǽ��ѯ�ı�ʱ��  
OSPEVENT( MCUVC_VMPPOLLING_CHANGE_TIMER,        EV_MCU_BGN + 77 );			//��ѯ�ı�ʱ��
OSPEVENT( MCUVC_WAIT_MPREG_TIMER,               EV_MCU_BGN + 78 );			//�ȴ�Mpע��ʱ��     
OSPEVENT( MCUVC_REFRESH_MCS_TIMER,              EV_MCU_BGN + 79 );			//ˢ�»��ʱ��          
OSPEVENT( MCUVC_MCUSRC_CHECK_TIMER,             EV_MCU_BGN + 80 );			//mcuԴ֪ͨ           
OSPEVENT( MCUVC_CHANGE_VMPCHAN_SPEAKER_TIMER,   EV_MCU_BGN + 81 );            
OSPEVENT( MCUVC_CHANGE_VMPCHAN_CHAIRMAN_TIMER,  EV_MCU_BGN + 82 );
OSPEVENT( MCUVC_CHANGE_VMPPARAM_TIMER,          EV_MCU_BGN + 83 );
OSPEVENT( MCUVC_RECREATE_DATACONF_TIMER,        EV_MCU_BGN + 84 );			//���´������ݻ���
OSPEVENT( MCU_SMCUOPENDVIDEOCHNNL_TIMER,		EV_MCU_BGN + 85 );			//�¼�mcu�ȴ���˫��ͨ����ʱ��
OSPEVENT( MCUVC_WAIT_CASCADE_CHANNEL_TIMER,     EV_MCU_BGN + 86 );          //�ȴ����¼�MCU�ļ���ͨ��
OSPEVENT( MCUVC_WAIT_MPOVERLOAR_TIMER,          EV_MCU_BGN + 87 );          //�ȴ� ����ص�MP������Ϣ�� ��ʱ��
OSPEVENT( MCUVC_AUTOSWITCH_TIMER,               EV_MCU_BGN + 88 );          //Rad������ѯKedaMcu�����ն�SetOut��ʱ��
//OSPEVENT( MCUVC_HDUPOLLING_CHANGE_TIMER,        EV_MCU_BGN + 89 );          //hdu��ѯ�ı�ʱ��

// xliang [12/12/2008] vmp hdͨ����ռ�У�Ҫ��ռ���ն˽�����ռ��ʱ
OSPEVENT( MCUVC_MTSEIZEVMP_TIMER,				EV_MCU_BGN + 90 );
// xliang [12/22/2008] VMP ������ѯ��ʱ
OSPEVENT( MCUVC_VMPBATCHPOLL_TIMER,				EV_MCU_BGN + 91 );

// hdu������ѯ��ʱ
OSPEVENT( MCUVC_HDUBATCHPOLLI_CHANGE_TIMER,     EV_MCU_BGN + 92 );          //hdu������ѯ�ı�ʱ��

OSPEVENT( MCUVC_VCMTOVERTIMER_TIMER,            EV_MCU_BGN + 93 );          //�����ն˳�ʱ��ʱ��
OSPEVENT( MCUVC_VCS_CHAIRPOLL_TIMER,            EV_MCU_BGN + 94 );          //VCS��ϯ��ѯ��ʱ��

//MCU�ȴ�������Ӧ��ʱ, ��Ϊbas��5�����ͣ�ҪԤ��5���ռ�
OSPEVENT( MCUVC_WAITBASRRSP_TIMER,			    EV_MCU_BGN + 95 );
//MCU���ն˷�FASTUPDATE�Ķ�ʱ���� ��199�Ŀռ�
OSPEVENT( MCUVC_FASTUPDATE_TIMER_ARRAY,	        EV_MCU_BGN + 100 );
// +101 -- + 297  �����ã�����������ؼ�֡�����⴦����������

//MCU�ڲ�MP���������� ֪ͨ��Ϣ
OSPEVENT( MCUVC_MPOVERLOAD_NOTIF,               EV_MCU_BGN + 298 );
//MCU���ն˷�˫��FASTUPDATE�Ķ�ʱ��
OSPEVENT( MCUVC_SECVIDEO_FASTUPDATE_TIMER,  	EV_MCU_BGN + 299 );

//MCU���鿪ʼ�Զ�¼��ʱ����
OSPEVENT( MCUVC_CONFSTARTREC_TIMER,             EV_MCU_BGN + 300 ); 
//MCU��ʼ����ʱ��, zgc, 2008-03-27
OSPEVENT( MCUVC_RECPLAY_WAITMPACK_TIMER,		EV_MCU_BGN + 301 );
//MCUÿ���賿0�㣬���øö�ʱ����������ˢ�¸�����Զ�¼��ʱ��, pengjie, 20091225
OSPEVENT( MCUVC_UPDATA_AUTOREC_TIMER,		EV_MCU_BGN + 302 );

//˫������mcu��ʱ�����ƻ��Ķ�ʱ�� [pengjie 2010/2/26]
OSPEVENT( MCUVC_NOTIFYMCUH239TOKEN_TIMER, 	EV_MCU_BGN + 303 );

// [pengjie 2010/9/29] �������Ƿ��й㲥Դ
OSPEVENT( MCUVC_CHECK_CONFBRDSRC_TIMER,		EV_MCU_BGN + 304 );

//MCU�ȴ�HD����Ƶ������Ӧ��ʱ, ��Ϊ����hd-bas����Ƶ���������4·��ҪԤ��3���ռ䣨��0��ʼ��
OSPEVENT( MCUVC_WAITHDVIDBASRSP_TIMER,			EV_MCU_BGN + 305 );
//MCU�ȴ�HD˫��������Ӧ��ʱ, ��Ϊ����hd-bas˫�����������1·
OSPEVENT( MCUVC_WAITHDDVIDBASRSP_TIMER,			EV_MCU_BGN + 310 );

//���ǻ������صĲ��ֶ�ʱ
OSPEVENT( TIMER_SCHEDULED_CHECK,                EV_MCU_BGN + 311 );
OSPEVENT( TIMER_DELAYCONF,                      EV_MCU_BGN + 312 );
OSPEVENT( TIMER_RESCHED,                        EV_MCU_BGN + 313 );
OSPEVENT( TIMER_ADDMT,                          EV_MCU_BGN + 314 );
OSPEVENT( TIMER_DELMT,                          EV_MCU_BGN + 315 );
OSPEVENT( TIMER_INVITE_UNJOINEDMT,              EV_MCU_BGN + 316 );
OSPEVENT( TIMER_SCHEDCONF,                      EV_MCU_BGN + 317 );

//���ǻ��飬��ʱˢ��; ���ǻ����ն���·��KeepAlive���ڱ���Ϣ����
OSPEVENT( MCUVC_CONFINFO_MULTICAST_TIMER,		EV_MCU_BGN + 318 );

//����MCU�ڲ�����ʵ��֪ͨHdu�����ɹ�����Ϣ��ΪTPeriEqpRegReq
OSPEVENT( MCU_HDUCONNECTED_NOTIF,		        EV_MCU_BGN + 350 );
//����MCU�ڲ�����ʵ��֪ͨHdu��������Ϣ��ΪTEqp
OSPEVENT( MCU_HDUDISCONNECTED_NOTIF,		    EV_MCU_BGN + 351 );
//mcucfg�ȴ�DSC�޸����ý�����ʱ��ʱ��, zgc, 2007-06-23
OSPEVENT( MCUCFG_DSCCFG_WAITINGCHANGE_OVER_TIMER,	EV_MCU_BGN + 352 );
//��ػỰ֪ͨmcucfg������Ϣ, zgc, 2007-11-09
//��Ϣ�壺��
OSPEVENT( MCSSSN_MCUCFG_MCSDISSCONNNECT_NOTIFY,		EV_MCU_BGN + 353 );

// [11/14/2011 liuxu]���巢��AllMtInfoToAllMcs��timer
OSPEVENT( MCUVC_SENDALLMT_ALLMCS_TIMER,	        EV_MCU_BGN + 354 );

// [11/14/2011 liuxu]���巢��AllMtInfoToAllMcs��timer
OSPEVENT( MCUVC_SEND_SMCUMTSTATUS_TIMER,	    EV_MCU_BGN + 355 );


OSPEVENT( MCUVC_REG_MTMGR_TIMER,				EV_MCU_BGN + 356 );		//Mcu ���������ն˹�����Դ��ʱ

OSPEVENT( MCUVC_CHAIRPOLLING_CHANGE_TIMER,      EV_MCU_BGN + 357 );			//��ϯ��ѯ�ı�ʱ��

OSPEVENT( MCUVC_MMCUSPYPOLLING_CHANGE_TIMER,    EV_MCU_BGN + 358 );			//�ϴ���ѯ�ı�ʱ��

//MCU�����跢FASTUPDATE�Ķ�ʱ���� ��48���ռ� _(+360 ��+408)
//������HDU��Tvwall��Recorder��Mixer��Prs��ֻ����bas/hdbas��vmp/hdvmp��vmptw���ݲ�������ͨ��ID
OSPEVENT( MCUVC_FASTUPDATE_TIMER_ARRAY4EQP,     EV_MCU_BGN + 360 );


/*
*	Special For Satellate MCU
*/
OSPEVENT( MCU_MULTICAST_MSG,				    EV_MCU_BGN + 410 );

OSPEVENT( MCU_MULTICAST_CONFLIST,				EV_MCU_BGN + 411 );

/////////////////////////////////////////////////////////////////////////
//mcu�ڲ���Ϣ
//����ǽ��ͨ����ѯ��ʱ��(��������dec5, hdu)Ԥ��80���ռ�(412 ~ 491)
OSPEVENT(MCUVC_TWPOLLING_CHANGE_TIMER ,		    EV_MCU_BGN + 412 );

//////////////////////////////////////////////////////////////////////////
//  mcuhdu�ڲ���Ϣ
//
//  ֪ͨhdu��ʼ��������
//  ��Ϣ��  THduSwitchInfo
OSPEVENT( MCUVC_STARTSWITCHHDU_NOTIFY,		  EV_MCU_BGN + 492 );
 
///////////////////////////////////////////////////////////
// mcuvcs�ڲ���Ϣ
// �ϼ�MCU�ͷŶ��¼����Ȼ�����Ƶ�Ȩ��      ��Ϣ��:��(��Ϣͷ�к���ָ�������CONFID)
OSPEVENT( MCUVC_VCSSN_MMCURLSCTRL_CMD,	 EV_MCU_BGN + 493 );
// �ϼ�MCU��ʼ�ӹܶԻ���ĵ���Ȩ��          ��Ϣ��:��
OSPEVENT( MCUVC_MMCUGETCTRL_CMD,             EV_MCU_BGN + 494 );

///////////////////////////////////////////////////////////
// ý����Դ�ص���ʱ��
// ��Ƶ����Դ�ϱ���ʱ���timer
OSPEVENT( MCUVC_VIDRES_SAFETIMER,	EV_MCU_BGN + 495 );
// ��Ƶ����Դ�ϱ���ʱ���timer
OSPEVENT( MCUVC_AUDRES_SAFETIMER,	EV_MCU_BGN + 496 );

///////////////////////////////////////////////////////////
//����λ��MCU֮�������������ͨѶ��Ϣ

//������������ģ��������Ϣ
OSPEVENT( MCU_MSEXCHANGER_POWERON_CMD,	EV_MCU_BGN + 500 );

//��λ��MCU����λ��MCU �����Ӷ�ʱ��
OSPEVENT( MCU_MCU_CONNECT_TIMER,		EV_MCU_BGN + 501 );
//��λ��MCU����λ��MCU ��ע�ᶨʱ��
OSPEVENT( MCU_MCU_REGISTER_TIMER,		EV_MCU_BGN + 502 );

//vxworks�¼��������״̬�Ķ�ʱ��
OSPEVENT( MCU_MCU_CEHCK_MSSTATE_TIMER,	EV_MCU_BGN + 503 );

//���ð�MCU���ð�MCU �����ݵ�����ʱ��
OSPEVENT( MCU_MCU_SYN_TIMER,		    EV_MCU_BGN + 504 );

//MCU֮�� �ȴ��Զ˵�����Ӧ�� �ĳ�ʱ��ʱ��
OSPEVENT( MCU_MCU_WAITFORRSP_TIMER,	    EV_MCU_BGN + 505 );

//��MCU��mcu����������
OSPEVENT( MCU_MCU_REBOOT_CMD,	        EV_MCU_BGN + 506 );
//��MCU��mcu��������������
OSPEVENT( MCU_MCU_UPDATE_CMD,	        EV_MCU_BGN + 509 );

//mcuagt��mcu������������mcu������
OSPEVENT( MCUAGT_MCU_REBOOT_CMD,	    EV_MCU_BGN + 507 );

//MCU֮�� ROUNDTRIP��·��� �ĳ�ʱ��ʱ��
OSPEVENT( MCU_MCU_ROUNDTRIP_TIMER,	    EV_MCU_BGN + 508 );

//��λ��MCU����λ��MCU ��ע������ ��Ϣ��: u32 dwLocalIp
OSPEVENT( MCU_MCU_REGISTER_REQ,			EV_MCU_BGN + 511 );
//��λ��MCU����λ��MCU ��ע���������
OSPEVENT( MCU_MCU_REGISTER_ACK,			EV_MCU_BGN + 512 );
//��λ��MCU����λ��MCU ��ע������ܾ�
OSPEVENT( MCU_MCU_REGISTER_NACK,		EV_MCU_BGN + 513 );

//MCU֮�� ֪ͨ �Է� ����MCU������λ���ͼ���ǰ������ʹ��״̬������������Э�� ��Ϣ��: u8 LocalMSType + u8 CurMSState
OSPEVENT( MCU_MCU_MS_DETERMINE,			EV_MCU_BGN + 516 );
//MCU֮�� ֪ͨ �Է� ����MCU��Э�̵�����ʹ�ý�� ��Ϣ��: u8 CurMSState
OSPEVENT( MCU_MCU_MS_RESULT,			EV_MCU_BGN + 517 );

//���ð�MCU���ð�MCU ���� ��ʼ���ݵ��� ��Ϣ��: TMSSynInfoReq
OSPEVENT( MCU_MCU_START_SYN_REQ,		EV_MCU_BGN + 521 );
//���ð�MCU�����ð�MCU ���� ��ʼ���ݵ��� ��Ϣ��: TMSSynInfoRsp
OSPEVENT( MCU_MCU_START_SYN_ACK,		EV_MCU_BGN + 522 );
//��λ��MCU����λ��MCU ������Ϣͬ������ܾ� ��Ϣ��: TMSSynState
OSPEVENT( MCU_MCU_START_SYN_NACK,		EV_MCU_BGN + 523 );
//���ð�MCU���ð�MCU �������ݵ��� ֪ͨ
OSPEVENT( MCU_MCU_END_SYN_NTF,			EV_MCU_BGN + 524 );

//��λ��MCU��λ��MCU ʵ���а���������ݵ��� ͬ�� ���� ��Ϣ��: TMSSynDataReqHead
OSPEVENT( MCU_MCU_SYNNING_DATA_REQ,		EV_MCU_BGN + 526 );
//��λ��MCU����λ��MCU ʵ���а���������ݵ��� ͬ�� ��Ӧ ��Ϣ��: TMSSynDataRsp
OSPEVENT( MCU_MCU_SYNNING_DATA_RSP,		EV_MCU_BGN + 527 );

//���ð�����Ϊ���ð�ʱ ֪ͨҵ��͸����Ựģ��������״̬�������Ϣ��: u8�Ƿ��л��ɹ�
OSPEVENT( MCU_MSSTATE_EXCHANGE_NTF,		EV_MCU_BGN + 531 );

//����̽����Ϣ
OSPEVENT( MCU_MCU_PROBE_REQ,            EV_MCU_BGN + 532 );
OSPEVENT( MCU_MCU_PROBE_ACK,            EV_MCU_BGN + 533 );  
OSPEVENT( MCU_MCU_PROBE_NACK,            EV_MCU_BGN + 534 ); 

//��mcu����mcu��LED���Ե�notify����Ϣ�壺TBrdLedState
OSPEVENT( MCU_MCU_LEDSTATUS_NOTIFY,	    EV_MCU_BGN + 535 );

OSPEVENT( EV_MCU_OPENSECVID_TIMER,		EV_MCU_BGN + 536 );//Ŀǰֻ���polycom

//����ϳɵ�ͨ����ѯ��ʱ����Ԥ��30����Ϣ�ţ�537--566���ܹ�̣�2014-11-24
OSPEVENT( MCUVC_VMPSINGLECHNPOLL_TIMER_START, EV_MCU_BGN + 537 );
OSPEVENT( MCUVC_VMPSINGLECHNPOLL_TIMER_END,   EV_MCU_BGN + 566 );

//����֧�ֶ�vmp��vmp���Timer����Ϊ16�ݣ�Ԥ��32��(608-639)
//����MCUVC_VMP_WAITVMPRSP_TIMER��MCUVC_WAIT_ALLVMPPRESETIN_ACK_TIMER
OSPEVENT( MCUVC_VMP_WAITVMPRSP_TIMER,        EV_MCU_BGN + 608 );
OSPEVENT( MCUVC_WAIT_ALLVMPPRESETIN_ACK_TIMER,  EV_MCU_BGN + 624 );

//MCUע��NU���Ӷ�ʱ��
OSPEVENT( MTADPSSN_CONNECTNU_TIMER,			EV_MCU_BGN + 630 );
//MCUע��NUע�ᶨʱ��
OSPEVENT( MTADPSSN_REGISTNU_TIMER,			EV_MCU_BGN + 631 );

//N+1ģʽ MCU�ڲ���Ϣ
OSPEVENT( NPLUS_VC_DATAUPDATE_NOTIF,        EV_MCU_BGN + 640 );
//mcuҵ�񷢸���mcu���ݹ���ģ����Ϣ
OSPEVENT( VC_NPLUS_MSG_NOTIF,               EV_MCU_BGN + 641 );
//֪ͨN+1���ݷ��������ã�ֹͣ���ݷ��񣬵����Ͽ����ӵĿͻ���
OSPEVENT( VC_NPLUS_RESET_NOTIF,             EV_MCU_BGN + 642 );

//N+1ģʽ mcu����Ϣ
//���Ӷ�ʱ��
OSPEVENT( MCU_NPLUS_CONNECT_TIMER,          EV_MCU_BGN + 650 );

//ע�ᶨʱ��
OSPEVENT( MCU_NPLUS_REG_TIMER,              EV_MCU_BGN + 651 );

//��·��ⳬʱ��ʱ��
OSPEVENT( MCU_NPLUS_RTD_TIMER,              EV_MCU_BGN + 652 );

//ע����Ϣ����Ϣ�壺TCMcuRegInfo
OSPEVENT( MCU_NPLUS_REG_REQ,                EV_MCU_BGN + 700 );
OSPEVENT( MCU_NPLUS_REG_ACK,                EV_MCU_BGN + 701 );
OSPEVENT( MCU_NPLUS_REG_NACK,               EV_MCU_BGN + 702 );

//��·�����Ϣ����Ϣ�壺��
OSPEVENT( MCU_NPLUS_RTD_REQ,                EV_MCU_BGN + 703 );
OSPEVENT( MCU_NPLUS_RTD_RSP,                EV_MCU_BGN + 704 );

//mcu������Ϣ֪ͨ��Ϣ������/��������ʱ֪ͨ������Ϣ�壺u8(NPLUS_CONF_START, NPLUS_CONF_RELEASE)+TConfInfo
OSPEVENT( MCU_NPLUS_CONFINFOUPDATE_REQ,     EV_MCU_BGN + 705 );
OSPEVENT( MCU_NPLUS_CONFINFOUPDATE_ACK,     EV_MCU_BGN + 706 );
OSPEVENT( MCU_NPLUS_CONFINFOUPDATE_NACK,    EV_MCU_BGN + 707 );

//mcu�û�����Ϣ֪ͨ��Ϣ ��ע��ɹ����û�����Ϣ�仯ʱ�����ع�ʱ֪ͨ������Ϣ�壺CUsrGrpsInfo
OSPEVENT( MCU_NPLUS_USRGRPUPDATE_REQ,         EV_MCU_BGN + 708 );
OSPEVENT( MCU_NPLUS_USRGRPUPDATE_ACK,         EV_MCU_BGN + 709 );
OSPEVENT( MCU_NPLUS_USRGRPUPDATE_NACK,        EV_MCU_BGN + 710 );

//����ն���Ϣ֪ͨ������ն��б仯ʱ֪ͨ������Ϣ�壺TMtInfo[]
OSPEVENT( MCU_NPLUS_CONFMTUPDATE_REQ,       EV_MCU_BGN + 711 );
OSPEVENT( MCU_NPLUS_CONFMTUPDATE_ACK,       EV_MCU_BGN + 712 );
OSPEVENT( MCU_NPLUS_CONFMTUPDATE_NACK,      EV_MCU_BGN + 713 );

//��ϯ�ն�֪ͨ����Ϣ�壺TMtAlias
OSPEVENT( MCU_NPLUS_CHAIRUPDATE_REQ,        EV_MCU_BGN + 714 );
OSPEVENT( MCU_NPLUS_CHAIRUPDATE_ACK,        EV_MCU_BGN + 715 );
OSPEVENT( MCU_NPLUS_CHAIRUPDATE_NACK,       EV_MCU_BGN + 716 );

//�����ն�֪ͨ����Ϣ�壺TMtAlias
OSPEVENT( MCU_NPLUS_SPEAKERUPDATE_REQ,      EV_MCU_BGN + 717 );
OSPEVENT( MCU_NPLUS_SPEAKERUPDATE_ACK,      EV_MCU_BGN + 718 );
OSPEVENT( MCU_NPLUS_SPEAKERUPDATE_NACK,     EV_MCU_BGN + 719 );

//VMP����Ϣ�壺TNPlusVmpInfo+TVMPParam
OSPEVENT( MCU_NPLUS_VMPUPDATE_REQ,          EV_MCU_BGN + 720 );
OSPEVENT( MCU_NPLUS_VMPUPDATE_ACK,          EV_MCU_BGN + 721 );
OSPEVENT( MCU_NPLUS_VMPUPDATE_NACK,         EV_MCU_BGN + 722 );

//ConfData֪ͨ��Ϣ��ע��ɹ�ʱ�����ع�ʱ֪ͨ������Ϣ�壺TNPlusConfData + N�ֽ���չ����+MAXNUM_SUB_MCU*TSmcuCallInfo
OSPEVENT( MCU_NPLUS_CONFDATAUPDATE_REQ,       EV_MCU_BGN + 723 );
OSPEVENT( MCU_NPLUS_CONFDATAUPDATE_ACK,       EV_MCU_BGN + 724 );
OSPEVENT( MCU_NPLUS_CONFDATAUPDATE_NACK,      EV_MCU_BGN + 725 );

//�û���Ϣ֪ͨ��Ϣ��ע��ɹ�ʱ�����ع�ʱ֪ͨ������Ϣ�壺CExUsrInfo[]����Ҫ�����а�
OSPEVENT( MCU_NPLUS_USRINFOUPDATE_REQ,        EV_MCU_BGN + 726 );
OSPEVENT( MCU_NPLUS_USRINFOUPDATE_ACK,        EV_MCU_BGN + 727 );
OSPEVENT( MCU_NPLUS_USRINFOUPDATE_NACK,       EV_MCU_BGN + 728 );

//������Ϣ�ع�
OSPEVENT( MCU_NPLUS_CONFROLLBACK_REQ,        EV_MCU_BGN + 729 );
OSPEVENT( MCU_NPLUS_CONFROLLBACK_ACK,        EV_MCU_BGN + 730 );
OSPEVENT( MCU_NPLUS_CONFROLLBACK_NACK,       EV_MCU_BGN + 731 );

//�û���Ϣ�ع�
OSPEVENT( MCU_NPLUS_USRROLLBACK_REQ,        EV_MCU_BGN + 732 );
OSPEVENT( MCU_NPLUS_USRROLLBACK_ACK,        EV_MCU_BGN + 733 );
OSPEVENT( MCU_NPLUS_USRROLLBACK_NACK,       EV_MCU_BGN + 734 );

//�û�����Ϣ�ع�
OSPEVENT( MCU_NPLUS_GRPROLLBACK_REQ,        EV_MCU_BGN + 735 );
OSPEVENT( MCU_NPLUS_GRPROLLBACK_ACK,        EV_MCU_BGN + 736 );
OSPEVENT( MCU_NPLUS_GRPROLLBACK_NACK,       EV_MCU_BGN + 737 );

//GKʵ��ע��֪ͨ��Ϣ����Ϣ�壺TRASInfo
OSPEVENT( MCU_NPLUS_RASINFOUPDATE_REQ,      EV_MCU_BGN + 738 );
OSPEVENT( MCU_NPLUS_RASINFOUPDATE_ACK,      EV_MCU_BGN + 739 );
OSPEVENT( MCU_NPLUS_RASINFOUPDATE_NACK,     EV_MCU_BGN + 740 );

//AutoMix����Ϣ�壺BOOL32
OSPEVENT( MCU_NPLUS_AUTOMIXUPDATE_REQ,          EV_MCU_BGN + 741 );
OSPEVENT( MCU_NPLUS_AUTOMIXUPDATE_ACK,          EV_MCU_BGN + 742 );
OSPEVENT( MCU_NPLUS_AUTOMIXUPDATE_NACK,         EV_MCU_BGN + 743 );

//ͬ���¼�MCU������Ϣ ��Ϣ�壺TSmcuCallInfo[]����
OSPEVENT( MCU_NPLUS_SMCUINFOUPDATE_REQ,         EV_MCU_BGN + 744 );
OSPEVENT( MCU_NPLUS_SMCUINFOUPDATE_ACK,			EV_MCU_BGN + 745 );
OSPEVENT( MCU_NPLUS_SMCUINFOUPDATE_NACK,		EV_MCU_BGN + 746 );

//�����������֪ͨ����Ϣ�壺TNPlusEqpCap
OSPEVENT( MCU_NPLUS_EQPCAP_NOTIF,           EV_MCU_BGN + 750 );

//MCU����VCS���͵ķ�����Ϣ��ʱ�� ��MAXNUM_MCU_CONF+MAXNUM_MCU_TEMPLATE(128�� +800 -- +927)
OSPEVENT( MCUVC_PACKINFO_TIMER,             EV_MCU_BGN + 800);

// [1/7/2011 xliang] ����Ϣ�������Ͷ�ʱ
OSPEVENT( MCUVC_SMSPACK_TIMER,				EV_MCU_BGN + 950);

// [pengjie 2011/5/18]��Ϣ951~953�����������Ѿ���ռ�ã����ǵ����ܺϲ������⣬���ｫ��Ԥ��

// [pengjie 2011/5/19] ��vcsssn��ͨinstan����daemon�Ŀ�����ʱ�����Ϣ��Ϊ u8 byTimeIdx ��ʱ��Id
OSPEVENT( MCUVC_STARTRELEASECONFTIMER_CMD,			EV_MCU_BGN + 954);
// [pengjie 2011/5/18] vcs�����ӳٽ�ᶨʱ������Ҫռ��16��timer( 955 ~ 971 )
OSPEVENT( MCUVC_RELEASECONF_TIMER,			EV_MCU_BGN + 955);

// END (EV_MCU_BGN + 971)
//�ն�����H239token�ȴ���˫��ͨ����ʱ��
OSPEVENT( MCUVC_WAITOPENDSCHAN_TIMER,           EV_MCU_BGN + 972 );
//��������ϳɳ�Ա����ı�����еĳ�Ա��Ϊ�¼��նˣ�������ش���������16��
//OSPEVENT( MCUVC_WAIT_ALLVMPPRESETIN_ACK_TIMER,			    EV_MCU_BGN + 973 );
//����������������������Ҫ�ָ��������Ҫ������ͬ������
OSPEVENT( MCUVC_RECOVERCONF_SYN_TIMER,           EV_MCU_BGN + 974 );
//��ش��������뱻������ģʽ�£����¼��ն˵�ʱ����Ҫ�ȴ��¼��ն˻�ack����Ϊ���Ե��¸��ն�
OSPEVENT( MCUVC_WAIT_LASTVMPROLLCALLFINISH_TIMER,           EV_MCU_BGN + 975 );
//�������ݻ������ݵ�ʱ�򣬸�instance���ã�ongoing��schedule��״̬����ȴ���������timer
OSPEVENT( MCUVC_WAITMSCONFDATA_TIMER,           EV_MCU_BGN + 976 );

//zyq50
OSPEVENT( MCUVC_OCCUPYMP_CMD, EV_MCU_BGN + 977  );
OSPEVENT( MCUVC_APPLYMPSUC_NTF, EV_MCU_BGN + 978  );
OSPEVENT( MCUVC_MPDISCONNECT_NTF, EV_MCU_BGN + 979  );

//mcu����Դ�ض�ʱ��
OSPEVENT( MCURESPOOL_CONNZK_TIMER, EV_MCU_BGN + 980  );

//�Զ���ᶨʱ��
//���ն��Զ���ᶨʱ��-1min
OSPEVENT( MCUVC_RELEASECONFNOMT_TIMER,          EV_MCU_BGN + 981 );
//�������ն��Զ���ᶨʱ��-5min
OSPEVENT( MCUVC_RELEASECONFNOJOINEDMT_TIMER,    EV_MCU_BGN + 982 );
//�����ն˽�һ�����Զ���ᶨʱ��-10min
OSPEVENT( MCUVC_RELEASECONFONLYONEMT_TIMER,     EV_MCU_BGN + 983 );

OSPEVENT( MCURESPOOL_UPDATEZKSTATUS_TIMER,		EV_MCU_BGN + 984  );

//��ش������ͷų�ʱ�Ķ���timer
OSPEVENT( MCUVC_RELEASETIMEOUTSPY_TIMER,		EV_MCU_BGN + 985 );
///////////////////////////////////////////////////////////

/********** wy[2014/09/22]����MAU��MCU��������(29001-29900)---�����ն��ڲ�ҵ����Ϣ bgn *******/

//MAU��MCU��������
OSPEVENT( MAU_MCU_CONNECT_REQ,                  EV_MCU_BGN + 1000 );
OSPEVENT( MCU_MAU_CONNECT_ACK,                  EV_MCU_BGN + 1001 );
OSPEVENT( MCU_MAU_CONNECT_NACK,                 EV_MCU_BGN + 1002 );

// ��������
//��Ϣ��: TReqHeadInfo+TConfInfo + 2 byte(������,TMtAlias����������,�������n)
//                  + n byte(TMtAlias������,ÿ��Ϊ 1byte(����)+1byte(����)+xbyte(�ַ���)+2byte(��������) 
//                            ��1�ֽ�ΪTMtAlias����,��2�ֽ�Ϊ����x,�����x�ֽ�ΪTMtAlias����)
//                  + TTvWallModule(��ѡ�ֶΣ��ɻ��������е��Ƿ��е���ǽģ�����) 
//                  + TVmpModule(��ѡ�ֶΣ��ɻ��������е��Ƿ��л���ϳ�ǽģ�����)  
//					+ TPollModule
//					+ TMixModule 
//                  + 2 byte(������,�������n)
//                  + n*TMTAlias
OSPEVENT( MAU_MCU_CREATECONF_REQ,               EV_MCU_BGN + 1003 );
OSPEVENT( MCU_MAU_CREATECONF_ACK,               EV_MCU_BGN + 1004 );
OSPEVENT( MCU_MAU_CREATECONF_NACK,              EV_MCU_BGN + 1005 );

//MAU����MCU����նˣ���Ϣ��: TReqHeadInfo+TMcu+byAddMtNum(u8)+TAddMtInfo
OSPEVENT( MAU_MCU_ADDMT_REQ,				    EV_MCU_BGN + 1006 );
OSPEVENT( MCU_MAU_ADDMT_ACK,				    EV_MCU_BGN + 1007 );
OSPEVENT( MCU_MAU_ADDMT_NACK,				    EV_MCU_BGN + 1008 );

//CM����MCU����նˣ���Ϣ��: TReqHeadInfo+TMcu+byAddMtNum(u8)+TAddMtInfo*byAddMtNum
OSPEVENT( CM_MCU_ADDMT_REQ,				        EV_MCU_BGN + 1009 );
OSPEVENT( MCU_CM_ADDMT_ACK,				        EV_MCU_BGN + 1010 );
OSPEVENT( MCU_CM_ADDMT_NACK,				    EV_MCU_BGN + 1011 );

//CM����MCUɾ���նˣ���Ϣ��: TReqHeadInfo+wMtNum(u16)+TMt*wMtNum
OSPEVENT( CM_MCU_DELMT_REQ,                     EV_MCU_BGN + 1012 );
OSPEVENT( MCU_CM_DELMT_ACK,                     EV_MCU_BGN + 1013 );
OSPEVENT( MCU_CM_DELMT_NACK,                    EV_MCU_BGN + 1014 );

//CM����MCU�����նˣ���Ϣ��: TReqHeadInfo+wMtNum(u16)+TMt*wMtNum
OSPEVENT( CM_MCU_CALLMT_REQ,				    EV_MCU_BGN + 1015 );
OSPEVENT( MCU_CM_CALLMT_ACK,				    EV_MCU_BGN + 1016 );
OSPEVENT( MCU_CM_CALLMT_NACK,				    EV_MCU_BGN + 1017 );

//CM����MCU�Ҷ��նˣ���Ϣ��: TReqHeadInfo+wMtNum(u16)+TMt*wMtNum
OSPEVENT( CM_MCU_DROPMT_REQ,				    EV_MCU_BGN + 1018 );
OSPEVENT( MCU_CM_DROPMT_ACK,				    EV_MCU_BGN + 1019 );
OSPEVENT( MCU_CM_DROPMT_NACK,				    EV_MCU_BGN + 1020 );

//MAU����MCU�������飬��Ϣ��: TReqHeadInfo
OSPEVENT( MAU_MCU_RELEASECONF_CMD,			    EV_MCU_BGN + 1021 );

//MCU�������֪ͨ
OSPEVENT( MCU_MAU_RELEASECONF_NTF,			    EV_MCU_BGN + 1022 );

//�ն��б�֪ͨ
//��Ϣ�壺u8*16(����e164)+u8*64(��������)+u8(�ն�����)+[ TJsonMtIdentify+TJsonMtDesc+u16(CallBitrate, ������)+u8(IsOnline)+
//		  u32(����Ƶ����ͨ��������������)+[TMtMgrVidSndChnStatus]+
//		  u32(����Ƶ����ͨ��������������)+[TMtMgrVidRcvChnStatus]+
//		  u32(˫����Ƶ����ͨ��������������)+[TMtMgrDVidSndChnStatus]+
//		  u32(˫����Ƶ����ͨ��������������)+[TMtMgrDVidRcvChnStatus]+
//		  u32(��Ƶ����ͨ��������������)+[TMtMgrAudSndChnStatus+u8(�Ƿ�����)]+
//		  u32(��Ƶ����ͨ��������������)+[TMtMgrAudRcvChnStatus+u8(�Ƿ���)] 
//        ]
OSPEVENT( MCU_CM_MTLIST_NTF,                    EV_MCU_BGN + 1023 );

//�᳡��������Ϣ��: TReqHeadInfo+��ͣ��ʾ(u8��1-���� 0-ȡ��)+��/������ʾ(u8��1-���� 0-����)
OSPEVENT( CM_MCU_CONFMUTE_REQ,                  EV_MCU_BGN + 1024 );
OSPEVENT( MCU_CM_CONFMUTE_ACK,                  EV_MCU_BGN + 1025 );
OSPEVENT( MCU_CM_CONFMUTE_NACK,                 EV_MCU_BGN + 1026 );

//�᳡��������Ϣ��: TReqHeadInfo+��ͣ��ʾ(u8��1-���� 0-ȡ��)+��/������ʾ(u8��1-���� 0-����)
OSPEVENT( CM_MCU_CONFSILENCE_REQ,               EV_MCU_BGN + 1027 );
OSPEVENT( MCU_CM_CONFSILENCE_ACK,               EV_MCU_BGN + 1028 );
OSPEVENT( MCU_CM_CONFSILENCE_NACK,              EV_MCU_BGN + 1029 );

//ȡ���᳡��������Ϣ��: TReqHeadInfo+��ͣ��ʾ(u8��1-���� 0-ȡ��)+��/������ʾ(u8��1-���� 0-����)
OSPEVENT( CM_MCU_CANCELCONFMUTE_REQ,            EV_MCU_BGN + 1030 );
OSPEVENT( MCU_CM_CANCELCONFMUTE_ACK,            EV_MCU_BGN + 1031 );
OSPEVENT( MCU_CM_CANCELCONFMUTE_NACK,           EV_MCU_BGN + 1032 );

//ȡ���᳡��������Ϣ��: TReqHeadInfo+��ͣ��ʾ(u8��1-���� 0-ȡ��)+��/������ʾ(u8��1-���� 0-����)
OSPEVENT( CM_MCU_CANCELCONFSILENCE_REQ,         EV_MCU_BGN + 1033 );
OSPEVENT( MCU_CM_CANCELCONFSILENCE_ACK,         EV_MCU_BGN + 1034 );
OSPEVENT( MCU_CM_CANCELCONFSILENCE_NACK,        EV_MCU_BGN + 1035);

// �ӳ����飬��Ϣ��: TReqHeadInfo+wDelay(u16)
OSPEVENT( CM_MCU_DELAYCONF_REQ,                 EV_MCU_BGN + 1036 );
OSPEVENT( MCU_CM_DELAYCONF_ACK,                 EV_MCU_BGN + 1037 );
OSPEVENT( MCU_CM_DELAYCONF_NACK,                EV_MCU_BGN + 1038 );

// ��ʼ��ѯ����Ϣ��: TPollInfo+TMtPollParam*wMtNum(u16)
OSPEVENT( CM_MCU_STARTPOLL_CMD,                 EV_MCU_BGN + 1039 );

// ֹͣ��ѯ
OSPEVENT( CM_MCU_STOPPOLL_CMD,                  EV_MCU_BGN + 1040 );

// ��ͣ��ѯ
OSPEVENT( CM_MCU_PAUSEPOLL_CMD,                 EV_MCU_BGN + 1041 );

// ������ѯ
OSPEVENT( CM_MCU_RESUMEPOLL_CMD,                EV_MCU_BGN + 1042 );

// ָ����ѯλ�ã���Ϣ��: TReqHeadInfo+TMt
OSPEVENT( CM_MCU_SPECPOLLPOS_REQ,               EV_MCU_BGN + 1043 );
OSPEVENT( MCU_CM_SPECPOLLPOS_ACK,               EV_MCU_BGN + 1044 );
OSPEVENT( MCU_CM_SPECPOLLPOS_NACK,              EV_MCU_BGN + 1045 );

// �޸���ѯ��������Ϣ��: TPollInfo+TMtPollParam*wMtNum(u16)
OSPEVENT( CM_CMU_CHANGEPOLLPARAM_CMD,           EV_MCU_BGN + 1046);

// �����ն˾�������Ϣ��: TReqHeadInfo+TMt+��ͣ��ʾ(u8��1-���� 0-ȡ��)+��/������ʾ(u8��1-���� 0-����)
OSPEVENT( CM_MCU_MTSILENCE_REQ,                 EV_MCU_BGN + 1047 );
OSPEVENT( MCU_CM_MTSILENCE_ACK,                 EV_MCU_BGN + 1048 );
OSPEVENT( MCU_CM_MTSILENCE_NACK,                EV_MCU_BGN + 1049 );

// ȡ���ն˾�������Ϣ��: TReqHeadInfo+TMt+��ͣ��ʾ(u8��1-���� 0-ȡ��)+��/������ʾ(u8��1-���� 0-����)
OSPEVENT( CM_MCU_CANCELMTSILENCE_REQ,           EV_MCU_BGN + 1050 );
OSPEVENT( MCU_CM_CANCELMTSILENCE_ACK,           EV_MCU_BGN + 1051 );
OSPEVENT( MCU_CM_CANCELMTSILENCE_NACK,          EV_MCU_BGN + 1052 );

// �����ն���������Ϣ��: TReqHeadInfo+TMt+��ͣ��ʾ(u8��1-���� 0-ȡ��)+��/������ʾ(u8��1-���� 0-����)
OSPEVENT( CM_MCU_MTMUTE_REQ,                    EV_MCU_BGN + 1053 );
OSPEVENT( MCU_CM_MTMUTE_ACK,                    EV_MCU_BGN + 1054 );
OSPEVENT( MCU_CM_MTMUTE_NACK,                   EV_MCU_BGN + 1055 );

// ȡ���ն���������Ϣ��: TReqHeadInfo+TMt+��ͣ��ʾ(u8��1-���� 0-ȡ��)+��/������ʾ(u8��1-���� 0-����)
OSPEVENT( CM_MCU_CANCELMTMUTE_REQ,              EV_MCU_BGN + 1056 );
OSPEVENT( MCU_CM_CANCELMTMUTE_ACK,              EV_MCU_BGN + 1057 );
OSPEVENT( MCU_CM_CANCELMTMUTE_NACK,             EV_MCU_BGN + 1058 );

// ���û��鰲ȫ����Ϣ��: TReqHeadInfo+ConfPwd(len:32)+OpenMode(u8)
OSPEVENT( CM_MCU_SETCONFSAFE_REQ,               EV_MCU_BGN + 1059 );
OSPEVENT( MCU_CM_SETCONFSAFE_ACK,               EV_MCU_BGN + 1060 );
OSPEVENT( MCU_CM_SETCONFSAFE_NACK,              EV_MCU_BGN + 1061 );

// ������ϯ����Ϣ��: TReqHeadInfo+TMt
OSPEVENT( CM_MCU_SETCHAIRMAN_REQ,               EV_MCU_BGN + 1062 );
OSPEVENT( MCU_CM_SETCHAIRMAN_ACK,               EV_MCU_BGN + 1063 );
OSPEVENT( MCU_CM_SETCHAIRMAN_NACK,              EV_MCU_BGN + 1064 );

// ȡ����ϯ����Ϣ��: TReqHeadInfo
OSPEVENT( CM_MCU_CANCELCHAIRMAN_REQ,            EV_MCU_BGN + 1065 );
OSPEVENT( MCU_CM_CANCELCHAIRMAN_ACK,            EV_MCU_BGN + 1066 );
OSPEVENT( MCU_CM_CANCELCHAIRMAN_NACK,           EV_MCU_BGN + 1067 );

// ���÷����ˣ���Ϣ��: TReqHeadInfo+TMt
OSPEVENT( CM_MCU_SETSPEAKER_REQ,                EV_MCU_BGN + 1068 );
OSPEVENT( MCU_CM_SETSPEAKER_ACK,                EV_MCU_BGN + 1069 );
OSPEVENT( MCU_CM_SETSPEAKER_NACK,               EV_MCU_BGN + 1070 );

// ȡ�������ˣ���Ϣ��: TReqHeadInfo
OSPEVENT( CM_MCU_CANCELSPEAKER_REQ,             EV_MCU_BGN + 1071 );
OSPEVENT( MCU_CM_CANCELSPEAKER_ACK,             EV_MCU_BGN + 1072 );
OSPEVENT( MCU_CM_CANCELSPEAKER_NACK,            EV_MCU_BGN + 1073 );

// ����ǿ�ƹ㲥����Ϣ��: TReqHeadInfo+byForceBrd(u8)
OSPEVENT( CM_MCU_FORCEBRD_CMD,                  EV_MCU_BGN + 1074 );
// ǿ�ƹ㲥֪ͨ����Ϣ�壺byForceBrd(u8)
OSPEVENT( MCU_CM_FORCEBRD_NTF,					EV_MCU_BGN + 1075 );

// �ն�ѡ������Ϣ��: TReqHeadInfo+TSwitchInfo
OSPEVENT( CM_MCU_STARTSEEMT_REQ,                EV_MCU_BGN + 1077 );
OSPEVENT( MCU_CM_STARTSEEMT_ACK,                EV_MCU_BGN + 1078 );
OSPEVENT( MCU_CM_STARTSEEMT_NACK,               EV_MCU_BGN + 1079 );

// ֹͣ�ն�ѡ������Ϣ��: TReqHeadInfo+TSwitchInfo
OSPEVENT( CM_MCU_STOPSEEMT_REQ,                 EV_MCU_BGN + 1080 );
OSPEVENT( MCU_CM_STOPSEEMT_ACK,                 EV_MCU_BGN + 1081 );
OSPEVENT( MCU_CM_STOPSEEMT_NACK,                EV_MCU_BGN + 1082 );

// ����ȫ�������նˣ���Ϣ��: TReqHeadInfo+wMtNum(u16) ��VC����CM_MCU_CALLLEFTMT_REQ��wMtNumΪ0
OSPEVENT( CM_MCU_CALLLEFTMT_REQ,                EV_MCU_BGN + 1083 );
OSPEVENT( MCU_CM_CALLLEFTMT_ACK,                EV_MCU_BGN + 1084 );
OSPEVENT( MCU_CM_CALLLEFTMT_NACK,               EV_MCU_BGN + 1085 );


//����������Ϣ֪ͨ
OSPEVENT( MCU_CM_CONFINFO_NOTIF,                EV_MCU_BGN + 1086 );

//��MAU�������
OSPEVENT( MAUSSN_HEADBEAR_TIMER,                EV_MCU_BGN + 1087 );

//MAU�������������Ϣ����Ϣ��: TReqHeadInfo
OSPEVENT( MAU_MCU_CONFINFO_REQ,                 EV_MCU_BGN + 1088 );
OSPEVENT( MCU_MAU_CONFINFO_ACK,                 EV_MCU_BGN + 1089 );
OSPEVENT( MCU_MAU_CONFINFO_NACK,                EV_MCU_BGN + 1090 );

//��ѯ����֪ͨ
OSPEVENT( MCU_CM_POLLPARAM_NTF,                 EV_MCU_BGN + 1091 );

//���鰲ȫ��Ϣ֪ͨ
OSPEVENT( MCU_CM_CONFSAGEINFO_NTF,              EV_MCU_BGN + 1092 );

//�������ʱ��֪ͨ
OSPEVENT( MCU_CM_CONFDURATION_NTF,              EV_MCU_BGN + 1093 );

//�ն������Ϊ������֪ͨ
OSPEVENT( MCU_CM_APPLYSPEAKER_NTF,				EV_MCU_BGN + 1094 );

//�ն������Ϊ��ϯ֪ͨ
OSPEVENT( MCU_CM_APPLYCHAIRMAN_NTF,				EV_MCU_BGN + 1095 );

//�ն����֪ͨ
OSPEVENT( MCU_CM_DELMT_NTF,						EV_MCU_BGN + 1096 );

//�ӳ���������(�ն˻���)
OSPEVENT( MCU_MAU_DELAYCONF_REQ,				EV_MCU_BGN + 1097 );
OSPEVENT( MAU_MCU_DELAYCONF_ACK,				EV_MCU_BGN + 1098 );
OSPEVENT( MAU_MCU_DELAYCONF_NACK,				EV_MCU_BGN + 1099 );

//mcuͬ�����黺����Ϣ��mau
OSPEVENT( MCU_MAU_CONFSYN_NTF,					EV_MCU_BGN + 1100 );

//CM�����������cmd
OSPEVENT( CM_CMU_CONFDETAIL_CMD,				EV_MCU_BGN + 1101 );

//�������Ϣ֪ͨ��ע������֪ͨ��ܣ�Я��TBasicConfInfo���������ô���Ϣ�����Զ���ṹ��XStruct��buf:TBasicConfInfo+XStruct
OSPEVENT( MCU_CM_SIMCONFINFO_NTF,               EV_MCU_BGN + 1102 );

//CM����������ϳɣ���Ϣ�壺TReqHeadInfo+TVMPParam+u8+[TVmpChnPollParam...]
OSPEVENT( CM_MCU_STARTVMP_REQ,				    EV_MCU_BGN + 1103 );
//CM��������ϳɳɹ���Ӧ����Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_STARTVMP_ACK,				    EV_MCU_BGN + 1104 );
//CM��������ϳ�ʧ�ܻ�Ӧ����Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_STARTVMP_NACK,				    EV_MCU_BGN + 1105 );

//CM����ֹͣ����ϳɣ���Ϣ�壺TReqHeadInfo
OSPEVENT( CM_MCU_STOPVMP_REQ,				    EV_MCU_BGN + 1106 );
//CMֹͣ����ϳɳɹ���Ӧ����Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_STOPVMP_ACK,				    EV_MCU_BGN + 1107 );
//CMֹͣ����ϳ�ʧ�ܻ�Ӧ����Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_STOPVMP_NACK,				    EV_MCU_BGN + 1108 );

//CM�����޸Ļ���ϳɲ�������Ϣ�壺TVMPParam+u8+[TVmpChnPollParam...]
OSPEVENT( CM_MCU_CHANGEVMPPARAM_REQ,			EV_MCU_BGN + 1109 );
//CM�޸Ļ���ϳɳɹ���Ӧ����Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_CHANGEVMPPARAM_ACK,			EV_MCU_BGN + 1110 );
//CM�޸Ļ���ϳ�ʧ�ܻ�Ӧ����Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_CHANGEVMPPARAM_NACK,			EV_MCU_BGN + 1111 );

//����ϳɲ���֪ͨ����Ϣ�壺TJsonVMPParam
OSPEVENT( MCU_CM_VMPPARAM_NTF,                  EV_MCU_BGN + 1112 );

//CM�������ն���������ϳ�
//��Ϣ�壺TMtIdentifyToCM(Ŀ���ն�)+MtChnId+TVMPParam (VmpModeΪCONF_VMPMODE_AUTOʱ����Ҫ��д)
OSPEVENT( CM_MCU_STARTMTVMP_REQ,				    EV_MCU_BGN + 1113 );
//CM��������ϳɳɹ���Ӧ����Ϣ�壺TMtIdentifyToCM(Ŀ���ն�)
OSPEVENT( MCU_CM_STARTMTVMP_ACK,				    EV_MCU_BGN + 1114 );
//CM��������ϳ�ʧ�ܻ�Ӧ����Ϣ�壺TMtIdentifyToCM(Ŀ���ն�)
OSPEVENT( MCU_CM_STARTMTVMP_NACK,				    EV_MCU_BGN + 1115 );

//CM����ֹͣ�ն���������ϳɣ���Ϣ�壺TMtIdentifyToCM(Ŀ���ն�)
OSPEVENT( CM_MCU_STOPMTVMP_REQ,				    EV_MCU_BGN + 1116 );
//CMֹͣ����ϳɳɹ���Ӧ����Ϣ�壺TMt(Ŀ���ն�)
OSPEVENT( MCU_CM_STOPMTVMP_ACK,				    EV_MCU_BGN + 1117 );
//CMֹͣ����ϳ�ʧ�ܻ�Ӧ����Ϣ�壺TMt(Ŀ���ն�)
OSPEVENT( MCU_CM_STOPMTVMP_NACK,				    EV_MCU_BGN + 1118 );

//CM�����޸��ն���������ϳɲ���
//��Ϣ�壺TMtIdentifyToCM(Ŀ���ն�)0+u8 MtChn +TVMPParam (VmpModeΪCONF_VMPMODE_AUTOʱ����Ҫ��д)
OSPEVENT( CM_MCU_CHANGEMTVMPPARAM_REQ,				    EV_MCU_BGN + 1119 );
//CM��������ϳɳɹ���Ӧ����Ϣ�壺TMtIdentifyToCM(Ŀ���ն�)
OSPEVENT( MCU_CM_CHANGEMTVMPPARAM_ACK,				    EV_MCU_BGN + 1120 );
//CM��������ϳ�ʧ�ܻ�Ӧ����Ϣ�壺TMtIdentifyToCM(Ŀ���ն�)
OSPEVENT( MCU_CM_CHANGEMTVMPPARAM_NACK,				    EV_MCU_BGN + 1121 );

//�ն������ϳɲ���֪ͨ����Ϣ�壺TMtIdentifyToCM(Ŀ���ն�)+u8 MtChn+TVMPParamToCM
OSPEVENT( MCU_CM_MTVMPPARAM_NTF,						EV_MCU_BGN + 1122 );

// Vip�б���Ϣ add by mxm
// ����Vip�б�	��Ϣ�壺TReqHeadInfo+TMt*n
OSPEVENT( CM_MCU_SETVIPLIST_REQ,				EV_MCU_BGN + 1123 );
OSPEVENT( MCU_CM_SETVIPLIST_ACK,				EV_MCU_BGN + 1124 );
OSPEVENT( MCU_CM_SETVIPLIST_NACK,				EV_MCU_BGN + 1125 );
//Vip�б�֪ͨ	��Ϣ�壺TMt*n
OSPEVENT( MCU_CM_VIPLIST_NTF,					EV_MCU_BGN + 1126 );

// ��ȡVip�б�
OSPEVENT( CM_MCU_GETVIPLIST_REQ,			    EV_MCU_BGN + 1127 );
//��Ϣ�壺TMt*n
OSPEVENT( MCU_CM_GETVIPLIST_ACK,				EV_MCU_BGN + 1128 );
OSPEVENT( MCU_CM_GETVIPLIST_NACK,				EV_MCU_BGN + 1129 );

// ��������
OSPEVENT( CM_MCU_STARTMIX_REQ,                  EV_MCU_BGN + 1130 );
OSPEVENT( MCU_CM_STARTMIX_ACK,                  EV_MCU_BGN + 1131 );
OSPEVENT( MCU_CM_STARTMIX_NACK,                 EV_MCU_BGN + 1132 );
OSPEVENT( MCU_CM_MIXPARAM_NTF,                  EV_MCU_BGN + 1133 ) ;

// ��������
OSPEVENT( CM_MCU_STOPMIX_REQ,                   EV_MCU_BGN + 1134 );
OSPEVENT( MCU_CM_STOPMIX_ACK,                   EV_MCU_BGN + 1135 );
OSPEVENT( MCU_CM_STOPMIX_NACK,                  EV_MCU_BGN + 1136 );

// ������������
OSPEVENT( CM_MCU_STARTVAC_REQ,					EV_MCU_BGN + 1137 );
OSPEVENT( MCU_CM_STARTVAC_ACK,					EV_MCU_BGN + 1138 );
OSPEVENT( MCU_CM_STARTVAC_NACK,					EV_MCU_BGN + 1139 );

// ������������
OSPEVENT( CM_MCU_STOPVAC_REQ,                   EV_MCU_BGN + 1140 );
OSPEVENT( MCU_CM_STOPVAC_ACK,                   EV_MCU_BGN + 1141 );
OSPEVENT( MCU_CM_STOPVAC_NACK,                  EV_MCU_BGN + 1142 );

// ��ӻ�����ԱCMD
OSPEVENT( CM_MCU_ADDMIXMEMBER_CMD,              EV_MCU_BGN + 1143 );
// ɾ��������ԱCMD
OSPEVENT( CM_MCU_REMOVEMIXMEMBER_CMD,           EV_MCU_BGN + 1144 );

// ��������  (EV_MCU_BGN + 1132 Ԥ��������������ӵĵ���NTF)
// ������������Ϣ�壺TReqHeadInfo+u8(����mode)+TMt(������)+TMt(��������)
OSPEVENT( CM_MCU_STARTROLLCALL_REQ,             EV_MCU_BGN + 1145 );
// ���������ɹ�����Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_STARTROLLCALL_ACK,             EV_MCU_BGN + 1146 );
// ��������ʧ�ܣ���Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_STARTROLLCALL_NACK,            EV_MCU_BGN + 1147 );

// ����ģʽ��mt֪ͨ
OSPEVENT( MCU_CM_ROLLCALL_NTF,					EV_MCU_BGN + 1148 );

// �رյ�������Ϣ�壺��
OSPEVENT( CM_MCU_STOPROLLCALL_REQ,              EV_MCU_BGN + 1149 );
// �رյ����ɹ�����Ϣ�壺��
OSPEVENT( MCU_CM_STOPROLLCALL_ACK,              EV_MCU_BGN + 1150 );
// �رյ���ʧ�ܣ���Ϣ�壺��
OSPEVENT( MCU_CM_STOPROLLCALL_NACK,             EV_MCU_BGN + 1151 );

// �޸ĵ�����������Ϣ�壺TReqHeadInfo+TMt(������)+TMt(��������)
OSPEVENT( CM_MCU_CHANGEROLLCALL_REQ,            EV_MCU_BGN + 1152 );
// �޸ĵ��������ɹ�����Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_CHANGEROLLCALL_ACK,            EV_MCU_BGN + 1153 );
// �޸ĵ�������ʧ�ܣ���Ϣ�壺TReqHeadInfo
OSPEVENT( MCU_CM_CHANGEROLLCALL_NACK,           EV_MCU_BGN + 1154 );

// MAU��MCU�·�BMC�������ն���Ϣ
OSPEVENT( MAU_MCU_MTLIST_NTF,                   EV_MCU_BGN + 1155 );

// MAU��MCU�·�BMC����������Ϣ
OSPEVENT( MAU_MCU_DOMAINLIST_NTF,               EV_MCU_BGN + 1156 );

//����ϳɵ�ͨ����ѯʱĳһ��ѯͨ������֪ͨ
//��Ϣ�壺u8(��������)+[TVmpChnPollParam...]
OSPEVENT( MCU_CM_VMPCHNPOLLPARAM_NTF,           EV_MCU_BGN + 1157 );

// ��������ǽ��ͨ��ѡ��	��Ϣ�壺TReqHeadInfo+u8(���)+u8(��Ա����)+THduSwitchInfo(���飬����Ϊǰһ��u8)
OSPEVENT( CM_CMU_STARTHDUSWITCH_REQ,			EV_MCU_BGN + 1158 );
// ��������ǽ��ͨ��ѡ���ɹ�	��Ϣ�壺TReqHeadInfo	
OSPEVENT( CMU_CM_STARTHDUSWITCH_ACK,			EV_MCU_BGN + 1159 );
// ��������ǽ��ͨ��ѡ��ʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STARTHDUSWITCH_NACK,			EV_MCU_BGN + 1160 );

// ֹͣ����ǽ��ͨ��ѡ��	��Ϣ�壺TReqHeadInfo+u8(���)+u8(��Ա����)+THduSwitchInfo(���飬����Ϊǰһ��u8)
OSPEVENT( CM_CMU_STOPHDUSWITCH_REQ,				EV_MCU_BGN + 1161 );
// ֹͣ����ǽ��ͨ��ѡ���ɹ�	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUSWITCH_ACK,				EV_MCU_BGN + 1162 );
// ֹͣ����ǽ��ͨ��ѡ��ʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUSWITCH_NACK,			EV_MCU_BGN + 1163 );

// ����ǽ��ͨ��ѡ��֪ͨ ��Ϣ�壺 TMsgHduInfo
OSPEVENT( CMU_CM_HDUSWITCH_NTF,					EV_MCU_BGN + 1164 );

// ��������ǽ��ͨ����ѯ	��Ϣ�壺TReqHeadInfo+TTvWallPollParam
OSPEVENT( CM_CMU_STARTHDUPOLL_CMD,				EV_MCU_BGN + 1165 );
// ֹͣ����ǽ��ͨ����ѯ	��Ϣ�壺TReqHeadInfo+u8+u8
OSPEVENT( CM_CMU_STOPHDUPOLL_CMD,				EV_MCU_BGN + 1166 );
// ��ͣ����ǽ��ͨ����ѯ	��Ϣ�壺TReqHeadInfo+u8+u8
OSPEVENT( CM_CMU_PAUSETHDUPOLL_CMD,				EV_MCU_BGN + 1167 );
// �ָ�����ǽ��ͨ����ѯ	��Ϣ�壺TReqHeadInfo+u8+u8
OSPEVENT( CM_CMU_RESUMEHDUPOLL_CMD,				EV_MCU_BGN + 1168 );
// �޸ĵ���ǽ��ͨ����ѯ	��Ϣ�壺TReqHeadInfo+TTvWallPollParam
OSPEVENT( CM_CMU_CHANGEHDUPOLL_CMD,				EV_MCU_BGN + 1169 );

// ����ǽ��ͨ����ѯ֪ͨ ��Ϣ�壺 TTvWallPollParam
OSPEVENT( CMU_CM_HDUPOLL_NTF,					EV_MCU_BGN + 1170 );

// ��������ǽ��������ϳ�	��Ϣ�壺TReqHeadInfo+u8+u8+TVMPParam
OSPEVENT( CM_CMU_STARTHDUVMP_REQ,				EV_MCU_BGN + 1171 );
// ��������ǽ�ɹ�	��Ϣ�壺TReqHeadInfo	
OSPEVENT( CMU_CM_STARTHDUVMP_ACK,				EV_MCU_BGN + 1172 );
// ��������ǽʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STARTHDUVMP_NACK,				EV_MCU_BGN + 1173 );

// �޸ĵ���ǽ��������ϳ�	��Ϣ�壺TReqHeadInfo+u8+u8+TVMPParam
OSPEVENT( CM_CMU_CHANGEHDUVMP_REQ,				EV_MCU_BGN + 1174 );
// �޸ĵ���ǽ��������ϳɳɹ�	��Ϣ�壺TReqHeadInfo	
OSPEVENT( CMU_CM_CHANGEHDUVMP_ACK,				EV_MCU_BGN + 1175 );
// �޸ĵ���ǽ��������ϳ�ʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_CHANGEHDUVMP_NACK,				EV_MCU_BGN + 1176 );

// ֹͣ����ǽ��������ϳ�	��Ϣ�壺TReqHeadInfo+u8+u8
OSPEVENT( CM_CMU_STOPHDUVMP_REQ,				EV_MCU_BGN + 1177 );
// ֹͣ����ǽ��������ϳɳɹ�	��Ϣ�壺TReqHeadInfo	
OSPEVENT( CMU_CM_STOPHDUVMP_ACK,				EV_MCU_BGN + 1178 );
// ֹͣ����ǽ��������ϳ�ʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUVMP_NACK,				EV_MCU_BGN + 1179 );

// ����ǽ��������ϳ�֪ͨ ��Ϣ�壺 u8+u8+TVMPParam
OSPEVENT( CMU_CM_HDUVMP_NTF,					EV_MCU_BGN + 1180 );

// ��������ǽ������ѯ	��Ϣ�壺TReqHeadInfo+THduPollSchemeInfo
OSPEVENT( CM_CMU_STARTHDUBATCHPOLL_REQ,			EV_MCU_BGN + 1181 );
// ��������ǽ������ѯ�ɹ�	��Ϣ�壺TReqHeadInfo	
OSPEVENT( CMU_CM_STARTHDUBATCHPOLL_ACK,			EV_MCU_BGN + 1182 );
// ��������ǽ������ѯʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STARTHDUBATCHPOLL_NACK,		EV_MCU_BGN + 1183 );

// ֹͣ����ǽ������ѯ	��Ϣ�壺TReqHeadInfo
OSPEVENT( CM_CMU_STOPHDUBATCHPOLL_REQ,			EV_MCU_BGN + 1184 );
// ֹͣ����ǽ������ѯ�ɹ�	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUBATCHPOLL_ACK,			EV_MCU_BGN + 1185 );
// ֹͣ����ǽ������ѯʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STOPHDUBATCHPOLL_NACK,			EV_MCU_BGN + 1186 );

// ��ͣ����ǽ������ѯ	��Ϣ�壺TReqHeadInfo
OSPEVENT( CM_CMU_PAUSEHDUBATCHPOLL_REQ,			EV_MCU_BGN + 1187 );
// ��ͣ����ǽ������ѯ�ɹ�	��Ϣ�壺TReqHeadInfo	
OSPEVENT( CMU_CM_PAUSEHDUBATCHPOLL_ACK,			EV_MCU_BGN + 1188 );
// ��ͣ����ǽ������ѯʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_PAUSEHDUBATCHPOLL_NACK,		EV_MCU_BGN + 1189 );

// �ָ�����ǽ������ѯ	��Ϣ�壺TReqHeadInfo
OSPEVENT( CM_CMU_RESUMEHDUBATCHPOLL_REQ,		EV_MCU_BGN + 1190 );
// �ָ�����ǽ������ѯ�ɹ�	��Ϣ�壺TReqHeadInfo	
OSPEVENT( CMU_CM_RESUMEHDUBATCHPOLL_ACK,		EV_MCU_BGN + 1191 );
// �ָ�����ǽ������ѯʧ��	��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_RESUMEHDUBATCHPOLL_NACK,		EV_MCU_BGN + 1192 );

// ����ǽ������ѯ֪ͨ ��Ϣ�壺 THduPollSchemeInfo
OSPEVENT( CMU_CM_HDUBATCHPOLL_NTF,				EV_MCU_BGN + 1193 );

// ��ͳ����ı����ǽͨ�����1����4����У� ��Ϣ�壺TReqHeadInfo+u8+u8+u8+u8
OSPEVENT( CM_CMU_CHANGEHDUVMPMODE_CMD,			EV_MCU_BGN + 1194 );
// ��ͳ����ı����ǽͨ�����֪ͨ	TReqHeadInfo+u8+u8+u8+u8
OSPEVENT( CMU_CM_CHANGEHDUVMPMODE_NTF,			EV_MCU_BGN + 1195 );

// �����Ƿ���ʾ����ǽͨ��̨�� ��Ϣ�壺TReqHeadInfo+u8+u8+u8+u8
OSPEVENT( CM_CMU_SETHDUDISPALIAS_CMD,			EV_MCU_BGN + 1196 );

// ¼����� : 
// ��ʼ¼�� ��Ϣ��:TReqHeadInfo + IsMerge(u8) + ¼������(KDV_NAME_MAX_LENGTH + 1) * s8�� + TRecStartPara + TMtAlias + u16(N) + N * TRecMt
// N = 0 ����¼��  N = 1 �ն�¼��  N > 1 �ϲ�¼��
OSPEVENT( CM_CMU_STARTREC_REQ,			        EV_MCU_BGN + 1197 );
// ��ʼ¼��ɹ� ��Ϣ�壺TReqHeadInfo + ¼������(KDV_NAME_MAX_LENGTH + 1) * s8�� + TRecStartPara + TMtAlias + u16(N) + N * TRecMt
OSPEVENT( CMU_CM_STARTREC_ACK,			        EV_MCU_BGN + 1198 );
// ��ʼ¼��ʧ�� ��Ϣ��: TReqHeadInfo + ¼������(KDV_NAME_MAX_LENGTH + 1) * s8�� +��TRecStartPara + TMtAlias + u16(N) + N * TRecMt
OSPEVENT( CMU_CM_STARTREC_NACK,			        EV_MCU_BGN + 1199 );
// ��ͣ¼�� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CM_CMU_PAUSEREC_REQ, 			        EV_MCU_BGN + 1200 );
// ��ͣ¼��ɹ� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_PAUSEREC_ACK, 			        EV_MCU_BGN + 1201 );
// ��ͣ¼��ʧ�� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_PAUSEREC_NACK,		         	EV_MCU_BGN + 1202 );
// �ָ�¼�� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CM_CMU_RESUMEREC_REQ,			        EV_MCU_BGN + 1203 );
// �ָ�¼��ɹ� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_RESUMEREC_ACK,			        EV_MCU_BGN + 1204 );
// �ָ�¼��ʧ�� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_RESUMEREC_NACK,			    EV_MCU_BGN + 1205 );     
// ֹͣ¼��ʧ�� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CM_CMU_STOPREC_REQ,			        EV_MCU_BGN + 1206 );
// ֹͣ¼��ʧ�� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_STOPREC_ACK,			        EV_MCU_BGN + 1207 );
// ֹͣ¼��ʧ�� ��Ϣ�壺TReqHeadInfo + recid(u8)
OSPEVENT( CMU_CM_STOPREC_NACK, 			        EV_MCU_BGN + 1208 );
// ¼�����֪ͨ ��Ϣ�壺recid(u8)
OSPEVENT( CM_CMU_GETRECPROG_CMD, 			    EV_MCU_BGN + 1209 );   
// ¼�����֪ͨ ��Ϣ�壺recid(u8) + TRecProg
OSPEVENT( CMU_CM_RECPROG_NTF, 			        EV_MCU_BGN + 1210 );   
// ¼�����֪ͨ ��Ϣ�壺recid(u8)
OSPEVENT( CM_CMU_GETRECSTATUS_CMD,              EV_MCU_BGN + 1211 );
// ¼��״̬֪ͨ ��Ϣ�壺TMtAlias + tCMVrsRecChnStatus
OSPEVENT( CMU_CM_RECORDRECSTATUS_NTF,			EV_MCU_BGN + 1212 ); 
// ¼�����쳣֪ͨ ��Ϣ�壺u8(TYPE_RECOED/TYPE_PLAY) + recid(u8)
OSPEVENT( CMU_CM_RECORDEREXCEPT_NTF,			    EV_MCU_BGN + 1213 ); 

OSPEVENT( CMU_CM_HDUSWITCH_FAIL_NTF,                EV_MCU_BGN + 1214);
// ������أ�
// ��ʼ���� ��Ϣ�壺TReqHeadInfo + TPlayEqpAttrib + TMtAlias 
OSPEVENT( CM_CMU_STARTPLAY_REQ,					EV_MCU_BGN + 1215 );
// ��ʼ����ɹ� ��Ϣ�壺TReqHeadInfo + TPlayEqpAttrib + TMtAlias
OSPEVENT( CMU_CM_STARTPLAY_ACK,					EV_MCU_BGN + 1216 );
// ��ʼ����ʧ�� ��Ϣ�壺TReqHeadInfo + TPlayEqpAttrib + TMtAlias
OSPEVENT( CMU_CM_STARTPLAY_NACK,				EV_MCU_BGN + 1217 ); 
// ��ͣ���� ��Ϣ�壺TReqHeadInfo
OSPEVENT( CM_CMU_PAUSEPLAY_REQ,					EV_MCU_BGN + 1218 );
// ��ͣ����ɹ� ��Ϣ�壺TReqHeadInfo 
OSPEVENT( CMU_CM_PAUSEPLAY_ACK,					EV_MCU_BGN + 1219 );
// ��ͣ����ʧ�� ��Ϣ�壺TReqHeadInfo 
OSPEVENT( CMU_CM_PAUSEPLAY_NACK,				EV_MCU_BGN + 1220 );
// �ָ����� ��Ϣ�壺TReqHeadInfo
OSPEVENT( CM_CMU_RESUMEPLAY_REQ,				EV_MCU_BGN + 1221 );
// �ָ�����ɹ� ��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_RESUMEPLAY_ACK,				EV_MCU_BGN + 1222 );
// �ָ�����ʧ�� ��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_RESUMEPLAY_NACK,				EV_MCU_BGN + 1223 );
// ֹͣ���� ��Ϣ�壺TReqHeadInfo
OSPEVENT( CM_CMU_STOPPLAY_REQ,					EV_MCU_BGN + 1224 );
// ֹͣ����ɹ� ��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STOPPLAY_ACK,					EV_MCU_BGN + 1225 );
// ֹͣ����ʧ�� ��Ϣ�壺TReqHeadInfo
OSPEVENT( CMU_CM_STOPPLAY_NACK,					EV_MCU_BGN + 1226 );
// ����������� ��Ϣ�壺TReqHeadInfo + TRecProg
OSPEVENT( CM_CMU_SEEK_REQ,						EV_MCU_BGN + 1227 );
// ����������ȳɹ� ��Ϣ�壺TReqHeadInfo + TRecProg
OSPEVENT( CMU_CM_SEEK_ACK,						EV_MCU_BGN + 1228 );
// �����������ʧ�� ��Ϣ�壺TReqHeadInfo + TRecProg
OSPEVENT( CMU_CM_SEEK_NACK,						EV_MCU_BGN + 1229 );
// ��ѯ�������	��Ϣ�壺TReqHeadInfo
OSPEVENT( CM_CMU_GETPLAYPROG_CMD,				EV_MCU_BGN + 1330 );
// �������֪ͨ ��Ϣ�壺TRecProg
OSPEVENT( CMU_CM_PLAYPROG_NTF,					EV_MCU_BGN + 1331 );
// ����״̬֪ͨ ��Ϣ�壺TMtAlias + TVrsRecChnnlStatus
OSPEVENT( CMU_CM_PLAYORDPLAYSTATUS_NTF,			EV_MCU_BGN + 1332 );
// ��ѯ�����״̬ ��Ϣ�壺TReqHeadInfo
OSPEVENT( CM_CMU_GETPLAYSTATUS_CMD,				EV_MCU_BGN + 1333 );

// ���Ͷ���Ϣ
OSPEVENT( CM_MCU_SENDMSG_CMD,					EV_MCU_BGN + 1334 );
// �ն�ѡ��֪ͨ
// ��Ϣ��: TMtIdentifyToCM(ѡ��Ŀ��)+u8(Ŀ�Ľ���ͨ��)+u8(ѡ��ģʽ)+u8(ѡ��Դ������:TYPE_MT...)+u8(ѡ��Դ������:MT_TYPE_MT...)
//         +[TMtIdentifyToCM(ѡ��Դ�ն�)+u8(Դ����ͨ��)]
OSPEVENT( MCU_CM_MTSELECTVIEW_NTF,				EV_MCU_BGN + 1335 );


//�ն�����廰֪ͨ
OSPEVENT( MCU_CM_APPLYMIX_NTF,				EV_MCU_BGN + 1336 );

//�޸��ն���������Ϣ�壺 TMtIdentifyToCM + u8(chnidx) + u8(codectype:1- ����, 2 - ����) + u8(volume)
OSPEVENT( CM_MCU_MODMTVOLUME_CMD,			EV_MCU_BGN + 1337 );
//�ն�����֪ͨ����Ϣ�壺 s8[7](����E164)+TMtIdentifyToCM + u8(chnidx) + u8(codectype:1- ����, 2 - ����) + u8(volume)
OSPEVENT( MCU_CM_MTVOLUME_NTF,				EV_MCU_BGN + 1338 );

// �¼����������أ�
// �����¼�����
OSPEVENT( CM_CMU_ENDSUBCONF_CMD,				EV_MCU_BGN + 1340 );

// �����¼�MCU�б�֪ͨ
// ��Ϣ�壺u8(�б��Ƿ�������0-��1-��)+u8(SMCU����)+[TMtIdentifyToCM+TMtDescToCM]...
OSPEVENT( CMU_CM_ALLSMCULIST_NTF,				EV_MCU_BGN + 1342 );
// ָ��ĳ���¼�������¼������б�֪ͨ
// ��Ϣ�壺u8(�б��Ƿ�������0-��1-��)+TMtIdentifyToCM(ָ�����¼�����)+u8(SMCU����)+[TMtIdentifyToCM+TMtDescToCM]...
OSPEVENT( CMU_CM_SMCULISTOFSMCU_NTF,			EV_MCU_BGN + 1343 );
// ָ��ĳ���¼�������ն��б�֪ͨ
// ��Ϣ�壺u8(�б��Ƿ�������0-��1-��)+TMtIdentifyToCM(ָ�����¼�����)+u8(�ն�����)+[TMtIdentifyToCM+TMtDescToCM+TMcuMcuMtInfo]...
OSPEVENT( CMU_CM_MTLISTOFSMCU_NTF,				EV_MCU_BGN + 1344 );
// �����¼�����ڵ�
// ��Ϣ�壺TMtIdentifyToCM+TMtDescToCM
OSPEVENT( CMU_CM_ADDSMCU_NTF,					EV_MCU_BGN + 1345 );
// ɾ���¼�����ڵ�
// ��Ϣ�壺TMtIdentifyToCM
OSPEVENT( CMU_CM_REMOVESMCU_NTF,				EV_MCU_BGN + 1346 );

//���鼴������֪ͨ���
OSPEVENT( MCU_CM_CONFWILLEND_NTF,				EV_MCU_BGN + 1347 );

//����״̬���֪ͨ��֪ͨcss�޸Ļ�����Ϣ
OSPEVENT( MCU_MAU_CONFSTATECHANGE_NTF,			EV_MCU_BGN + 1348 );

//mpc�������̻�������ʱ�䣬��Ϣ��:TReqHeadInfo+u16(wDelayTime)
OSPEVENT( MCU_MAU_SUBCONFDURATION_REQ,          EV_MCU_BGN + 1349 );
OSPEVENT( MAU_MCU_SUBCONFDURATION_ACK,	        EV_MCU_BGN + 1350 );
OSPEVENT( MAU_MCU_SUBCONFDURATION_NACK,	        EV_MCU_BGN + 1351 );

//���ָ���ϴ��ն�
//��Ϣ�壺TMtIdentifyToCM(��ָ�����ն�)
OSPEVENT( CM_MCU_SPECSRCOFMMCU_REQ,				EV_MCU_BGN + 1352 );
//���ָ���ϴ��ն˳ɹ���Ӧ
OSPEVENT( MCU_CM_SPECSRCOFMMCU_ACK,				EV_MCU_BGN + 1353 );
//���ָ���ϴ��ն�ʧ����Ӧ
OSPEVENT( MCU_CM_SPECSRCOFMMCU_NACK,			EV_MCU_BGN + 1354 );
//���ȡ���ϴ��ն�
OSPEVENT( CM_MCU_CANCELSRCOFMMCU_CMD,			EV_MCU_BGN + 1355 );
//�ϴ��ն�֪ͨ: TReqHeadInfo+TMtIdentifyToCM
OSPEVENT( MCU_CM_SRCOFMMCU_NTF,					EV_MCU_BGN + 1356 );
// �ϴ��ն���ѯ״̬֪ͨ: TPollInfo +  TOperObjToCM[]
OSPEVENT( MCU_CM_MMCUSRCPOLL_NTF,				EV_MCU_BGN + 1357 );
// ��ʼ�ϴ��ն���ѯ: TPollInfo+TMtPollParam*wMtNum(u16)
OSPEVENT( CM_MCU_STARTMMCUSRCPOLL_CMD,			EV_MCU_BGN + 1358 );
// ��ͣ�ϴ��ն���ѯ
OSPEVENT( CM_MCU_PAUSEMMCUSRCPOLL_CMD,			EV_MCU_BGN + 1359 );
// ֹͣ�ϴ��ն���ѯ
OSPEVENT( CM_MCU_STOPMMCUSRCPOLL_CMD,			EV_MCU_BGN + 1360 );
// �޸Ļ���˫������ģʽ: u8(0 - ������ģʽ��1 - ������ģʽ )
OSPEVENT( CM_MCU_CHANGEDUALMODE_CMD,			EV_MCU_BGN + 1361 );
// ָ������˫������: TMtIdentifyToCM
OSPEVENT( CM_MCU_SPECDUALSRC_CMD,				EV_MCU_BGN + 1362 );
// ȡ������˫������: TMtIdentifyToCM
OSPEVENT( CM_MCU_CANCELDULASRC_CMD,				EV_MCU_BGN + 1363 );



OSPEVENT( CM_CMU_MTCAMERA_MOV_CMD,				EV_MCU_BGN + 1364 );
OSPEVENT( CM_CMU_MTCAMERA_STOP_CMD,				EV_MCU_BGN + 1365 );
OSPEVENT( CM_CMU_MTCAMERA_RCENABLE_CMD,			EV_MCU_BGN + 1366 );
OSPEVENT( CM_CMU_MTCAMERA_SAVETOPOS_CMD,		EV_MCU_BGN + 1367 );
OSPEVENT( CM_CMU_MTCAMERA_MOVETOPOS_CMD,		EV_MCU_BGN + 1368 );

// �澯֪ͨ
OSPEVENT( CMU_CM_ALARMINFO_NTF,					EV_MCU_BGN + 1369 );
// ѡ��ʧ��֪ͨ
OSPEVENT( CMU_CM_STARTSEE_FAIL_NTF,				EV_MCU_BGN + 1370 );

//����ʣ��ʱ��֪ͨ css--cmu
OSPEVENT( MAU_MCU_CONFTIMELEFT_NTF,				EV_MCU_BGN + 1371 );
//�������ʱ��֪ͨ css--cmu
OSPEVENT( MAU_MCU_CONFDURATION_NTF,				EV_MCU_BGN + 1372 );
//vmp����ʧ��֪ͨ
OSPEVENT( CMU_CM_STARTVMP_FAIL_NTF,				EV_MCU_BGN + 1373 );
OSPEVENT( CMU_CM_STARTMTVMP_FAIL_NTF,			EV_MCU_BGN + 1374 );
OSPEVENT( CMU_CM_STARTHDUVMP_FAIL_NTF,			EV_MCU_BGN + 1375 );

OSPEVENT( CMU_CM_STARTMIX_FAIL_NTF,				EV_MCU_BGN + 1376 );

// �ָ��ϴ��ն���ѯ   ����ʱ���󲹵ĸ���Ϣ ��1358
OSPEVENT( CM_MCU_RESUMEMMCUSRCPOLL_CMD,			EV_MCU_BGN + 1377 );
// ָ���ϴ���ѯpos req  TReqHeadInfo + TOperObjToCM + byPollMode
OSPEVENT( CM_CMU_MMCUSRCPOLLPOS_REQ,			EV_MCU_BGN + 1378 );
OSPEVENT( CMU_CM_MMCUSRCPOLLPOS_ACK,			EV_MCU_BGN + 1379 );
OSPEVENT( CMU_CM_MMCUSRCPOLLPOS_NACK,			EV_MCU_BGN + 1380 );
// �ı��ϴ���ѯ��Աcmd
OSPEVENT( CM_CMU_CHANGEMMCUSRCPOLLPARAM_CMD,	EV_MCU_BGN + 1381 );


//��ܿ�ʼ��ͨ���
OSPEVENT( CM_CMU_STARTMONITORING_REQ,			EV_MCU_BGN + 1382 );
OSPEVENT( CMU_CM_STARTMONITORING_ACK,			EV_MCU_BGN + 1383 );
OSPEVENT( CMU_CM_STARTMONITORING_NACK,			EV_MCU_BGN + 1384 );

//��ܿ�ʼ�㲥���
OSPEVENT( CM_CMU_STARTBRDMONITORING_REQ,		EV_MCU_BGN + 1385 );
OSPEVENT( CMU_CM_STARTBRDMONITORING_ACK,		EV_MCU_BGN + 1386 );
OSPEVENT( CMU_CM_STARTBRDMONITORING_NACK,		EV_MCU_BGN + 1387 );

//��ܿ�ʼ˫�����
OSPEVENT( CM_CMU_STARTDVIDMONITORING_REQ,		EV_MCU_BGN + 1388 );
OSPEVENT( CMU_CM_STARTDVIDMONITORING_ACK,		EV_MCU_BGN + 1389 );
OSPEVENT( CMU_CM_STARTDVIDMONITORING_NACK,		EV_MCU_BGN + 1390 );

// ���鿪ʼ���֪ͨ
OSPEVENT( CMU_CM_STARTMONITORING_NTF,			EV_MCU_BGN + 1391 );

//���ֹͣ���
OSPEVENT( CM_CMU_STOPMONITORING_CMD,			EV_MCU_BGN + 1392 );

//�������ؼ�֡
OSPEVENT( CM_CMU_NEEDIFRAME_CMD,				EV_MCU_BGN + 1393 );

//�������ָ���ն˹ؼ�֡
OSPEVENT( CM_CMU_NEEDSPECMTIFRAME_CMD,			EV_MCU_BGN + 1394 );

//�������ָ���ն˹ؼ�֡
OSPEVENT( CM_CMU_GETCURRENTBRDSRC_REQ,			EV_MCU_BGN + 1395 );
OSPEVENT( CMU_CM_GETCURRENTBRDSRC_ACK,			EV_MCU_BGN + 1396 );
OSPEVENT( CMU_CM_GETCURRENTBRDSRC_NACK,			EV_MCU_BGN + 1397 );

//����ֹͣ���֪ͨ, ��Ϣ�壺TSwitchDstInfo
OSPEVENT( CMU_CM_STOPMONITORING_NTF,			EV_MCU_BGN + 1398 );

//�����޸Ļ����������Ϣ��:TReqHeadInfo+u16(wConfNameLen)+s8[confName]
OSPEVENT( MCU_MAU_MODIFYCONFNAME_REQ,           EV_MCU_BGN + 1399 );
OSPEVENT( MAU_MCU_MODIFYCONFNAME_ACK,	        EV_MCU_BGN + 1400 );
OSPEVENT( MAU_MCU_MODIFYCONFNAME_NACK,	        EV_MCU_BGN + 1401 );

//��ȡָ���ն�״̬����
OSPEVENT( CM_CMU_GETMTSTATUS_REQ,	        EV_MCU_BGN + 1402 );
OSPEVENT( CMU_CM_GETMTSTATUS_ACK,	        EV_MCU_BGN + 1403 );
OSPEVENT( CMU_CM_GETMTSTATUS_NACK,	        EV_MCU_BGN + 1404 );

// ���涨��api��������
OSPEVENT( CM_CMU_GETMTLIST_REQ,						EV_MCU_BGN + 1405 );
//��Ϣ�壺u8*16(����e164)+u8*64(��������)+u8(�ն�����)+[ TJsonMtIdentify+TJsonMtDesc+u16(CallBitrate, ������)+u8(IsOnline)+
//		  u32(����Ƶ����ͨ��������������)+[TMtMgrVidSndChnStatus]+
//		  u32(����Ƶ����ͨ��������������)+[TMtMgrVidRcvChnStatus]+
//		  u32(˫����Ƶ����ͨ��������������)+[TMtMgrDVidSndChnStatus]+
//		  u32(˫����Ƶ����ͨ��������������)+[TMtMgrDVidRcvChnStatus]+
//		  u32(��Ƶ����ͨ��������������)+[TMtMgrAudSndChnStatus+u8(�Ƿ�����)]+
//		  u32(��Ƶ����ͨ��������������)+[TMtMgrAudRcvChnStatus+u8(�Ƿ���)] 
//        ]
OSPEVENT( CMU_CM_GETMTLIST_ACK,						EV_MCU_BGN + 1406 );
OSPEVENT( CMU_CM_GETMTLIST_NACK,                    EV_MCU_BGN + 1407 );

//�����ն�֪ͨTMT + bySuccess
OSPEVENT( MCU_CM_CALLMT_NTF,						EV_MCU_BGN + 1408 );

//��ȡ�ն�Ԥ��λ��Ϣ
OSPEVENT( CM_CMU_MTCAMERA_GETPOSINFO_CMD,           EV_MCU_BGN + 1409 );
//�ն�Ԥ��λ��Ϣ�ϱ�
OSPEVENT( CMU_CM_MTCAMERA_POSINFO_NTF,                EV_MCU_BGN + 1410 );

OSPEVENT( MAU_MCU_RESTORECONF_REQ,               EV_MCU_BGN + 1411 );
OSPEVENT( MAU_MCU_RESTORECONF_ACK,               EV_MCU_BGN + 1412 );
OSPEVENT( MAU_MCU_RESTORECONF_NACK,              EV_MCU_BGN + 1413 );

/********** wy[2014/09/22]����MAU��MCU��������(29001-30000)---�����ն��ڲ�ҵ����Ϣ end *******/



/********** rnn[2015/01/19]����MCU/MAU�ڲ���������ؽ�������(29901-30000)---�����ն��ڲ�ҵ����Ϣ bgn *******/
//����������֪ͨ ��Ϣ�壺TMcuConfInfo
OSPEVENT( MCU_ADP_CONFCREATE_NTF,				EV_MCU_BGN + 1900 );
//���ٶ�����֪ͨ ��Ϣ�壺TMcuConfInfo
OSPEVENT( MCU_ADP_CONFDESTROY_NTF,				EV_MCU_BGN + 1901 );
//�ն����֪ͨ ��Ϣ�壺TMtInfoInConf
OSPEVENT( MCU_ADP_MTADD_NTF,					EV_MCU_BGN + 1902 );
//�ն����֪ͨ ��Ϣ�壺TMtInfoInConf
OSPEVENT( MCU_ADP_MTDEL_NTF,					EV_MCU_BGN + 1903 );
//ADP����֪ͨ ��Ϣ�壺TMtInfoInConf
OSPEVENT( MCU_ADP_ADPONELINE_NTF,               EV_MCU_BGN + 1904 );


/********** rnn[2015/01/19]����MCU/MAU�ڲ���������ؽ�������(29901-30000)---�����ն��ڲ�ҵ����Ϣ end *******/



/********** VC��INTERACT��������(30001-30200)---����RECORDER�ڲ�ҵ����Ϣ bgn *******/
//��ʼ������ģ��,��Ϣ��TInterActInitInfo
OSPEVENT( MCU_INTERACT_INIT_CMD,				EV_REC_BGN );
//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( MCU_INTERACT_ADDONETOONE_CMD,			EV_REC_BGN + 1 );
//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( MCU_INTERACT_ADDNTON_CMD,				EV_REC_BGN + 2 );
//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( MCU_INTERACT_ADDONETON_CMD,			EV_REC_BGN + 3 );
//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( MCU_INTERACT_CHANGENTON_CMD,			EV_REC_BGN + 4 );
//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( MCU_INTERACT_ADDVIEWERS_CMD,			EV_REC_BGN + 5 );

OSPEVENT( MCU_INTERACT_INITACTORSWITCH_CMD,		EV_REC_BGN + 6 );

OSPEVENT( MCU_INTERACT_INITVIEWERSWITCH_CMD,	EV_REC_BGN + 7 );
//Ԥ������Դ ��Ϣ��:TConfResDemand
OSPEVENT( MCU_INTERACT_APPLYMEDIARESOURCE_CMD,			EV_REC_BGN + 8 );

//����actor��Ӧ������Ƶѡ������
OSPEVENT( MCU_INTERACT_SETACTORSELECTSWITCHMUTE_CMD,	EV_REC_BGN + 9 );

//��Դ����֪ͨ ��Ϣ��:u8 MediaMode
OSPEVENT( MCU_INTERACT_MEDIAEQPONLINE_NTF,		EV_REC_BGN + 10 );

// actor��Ӧҵ�񽻻���ִ������������ u8 byIsRmv + u8 actorNum + actor*N 
OSPEVENT( MCU_INTERACT_ACOTRSWITCHMUTE_CMD,		EV_REC_BGN + 11 );
// viewer��Ӧҵ�񽻻���ִ�о��������� u8 byIsRmv + u8 viewerNum + viewer*N 
OSPEVENT( MCU_INTERACT_VIEWERSWITCHMUTE_CMD,	EV_REC_BGN + 12 );


OSPEVENT( MCU_INTERACT_RELEASEACTORSWITCH_CMD,	EV_REC_BGN + 22 );
//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( MCU_INTERACT_RELEASEVIEWERSWITCH_CMD,	EV_REC_BGN + 23 );

//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( MCU_INTERACT_MSGRES_RSP,				EV_REC_BGN + 24 );

OSPEVENT( MCU_INTERACT_EQPRES_RSP,				EV_REC_BGN + 25 );

OSPEVENT( MCU_INTERACT_DELINTERACT_CMD,			EV_REC_BGN + 26 );

OSPEVENT( MCU_INTERACT_DELVIEWERS_CMD,			EV_REC_BGN + 27 );

OSPEVENT( MCU_INTERACT_CLEAR_CMD,				EV_REC_BGN + 28 );
//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( INTERACT_MCU_RLT_NTF,					EV_REC_BGN + 29 );

// ��ý����Դ������йؼ�֡������Ϣ�壺INTERACTIONID(u32)+CViewer+byMediaMode(u8)
OSPEVENT( MCU_INTERACT_IFRAME_CMD,              EV_REC_BGN + 30 );
// �л�HDUͨ����� ��Ϣ�� TInteractionHduPicStyleParam
OSPEVENT( MCU_INTERACT_CHGHDUPICSTYLE_CMD,      EV_REC_BGN + 31 );
// �л������֪ͨ TInteractionHduPicStyleParam ��ERROR != 0ʧ�ܣ� 
OSPEVENT( INTERACT_MCU_CHGHDUPICSTYLE_NTF,      EV_REC_BGN + 32 );
// �޸�One2One����
OSPEVENT( MCU_INTERACT_CHANGEONETOONE_CMD,      EV_REC_BGN + 33);

//	u8 byCBChlNum + byCBChlNum*( tParam + wErrCode )
OSPEVENT( INTERACT_MCU_HDURESRVE_NTF,         EV_REC_BGN + 34 );
// ����HDUͨ��̨�� ��Ϣ�� TInteractionHduDispAliasParam ����ظ�
OSPEVENT( MCU_INTERACT_SETHDUDISPALIAS_CMD,     EV_REC_BGN + 35 );
// ����ģ�����Զ˿ڵ��ߺ���Ľ��֪ͨ
OSPEVENT( INTERACT_MCU_MEDIAPORTRLT_NTF,        EV_REC_BGN + 36 );

// ԤռHDUͨ��(ֻ֧�ֵ�ͨ��Ԥռ���ķ����ͨ����֧��) ��Ϣ�� u8 byNum + TCtrHduInfo*byNum + BooL32 bReserve
OSPEVENT( MCU_INTERACT_RESERVEHDUCHL_CMD,		EV_REC_BGN + 37 );

//����ģ������MCUVC������Ľ��֪ͨ
OSPEVENT( MCU_INTERACT_CHANGEONETON_CMD,		EV_REC_BGN + 38 );

OSPEVENT( MCU_INTERACT_BACHRESERVEHDUCHL_TIME,  EV_REC_BGN + 39 );

// �⳧���ն��Ի����buf��
OSPEVENT( MCU_INTERACT_ACTORMEDIALOOP_CMD,	   EV_REC_BGN + 40 );
/********** VC��INTERACT��������(30001-30041)---����RECORDER�ڲ�ҵ����Ϣ end *******/

/********** INTERACT��MTMGR��������(30041-30200)---����RECORDER�ڲ�ҵ����Ϣ begin *******/
// ������������Դ����:CViewer+u32(dwPariID)+u8(0:���������Դ 1:���������Դ)+TPortEncDecCap���������
OSPEVENT( INTERACT_MTMGR_APPLYDECENCRES_CMD,        EV_REC_BGN + 41 );
// �ͷű��������Դ����:HMEDIARES(�������)+u8(0:�ͷŽ�����Դ 1:�ͷű�����Դ)
OSPEVENT( INTERACT_MTMGR_RELEASEDECENCRES_CMD,        EV_REC_BGN + 42 );
// ����������Դ֪ͨ:CViewer+u32(dwPariID)+u8(0:���������Դ 1:���������Դ)+HMEDIARES(�������)
OSPEVENT( MTMGR_INTERACT_APPLYENCRES_NTF,        EV_REC_BGN + 43 );
//����bas ������� cActor + cViewer + TSimCapSet
OSPEVENT( MCU_INTERACT_ADJUSTBASENCPARAM_CMD,  EV_REC_BGN + 44 );

//MCU��,¼����ʱ�� ��16��,Ԥ��16��  ��¼��û�а�ʱ�ɹ���ɾ��¼�������vc������,
OSPEVENT( MCUVC_MC_RECORD_TIMER,       EV_REC_BGN + 45 );
// vrs ռ�� 16����ʱ����֮��EV_REC_BGN + 61 ��ʼ
 
/********** INTERACT��MTMGR��������(30041-30200)---����RECORDER�ڲ�ҵ����Ϣ end *******/

/********** VC��MtMgr��������[��͸��](30201-30400) ---���û������ڲ�ҵ����Ϣ begin******/
/*-------
ע�����
--------*/
//VCע��MTMGR��	VCApp->MtMgrApp,	��Ϣ�壺TConfInfo4Call
OSPEVENT(VC_MTMGR_REG_REQ,						EV_MIXER_BGN );
//MtMgr��ӦVCע�ᣬMtMgrApp->VCApp,	��Ϣ�壺��
OSPEVENT(MTMGR_VC_REG_ACK,						EV_MIXER_BGN + 1 );
OSPEVENT(MTMGR_VC_REG_NACK,						EV_MIXER_BGN + 2 );
//ע��MTMGR		VCApp->MtMgrApp,	��Ϣ�壺��
OSPEVENT(VC_MTMGR_UNREG_CMD,					EV_MIXER_BGN + 3 );
/*-----------
���йҶ����
------------*/
//����նˣ�	VCApp->MtMgrApp��	��Ϣ�壺u8(num) + TAddMtInfo[] + u8(�Ƿ�Ҫ��������) + u8(�Ƿ��ǿ����Ǻ���)
OSPEVENT(VC_MTMGR_ADDMT_REQ,					EV_MIXER_BGN + 4 );
//����նˣ�	VCApp->MtMgrApp��	��Ϣ�壺u8(num) + TAddMtInfo[] + u8(�Ƿ�Ҫ��������) + u8(�Ƿ��ǿ����Ǻ���) + num*sizeof(TMT)
//											û����ӳɹ����ն��ÿյ�TMt���
OSPEVENT(MTMGR_VC_ADDMT_ACK,					EV_MIXER_BGN + 5 );
OSPEVENT(MTMGR_VC_ADDMT_NACK,					EV_MIXER_BGN + 6 );
//�����ն�,		VcApp->MtMgrApp,	��Ϣ�壺TMt	  (Ҫ�����նˣ���Ҫ�������ն���TMt����SetNull)	+
//											BOOL32(�Ƿ�����mcu����Alert����֪ͨ)				+
//											BOOL32(�Ƿ�������mcu�㲥��Alert����֪ͨ����ֻ�ǻظ�������mcu)	+
//											u8	  (��������: ��������[VCS_FORCECALL_REQ] ����ǿ������[VCS_FORCECALL_CMD])	
OSPEVENT(VC_MTMGR_CALLMT_CMD,					EV_MIXER_BGN + 7 );
//�����ն�ʧ��֪ͨ
OSPEVENT(MTMGR_VC_CALLMTFAIL_NTF,				EV_MIXER_BGN + 8 );
//�ն˳ɹ����֪ͨ
OSPEVENT(MTMGR_VC_CALLMTOK_NTF,					EV_MIXER_BGN + 9 );

// OSPEVENT(VC_MTMGR_DEMAND_DSRCVCAP_CMD,		EV_MCUMT_STD_BGN + 306 );
// ˫������ͨ�棬					��Ϣ�壺Null
OSPEVENT(MTMGR_VC_DSRCVCAP_NTF,					EV_MIXER_BGN + 10 );
//VCҵ�������˫��ͨ����			��Ϣ�壺TLogicChannel
OSPEVENT(VC_MTMGR_DSFWD_OLC_CMD,				EV_MIXER_BGN + 11 );

//�����߼�ͨ���ɹ���֪ͨ,MtMgrApp->VcApp, ��Ϣ�壺byChannelmode
OSPEVENT(MTMGR_VC_BWD_OLCOK_NTF,				EV_MIXER_BGN + 12 );
//ǰ���߼�ͨ���ɹ���֪ͨ,MtMgrApp->VcApp, ��Ϣ�壺byChannelmode
OSPEVENT(MTMGR_VC_FWD_OLCOK_NTF,				EV_MIXER_BGN + 13 );
//�޸ĺ���ģʽ��VcApp->MtMgrApp,	��Ϣ�壺byCallMode
OSPEVENT(VC_MTMGR_CHGCALLMODE_CMD,				EV_MIXER_BGN + 14 );

//�Ҷ��նˣ�	VcApp->MtMgrApp,	��Ϣ�壺byDel(�Ƿ�ɾ��)
OSPEVENT(VC_MTMGR_DROPMT_CMD,					EV_MIXER_BGN + 15 );
//�ն�ɾ��/�Ҷϴ����֪ͨVC��		��Ϣ�壺TMtAlias + byDel(�Ƿ�ɾ��)
OSPEVENT(MTMGR_VC_DROPMT_NTF,					EV_MIXER_BGN + 16 );   //�����Զ���ᶨʱ��

//ǰ���߼�ͨ���ɹ���֪ͨ,MtMgrApp->VcApp, ��Ϣ�壺byChannelmode
OSPEVENT(MTMGR_VC_FWD_OLCFAIL_NTF,				EV_MIXER_BGN + 17 );

//ǰ���߼�ͨ���ɹ���֪ͨ,VcApp->MtMgrApp, ��Ϣ�壺tMT+TLogicalChannel_HasChnIdx
OSPEVENT(VC_MTMGR_BWD_OLCOK_NTF,				EV_MIXER_BGN + 18 );
OSPEVENT(VC_MTMGR_BWD_OLCFAIL_NTF,				EV_MIXER_BGN + 19 );

/*--------------------------------------------
VCҵ������ն˶���ϵ�� VcApp->MtMgrApp
---------------------------------------------*/
//���ն�׼��������
OSPEVENT(VC_MTMGR_MTRCV_CMD,					EV_MIXER_BGN + 20 );
//���ն�׼��������
OSPEVENT(VC_MTMGR_MTSND_CMD,					EV_MIXER_BGN + 21 );
//���ն�����ؼ�֡,		��Ϣ�壺u8(byMode: v/secv) + u8(byChnIdx) + BOOL32 bDirectApplyMt(�Ƿ�ֱ�����ն�����)
OSPEVENT(VC_MTMGR_REQIFRAME_CMD ,				EV_MIXER_BGN + 22 );
//�����ն˽��յ�����,	��Ϣ�壺tLogicChannel
OSPEVENT(VC_MTMGR_MTRCVBRCTRL_CMD ,				EV_MIXER_BGN + 23 );
//�����ն˷��͵�����,	��Ϣ�壺tLogicChannel
OSPEVENT(VC_MTMGR_MTSNDBRCTRL_CMD,				EV_MIXER_BGN + 24 );
//���߼�ͨ������,		��Ϣ�壺u8(byFwd) + u8(ChannelType:V,A...)
OSPEVENT(VC_MTMGR_CLC_CMD,						EV_MIXER_BGN + 25 );
//�����ն˱���ֱ���,	��Ϣ�壺u8(byRes) + u8(mode: MODE_VIDEO) + u8(byChnIdx)
OSPEVENT(VC_MTMGR_MTRESCTRL_CMD,				EV_MIXER_BGN + 26 );
//�����ն˱���֡��,		��Ϣ�壺u8(byFps) + u8(mode: MODE_VIDEO) + u8(byChnIdx)
OSPEVENT(VC_MTMGR_MTFPSCTRL_CMD,				EV_MIXER_BGN + 27 );
//�ն˸ı��������֪ͨ
OSPEVENT(VC_MTMGR_MTRCVBRCHG_NTF,				EV_MIXER_BGN + 28 );
//�ն˻ָ��������Դ֪ͨ
OSPEVENT(VC_MTMGR_MTENCDECRES_RESUME_NTF,		EV_MIXER_BGN + 29 );

/*---------------------------------
�ն˱仯֪ͨVC	MtMgrApp->VcApp
----------------------------------*/
//����״̬�ı�֪ͨ,		��Ϣ�壺BOOL(bOnline)+u8(byReason)
OSPEVENT(MTMGR_VC_OnLineST_NTF,					EV_MIXER_BGN + 30 );
//�ն˹ر��߼�ͨ��֪ͨ,	��Ϣ�壺TLogicChannel + u8(byFwd) 
OSPEVENT(MTMGR_VC_CLC_NTF,						EV_MIXER_BGN + 31 );
//�ն˸ı䷢������֪ͨ,	��Ϣ�壺u16(wBitrate)
OSPEVENT(MTMGR_VC_MTSNDBRCHG_NTF,				EV_MIXER_BGN + 32 );
//�ն˸ı��������֪ͨ,	��Ϣ�壺u16(wBitrate)
OSPEVENT(MTMGR_VC_MTRCVBRCHG_NTF,				EV_MIXER_BGN + 33 );

//�ͷ�˫������
OSPEVENT(VC_MTMGR_RELEASEH239TOKEN_CMD,			EV_MIXER_BGN + 34 );

//�ն˺���ģʽ�ı�֪ͨ
OSPEVENT(VC_MTMGR_MODMTCALLMODE_CMD,			EV_MIXER_BGN + 35 );
OSPEVENT(MTMGR_VC_MTCALLMODE_NOTIF,				EV_MIXER_BGN + 36 );

//�ն�״̬�ı�֪ͨ,		��Ϣ�壺TMtStatus
OSPEVENT(VC_MTMGR_MTSTATUS_CMD,					EV_MIXER_BGN + 37 );
OSPEVENT(MTMGR_VC_MTSTATUS_NOTIF,				EV_MIXER_BGN + 38 );

//����֪ͨ
OSPEVENT(VC_MTMGR_MPDISCONNECTED_NTF,   		EV_MIXER_BGN + 39 );



/*---------------------------------
VRS����	MtMgrApp <-> VcApp
----------------------------------*/
// MsgBody: TStartRecMsgInfo + u16 wMtDialRate + u8 byCallMode
OSPEVENT(VC_MTMGR_ADDREC_REQ,   				EV_MIXER_BGN + 40 );		// ���¼���ն�
OSPEVENT(MTMGR_VC_ADDREC_ACK,   				EV_MIXER_BGN + 41 );
OSPEVENT(MTMGR_VC_ADDREC_NACK,   				EV_MIXER_BGN + 42 );
// MsgBody: TMtAlias���б��� + TPlayEqpAttrib + u16 wMtDialRate + u8 byCallMode
OSPEVENT(VC_MTMGR_ADDPLAY_REQ,   				EV_MIXER_BGN + 43 );		// ��ӷ����ն�
OSPEVENT(MTMGR_VC_ADDPLAY_ACK,   				EV_MIXER_BGN + 44 );
OSPEVENT(MTMGR_VC_ADDPLAY_NACK,   				EV_MIXER_BGN + 45 );

//zjj20150521 mtmgr��֪interaction�˿ڻص���Ϣ��������Ҫ�Ƕ˿ڵ�����Ϣ
//��Ϊhdu�õĶ˿ںͻ�ؼ���õĶ˿���interaction�й���
OSPEVENT(MTMGR_INTERACT_CBPORTMGR_NTF,   	EV_MIXER_BGN + 46 );

//����޸Ļ������룬����ŵ�����֪ͨmtmgr����
OSPEVENT(VC_MTMGR_CONFINFO_NTF,   				EV_MIXER_BGN + 47 );

//ͣ˫��mtmgr�ָ������ն˵Ľ��պͷ�������֪ͨ
OSPEVENT(MTMGR_VC_STOPSECVIDEOBRDOK_NTF,   				EV_MIXER_BGN + 48 );

//MtMgr����E164�Ų���NU��Ϣ
OSPEVENT(MTMGR_UPU_FINDNUBYE164NO_CMD,   				EV_MIXER_BGN + 49 );

//upu��ʱ��ѯ����ƽ̨��nu��Ϣ һ����һ��
OSPEVENT(UPUSSN_REFRESHNUINFO_TIMER,   			     	EV_MIXER_BGN + 50 );

//Upu������MtMgr�����ն�
OSPEVENT(UPU_MTMGR_ADDMTWITHNU_CMD,                     EV_MIXER_BGN + 51 );

//Upuapp��upussnע��NU
OSPEVENT(UPUDATA_UPUSSN_REGISTNU_CMD,                   EV_MIXER_BGN + 52 );

//���²�ѯ�¼�
OSPEVENT(UPUSSN_REFRESHFINDLIST_TIMER,                 EV_MIXER_BGN + 53 );

//��ش����ɣ�vc�յ�spynotify��֪ͨmtmanagerģ�⿪ͨmmcu����ͨ����Ϣ
OSPEVENT(VC_MTMGR_SPYFWD_OPENLOGICCHNNL_CMD,			EV_MIXER_BGN + 54 );
//��ش����ɣ�vc����spynotify��֪ͨmtmanagerģ�⿪ͨsmcu����ͨ����Ϣ
OSPEVENT(VC_MTMGR_SPYBWD_OPENLOGICCHNNL_CMD,			EV_MIXER_BGN + 55 );
//��ش����ɣ�// mtid + Fwd + logicalChnl 
OSPEVENT(VC_MTMGR_SPY_CLOSELOGICCHNNL_CMD,			EV_MIXER_BGN + 56 );

//��ش����� ������Զ��rtcp��ַ�Ľ��� u8 ChnIdx + u8 byMode + TTransportAddr
OSPEVENT(VC_MTMGR_SPYMT_STARTRTCP_CMD,					EV_MIXER_BGN + 57 );
OSPEVENT(VC_MTMGR_SPYMT_STOPRTCP_CMD,					EV_MIXER_BGN + 58 );

//��ش����� ��ش��ն�����ؼ�֡  TMt + Mode + Chnidx
OSPEVENT(VC_MTMGR_SPYMT_FASTUPDATE_CMD,					EV_MIXER_BGN + 59 );

// ���������ն�����
OSPEVENT(VC_MTMGR_SETMTVOLUME_CMD,						EV_MIXER_BGN + 60 );
/********** VC��MtMgr��������[��͸��](30201-30400) ---���û������ڲ�ҵ����Ϣ end********/

/********** InterAct��InterAct�ڲ���������((30401-30500)) ---���õ���ǽ�ڲ�ҵ����Ϣ bgn********/
// ��������ý����Դ�ص�֪ͨ
OSPEVENT( INTERACT_INTERACT_CBALLMEDIARES_NTF,  EV_TVWALL_BGN );

// �˿�VMP�����ص�֪ͨ
OSPEVENT( INTERACT_INTERACT_CBMULTIPICMGR_NTF,  EV_TVWALL_BGN + 1 );

// ��ͳVMP�����ص�֪ͨ
OSPEVENT( INTERACT_INTERACT_CBVMPMGR_NTF,       EV_TVWALL_BGN + 2 );

// Mixer�����ص�֪ͨ
OSPEVENT( INTERACT_INTERACT_CBMIXERMGR_NTF,     EV_TVWALL_BGN + 3 );

// BAS�����ص�֪ͨ
OSPEVENT( INTERACT_INTERACT_CBBASMGR_NTF,       EV_TVWALL_BGN + 4 );

// HDU�����ص�֪ͨ
OSPEVENT( INTERACT_INTERACT_CBHDUMGR_NTF,       EV_TVWALL_BGN + 5 );

// �˿ڲ����ص�֪ͨ
OSPEVENT( INTERACT_INTERACT_CBPORTMGR_NTF,       EV_TVWALL_BGN + 6 );
/********** InterAct��InterAct�ڲ���������((30401-30500)) ---���õ���ǽ�ڲ�ҵ����Ϣ end********/


#endif /* _EV_MCU_H_ */


