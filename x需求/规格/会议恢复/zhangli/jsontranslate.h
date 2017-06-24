/*****************************************************************************
ģ����      : common
�ļ���      : jsontranslate.h
����ʱ��    : 2014�� 08�� 26��
ʵ�ֹ���    : 
����        : ��Ҳ
�汾        : 
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2014/08/26  5.0         ��Ҳ          ����
******************************************************************************/
#ifndef	_JSON_TRANSLATE_H_
#define	_JSON_TRANSLATE_H_

#include "osp.h"
#include "mcustruct.h"
#include "vccommon.h"
#include "mcuconst.h"
#include "jansson_s.h"
#include "maustruct.h"
#include "authmanage.h"
#include "mcuinnerstruct.h"
#include <string>
using namespace std;

#pragma warning( disable:4786 )

/* ��ͷ�ļ�ʵ�ֽӿں�������
GetConfE164FromJson
GetConfNameFromJson
GetMOIDFromJson
GetConfInfoFromJson
GetConfInfoExFromJson
GetMtAliasListFromJson
GetVmpModuleFromJson
GetPollModuleFromJson
GetHduModuleFromJson
GetReqHeadFromJson
GetConfIdxFromJson
GetErrCodeFromJson
GetConfIdFromJson
GetMsgTypeFromJson
GetDelayFromJson
GetMtListFromJson
GetDomainListFromJson
GetConfStateTypeFromJson

SetMtAliasListToJson
ApiSetConfInfoToJson
SetConfInfoExToJson
SetMsgTypeToJson
SetReqHeadToJson
SetConfIdxToJson
SetErrCodeToJson
SetConfIdToJson
SetConfE164ToJson
SetDelayToJson
SetMtListToJson
SetDomainListToJson
SetConfDataToJson
SetHasXmpuSerToJson
SetConfStateTypeFromJson
SetConfNameToJson
*/

// ����MCU���͸�MAU������
//#define MQ_MAU_CONF_EX          "mau.conf.ex:172.16.80.104"
//#define MQ_MAU_CONF_K           "mau.conf.k:172.16.80.104"
#define MQ_MAU_CONF_EX          "mau.conf.ex"
#define MQ_MAU_CONF_K           "mau.conf.k"


// ����MAU���͸�MCU������
//#define MQ_MCU_EX             "cmu.conf.ex:172.16.80.104"
#define MQ_MCU_EX               "cmu.conf.ex"

#define MAXLEN_JSONBUF         (u16)(SERV_MSG_LEN - SERV_MSGHEAD_LEN - 500) // TReqHeadInfo ����Ϊ462���˴�ȡ500�ֽ�
#define MAXLEN_MSGTYPE         (u16)255

#define MAXNUM_ONEPACK         (u32)80                  

// Json�ֶκ궨��
#define JSON_MSGTYPE           "type"            //��Ϣ����
#define JSON_ERRCODE           "errcode"         //������

#define JSON_QNAME             "qname"           //MQ������
#define JSON_CMUID             "cmuid"           //MAU��¼CMU��InstId
#define JSON_CMUIP             "ip"				//MAU��¼CMU��Ip
#define JSON_CMUPID			   "pid"			// cmupid

#define JSON_REQHEADINFO       "reqheadinfo"     //��Ϣͷ
#define JSON_REQHEAD_UNIQUEID  "uniqueid"
#define JSON_REQHEAD_EVENTID   "reqeventid"
#define JSON_REQHEAD_SRCID     "reqsrcid"
#define JSON_REQHEAD_MTREQID   "mtreqid"
#define JSON_REQHEAD_RPC	   "reqrpc"
#define JSON_REQHEAD_RPCID	   "reqrpcid"
#define JSON_REQHEAD_PRODUCTID "productid"        //�ն˵�productid
#define JSON_REQHEAD_VERID     "verid"            //�ն˵�verid

#define JSON_CONFCREATEBY      "confcreateby"     //���鴴����ʽ
#define JSON_CONFE164          "confE164"         //����E164
#define JSON_CONFIDX           "confidx"          //��������
#define JSON_CONFID            "confid"           //����id
#define JSON_MEETINTID         "meetingID"
#define JSON_MOID              "moid"             //��moid
#define JSON_SMOID             "smoid"            //�ϼ����moid
#define JSON_GUID              "guid"
#define JSON_DOMAINNAME        "domainname"
#define JSON_CONFNAME          "confname"
#define JSON_CREATORNAME       "creatorname"       //�����߱���
#define JSON_CREATORMOID       "creatormoid"       //������moid
#define JSON_MCUADDR		   "mcuaddr"			  //���������mcu��ַ
#define JSON_ISPORTCONF        "isportconf"        // 0 ��ͳ���飻 1 �˿ڻ���
#define JSON_ISNEEDPWD		   "isneedpwd"		  //�Ƿ���Ҫ����
#define JSON_PSW               "psw"               //��������
#define JSON_BANDWIDTH         "bandwidth"         //��������
#define JSON_RES               "resolution"        //����ֱ���
#define JSON_DURATION          "duration"          //����ʱ��
#define JSON_ENCRYPT_MANUAL	   "enckeymanual"	  //�Ƿ��Զ����ܣ�0-�Զ� 1-�ֶ�
#define JSON_ENCRYPTMODE       "encryptmode"       //��������ģʽ��2-AES��0-������
#define JSON_ENCRYPTPARAM      "encryptparam"      //�������ܲ���
#define JSON_ENCRYPTKEY        "encryptkey"        //AES��������key
#define JSON_CHAIRMAN          "chairman"          //��ϯ
#define JSON_CHAIRMANALIAS	   "chairmanalias"	  //��ϯ����
#define JSON_SPEAKER           "speaker"           //������
#define JSON_SPEAKERALIAS      "speakeralias"      //�����˱���
#define JSON_MIXMODE           "mixmode"           //0-��ʼֵ�� 1-���ۣ�2-���ƻ�����4-����������5-����+��������
#define JSON_MIXNUM            "mixnum"
#define JSON_MIXMAXNUM         "mixmaxnum"
#define JSON_VACINTERVAL       "vacinterval"       //����������� ��λ��s
#define JSON_ISVOICEINSPIRE    "isvoiceinspire"    //�Ƿ�����������
#define JSON_MIXPARAM		   "mixparam"		  // ����ģ�����
#define JSON_ALLMUTE           "allmute"           //1-ȫ��������0-������
#define JSON_ALLSILENCE        "allsilence"        //1-ȫ�徲����0-������
#define JSON_DUALMODE          "dualmode"          //����˫����1-�����ն�,0-������
#define JSON_SPEAKERSRC        "speakersrc"        //�����˵�Դ:   0-���Լ� 1-����ϯ 2-����һ�η�����
#define JSON_CALLMODE          "callmode"          //����ģʽ��0-�ֶ�����, 2-��ʱ����
#define JSON_CALLINTERVAL      "callinterval"      //���м������С10s
#define JSON_CALLTIMES         "calltimes"         //���д�������С2��,���10��
#define JSON_SAT               "sat"               //�Ƿ����ǻ��� 0-��ͨ���飻 1-���ǻ���
#define JSON_SATBANDWIDTH      "satbandwidth"      //֧���鲥���ʣ��������ǣ�sat�ֶ�Ϊ1ʱ��Ч
#define JSON_PUBLISHCONF       "publicconf"        //1-�������飻0-�ǹ�������
#define JSON_OPENMODE          "openmode"          //0-���ػ��飻1-ƾ���������飻2-�������飻
#define	JSON_NODISTURB		   "nodisturb"		  //��Ӧ�ն������ģʽ: 0-������ţ�1-�����
#define JSON_SHARECONF         "shareconf"         //�Ƿ������ 1-����0-��ͨ����
#define JSON_VMPMODULE         "vmpmodule"         //�Ƿ�ʹ�û���ϳ�ģ�� 0-��ʹ�ã�1-ʹ��
#define JSON_POLLMODULE        "pollmodule"        //�Ƿ�ʹ����ѯģ�� 0-��ʹ�ã�1-ʹ��
#define	JSON_MIXMODULE		   "mixmodule"		  //�Ƿ�ʹ�û���ģ�� 0-��ʹ�ã�1-ʹ��
#define JSON_HDUMODULE         "hdumodule"         //�Ƿ�ʹ�õ���ǽģ�� 0-��ʹ�ã�1-ʹ��
#define JSON_AUTORECATTRB      "autorecattrb"     //�Զ�¼������
#define JSON_AUTOREC		   "autorec"		  //�Ƿ��Զ�¼���־
#define JSON_MANUALRELEASE     "manualrelease"     //�Ƿ��ֶ���� 1:�ֶ���0���Զ�
#define JSON_VIDEOPRIOR        "videoprior"        //��Ƶ����  1-�������� 0-�ٶ�����
#define JSON_DELAY             "delay"             //�����ӳ�ʱ��
#define JSON_MEDIAMODE         "mediamode"         //ý���ʽ 1-��Ƶ��2-��Ƶ��3-����Ƶ
#define JSON_FORCEBRD          "forcebrd"          //ǿ�ƹ㲥  1-ǿ�ƹ㲥  0-ȡ��ǿ�ƹ㲥
#define JSON_HASXMPUSER		   "hasxmpu"			  //�Ƿ�����xmpu������
#define JSON_SMARTPACKETLOSS   "smartpacketloss"	  //�Ƿ�ѡȡ�����ܶ����ش� //0-��ʹ�ö����ش� //1-ʹ�ö����ش�
#define JSON_ONEREFORMING	   "onereforming"	  //�Ƿ�ѡȡ�˹�һ����
#define JSON_SPEAKERAUDIO	   "speakeraudio"	  //�����˴���Ƶ�� 0-������Ƶ��1-����Ƶ
#define JSON_DOUBLESPEED	   "doublespeed"		  //�Ƿ�ʹ��˫��
#define JSON_SECMEDIABITRATE   "secmediabitrate"   //��������
#define JSON_AUTOCLOSE		   "autoclose"		  //�Զ�����
#define JSON_INTELLERROR	   "intellerrorelimination"	//���ܲ������
#define JSON_SPEAKERAUDIO	   "speakeraudio"	  //�����˴���Ƶ
#define JSON_DOUBLEPERCENT	   "doublepercent"     //˫������
#define JSON_DOUBLEFORMAT	   "doubleformat"	  //˫����Ƶ��ʽ
#define JSON_H239			   "h239"			  //�Ƿ�����H239
#define JSON_DATAMODE		   "datamode"		  //0-���������ݵ�����Ƶ���� 1-�������ݵ�����Ƶ���� 2-ֻ�����ݵĻ���
#define JSON_URL			   "url"				  //�����õ�URL
#define JSON_ISOLDMCU		   "isoldmcu"         //�Ƿ������ɻ���


#define JSON_MAXJOINEDMT	   "maxjoinedmt"		  //�������ն�����



#define JSON_MCULIST		   "mculist"			  //mcu�б�
#define JSON_MCUNAME		   "mcuname"			  //mcu����
#define JSON_MCUTYPE		   "mcutype"			  //mcu����
#define JSON_MCUIP			   "mcuip"			  //mcuIP
#define JSON_GKPREFIX		   "gkprefix"		  //MCU��GKǰ׺
#define JSON_DCASTCONF		   "dcastconf"		  //�鲥��������
#define JSON_DCAST			   "dcast"			  //�Ƿ�֧���鲥
#define JSON_DCASTIP		   "dcastip"			  //�鲥IP
#define JSON_DCASTPORT		   "dcastport"		  //�鲥�˿�

#define JSON_SATCONF		   "satconf"			  //���ǻ�������
#define JSON_SAT			   "sat"				  //�Ƿ����ǻ���
#define JSON_SATIP			   "satip"			  //���ǻ���IP
#define JSON_SATPORT		   "satport"			  //���ǻ���˿�
#define JSON_SATSPYNUM		   "satspynum"		  //�ش�ͨ����
#define JSON_SATBANDWIDTH	   "satbandwidth"	  //�鲥����

#define JSON_RECORDCONF         "recordconf"         //¼������
#define JSON_REC_NAME           "recname"            //¼���ļ���
#define JSON_RECORDNAME         "recordname"         //¼���ļ���
#define JSON_RECCHN             "recchn"             //¼��ͨ��
#define JSON_IS_REC_MAIN_VID    "isrecmainvideo"     //�Ƿ�¼������ʽ����
#define JSON_IS_REC_DSTREAM     "isrecdstream"       //�Ƿ�¼��˫��
#define JSON_RECENABLE          "recenable"          //�Ƿ񼤻�
#define JSON_RECPUBLISH         "recpublish"         //�Ƿ��Զ�����

#define JSON_CASCADECONF	   "cascadeconf"		  //��������������Ϣ
#define JSON_CASCADEMODE	   "cascademode"		  //����ģʽ
#define JSON_CASCADEISUPLOAD   "isupload"		  //�����Ƿ������ϴ�
#define JSON_CASCADEISSPY	   "isspy"			  //�����Ƿ�����ش�
#define JSON_CASCADESPYBW	   "spybandwidth"	  //�����ش�����

#define JSON_SWITCHMODE        "switchmode"        //ѡ��ģʽ
#define JSON_SRCMT             "srcmt"             //Դ�ն�
#define JSON_DSTMT             "dstmt"             //Ŀ���ն�
#define JSON_MT                "mt"
#define JSON_MTTYPE            "mttype"            //�ն�����
#define JSON_BITRATE		   "bitrate"           //�ն�����
#define JSON_PROTOCOL		   "protocol"		  //Э��
#define JSON_TIMEID            "timeid"   
#define JSON_MTNO              "mtNO"              //E164/PhoneNum
#define JSON_MTALIAS           "mtalias"           //�ն˱���
#define JSON_MTALIASINFO	   "mtaliasinfo"       //�ն˱���
#define JSON_MTONLINE          "online"            //�Ƿ�����
#define JSON_MTSILENCE         "silence"           //����
#define JSON_MTMUTE            "mute"              //����
#define JSON_MTSECVIDEO        "secvideo"          //�Ƿ���˫��
#define JSON_MTSENDRATE        "sendrate"          //ʵ�ʷ�������
#define JSON_MTRCVRATE         "rcvrate"           //ʵ�ʽ�������
#define JSON_DATAISMODIFIED	   "dataismodified"	  //�����Ƿ񱻴۸�
#define JSON_MTIDENTIFY		   "mtidentify"		  //�ն˱�ʶ
#define JSON_MTCHNID		   "mtchnid"			  //�ն�ͨ��id��Ϊ��֧�ֶ���
#define JSON_MTID			   "mtid"			  //�ն�id
#define JSON_MTDESC			   "mtdesc"			  //�ն�����
#define JSON_MCUIDX			   "mcuidx"			  //MCU������
#define JSON_MTIP			   "mtip"			  //�ն�ip
#define JSON_MTIPPORT		   "mtip"			  //�ն�ipport
#define JSON_MESSAGE		   "msg"				  //��Ϣ����
#define JSON_SELECTSRC		   "selectsrc"		  //ѡ��Դ
#define JSON_SELECTDST		   "selectdst"		  //ѡ��Ŀ��
#define JSON_SELECTSRCTYPE	   "selectsrctype"	  //ѡ��Դ����
#define JSON_SENDMSGTYPE	   "msgtype"			 //��Ϣ����:1:��ҳ���� 2:����������� 3:ȫҳ����
#define JSON_ROLLRATE		   "rollrate"			//�����ٶ� 1������ 2������ 3������
#define JSON_ROLLTIMES		   "rolltimes"			 //����������1-255 ����Ϊ1�� 255Ϊ�����ƹ���
#define JSON_STREAMCHN		   "streamchn"		  //����ͨ��
#define JSON_STREAMCHNID	   "chnid"			  //����ͨ����
#define JSON_STREAMCHNALIAS	   "chnalias"		  //����ͨ������
#define JSON_ISSENDING		   "issending"		  //�Ƿ��ڷ���
#define JSON_VIDEOSNDCHN	   "vsndchn"			  //��Ƶ����ͨ��
#define JSON_VIDEORCVCHN	   "vrcvchn"			  //��Ƶ����ͨ��
#define JSON_AUDIOSNDCHN	   "asndchn"			  //��Ƶ����ͨ��
#define JSON_AUDIORCVCHN	   "arcvchn"			  //��Ƶ����ͨ��
#define JSON_DVIDEOSNDCHN	   "svsndchn"		  //˫����Ƶ����ͨ��
#define JSON_DVIDEORCVCHN	   "svrcvchn"		  //˫����Ƶ����ͨ��
#define JSON_SUCCESS		   "success"			//�Ƿ�ɹ�

#define JSON_CODECTYPE		    "codectype"		  //���������

#define JSON_TEMPLATELIST      "templateinfo"
#define JSON_CONFLIST          "confinfo"
#define JSON_VIDEOFORMAT       "videoformat"
#define JSON_SECVIDEOFORMAT    "secvideoformat"
#define JSON_MEDIATYPE         "mediatype"
#define JSON_MEDIABITRATE      "mediabitrate"
#define JSON_MEDIARES          "mediares"
#define JSON_MEDIAFRAME        "mediaframe"
#define JSON_MEDIAH264		   "mediah264"
#define JSON_AUDIOFORMAT       "audioformat"
#define JSON_AUDIOTYPE         "audiotype"
#define JSON_CONFSTARTTIME     "starttime"
#define JSON_CONFENDTIME       "endtime"
#define JSON_BOOKSTARTTIME	   "bookstarttime"

#define JSON_VMPPARAM          "vmpparam"
#define JSON_VMPISCAPING	   "enable"			   //����ϳ����ڽ���
#define JSON_VMPBRDST          "vmpbrdst"           //����ϳ����ն˹㲥 0-���㲥��1-�㲥
#define JSON_VMPAUTO           "vmpauto"            //����ϳ��Զ�
#define JSON_VMPSTYLE          "vmpstyle"           //����ϳɷ��
#define JSON_VMPSCHEMEID       "vmpschemeid"        //����ϳɷ��
#define JSON_VMPMODE           "mode"               //����ϳ�ͼ�񸴺Ϸ�ʽ
#define JSON_VMPBATCHPOLLTIME  "batchpolltime"      //����ϳ�������ѯ������룩������modeΪ4ʱ��Ч
#define JSON_VMPBATCHPOLLNUM   "batchpollnum"       //����ϳ�������ѯ����������modeΪ4ʱ��Ч
#define JSON_VMPPRIM           "vmprim"             //����ϳ�ʹ�ñ߿� 0-��ʹ�ã� 1-ʹ��
#define JSON_VMPVOICEHINT      "voicehint"          //����ϳ�������ʾ��
#define JSON_VMPADDALIAS       "vmpaddalias"        //����ϳɱ�����ʾ 0-����ʾ��1-��ʾ
#define JSON_VMPMEMBERS        "vmpmembers"         //����ϳɳ�Ա
#define JSON_VMPCHNIDX         "chnidx"             //����ϳɳ�Աλ��
#define JSON_VMPINDEX          "vmpindex"           //����ϳɶ�Ӧ�ն��б�λ��
#define JSON_VMPTYPE           "vmptype"            //����ϳ�/����ǽ��Ա����
#define JSON_VMPSTATUS         "vmpstatus"          //����ϳɳ�Ա״̬
#define JSON_VMPPOLLPARAM      "memberpollparam"    //����ϳɶ����ͨ��������ѯ
#define JSON_VMPPOLLIDX        "chnidx"             //����ϳ�ͨ������
#define JSON_VMPPOLLNUM        "pollnum"            //����ϳ���ѯ������0Ϊһֱ��ѯ
#define JSON_VMPPOLLKEEPTIME   "keeptime"           //����ϳ���ѯʱ����(��)
#define JSON_VMPPOLLMT         "pollmt"             //����ϳ���ѯ�ն�

#define JSON_POLLPARAM         "pollparam"
#define JSON_POLLMODE          "pollmode"           //��ѯģʽ  0-����ѯ�㲥  1-��ͼ�񱾵���ѯ�㲥  
														   //3-������������  6-������ѯ��Ƶ  7-������ѯ����
														   //8-����+������ѯ��Ƶ   9-����+������ѯ����   
														   //10-��ϯ����Ƶ��ѯ  11-��ϯ����Ƶ��ѯ
#define JSON_POLLNUM           "pollnum"            //��ѯ������0Ϊһֱ��ѯ
#define JSON_POLLKEEPTIME      "keeptime"           //��ѯ������룩
#define JSON_POLLSTATE         "pollstate"          //��ѯ״̬
#define JSON_POLLMT            "pollmt"             //��ѯ��Ա
#define JSON_CURPOLLMT         "curpollmt"          //��ǰ��ѯ��Ա
#define JSON_POLLIDX           "pollindex"          //��ѯ��Ӧ�ն��б�λ��

#define JSON_CONFDATAINFO      "confdatainfo"       //mpc��mpcd�ϱ�������Ϣ
#define JSON_CONFMTNUM         "mtnum"              //��������ն���Ŀ
#define JSON_CMFLAG            "flag"			   //��ܻ�ȡ�����б�ʱ��ʶ

#define JSON_DOMAIN            "domain"
#define JSON_DELFLAG           "delflag"            //�Ƿ�ɾ����ʾ

#define JSON_TELCONFFLAG       "telconfflag"        //�Ƿ����绰�����ʾ
#define JSON_LIMITEDFLAG       "limitedflag"        //�Ƿ������˺�
#define JSON_DOMAINLVL         "domainlvl"          //�򼶱�
#define JSON_PLATFORMPREFIX    "platformprefix"     //ƽ̨��ǰ׺
#define JSON_MAXCONFNUM        "maxconfnum"         //�������������ٿ���
#define JSON_MAXCCONFNUM       "maxcconfnum"        //�����������������

#define JSON_ROLLCALLMODE	   "rollmode"		   //����ģʽ
#define JSON_ROLLCALLER		   "rollcaller"		   //������
#define JSON_ROLLCALLEE	       "rollcallee"		   //��������

#define JSON_VIPMT			   "vipmt"			   //vip�ն��б�
#define JSON_MIXMEMBER		   "mixmember"		   //���ƻ����ն˱�
#define JSON_MIXINDEX		   "mixindex"		   //���ƻ����ն�������
#define JSON_LEFTTIME		   "lefttime"		   //����ʣ��ʱ��
#define JSON_CONFSTATETYPE     "confstatetype"      //����״̬����

#define JSON_VOLUME				"volume"				//����

#define JSON_HDUPARAM           "hduparam"
#define JSON_ALLHDUINFO			"allhduinfo"			//���еĵ���ǽ��Ϣ
#define JSON_HDULIST			"hdulist"			//����ǽ�б�
#define JSON_HDUISONLINE		"isonline"			//����ǽ�Ƿ�����
#define JSON_HDUCHNNUM			"chnnum"				//����ǽͨ����Ŀ
#define JSON_HDUALIAS			"hdualias"			//����ǽ����
#define JSON_HDUGUID			"hduguid"			//����ǽguid
#define JSON_HDUCHNINFO			"chninfo"			//����ǽͨ����Ϣ
#define JSON_HDUCHNISUSED       "isused"				//����ǽͨ���Ƿ�ʹ��
#define JSON_HDUCHNISSILENCE	"issilence"			//����ǽͨ���Ƿ���
#define JSON_HDUID				"hduid"				//����ǽid��
#define JSON_HDUCHLIDX			"chnnlidx"			//����ǽͨ������
#define JSON_HDUSCHEDIDX		"hduschedidx"		//����ǽԤ��id
#define JSON_HDUSTYLE			"hdustyle"			//����ǽ���
#define JSON_HDUMEMBER			"hdumember"			//����ǽͨ����Ա
#define JSON_HDUSUBCHLIDX		"subchnidx"			//����ǽ��ͨ������
#define JSON_HDU_CHNINFO		"hduchninfo"			//����ǽͨ����Ϣ(������ѯʱ�õ�)
#define JSON_HDU_INDEX			"hduindex"			//����ǽ�ն�����(����Ԥ��ʱʹ��)		   
#define JSON_PUBLISH_MODE       "publishmode"        //����ģʽ
#define JSON_ALIAS_TYPE         "aliastype"          //��������
#define JSON_ADDR               "addr"               //��ַ��IP��
#define JSON_VRSNO              "vrsNO"              //VRS����
#define JSON_VRS_ALIAS          "vrsalias"           //VRS����
#define JSON_PROG               "prog"               //����
#define JSON_CURPROG            "curprog"            //��ǰ¼�����
#define JSON_TOTALTIME          "totaltime"          //¼����ʱ��
#define JSON_STATUS             "status"             //״̬
#define JSON_CHANSTATE          "chanstate"          //ͨ��״̬
#define JSON_CHNID              "chnid"              //ͨ����
#define JSON_FILENAME			"filename"			//�����ļ���
#define JSON_ISSECVIDEOPLAY		"issecvideoplay"		//�Ƿ�˫������
#define JSON_FILEID				"fileid"				//�����ļ�id
#define JSON_PLAYCHN			"playchn"			//����ͨ��
#define JSON_RECPLAY            "recplay"            //¼�� ����
#define JSON_RECID              "recid"              //¼��id
#define JSON_ISMERGE            "ismerge"            //�Ƿ�ϲ�¼��

#define JSON_SMCU				"smcu"				//�¼�MCU
#define JSON_SMCULIST			"smculist"			//�¼�MCU�б�
#define JSON_OPERTYPE			"opertype"			//��������
#define JSON_OPEROVER			"operover"			//��������
#define JSON_ENDALLSUBCONF		"endallsubconf"		//���������¼�����

#define JSON_MTCAMERA_PARAM		"mov"				//Զң����
#define JSON_MTCAMERA_POS		"pos"				//��ƵԴλ��
#define JSON_RCENABLE			"enbale"				//����ͷʹ��
#define JSON_ADDMT_TYPE         "addtype"            //����ն˷�ʽ���ն���ᡢ������ӣ�
#define JSON_MTINDEX			"mtindex"			//�ն�����������ģ������ģ�
#define JSON_MTCAMERA_NAME      "Name"              //��ƵԴԤ��λ
#define JSON_MTCAMERAVCL_INFO      "vclinfo"           ////ͨ��Ԥ��λ��Ϣ

#define JSON_MONITORSRC			"monitorsrc"			//���Դ
#define JSON_VIDSRCCHN			"vidsrcchn"			//��ƵԴͨ����
#define JSON_AUDSRCCHN			"audsrcchn"			//��ƵԴͨ����
#define JSON_DSTVIDADDR			"dstvidaddr"			//��ƵĿ�ĵ�ַ
#define JSON_DSTAUDADDR			"dstaudaddr"			//��ƵĿ�ĵ�ַ
#define	JSON_TRANSPORTADDR		"transportaddr"		//���紫���ַ
#define JSON_DSTADDR			"dstaddr"			//Ŀ�ĵ�ַ
#define JSON_DSTADDRLIST		"dstaddrlist"		//Ŀ�ĵ�ַ�б�
#define JSON_SRCRTCPADDR		"srcrtcpaddr"		//ԴRTCP��ַ

#define JSON_DOUBLEPAYLOAD		"doublepayload"		//��̬�غɲ���
#define JSON_REALPAYLOAD		"realpayload"		//��ʵ�غ�
#define JSON_ACTIVEPAYLOAD		"activepayload"		//��̬�غ�
#define JSON_MEMBERTYPE			"membertype"		//���Դ����0-none, 1-brd, 2-secbrd

#define JSON_AACCAP				"aaccap"				//��Ƶaac����
#define JSON_SAMPLEFREQ			"samplefreq"			//������
#define JSON_CHNLTYPE			"chnltype"			//��������
#define JSON_MAXFRAMENUM		"maxframenum"		//���֡��

#define JSON_BRDSRCTYPE         "brdsrctype"         //�㲥Դ����  0-��Ч  1-�ն�  2-�ϼ�mcu 3-�¼�mcu 4-vmp 5-mix 

#define JSON_MONITOR            "monitor"          //���Դ�ն� mpuid	
#define JSON_IP					"ip"
#define JSON_PORT				"port"

#define JSON_MTSRC				"src"
#define JSON_MTSRCTYPE			"srctype"

#define  JSON_AUTORECATTRB      "autorecattrb"  //�����Զ�¼��
#define  JSON_AUTOREC           "autorec"       //

#define JSON_DOUBLESTREAMMT		"doublevideomt"

//MAU��MCU��������
#define EV_MAU_MCU_CONNECT_REQ                      "MAU_MCU_CONNECT_REQ"
#define EV_MCU_MAU_CONNECT_ACK                      "MCU_MAU_CONNECT_ACK"
#define EV_MCU_MAU_CONNECT_NACK                     "MCU_MAU_CONNECT_NACK"

//CMU����֪ͨ
#define EV_MCU_MAU_LIVE_NTF                         "MCU_MAU_LIVE_NTF"

//MAU��MCU���ʹ�������
#define EV_MAU_CMU_CREATECONF_REQ                   "MAU_MCU_CREATECONF_REQ"
#define EV_MCU_MAU_CREATECONF_ACK	                "MCU_MAU_CREATECONF_ACK"
#define EV_MCU_MAU_CREATECONF_NACK                  "MCU_MAU_CREATECONF_NACK"

#define EV_MAU_MCU_RESTORECONF_REQ                  "MAU_MCU_RESTORECONF_REQ"
#define EV_MCU_MAU_RESTORECONF_ACK                  "MCU_MAU_RESTORECONF_ACK"
#define EV_MCU_MAU_RESTORECONF_NACK                 "MCU_MAU_RESTORECONF_NACK"


//MAU�������������Ϣ
#define EV_MAU_MCU_CONFINFO_REQ                     "MAU_MCU_CONFINFO_REQ"
#define EV_MCU_MAU_CONFINFO_ACK                     "MCU_MAU_CONFINFO_ACK"
#define EV_MCU_MAU_CONFINFO_NACK                    "MCU_MAU_CONFINFO_NACK"

//CM���������ϸ��Ϣ
#define EV_CM_CMU_DETAILCONFINFO_CMD				"CM_CMU_DETAILCONFINFO_CMD"

//MAU����MCU����ն�
#define EV_MAU_MCU_ADDMT_REQ                        "MAU_MCU_ADDMT_REQ"
#define EV_MCU_MAU_ADDMT_ACK                        "MCU_MAU_ADDMT_ACK"
#define EV_MCU_MAU_ADDMT_NACK                       "MCU_MAU_ADDMT_NACK"

//CM����MCU����ն�
#define EV_CM_CMU_ADDMT_REQ                        "CM_CMU_ADDMT_REQ"
#define EV_CMU_CM_ADDMT_ACK                        "CMU_CM_ADDMT_ACK"
#define EV_CMU_CM_ADDMT_NACK                       "CMU_CM_ADDMT_NACK"

//CM����MCUɾ���ն�
#define EV_CM_CMU_DELMT_REQ                        "CM_CMU_DELMT_REQ"
#define EV_CMU_CM_DELMT_ACK                        "CMU_CM_DELMT_ACK"
#define EV_CMU_CM_DELMT_NACK                       "CMU_CM_DELMT_NACK"

//CM����MCU�����ն�
#define EV_CM_CMU_CALLMT_REQ                        "CM_CMU_CALLMT_REQ"
#define EV_CMU_CM_CALLMT_ACK                        "CMU_CM_CALLMT_ACK"
#define EV_CMU_CM_CALLMT_NACK                       "CMU_CM_CALLMT_NACK"

//CM����MCU�Ҷ��ն�
#define EV_CM_CMU_DROPMT_REQ                        "CM_CMU_DROPMT_REQ"
#define EV_CMU_CM_DROPMT_ACK                        "CMU_CM_DROPMT_ACK"
#define EV_CMU_CM_DROPMT_NACK                       "CMU_CM_DROPMT_NACK"


//MAU����MCU��������
#define EV_MAU_MCU_RELEASECONF_CMD                  "MAU_MCU_RELEASECONF_CMD"

//MCU�������֪ͨ
#define EV_MCU_MAU_CONFRELEASE_NTF                  "MCU_MAU_CONFRELEASE_NTF"

//�����ն�״̬֪ͨ
#define EV_CMU_CM_MTLIST_NTF                        "CMU_CM_MTLIST_NTF"

//������Ϣ֪ͨ
#define EV_CMU_CM_CONFDETAILINFO_NTF                "CMU_CM_CONFDETAILINFO_NTF"

//�����Ҫ��Ϣ֪ͨ
#define EV_CMU_CM_SIMCONFINFO_NTF                   "CMU_CM_SIMCONFINFO_NTF"

//��ѯ����֪ͨ
#define EV_CMU_CM_POLLPARAM_NTF                     "CMU_CM_POLLPARAM_NTF"

//���鰲ȫ��Ϣ֪ͨ
#define EV_CMU_CM_CONFSAGEINFO_NTF                  "CMU_CM_CONFSAGEINFO_NTF"

//�����ʱ��֪ͨ
#define EV_CMU_CM_CONFDURATION_NTF                  "CMU_CM_CONFDURATION_NTF"
#define EV_MAU_CMU_CONFDURATION_NTF                 "MAU_CMU_CONFDURATION_NTF"

//MCU�ϱ���ǰ�����б�
#define EV_MCU_MAU_CONFLIST_NTF                     "MCU_MAU_CONFLIST_NTF"

//MCU�ϱ���ǰ����б�
#define CMU_MAU_ALLMONITORINFO_NTF                  "CMU_MAU_ALLMONITORINFO_NTF"
//MT�����Ϊ����֪ͨ
#define EV_CMU_CM_MTAPPLYSPEAKER_NTF				"CMU_CM_MTAPPLYSPEAKER_NTF"

//MT�����Ϊ��ϯ֪ͨ
#define EV_CMU_CM_MTAPPLYCHAIRMAN_NTF				"CMU_CM_MTAPPLYCHAIRMAN_NTF"

//mt ����֪ͨ
#define EV_CMU_CM_CALLMT_NTF						"CMU_CM_CALLMT_NTF"

//MT����������
#define EV_CMU_CM_MTAPPLYMIX_NTF					"CMU_CM_MTAPPLYMIX_NTF"

#define EV_CMU_CM_STARTMIX_FAIL_NTF					"CMU_CM_STARTMIX_FAIL_NTF"

//MT���֪ͨ(֪ͨ���ɾ����Ӧ�ն�)
#define EV_CMU_CM_DELMT_NTF							"CMU_CM_DELMT_NTF"

//���ն˷��Ͷ���Ϣ
#define	EV_CM_CMU_SENDMSG_CMD						"CM_CMU_SENDMSG_CMD"

//�᳡����
#define EV_CM_CMU_CONFMUTE_REQ						"CM_CMU_CONFMUTE_REQ"
#define EV_CMU_CM_CONFMUTE_ACK						"CMU_CM_CONFMUTE_ACK"
#define EV_CMU_CM_CONFMUTE_NACK				    	"CMU_CM_CONFMUTE_NACK"

//�᳡����
#define EV_CM_CMU_CONFSILENCE_REQ					"CM_CMU_CONFSILENCE_REQ"
#define EV_CMU_CM_CONFSILENCE_ACK					"CMU_CM_CONFSILENCE_ACK"
#define EV_CMU_CM_CONFSILENCE_NACK					"CMU_CM_CONFSILENCE_NACK"

//ȡ���᳡����
#define EV_CM_CMU_CANCELCONFMUTE_REQ				"CM_CMU_CANCELCONFMUTE_REQ"
#define EV_CMU_CM_CANCELCONFMUTE_ACK				"CMU_CM_CANCELCONFMUTE_ACK"
#define EV_CMU_CM_CANCELCONFMUTE_NACK				"CMU_CM_CANCELCONFMUTE_NACK"

//ȡ���᳡����
#define EV_CM_CMU_CANCELCONFSILENCE_REQ			    "CM_CMU_CANCELCONFSILENCE_REQ"
#define EV_CMU_CM_CANCELCONFSILENCE_ACK		    	"CMU_CM_CANCELCONFSILENCE_ACK"
#define EV_CMU_CM_CANCELCONFSILENCE_NACK			"CMU_CM_CANCELCONFSILENCE_NACK"

// �ӳ����� -- �ϵ�
#define EV_CM_CMU_DELAYCONF_REQ                     "CM_CMU_DELAYCONF_REQ"
#define EV_CMU_CM_DELAYCONF_ACK                     "CMU_CM_DELAYCONF_ACK"
#define EV_CMU_CM_DELAYCONF_NACK                    "CMU_CM_DELAYCONF_NACK"// ��ʼ��ѯ
#define EV_CM_CMU_STARTPOLL_CMD                     "CM_CMU_STARTPOLL_CMD"

// ֹͣ��ѯ
#define EV_CM_CMU_STOPPOLL_CMD                      "CM_CMU_STOPPOLL_CMD"

// ��ͣ��ѯ
#define EV_CM_CMU_PAUSEPOLL_CMD                     "CM_CMU_PAUSEPOLL_CMD"

// ������ѯ
#define EV_CM_CMU_RESUMEPOLL_CMD                    "CM_CMU_RESUMEPOLL_CMD"

// ָ����ѯλ��
#define EV_CM_CMU_SPECPOLLPOS_REQ                   "CM_CMU_SPECPOLLPOS_REQ"
#define EV_CMU_CM_SPECPOLLPOS_ACK                   "CMU_CM_SPECPOLLPOS_ACK"
#define EV_CMU_CM_SPECPOLLPOS_NACK                  "CMU_CM_SPECPOLLPOS_NACK"

// �޸���ѯ����
#define EV_CM_CMU_MDFPOLL_CMD                       "CM_CMU_CHANGEPOLLPARAM_CMD"

// �����ն˾���
#define EV_CM_CMU_MTSILENCE_REQ                     "CM_CMU_MTSILENCE_REQ"
#define EV_CMU_CM_MTSILENCE_ACK                     "CMU_CM_MTSILENCE_ACK"
#define EV_CMU_CM_MTSILENCE_NACK                    "CMU_CM_MTSILENCE_NACK"

// ȡ���ն˾���
#define EV_CM_CMU_CANCELMTSILENCE_REQ               "CM_CMU_CANCELMTSILENCE_REQ"
#define EV_CMU_CM_CANCELMTSILENCE_ACK               "CMU_CM_CANCELMTSILENCE_ACK"
#define EV_CMU_CM_CANCELMTSILENCE_NACK              "CMU_CM_CANCELMTSILENCE_NACK"

// �����ն�����
#define EV_CM_CMU_MTMUTE_REQ                        "CM_CMU_MTMUTE_REQ"
#define EV_CMU_CM_MTMUTE_ACK                        "CMU_CM_MTMUTE_ACK"
#define EV_CMU_CM_MTMUTE_NACK                       "CMU_CM_MTMUTE_NACK"

// ȡ���ն�����
#define EV_CM_CMU_CANCELMTMUTE_REQ                  "CM_CMU_CANCELMTMUTE_REQ"
#define EV_CMU_CM_CANCELMTMUTE_ACK                  "CMU_CM_CANCELMTMUTE_ACK"
#define EV_CMU_CM_CANCELMTMUTE_NACK                 "CMU_CM_CANCELMTMUTE_NACK"

// �޸��ն�����
#define EV_CM_CMU_MODMTVOLUME_CMD					"CM_CMU_MODMTVOLUME_CMD"
// �ն�����֪ͨ
#define EV_CMU_CM_MTVOLUME_NTF						"CMU_CM_MTVOLUME_NTF"


// ���û��鰲ȫ
#define EV_CM_CMU_SETCONFSAFE_REQ                   "CM_CMU_SETCONFSAFE_REQ"
#define EV_CMU_CM_SETCONFSAFE_ACK                   "CMU_CM_SETCONFSAFE_ACK"
#define EV_CMU_CM_SETCONFSAFE_NACK                  "CMU_CM_SETCONFSAFE_NACK"

// ������ϯ
#define EV_CM_CMU_SETCHAIRMAN_REQ                   "CM_CMU_SETCHAIRMAN_REQ"
#define EV_CMU_CM_SETCHAIRMAN_ACK                   "CMU_CM_SETCHAIRMAN_ACK"
#define EV_CMU_CM_SETCHAIRMAN_NACK                  "CMU_CM_SETCHAIRMAN_NACK"

// ȡ����ϯ
#define EV_CM_CMU_CANCELCHAIRMAN_REQ                "CM_CMU_CANCELCHAIRMAN_REQ"
#define EV_CMU_CM_CANCELCHAIRMAN_ACK                "CMU_CM_CANCELCHAIRMAN_ACK"
#define EV_CMU_CM_CANCELCHAIRMAN_NACK               "CMU_CM_CANCELCHAIRMAN_NACK"

// ���÷�����
#define EV_CM_CMU_SETSPEAKER_REQ                    "CM_CMU_SETSPEAKER_REQ"
#define EV_CMU_CM_SETSPEAKER_ACK                    "CMU_CM_SETSPEAKER_ACK"
#define EV_CMU_CM_SETSPEAKER_NACK                   "CMU_CM_SETSPEAKER_NACK"

// ȡ��������
#define EV_CM_CMU_CANCELSPEAKER_REQ                 "CM_CMU_CANCELSPEAKER_REQ"
#define EV_CMU_CM_CANCELSPEAKER_ACK                 "CMU_CM_CANCELSPEAKER_ACK"
#define EV_CMU_CM_CANCELSPEAKER_NACK                "CMU_CM_CANCELSPEAKER_NACK"

// ����ǿ�ƹ㲥
#define EV_CM_CMU_FORCEBRD_CMD                      "CM_CMU_FORCEBRD_CMD"
// ǿ�ƹ㲥֪ͨ
#define EV_CMU_CM_FORCEBRD_NTF                      "CMU_CM_FORCEBRD_NTF"

// �ն�ѡ��
#define EV_CM_CMU_STARTSEEMT_REQ                    "CM_CMU_STARTSEEMT_REQ"
#define EV_CMU_CM_STARTSEEMT_ACK                    "CMU_CM_STARTSEEMT_ACK"
#define EV_CMU_CM_STARTSEEMT_NACK                   "CMU_CM_STARTSEEMT_NACK"

// ֹͣ�ն�ѡ��
#define EV_CM_CMU_STOPSEEMT_REQ                     "CM_CMU_STOPSEEMT_REQ"
#define EV_CMU_CM_STOPSEEMT_ACK                     "CMU_CM_STOPSEEMT_ACK"
#define EV_CMU_CM_STOPSEEMT_NACK                    "CMU_CM_STOPSEEMT_NACK"

// ����ȫ�������ն�
#define EV_CM_CMU_CALLLEFTMT_REQ                    "CM_CMU_CALLLEFTMT_REQ"
#define EV_CMU_CM_CALLLEFTMT_ACK                    "CMU_CM_CALLLEFTMT_ACK"
#define EV_CMU_CM_CALLLEFTMT_NACK                   "CMU_CM_CALLLEFTMT_NACK"

// �������̻���ʱ��
#define EV_CMU_MAU_SUBCONFDURATION_REQ				"EV_CMU_MAU_SUBCONFDURATION_REQ"
#define EV_MAU_CMU_SUBCONFDURATION_ACK				"EV_MAU_CMU_SUBCONFDURATION_ACK"
#define EV_MAU_CMU_SUBCONFDURATION_NACK				"EV_MAU_CMU_SUBCONFDURATION_NACK"

// �����޸Ļ�������
#define EV_CMU_MAU_MODIFYCONFNAME_REQ				"EV_CMU_MAU_MODIFYCONFNAME_REQ"
#define EV_MAU_CMU_MODIFYCONFNAME_ACK				"EV_MAU_CMU_MODIFYCONFNAME_ACK"
#define EV_MAU_CMU_MODIFYCONFNAME_NACK				"EV_MAU_CMU_MODIFYCONFNAME_NACK"

// ��������ϳ�
#define EV_CM_CMU_STARTVMP_REQ						"CM_CMU_STARTVMP_REQ"
#define EV_CMU_CM_STARTVMP_ACK						"CMU_CM_STARTVMP_ACK"
#define EV_CMU_CM_STARTVMP_NACK						"CMU_CM_STARTVMP_NACK"

// ֹͣ����ϳ�
#define EV_CM_CMU_STOPVMP_REQ						"CM_CMU_STOPVMP_REQ"
#define EV_CMU_CM_STOPVMP_ACK						"CMU_CM_STOPVMP_ACK"
#define EV_CMU_CM_STOPVMP_NACK						"CMU_CM_STOPVMP_NACK"

// �޸Ļ���ϳɲ���
#define EV_CM_CMU_CHANGEVMPPARAM_REQ				"CM_CMU_CHANGEVMPPARAM_REQ"
#define EV_CMU_CM_CHANGEVMPPARAM_ACK				"CMU_CM_CHANGEVMPPARAM_ACK"
#define EV_CMU_CM_CHANGEVMPPARAM_NACK				"CMU_CM_CHANGEVMPPARAM_NACK"

// ����ϳɲ���֪ͨ
#define EV_CMU_CM_VMPPARAM_NTF                      "CMU_CM_VMPPARAM_NTF"
#define EV_CMU_CM_STARTVMP_FAIL_NTF					"CMU_CM_STARTVMP_FAIL_NTF"

// �����ն������ϳ� 
#define EV_CM_CMU_STARTMTVMP_REQ					"CM_CMU_STARTMTVMP_REQ"
#define EV_CMU_CM_STARTMTVMP_ACK					"CMU_CM_STARTMTVMP_ACK"
#define EV_CMU_CM_STARTMTVMP_NACK					"CMU_CM_STARTMTVMP_NACK"

// ֹͣ�ն������ϳ�
#define EV_CM_CMU_STOPMTVMP_REQ						"CM_CMU_STOPMTVMP_REQ"
#define EV_CMU_CM_STOPMTVMP_ACK						"CMU_CM_STOPMTVMP_ACK"
#define EV_CMU_CM_STOPMTVMP_NACK					"CMU_CM_STOPMTVMP_NACK"

#define EV_CM_CMU_CHANGEMTVMPPARAM_REQ				"CM_CMU_CHANGEMTVMPPARAM_REQ"
#define EV_CMU_CM_CHANGEMTVMPPARAM_ACK				"CMU_CM_CHANGEMTVMPPARAM_ACK"
#define EV_CMU_CM_CHANGEMTVMPPARAM_NACK				"CMU_CM_CHANGEMTVMPPARAM_NACK"

#define EV_CMU_CM_MTVMPPARAM_NTF					"CMU_CM_MTVMPPARAM_NTF"


// ����ϳɵ�ͨ����ѯͨ����ѯ����֪ͨ
#define EV_CMU_CM_VMPCHNPOLLPARAM_NTF               "CMU_CM_VMPCHNPOLLPARAM_NTF"

// ����VIP�б�
#define EV_CM_CMU_SETVIPLIST_REQ                    "CM_CMU_SETVIPLIST_REQ"
#define EV_CMU_CM_SETVIPLIST_ACK                    "CMU_CM_SETVIPLIST_ACK"
#define EV_CMU_CM_SETVIPLIST_NACK                   "CMU_CM_SETVIPLIST_NACK"

//VIP�б�֪ͨ
#define EV_CMU_CM_VIPLIST_NTF						"CMU_CM_VIPLIST_NTF"

// ��������
#define EV_CM_CMU_STARTMIX_REQ                      "CM_CMU_STARTMIX_REQ"
#define EV_CMU_CM_STARTMIX_ACK                      "CMU_CM_STARTMIX_ACK"
#define EV_CMU_CM_STARTMIX_NACK                     "CMU_CM_STARTMIX_NACK"

// ��������
#define EV_CM_CMU_STOPMIX_REQ                       "CM_CMU_STOPMIX_REQ"
#define EV_CMU_CM_STOPMIX_ACK                       "CMU_CM_STOPMIX_ACK"
#define EV_CMU_CM_STOPMIX_NACK                      "CMU_CM_STOPMIX_NACK"

// ��ӻ�����Ա
#define EV_CM_CMU_ADDMIXMEMBER_CMD                  "CM_CMU_ADDMIXMEMBER_CMD"
// ɾ��������Ա
#define EV_CM_CMU_REMOVEMIXMEMBER_CMD               "CM_CMU_REMOVEMIXMEMBER_CMD"

// ��������֪ͨ
#define EV_CMU_CM_MIXPARAM_NTF                      "CMU_CM_MIXPARAM_NTF"

// ��������
#define EV_CM_CMU_STARTROLLCALL_REQ                 "CM_CMU_STARTROLLCALL_REQ"
#define EV_CMU_CM_STARTROLLCALL_ACK                 "CMU_CM_STARTROLLCALL_ACK"
#define EV_CMU_CM_STARTROLLCALL_NACK                "CMU_CM_STARTROLLCALL_NACK"

#define	EV_CMU_CM_ROLLCALL_NTF						"CMU_CM_ROLLCALL_NTF"

// �رյ���
#define EV_CM_CMU_STOPROLLCALL_REQ                  "CM_CMU_STOPROLLCALL_REQ"
#define EV_CMU_CM_STOPROLLCALL_ACK                  "CMU_CM_STOPROLLCALL_ACK"
#define EV_CMU_CM_STOPROLLCALL_NACK                 "CMU_CM_STOPROLLCALL_NACK"

// �޸ĵ�������
#define EV_CM_CMU_CHANGEROLLCALL_REQ                "CM_CMU_CHANGEROLLCALL_REQ"
#define EV_CMU_CM_CHANGEROLLCALL_ACK                "CMU_CM_CHANGEROLLCALL_ACK"
#define EV_CMU_CM_CHANGEROLLCALL_NACK               "CMU_CM_CHANGEROLLCALL_NACK"

// ��������ǽ��ͨ��ѡ��
#define EV_CM_CMU_STARTHDUSWITCH_REQ				"CM_CMU_STARTHDUSWITCH_REQ"
#define EV_CMU_CM_STARTHDUSWITCH_ACK				"CMU_CM_STARTHDUSWITCH_ACK"
#define EV_CMU_CM_STARTHDUSWITCH_NACK				"CMU_CM_STARTHDUSWITCH_NACK"
// �رյ���ǽ��ͨ��ѡ��
#define EV_CM_CMU_STOPHDUSWITCH_REQ					"CM_CMU_STOPHDUSWITCH_REQ"
#define EV_CMU_CM_STOPHDUSWITCH_ACK					"CMU_CM_STOPHDUSWITCH_ACK"
#define EV_CMU_CM_STOPHDUSWITCH_NACK				"CMU_CM_STOPHDUSWITCH_NACK"
// ����ǽ��ͨ��ѡ��֪ͨ
#define EV_CMU_CM_HDUSWITCH_NTF						"CMU_CM_HDUSWITCH_NTF"
#define EV_CMU_CM_HDUSWITCH_FAIL_NTF                "CMU_CM_HDUSWITCH_FAIL_NTF"

// ��������ǽ��ͨ����ѯ
#define EV_CM_CMU_STARTHDUPOLL_CMD					"CM_CMU_STARTHDUPOLL_CMD"
// �رյ���ǽ��ͨ����ѯ
#define EV_CM_CMU_STOPHDUPOLL_CMD					"CM_CMU_STOPHDUPOLL_CMD"
// ��ͣ����ǽ��ͨ����ѯ
#define EV_CM_CMU_PAUSEHDUPOLL_CMD					"CM_CMU_PAUSEHDUPOLL_CMD"
// �ָ�����ǽ��ͨ����ѯ
#define EV_CM_CMU_RESUMEHDUPOLL_CMD					"CM_CMU_RESUMEHDUPOLL_CMD"
// �޸ĵ���ǽ��ͨ����ѯ
#define EV_CM_CMU_CHANGEHDUPOLL_CMD					"CM_CMU_CHANGEHDUPOLL_CMD"
// ����ǽ��ͨ����ѯ֪ͨ
#define EV_CMU_CM_HDUPOLL_NTF						"CMU_CM_HDUPOLL_NTF"

// ��������ǽ��������ϳ�
#define EV_CM_CMU_STARTHDUVMP_REQ					"CM_CMU_STARTHDUVMP_REQ"
#define EV_CMU_CM_STARTHDUVMP_ACK					"CMU_CM_STARTHDUVMP_ACK"
#define EV_CMU_CM_STARTHDUVMP_NACK					"CMU_CM_STARTHDUVMP_NACK"
// �رյ���ǽ��������ϳ�
#define EV_CM_CMU_STOPHDUVMP_REQ					"CM_CMU_STOPHDUVMP_REQ"
#define EV_CMU_CM_STOPHDUVMP_ACK					"CMU_CM_STOPHDUVMP_ACK"
#define EV_CMU_CM_STOPHDUVMP_NACK					"CMU_CM_STOPHDUVMP_NACK"
// �޸ĵ���ǽ��������ϳ�
#define EV_CM_CMU_CHANGEHDUVMP_REQ					"CM_CMU_CHANGEHDUVMP_REQ"
#define EV_CMU_CM_CHANGEHDUVMP_ACK					"CMU_CM_CHANGEHDUVMP_ACK"
#define EV_CMU_CM_CHANGEHDUVMP_NACK					"CMU_CM_CHANGEHDUVMP_NACK"
// ����ǽ��������ϳ�֪ͨ
#define EV_CMU_CM_HDUVMP_NTF						"CMU_CM_HDUVMP_NTF"

// ��������ǽ������ѯ
#define EV_CM_CMU_STARTHDUBATCHPOLL_REQ				"CM_CMU_STARTHDUBATCHPOLL_REQ"
#define EV_CMU_CM_STARTHDUBATCHPOLL_ACK				"CMU_CM_STARTHDUBATCHPOLL_ACK"
#define EV_CMU_CM_STARTHDUBATCHPOLL_NACK			"CMU_CM_STARTHDUBATCHPOLL_NACK"
// �رյ���ǽ������ѯ
#define EV_CM_CMU_STOPHDUBATCHPOLL_REQ				"CM_CMU_STOPHDUBATCHPOLL_REQ"
#define EV_CMU_CM_STOPHDUBATCHPOLL_ACK				"CMU_CM_STOPHDUBATCHPOLL_ACK"
#define EV_CMU_CM_STOPHDUBATCHPOLL_NACK				"CMU_CM_STOPHDUBATCHPOLL_NACK"
// ��ͣ����ǽ������ѯ
#define EV_CM_CMU_PAUSEHDUBATCHPOLL_REQ				"CM_CMU_PAUSEHDUBATCHPOLL_REQ"
#define EV_CMU_CM_PAUSEHDUBATCHPOLL_ACK				"CMU_CM_PAUSEHDUBATCHPOLL_ACK"
#define EV_CMU_CM_PAUSEHDUBATCHPOLL_NACK			"CMU_CM_PAUSEHDUBATCHPOLL_NACK"
// �ָ�����ǽ������ѯ
#define EV_CM_CMU_RESUMEHDUBATCHPOLL_REQ			"CM_CMU_RESUMEHDUBATCHPOLL_REQ"
#define EV_CMU_CM_RESUMEHDUBATCHPOLL_ACK			"CMU_CM_RESUMEHDUBATCHPOLL_ACK"
#define EV_CMU_CM_RESUMEHDUBATCHPOLL_NACK			"CMU_CM_RESUMEHDUBATCHPOLL_NACK"
// ����ǽ������ѯ֪ͨ
#define EV_CMU_CM_HDUBATCHPOLL_NTF					"CMU_CM_HDUBATCHPOLL_NTF"

// �ı����ǽͨ�����(����Դ�ͳ����)
#define EV_CM_CMU_CHANGEHDUVMPMODE_CMD				"CM_CMU_CHANGEHDUVMPMODE_CMD"
// �ı����ǽͨ�����ntf(����Դ�ͳ����)
#define EV_CMU_CM_CHANGEHDUVMPMODE_NTF				"CMU_CM_CHANGEHDUVMPMODE_NTF"

// ¼�����
#define EV_CM_CMU_STARTREC_REQ                      "CM_CMU_STARTREC_REQ"
#define EV_CMU_CM_STARTREC_ACK                      "CMU_CM_STARTREC_ACK"
#define EV_CMU_CM_STARTREC_NACK                     "CMU_CM_STARTREC_NACK"
#define EV_CM_CMU_PAUSEREC_REQ                      "CM_CMU_PAUSEREC_REQ"
#define EV_CMU_CM_PAUSEREC_ACK                      "CMU_CM_PAUSEREC_ACK"
#define EV_CMU_CM_PAUSEREC_NACK                     "CMU_CM_PAUSEREC_NACK"
#define EV_CM_CMU_RESUMEREC_REQ                     "CM_CMU_RESUMEREC_REQ"
#define EV_CMU_CM_RESUMEREC_ACK                     "CMU_CM_RESUMEREC_ACK"
#define EV_CMU_CM_RESUMEREC_NACK                    "CMU_CM_RESUMEREC_ACK"
#define EV_CM_CMU_STOPREC_REQ                       "CM_CMU_STOPREC_REQ"
#define EV_CMU_CM_STOPREC_ACK                       "CMU_CM_STOPREC_ACK"
#define EV_CMU_CM_STOPREC_NACK                      "CMU_CM_STOPREC_NACK"
#define EV_CM_CMU_GETRECPROG_CMD                    "CM_CMU_GETRECPROG_CMD"
#define EV_CMU_CM_RECPROG_NTF                       "CMU_CM_RECPROG_NTF"
#define EV_CM_CMU_GETRECSTATUS_CMD                  "CM_CMU_GETRECSTATUS_CMD"
#define EV_CMU_CM_RECORDRECSTATUS_NTF               "CMU_CM_RECORDRECSTATUS_NTF"
#define EV_CMU_CM_RECORDEREXCEPT_NTF                "CMU_CM_RECORDEREXCEPT_NTF"

// �������
// ��ʼ����
#define EV_CM_CMU_STARTPLAY_REQ                     "CM_CMU_STARTPLAY_REQ"
#define EV_CMU_CM_STARTPLAY_ACK                     "CMU_CM_STARTPLAY_ACK"
#define EV_CMU_CM_STARTPLAY_NACK                    "CMU_CM_STARTPLAY_NACK"
// ��ͣ����
#define EV_CM_CMU_PAUSEPLAY_REQ                     "CM_CMU_PAUSEPLAY_REQ"
#define EV_CMU_CM_PAUSEPLAY_ACK                     "CMU_CM_PAUSEPLAY_ACK"
#define EV_CMU_CM_PAUSEPLAY_NACK                    "CMU_CM_PAUSEPLAY_NACK"
// �ָ�����
#define EV_CM_CMU_RESUMEPLAY_REQ                    "CM_CMU_RESUMEPLAY_REQ"
#define EV_CMU_CM_RESUMEPLAY_ACK                    "CMU_CM_RESUMEPLAY_ACK"
#define EV_CMU_CM_RESUMEPLAY_NACK                   "CMU_CM_RESUMEPLAY_ACK"
// ֹͣ����
#define EV_CM_CMU_STOPPLAY_REQ                      "CM_CMU_STOPPLAY_REQ"
#define EV_CMU_CM_STOPPLAY_ACK                      "CMU_CM_STOPPLAY_ACK"
#define EV_CMU_CM_STOPPLAY_NACK                     "CMU_CM_STOPPLAY_NACK"
// �����������
#define EV_CM_CMU_SEEK_REQ							"CM_CMU_SEEK_REQ"
#define EV_CMU_CM_SEEK_ACK							"CMU_CM_SEEK_ACK"
#define EV_CMU_CM_SEEK_NACK							"CMU_CM_SEEK_NACK"
// ��ѯ�������
#define	EV_CM_CMU_GETPLAYPROG_CMD					"CM_CMU_GETPLAYPROG_CMD"
// ��ѯ�����״̬
#define	EV_CM_CMU_GETPLAYSTATUS_CMD					"CM_CMU_GETPLAYSTATUS_CMD"
// �������֪ͨ
#define EV_CMU_CM_PLAYPROG_NTF                      "CMU_CM_PLAYPROG_NTF"
// ����״̬֪ͨ
#define EV_CMU_CM_PLAYORDPLAYSTATUS_NTF             "CMU_CM_PLAYORDPLAYSTATUS_NTF"
// �����¼�����
#define EV_CM_CMU_ENDSUBCONF_CMD					"CM_CMU_ENDSUBCONF_CMD"

// �����¼������б�֪ͨ
#define EV_CMU_CM_ALLSMCULIST_NTF					"CMU_CM_ALLSMCULIST_NTF"
// ָ�����¼�������¼������б�֪ͨ
#define EV_CMU_CM_SMCULISTOFSMCU_NTF				"CMU_CM_SMCULISTOFSMCU_NTF"
// ָ�����¼�������ն��б�֪ͨ
#define EV_CMU_CM_MTLISTOFSMCU_NTF					"CMU_CM_MTLISTOFSMCU_NTF"
// �����µ��¼�����ڵ�
#define EV_CMU_CM_ADDSMCU_NTF						"CMU_CM_ADDSMCU_NTF"
// �Ƴ��¼�����ڵ�
#define EV_CMU_CM_REMOVESMCU_NTF					"CMU_CM_REMOVESMCU_NTF"
// �ն�ѡ��֪ͨ
#define EV_CMU_CM_MTSELECTVIEW_NTF					"CMU_CM_MTSELECTVIEW_NTF"
// �ն�ֹͣѡ��
#define EV_CMU_CM_MTSELECTVIEWSTOP_NTF				"CMU_CM_MTSELECTVIEWSTOP_NTF"
// ָ���ն��ϴ�Դ
#define EV_CM_CMU_SPECSRCOFMMCU_REQ					"CM_CMU_SPECSRCOFMMCU_REQ"
// ָ���ն��ϴ�Դ�ɹ���Ӧ
#define EV_CMU_CM_SPECSRCOFMMCU_ACK					"CMU_CM_SPECSRCOFMMCU_ACK"
// ָ���ն��ϴ�Դʧ�ܻ�Ӧ
#define EV_CMU_CM_SPECSRCOFMMCU_NACK				"CMU_CM_SPECSRCOFMMCU_NACK"
// ȡ���ն��ϴ�Դ
#define EV_CM_CMU_CANCELSRCOFMMCU_CMD				"CM_CMU_CANCELSRCOFMMCU_CMD"
// �ն��ϴ�Դ֪ͨ
#define EV_CMU_CM_SRCOFMMCU_NTF						"CMU_CM_SRCOFMMCU_NTF"
// �ն��ϴ���ѯ֪ͨ
#define EV_CMU_CM_MMCUSRCPOLL_NTF					"CMU_CM_MMCUSRCPOLL_NTF"
// ��ʼ�ϴ��ն���ѯ
#define EV_CM_CMU_STARTMMCUSRCPOLL_CMD				"CM_CMU_STARTMMCUSRCPOLL_CMD"
// ��ͣ�ϴ��ն���ѯ
#define EV_CM_CMU_PAUSEMMCUSRCPOLL_CMD				"CM_CMU_PAUSEMMCUSRCPOLL_CMD"
// ֹͣ�ϴ��ն���ѯ
#define EV_CM_CMU_STOPMMCUSRCPOLL_CMD				"CM_CMU_STOPMMCUSRCPOLL_CMD"
// �ָ��ϴ��ն���ѯ
#define EV_CM_CMU_RESUMEMMCUSRCPOLL_CMD				"CM_CMU_RESUMEMMCUSRCPOLL_CMD"
// ָ���ϴ���ѯ�ն�
#define EV_CM_CMU_MMCUSRCPOLLPOS_REQ				"CM_CMU_MMCUSRCPOLLPOS_REQ"
#define EV_CMU_CM_MMCUSRCPOLLPOS_ACK				"CMU_CM_MMCUSRCPOLLPOS_ACK"
#define EV_CMU_CM_MMCUSRCPOLLPOS_NACK				"CMU_CM_MMCUSRCPOLLPOS_NACK"
// �޸��ϴ���ѯ��Ա
#define EV_CM_CMU_CHANGEMMCUSRCPOLLPARAM_CMD		"CM_CMU_CHANGEMMCUSRCPOLLPARAM_CMD"
// �޸Ļ���˫������ģʽ
#define EV_CM_CMU_CHANGEDUALMODE_CMD				"CM_CMU_CHANGEDUALMODE_CMD"
// ָ������˫������
#define EV_CM_CMU_SPECDUALSRC_CMD					"CM_CMU_SPECDUALSRC_CMD"
// ȡ������˫������
#define EV_CM_CMU_CANCELDUALSRC_CMD					"CM_CMU_CANCELDUALSRC_CMD"

// ��ܿ�ʼ��ͨ���
#define EV_CM_CMU_STARTMONITORING_REQ				"CM_CMU_STARTMONITORING_REQ"
#define EV_CMU_CM_STARTMONITORING_ACK				"CMU_CM_STARTMONITORING_ACK"
#define EV_CMU_CM_STARTMONITORING_NACK				"CMU_CM_STARTMONITORING_NACK"

// ��ܿ�ʼ�᳡�㲥���
#define EV_CM_CMU_STARTBRDMONITORING_REQ			"CM_CMU_STARTBRDMONITORING_REQ"
#define EV_CMU_CM_STARTBRDMONITORING_ACK			"CMU_CM_STARTBRDMONITORING_ACK"
#define EV_CMU_CM_STARTBRDMONITORING_NACK			"CMU_CM_STARTBRDMONITORING_NACK"

// ��ܿ�ʼ�᳡˫�����
#define EV_CM_CMU_STARTDVIDMONITORING_REQ			"CM_CMU_STARTDVIDMONITORING_REQ"
#define EV_CMU_CM_STARTDVIDMONITORING_ACK			"CMU_CM_STARTDVIDMONITORING_ACK"
#define EV_CMU_CM_STARTDVIDMONITORING_NACK			"CMU_CM_STARTDVIDMONITORING_NACK"

// ��ܼ������ؼ�֡
#define EV_CM_CMU_NEEDIFRAME_CMD					"CM_CMU_NEEDIFRAME_CMD"

// �����ָ���ն�����ؼ�֡
#define EV_CM_CMU_NEEDSPECMTIFRAME_CMD				"CM_CMU_NEEDSPECMTIFRAME_CMD"

// ���ֹͣ���
#define EV_CM_CMU_STOPMONITORING_CMD				"CM_CMU_STOPMONITORING_CMD"

// ���鿪ʼ���֪ͨ
#define EV_CMU_CM_STARTMONITORING_NTF				"CMU_CM_STARTMONITORING_NTF"
// ����ֹͣ���֪ͨ
#define EV_CMU_CM_STOPMONITORING_NTF				"CMU_CM_STOPMONITORING_NTF"
// CMU��MAU�ϱ������Ϣ
#define EV_CMU_MAU_ALLMONITORINFO_NTF               "CMU_MAU_ALLMONITORINFO_NTF"


// ���������鵱ǰ�㲥Դ
#define EV_CM_CMU_GETCURRENTBRDSRC_REQ				"CM_CMU_GETCURRENTBRDSRC_REQ"
#define EV_CMU_CM_GETCURRENTBRDSRC_ACK				"CMU_CM_GETCURRENTBRDSRC_ACK"
#define EV_CMU_CM_GETCURRENTBRDSRC_NACK				"CMU_CM_GETCURRENTBRDSRC_NACK"

// ��ȡָ���ն�״̬����
#define EV_CM_CMU_GETMTSTATUS_REQ			     	"CM_CMU_GETMTSTATUS_REQ"
#define EV_CMU_CM_GETMTSTATUS_ACK				    "CMU_CM_GETMTSTATUS_ACK"
#define EV_CMU_CM_GETMTSTATUS_NACK			    	"CMU_CM_GETMTSTATUS_NACK"

// ��ȡָ�������ն��б�
#define EV_CM_CMU_GETMTLIST_REQ			     		"CM_CMU_GETMTLIST_REQ"
#define EV_CMU_CM_GETMTLIST_ACK						"CMU_CM_GETMTLIST_ACK"
#define EV_CMU_CM_GETMTLIST_NACK			    	"CMU_CM_GETMTLIST_NACK"
//
#define EV_CM_CMU_MTCAMERA_MOV_CMD					"CM_CMU_MTCAMERA_MOV_CMD"
#define EV_CM_CMU_MTCAMERA_STOP_CMD					"CM_CMU_MTCAMERA_STOP_CMD"
#define EV_CM_CMU_MTCAMERA_RCENABLE_CMD				"CM_CMU_MTCAMERA_RCENABLE_CMD"
#define EV_CM_CMU_MTCAMERA_SAVETOPOS_CMD			"CM_CMU_MTCAMERA_SAVETOPOS_CMD"
#define EV_CM_CMU_MTCAMERA_MOVETOPOS_CMD			"CM_CMU_MTCAMERA_MOVETOPOS_CMD"

//��ȡ�ն�Ԥ��λ��Ϣ
#define EV_CM_CMU_MTCAMERA_GETPOSINFO_CMD           "CM_CMU_MTCAMERA_GETPOSINFO_CMD"
//�ն�Ԥ��λ��Ϣ�ϱ�
#define EV_CMU_CM_MTCAMERA_POSINFO_NTF               "CMU_CM_MTCAMERA_POSINFO_NTF"

// ϵͳ�澯֪ͨ
#define EV_CMU_CM_ALARMINFO_NTF						"CMU_CM_ALARM_INFO_NTF"
// ѡ��ʧ��֪ͨ
#define EV_CMU_CM_STARTSEEMT_FAIL_NTF					"CMU_CM_STARTSEEMT_FAIL_NTF"

// �����ӳ�����ʱ��
#define EV_CMU_MAU_DELAYCONF_REQ					"EV_CMU_MAU_DELAYCONF_REQ"
#define EV_MAU_CMU_DELAYCONF_ACK					"EV_MAU_CMU_DELAYCONF_ACK"
#define EV_MAU_CMU_DELAYCONF_NACK					"EV_MAU_CMU_DELAYCONF_NACK"

// ֪ͨmauͬ������
#define	EV_CMU_MAU_CONFSYN_NTF						"CMU_MAU_CONFSYN_NTF"

// �ն�������Ϣͬ��
#define EV_MAU_MCU_MTLIST_NTF                       "MAU_MCU_MTLIST_NTF"

// ��������Ϣͬ��
#define EV_MAU_MCU_DOMAINLIST_NTF                   "MAU_MCU_DOMAINLIST_NTF"
//����ʣ��ʱ��֪ͨ css--cm
#define	EV_CMU_CM_CONFTIMELEFT_NTF					"CMU_CM_CONFTIMELEFT_NTF"
//����ʣ��ʱ��֪ͨ css--cmu
#define EV_MAU_CMU_CONFTIMELEFT_NTF                 "MAU_CMU_CONFTIMELEFT_NTF"

// ����״̬��Ϣ�ı�֪ͨ
#define EV_MCU_MAU_CONFSTATECHANGE_NTF				"MCU_MAU_CONFSTATECHANGE_NTF"

#ifdef _MSC_VER
#if _MSC_VER <= 1200
#define __FUNCTION__ ""
#endif
#endif

static BOOL32 __SetStringToJson(const json_t_ptr& pjRoot, const s8* abyName, const s8* abyValue, const s8* abyFuncName)
{
	json_t_ptr pjSubNode = json_string(abyValue);
	if (!pjSubNode)
	{
		OspPrintf(TRUE, FALSE, "[%s] json_string %s is NULL!\n", abyFuncName, abyName);
		return FALSE;
	}
	else
	{
		json_object_set_s(pjRoot, abyName, pjSubNode);
		return TRUE;
	}
}


static BOOL32 __SetIntAsStringToJson(const json_t_ptr& pjRoot, const s8* abyName, s32 dwValue, const s8* abyFuncName)
{
	s8 abyTemp[20] = { 0 };
	sprintf(abyTemp, "%d", dwValue);
	return __SetStringToJson(pjRoot, abyName, abyTemp, abyFuncName);
}


static BOOL32 __SetUIntAsStringToJson(const json_t_ptr& pjRoot, const s8* abyName, u32 dwValue, const s8* abyFuncName)
{
	s8 abyTemp[20] = { 0 };
	sprintf(abyTemp, "%u", dwValue);
	return __SetStringToJson(pjRoot, abyName, abyTemp, abyFuncName);
}

static BOOL32 __SetIntToJson(const json_t_ptr& pjRoot, const s8* abyName, u32 dwValue, const s8* abyFuncName)
{
	json_t_ptr pjSubNode = json_integer(dwValue);
	if (!pjSubNode)
	{
		OspPrintf(TRUE, FALSE, "[%s] jsonInterger %s is NULL!\n", abyFuncName, abyName);
		return FALSE;
	}
	else
	{
		json_object_set_s(pjRoot, abyName, pjSubNode);
		return TRUE;
	}
}

static BOOL32 __GetStringFromJson(const json_t_ptr& pjObj, const s8* abyName, const s8** ppchValue, const s8* abyFuncName)
{
	json_t_ptr pjSubObj = json_object_get_s(pjObj, abyName);
	if (NULL == pjSubObj)
	{
		OspPrintf(TRUE, FALSE, "[%s] json_object_get %s is NULL!\n", abyFuncName, abyName);
		return FALSE;
	}
	
	*ppchValue = json_string_value(pjSubObj);
	return TRUE;
}

static BOOL32 __GetStringAsUIntFromJson(const json_t_ptr& pjObj, const s8* abyName, u32&dwValue, const s8* abyFuncName)
{
	const s8* pchString = NULL;
	if (__GetStringFromJson(pjObj, abyName, &pchString, abyFuncName))
	{
		dwValue = strtoul(pchString, 0, 10);
		return TRUE;
	}
	return FALSE;
}

static BOOL32 __GetIntFromJson(const json_t_ptr& pjObj, const s8* abyName, u32&dwValue, const s8* abyFuncName)
{
	json_t_ptr pjSubObj = json_object_get_s(pjObj, abyName);
	if (NULL == pjSubObj)
	{
		OspPrintf(TRUE, FALSE, "[%s] json_object_get %s is NULL!\n", abyFuncName, abyName);
		return FALSE;
	}
	
	dwValue = (u32)json_integer_value(pjSubObj);
	return TRUE;
}

static BOOL32 __GetStringAsIntFromJson(const json_t_ptr& pjObj, const s8* abyName, u32&dwValue, const s8* abyFuncName)
{
	const s8* pchString = NULL;
	if (__GetStringFromJson(pjObj, abyName, &pchString, abyFuncName))
	{
		dwValue = strtol(pchString, 0, 10);
		return TRUE;
	}
	return FALSE;
}

static BOOL32 __LoadJson(const s8 * pchJsonBuf, u32 dwJsonBufLen, json_t_ptr& pjRoot, BOOL32 bCreateIfNull, const s8* abyFuncName)
{
	if (NULL == pchJsonBuf)
	{
		OspPrintf(TRUE, FALSE, "[%s] Param is NULL, retur!\n", abyFuncName);
		return FALSE;
	}

	json_error_t jReason;
	if (0 != dwJsonBufLen)
	{
		pjRoot = json_loads(pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason);
		if (!pjRoot)
		{
			OspPrintf(TRUE, FALSE, "[%s] Load Json Error [%d:%d]%s, return!\n", abyFuncName, jReason.line, jReason.column, jReason.text);
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
	else
	{
		if (bCreateIfNull)
		{
			pjRoot = json_object();
			if (!pjRoot)
			{
				OspPrintf(TRUE, FALSE, "[%s] Create JsonObj Failed, return!\n", abyFuncName);
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

static BOOL32 __DumpJson(const json_t_ptr pjRoot, s8 * pchJsonBuf, u32 dwMaxLen, u32& dwRealLen, const s8* abyFuncName)
{
	s8 * pchData = json_dumps(pjRoot, 0);
	if (NULL == pchData)
	{
		OspPrintf(TRUE, FALSE, "[%s] json_dumps is NULL!\n", abyFuncName);
		return FALSE;
	}

	if (dwMaxLen < strlen(pchData))
	{
		OspPrintf(TRUE, FALSE, "[%s] pchData len:%d > bufflen:%d, return!\n", abyFuncName, dwMaxLen);
		json_free(pchData);
		return FALSE;
	}

	dwRealLen = strlen(pchData);
	memcpy(pchJsonBuf, pchData, dwRealLen);
	json_free(pchData);
	return TRUE;
}

//VC6 dose not support __VA_ARGS__
//#define ReturnIfFailed(func, ...) if(!func) return __VA_ARGS__
#define ReturnIfFailed(func) if(!func) return FALSE
#define LoadJson(pchJsonBuf, dwJsonLen, pjRoot, bCreateIfNull) __LoadJson(pchJsonBuf, dwJsonLen, pjRoot, bCreateIfNull, __FUNCTION__)
#define DumpJson(pjRoot, pchJsonBuf, dwMaxLen, dwRealLen) __DumpJson(pjRoot, pchJsonBuf, dwMaxLen, dwRealLen, __FUNCTION__)
#define SetStringToJson(root, name, value)	__SetStringToJson(root, name, value, __FUNCTION__)
#define SetIntAsStringToJson(root, name, value) __SetIntAsStringToJson(root, name, value, __FUNCTION__)
#define SetUIntAsStringToJson(root, name, value) __SetUIntAsStringToJson(root, name, (value), __FUNCTION__)
#define SetBoolAsStringToJson(root, name, value) __SetUIntAsStringToJson(root, name, (value) ? 1 : 0, __FUNCTION__)
#define SetIntToJson(root, name, value) __SetIntToJson(root, name, value, __FUNCTION__)
#define GetStringFromJson(root, name, value) __GetStringFromJson(root, name, value, __FUNCTION__)
#define GetStringAsIntFromJson(root, name, value) __GetStringAsIntFromJson(root, name, value, __FUNCTION__)
#define GetStringAsUIntFromJson(root, name, value) __GetStringAsUIntFromJson(root, name, value, __FUNCTION__)
#define GetIntFromJson(root, name, value) __GetIntFromJson(root, name, value, __FUNCTION__)
/*=============================================================================
�� �� ���� GetConfE164FromJson
��    �ܣ�
�㷨ʵ�֣�
ȫ�ֱ�����
��    ���� void
�� �� ֵ�� void
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetConfE164FromJson(const json_t_ptr& pjRoot, s8 * pchConfE164, u32 dwConfE164Len)
{
	json_t_ptr pjConfE164 = json_object_get_s(pjRoot, JSON_CONFE164);
	if (NULL == pjConfE164)
	{
		OspPrintf(TRUE, FALSE, "[GetConfE164FromJson] json_object_get ConfE164 is NULL, retur FALSE!\n");
		return FALSE;
	}

	u32 dwLen = MAXLEN_CONFE164 >= dwConfE164Len ? dwConfE164Len : MAXLEN_CONFE164;
	strncpy(pchConfE164, json_string_value(pjConfE164), dwLen);
	return TRUE;
}

static BOOL32 GetConfE164FromJson(const s8 * pchJsonBuf, s8 * pchConfE164, u32 dwConfE164Len )
{

	if ( NULL == pchJsonBuf || NULL == pchConfE164 || 0 == dwConfE164Len )
	{
		OspPrintf( TRUE, FALSE, "[GetConfE164FromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfE164FromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}
	
	return GetConfE164FromJson(pjRoot, pchConfE164, dwConfE164Len);
}

static BOOL32 GetConfPasswordFromJson(const json_t_ptr& pjRoot, s8 * pchPassword, u32 dwPwdLen)
{
	json_t_ptr pjConfPwd = json_object_get_s(pjRoot, JSON_PSW);
	if (NULL == pjConfPwd)
	{
		OspPrintf(TRUE, FALSE, "[GetConfNameFromJson] json_object_get ConfName is NULL, retur FALSE!\n");
		return FALSE;
	}

	u32 dwLen = MAXLEN_PWD >= dwPwdLen ? dwPwdLen : MAXLEN_PWD;
	strncpy(pchPassword, json_string_value(pjConfPwd), dwLen);
	return TRUE;
}

static BOOL32 GetConfNameFromJson(const json_t_ptr& pjRoot, s8 * pchConfName, u32 dwConfNanemLen)
{
	json_t_ptr pjConfName = json_object_get_s(pjRoot, JSON_CONFNAME);
	if (NULL == pjConfName)
	{
		OspPrintf(TRUE, FALSE, "[GetConfNameFromJson] json_object_get ConfName is NULL, retur FALSE!\n");
		return FALSE;
	}

	u32 dwLen = MAXLEN_CONFNAME >= dwConfNanemLen ? dwConfNanemLen : MAXLEN_CONFNAME;
	strncpy(pchConfName, json_string_value(pjConfName), dwLen);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetConfNameFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetConfNameFromJson(const s8 * pchJsonBuf, s8 * pchConfName, u32 dwConfNanemLen )
{
	if ( NULL == pchJsonBuf || NULL == pchConfName || 0 == dwConfNanemLen )
	{
		OspPrintf( TRUE, FALSE, "[GetConfNameFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfNameFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}
	
	return GetConfNameFromJson(pjRoot, pchConfName, dwConfNanemLen);
}

/*=============================================================================
�� �� ���� GetMOIDFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetMOIDFromJson(const s8 * pchJsonBuf, s8 * pchDomainMOID, u32 dwDomainMOIDLen )
{
	if ( NULL == pchJsonBuf || NULL == pchDomainMOID || 0 == dwDomainMOIDLen )
	{
		OspPrintf( TRUE, FALSE, "[GetMOIDFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMOIDFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjMoId = json_object_get_s( pjRoot, JSON_MOID );
	if ( NULL == pjMoId )
	{
		OspPrintf( TRUE, FALSE, "[GetMOIDFromJson] json_object_get domainmoid is NULL, retur FALSE!\n" );
		return FALSE;
	}
	
	u32 dwLen = OPERATION_MAXLEN_MOID >= dwDomainMOIDLen ? dwDomainMOIDLen : OPERATION_MAXLEN_MOID;
	strncpy( pchDomainMOID, json_string_value( pjMoId ), dwLen );

	return TRUE;
}

/*=============================================================================
�� �� ���� GetUserDomainIdFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/07/02  5.0         lbg                   ����
=============================================================================*/
static BOOL32 GetUserDomainIdFromJson(const s8 * pchJsonBuf, s8 * pchDomainMOID, u32 dwDomainMOIDLen )
{
	if ( NULL == pchJsonBuf || NULL == pchDomainMOID || 0 == dwDomainMOIDLen )
	{
		OspPrintf( TRUE, FALSE, "[GetUserDomainIdFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetUserDomainIdFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjMoId = json_object_get_s( pjRoot, "userDomainMoid" );
	if ( NULL == pjMoId )
	{
		OspPrintf( TRUE, FALSE, "[GetUserDomainIdFromJson] json_object_get domainmoid is NULL, retur FALSE!\n" );
		return FALSE;
	}

	u32 dwLen = OPERATION_MAXLEN_MOID >= dwDomainMOIDLen ? dwDomainMOIDLen : OPERATION_MAXLEN_MOID;
	strncpy(pchDomainMOID, json_string_value(pjMoId), dwLen);

	return TRUE;
}

/*=============================================================================
�� �� ���� GetNameFromJson
��    �ܣ� Jsonת��Ϊ�����
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetNameFromJson(const s8 * pchJsonBuf, s8 * pchDomainName, u32 dwDomainNameLen )
{
	if ( NULL == pchJsonBuf || NULL == pchDomainName || 0 == dwDomainNameLen )
	{
		OspPrintf( TRUE, FALSE, "[GetNameFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetNameFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjName = json_object_get_s( pjRoot, "name" );
	if ( NULL == pjName )
	{
		OspPrintf( TRUE, FALSE, "[GetNameFromJson] json_object_get domainname is NULL, return FALSE!\n" );
		return FALSE;
	}

	strncpy(pchDomainName, json_string_value(pjName), dwDomainNameLen);

	return TRUE;
}

/*=============================================================================
�� �� ���� GetE164FromJson
��    �ܣ� Jsonת��Ϊ�����
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetE164FromJson(const s8 * pchJsonBuf, s8 * pchE164, u32 dwE164Len )
{
	if ( NULL == pchJsonBuf || NULL == pchE164 || 0 == dwE164Len )
	{
		OspPrintf( TRUE, FALSE, "[GetE164FromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetE164FromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjE164 = json_object_get_s( pjRoot, "e164" );
	if ( NULL == pjE164 )
	{
		OspPrintf( TRUE, FALSE, "[GetE164FromJson] json_object_get pjE164 is NULL, return FALSE!\n" );
		return FALSE;
	}

	strncpy(pchE164, json_string_value(pjE164), dwE164Len);

	return TRUE;
}

/*=============================================================================
�� �� ���� GetDeviceTypeFromJson
��    �ܣ� Jsonת��Ϊ�����
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetDeviceTypeFromJson(const s8 * pchJsonBuf, u16& wDeviceType )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetDeviceTypeFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetDeviceTypeFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjDeviceType = json_object_get_s( pjRoot, "deviceType" );
	if ( NULL == pjDeviceType )
	{
		OspPrintf( TRUE, FALSE, "[GetDeviceTypeFromJson] json_object_get pjDeviceType is NULL, return FALSE!\n" );
		return FALSE;
	}

	wDeviceType = (u16)atoi( json_string_value( pjDeviceType ) );
	return TRUE;
}

/*=============================================================================
�� �� ���� GetLimitedFromJson
��    �ܣ� Jsonת��Ϊ�����
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetLimitedFromJson(const s8 * pchJsonBuf, BOOL32& bLimited )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetLimitedFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetLimitedFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjLimited = json_object_get_s( pjRoot, "limited" );
	if ( NULL == pjLimited )
	{
		OspPrintf( TRUE, FALSE, "[GetLimitedFromJson] json_object_get limited is NULL, return FALSE!\n" );
		return FALSE;
	}
	bLimited =  json_is_true(pjLimited);

	return TRUE;
}

/*=============================================================================
�� �� ���� GetGuidFromJson
��    �ܣ� Jsonת��Ϊguid
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetGuidFromJson(const s8 * pchJsonBuf, s8 * pchDomainGuid, u32 dwDomainGuidLen )
{
	if ( NULL == pchJsonBuf || NULL == pchDomainGuid || 0 == dwDomainGuidLen )
	{
		OspPrintf( TRUE, FALSE, "[GetGuidFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetGuidFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjGuid = json_object_get_s( pjRoot, "domainGuid" );
	if ( NULL == pjGuid )
	{
		OspPrintf( TRUE, FALSE, "[GetGuidFromJson] json_object_get domainGuid is NULL, return FALSE!\n" );
		return FALSE;
	}

	strncpy(pchDomainGuid, json_string_value(pjGuid), dwDomainGuidLen);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetNumSegmentFromJson
��    �ܣ� Jsonת��Ϊmoid
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetNumSegmentFromJson(const s8 * pchJsonBuf, s8 * pchNumSegment, u32 dwNumSegmentLen )
{
	if ( NULL == pchJsonBuf || NULL == pchNumSegment || 0 == dwNumSegmentLen )
	{
		OspPrintf( TRUE, FALSE, "[GetNumSegmentFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetNumSegmentFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjNumSegment = json_object_get_s( pjRoot, "numberSegment" );
	if ( NULL == pjNumSegment )
	{
		OspPrintf( TRUE, FALSE, "[GetNumSegmentFromJson] json_object_get pjNumSegment is NULL, return FALSE!\n" );
		return FALSE;
	}

	strncpy(pchNumSegment, json_string_value(pjNumSegment), dwNumSegmentLen);

	return TRUE;
}

/*=============================================================================
�� �� ���� GetServerMoidFromJson
��    �ܣ� Jsonת��Ϊmoid
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetServerMoidFromJson(const s8 * pchJsonBuf, s8 * pchDomainMoid, u32 dwDomainMoidLen )
{
	if ( NULL == pchJsonBuf || NULL == pchDomainMoid || 0 == dwDomainMoidLen )
	{
		OspPrintf( TRUE, FALSE, "[GetServerMoidFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetServerMoidFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjMoid = json_object_get_s( pjRoot, "serviceDomainMoid" );
	if ( NULL == pjMoid )
	{
		OspPrintf( TRUE, FALSE, "[GetServerMoidFromJson] json_object_get domainmoid is NULL, return FALSE!\n" );
		return FALSE;
	}

	strncpy(pchDomainMoid, json_string_value(pjMoid), dwDomainMoidLen);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetPlatformMoidFromJson
��    �ܣ� Jsonת��Ϊmoid
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetPlatformMoidFromJson(const s8 * pchJsonBuf, s8 * pchDomainMoid, u32 dwDomainMoidLen )
{
	if ( NULL == pchJsonBuf || NULL == pchDomainMoid || 0 == dwDomainMoidLen )
	{
		OspPrintf( TRUE, FALSE, "[GetPlatformMoidFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetPlatformMoidFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjMoid = json_object_get_s( pjRoot, "platformDomainMoid" );
	if ( NULL == pjMoid )
	{
		OspPrintf( TRUE, FALSE, "[GetPlatformMoidFromJson] json_object_get domainmoid is NULL, return FALSE!\n" );
		return FALSE;
	}

	strncpy(pchDomainMoid, json_string_value(pjMoid), dwDomainMoidLen);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetEnabledFromJson
��    �ܣ� Jsonת��Ϊenabled
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetEnabledFromJson(const s8 * pchJsonBuf, BOOL32& bEnabled )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetEnabledFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetEnabledFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjEnabled = json_object_get_s( pjRoot, "enable" );
	if ( NULL == pjEnabled )
	{
		OspPrintf( TRUE, FALSE, "[GetEnabledFromJson] json_object_get domainEnabled is NULL, return FALSE!\n" );
		return FALSE;
	}
	bEnabled = json_is_true(pjEnabled);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetEnabledFromJson
��    �ܣ� Jsonת��Ϊenabled
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetUseFlagFromJson(const s8 * pchJsonBuf, BOOL32& bEnabled )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetUseFlagFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetUseFlagFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjEnabled = json_object_get_s( pjRoot, "usedFlag" );
	if ( NULL == pjEnabled )
	{
		OspPrintf( TRUE, FALSE, "[GetUseFlagFromJson] json_object_get domainEnabled is NULL, return FALSE!\n" );
		return FALSE;
	}

	bEnabled = (u32)json_integer_value(pjEnabled);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetMaxConfNumFromJson
��    �ܣ� Jsonת��Ϊenabled
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetMaxConfNumFromJson(const s8 * pchJsonBuf, u16& wConfNum )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetMaxConfNumFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMaxConfNumFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjConfNum = json_object_get_s( pjRoot, "concurrentNumber" );
	if ( NULL == pjConfNum )
	{
		OspPrintf( TRUE, FALSE, "[GetMaxConfNumFromJson] json_object_get pjConfNum is NULL, return FALSE!\n" );
		return FALSE;
	}

	wConfNum = (u16)json_integer_value(pjConfNum);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetMoIdNumFromJson
��    �ܣ� Jsonת��Ϊenabled
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetMoIdNumFromJson(const s8 * pchJsonBuf, u32 &dwMoidNum )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetMoIdNumFromJson]Param is NULL, return!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL == pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMoIdNumFromJson] json_loads err!\n" );
		return FALSE;
	}

	json_t_ptr pjMoidArray = json_object_get_s( pjRoot, JSON_MOID );
	if ( NULL == pjMoidArray )
	{
		OspPrintf( TRUE, FALSE, "[GetMoIdNumFromJson] json_object_get MoidArray is NULL!\n" );
		return FALSE;
	}

	dwMoidNum = json_array_size( pjMoidArray );
	return TRUE;
}


/*=============================================================================
�� �� ���� GetMoIdListFromJson
��    �ܣ� Jsonת��Ϊenabled
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/03  5.0         lbg                    ����
=============================================================================*/
static BOOL32 GetMoIdListFromJson(const s8 * pchJsonBuf, s8 **pachMoid )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetMoIdListFromJson]Param is NULL, return!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL == pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMoIdListFromJson] json_loads err!\n" );
		return FALSE;
	}

	json_t_ptr pjMoidArray = json_object_get_s( pjRoot, JSON_MOID );
	if ( NULL == pjMoidArray )
	{
		OspPrintf( TRUE, FALSE, "[GetMoIdListFromJson] json_object_get MoidArray is NULL!\n" );
		return FALSE;
	}

	u16 wMoidNum = 0;
	wMoidNum = json_array_size( pjMoidArray );

	u16 wMoidIdx = 0;
	for ( wMoidIdx = 0; wMoidIdx < wMoidNum; wMoidIdx++ )
	{
		json_t_ptr pjMoidInfo = json_array_get_s( pjMoidArray, wMoidIdx );
		if ( NULL == pjMoidInfo )
		{
			continue;
		}
		strncpy( pachMoid[wMoidIdx], json_string_value(pjMoidInfo), OPERATION_MAXLEN_MOID );
	}

	return TRUE;
}

static void GetMtAliasListFromJson(json_t_ptr pjRoot, TMtAlias * ptMtAlias, u16* awBitRate, u16 &wMtNum)
{
	if (!pjRoot)
	{
		return;
	}

	json_t_ptr pjMtArray = json_object_get_s(pjRoot, JSON_MT);
	if (NULL == pjMtArray)
	{
		OspPrintf(TRUE, FALSE, "[GetMtAliasListFromJson] json_object_get MtArray is NULL!\n");
		return;
	}

	wMtNum = json_array_size(pjMtArray);
	//rnn[2015/04/21]SDM-00025742 ���ڻ�ܲ������ƣ��˴������Ƶ��������ն����191��,����ptMtAliasԽ�絼��cmu����
	if (wMtNum >= MAXNUM_CONF_MT)
	{
		OspPrintf(TRUE, FALSE, "[GetMtAliasListFromJson]Mt Num.%d over 191, set to 191!\n", wMtNum);
		wMtNum = MAXNUM_CONF_MT - 1;
	}
	//end
	u16 wMtIdx = 0;
	for (wMtIdx = 0; wMtIdx < wMtNum; wMtIdx++)
	{
		json_t_ptr pjMtInfo = json_array_get_s(pjMtArray, wMtIdx);
		if (NULL == pjMtInfo)
		{
			continue;
		}

		json_t_ptr pjMtNO = json_object_get_s(pjMtInfo, JSON_MTNO);
		if (NULL == pjMtNO)
		{
			continue;
		}

		json_t_ptr pjMtType = json_object_get_s(pjMtInfo, JSON_MTTYPE);
		if (NULL == pjMtType)
		{
			continue;
		}

		json_t_ptr pjProtocol = json_object_get_s(pjMtInfo, JSON_PROTOCOL);
		// �˴������п�continue
// 		if ( NULL == pjProtocol )
// 		{
// 			continue;
// 		}

		json_t_ptr pjBitRate = json_object_get_s(pjMtInfo, JSON_BITRATE);
		awBitRate[wMtIdx] = pjBitRate ? atoi(json_string_value(pjBitRate)) : 0;

		u8 byMtAliasType = mtAliasTypeBegin;
		const s8 * pchMtNo = json_string_value(pjMtNO);
		u32 dwSetStrLen = strspn(pchMtNo, "0123456789#*");
		if (dwSetStrLen == strlen(pchMtNo))
		{
			if (atoi(json_string_value(pjMtType)) == 3)
			{
				byMtAliasType = mtAliasTypePartNumber;
			}
			else
			{
				byMtAliasType = mtAliasTypeE164;
			}

			ptMtAlias[wMtIdx].SetAlias((u8)byMtAliasType,
				(u8)strlen(pchMtNo),
				pchMtNo);
		}
		else
		{
			// Ҫ�ڴ˴��п�
			if (NULL == pjProtocol)
			{
				continue;
			}
			if (atoi(json_string_value(pjProtocol)) == 0)
			{
				byMtAliasType = mtAliasTypeTransportAddress;
			}
			else if (atoi(json_string_value(pjProtocol)) == 1)
			{
				byMtAliasType = mtAliasTypeIpSIP;
			}
			else
			{
				continue;
			}

			TTransportAddr tAddr;
			tAddr.SetNull();
			tAddr.SetNetSeqIpAddr(inet_addr(pchMtNo));
			ptMtAlias[wMtIdx].SetAlias(byMtAliasType, sizeof(tAddr), (const s8*)&tAddr);
		}

	}
}

/*=============================================================================
�� �� ���� GetMtAliasListFromJson
��    �ܣ� Jsonת��Ϊ�ն˱���
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static void GetMtAliasListFromJson( const s8 * pchJsonBuf, TMtAlias * ptMtAlias, u16* awBitRate, u16 &wMtNum )
{
	if ( NULL == pchJsonBuf || NULL == ptMtAlias )
	{
		OspPrintf( TRUE, FALSE, "[GetMtAliasListFromJson]Param is NULL, return!\n" );
		return;
	}

	wMtNum = 0;

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL == pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMtAliasListFromJson] json_loads err!\n" );
		return;
	}

	GetMtAliasListFromJson(pjRoot, ptMtAlias, awBitRate, wMtNum);

	return;
}

/*=============================================================================
�� �� ���� GetMtListFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetMtListFromJson(const s8 * pchJsonBuf, CKdvMtInfo * pcMtInfo, u32 &dwMtInfoNum, BOOL32 &bDel )
{
	if ( NULL == pchJsonBuf || NULL == pcMtInfo )
	{
		OspPrintf( TRUE, FALSE, "[GetMtListFromJson]Param is NULL, return!\n" );
		return FALSE;
	}

	u32 dwTmpMtInfoNum = 0;

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL == pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMtListFromJson] json_loads err!\n" );
		return FALSE;
	}

	// �Ƿ�ɾ����ʾ
	bDel = FALSE;
	json_t_ptr pjDel = json_object_get_s( pjRoot, JSON_DELFLAG );
	if ( NULL != pjDel )
	{
		if ( 1 == (u16)atoi( json_string_value( pjDel ) ) )
		{
			bDel = TRUE;
		}
	}
	
	json_t_ptr pjMtArray = json_object_get_s( pjRoot, JSON_MT );
	if ( NULL == pjMtArray )
	{
		OspPrintf( TRUE, FALSE, "[GetMtListFromJson] json_object_get MtArray is NULL!\n" );
		return FALSE;
	}
	
	dwTmpMtInfoNum = json_array_size( pjMtArray );
	u32 dwMtIdx = 0;
	for ( dwMtIdx = 0; dwMtIdx < dwTmpMtInfoNum; dwMtIdx++ )
	{
		json_t_ptr pjMtInfo = json_array_get_s( pjMtArray, dwMtIdx );
		if ( NULL == pjMtInfo )
		{
			continue;
		}
		
		// ��GUID
		json_t_ptr pjGUID = json_object_get_s( pjMtInfo, JSON_GUID );
		if ( NULL == pjGUID )
		{
			continue;
		}
		pcMtInfo[dwMtIdx].SetDomainGUID( json_string_value( pjGUID ) );
		
		// ��MOID
		json_t_ptr pjMOID = json_object_get_s( pjMtInfo, JSON_MOID );
		if ( NULL == pjMOID )
		{
			continue;
		}
		pcMtInfo[dwMtIdx].SetDomainMOID( json_string_value( pjMOID ) );

		// mtNO
		json_t_ptr pjMtNO = json_object_get_s( pjMtInfo, JSON_MTNO );
		if ( NULL == pjMtNO )
		{
			continue;
		}
		pcMtInfo[dwMtIdx].SetE164( json_string_value( pjMtNO ) );
		
		// mtType
		json_t_ptr pjMtType = json_object_get_s( pjMtInfo, JSON_MTTYPE );
		if ( NULL == pjMtType )
		{
			continue;
		}
		pcMtInfo[dwMtIdx].SetMtType( (u16)atoi( json_string_value( pjMtType ) ) );
		
		BOOL32 bFlag = FALSE;

		// �Ƿ����绰����
		json_t_ptr pjTelConfFlag = json_object_get_s( pjMtInfo, JSON_TELCONFFLAG );
		if ( NULL == pjTelConfFlag )
		{
			continue;
		}
		bFlag = ( 1 == (u16)atoi( json_string_value( pjTelConfFlag ) ) ) ? TRUE : FALSE;
		pcMtInfo[dwMtIdx].SetTelConfFlag( bFlag );

		// �Ƿ������˺�
		json_t_ptr pjLimitedFlag = json_object_get_s( pjMtInfo, JSON_LIMITEDFLAG );
		if ( NULL == pjLimitedFlag )
		{
			continue;
		}
		bFlag = ( 1 == (u16)atoi( json_string_value( pjLimitedFlag ) ) ) ? TRUE : FALSE;
		pcMtInfo[dwMtIdx].SetLimitedFlag( bFlag );
	}

	dwMtInfoNum = dwTmpMtInfoNum;
	return TRUE;
}


/*=============================================================================
�� �� ���� GetDomainListFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetDomainListFromJson(const s8 * pchJsonBuf, CKdvDomainInfo * pcDomainInfo, u32 &dwDomainNum, BOOL32 &bDel )
{
	if ( NULL == pchJsonBuf || NULL == pcDomainInfo )
	{
		OspPrintf( TRUE, FALSE, "[GetDomainListFromJson]Param is NULL, return!\n" );
		return FALSE;
	}
	
	u32 dwTmpDomainNum = 0;
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL == pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetDomainListFromJson] json_loads err!\n" );
		return FALSE;
	}
	
	// �Ƿ�ɾ����ʾ
	bDel = FALSE;
	json_t_ptr pjDel = json_object_get_s( pjRoot, JSON_DELFLAG );
	if ( NULL != pjDel )
	{
		if ( 1 == (u16)atoi( json_string_value( pjDel ) ) )
		{
			bDel = TRUE;
		}
	}
	
	json_t_ptr pjDomainInfoArray = json_object_get_s( pjRoot, JSON_DOMAIN );
	if ( NULL == pjDomainInfoArray )
	{
		OspPrintf( TRUE, FALSE, "[GetDomainListFromJson] json_object_get MtArray is NULL!\n" );
		return FALSE;
	}
	
	dwTmpDomainNum = json_array_size( pjDomainInfoArray );
	u32 dwDomainInfoIdx = 0;
	for ( dwDomainInfoIdx = 0; dwDomainInfoIdx < dwTmpDomainNum; dwDomainInfoIdx++ )
	{
		json_t_ptr pjDomainInfo = json_array_get_s( pjDomainInfoArray, dwDomainInfoIdx );
		if ( NULL == pjDomainInfo )
		{
			continue;
		}
		
		// ��GUID
		json_t_ptr pjGUID = json_object_get_s( pjDomainInfo, JSON_GUID );
		if ( NULL == pjGUID )
		{
			continue;
		}
		pcDomainInfo[dwDomainInfoIdx].SetDomainGUID( json_string_value( pjGUID ) );
		
		// ��MOID
		json_t_ptr pjMOID = json_object_get_s( pjDomainInfo, JSON_MOID );
		if ( NULL == pjMOID )
		{
			continue;
		}
		pcDomainInfo[dwDomainInfoIdx].SetDomainMOID( json_string_value( pjMOID ) );

		// �ϼ���MOID
		json_t_ptr pjSMOID = json_object_get_s( pjDomainInfo, JSON_SMOID );
		if ( NULL == pjSMOID )
		{
			continue;
		}
		pcDomainInfo[dwDomainInfoIdx].SetSDomainMOID( json_string_value( pjSMOID ) );

		// ������
		json_t_ptr pjDomainName = json_object_get_s( pjDomainInfo, JSON_DOMAINNAME );
		if ( NULL == pjDomainName )
		{
			continue;
		}
		pcDomainInfo[dwDomainInfoIdx].SetWholeName( json_string_value( pjDomainName ) );

		// ƽ̨��ǰ׺
		json_t_ptr pjPrefix = json_object_get_s( pjDomainInfo, JSON_PLATFORMPREFIX );
		if ( NULL == pjPrefix )
		{
			continue;
		}
		pcDomainInfo[dwDomainInfoIdx].SetPlatformPrefix( json_string_value( pjPrefix ) );
		
		// �򼶱�
		json_t_ptr pjDomainLvl = json_object_get_s( pjDomainInfo, JSON_DOMAINLVL );
		if ( NULL == pjDomainLvl )
		{
			continue;
		}
		pcDomainInfo[dwDomainInfoIdx].SetDomainLevel( (u16)atoi( json_string_value( pjDomainLvl ) ) );

		// �������������ٿ���
		json_t_ptr pjMaxConfNum = json_object_get_s( pjDomainInfo, JSON_MAXCONFNUM );
		if ( NULL == pjMaxConfNum )
		{
			continue;
		}
		pcDomainInfo[dwDomainInfoIdx].SetMaxConfNum( (u16)atoi( json_string_value( pjMaxConfNum ) ) );

		// �����������������
		json_t_ptr pjMaxCascadeConfNum = json_object_get_s( pjDomainInfo, JSON_MAXCCONFNUM );
		if ( NULL == pjMaxCascadeConfNum )
		{
			continue;
		}
		pcDomainInfo[dwDomainInfoIdx].SetMaxCascadeConfNum( (u16)atoi( json_string_value( pjMaxCascadeConfNum ) ) );
	}

	dwDomainNum = dwTmpDomainNum;
	
	return TRUE;
}

/*=============================================================================
�� �� ���� GetConfInfoFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetConfInfoExFromJson(const s8 * pchJsonBuf, TConfInfoEx & tConfInfoEx )
{
	if ( NULL == pchJsonBuf )
	{
		LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetConfInfoExFromJson] pchJsonBuf is NULL, retur FALSE!\n" );
		return FALSE;
	}

	/*TConfInfoEx�ṹ���е� TMtAlias m_tVrsRecAlias��Ա��GetAutoRecInfoFromJson �л�ȡ��
	TDurationDate  m_tDurationDate �ݲ���ȡ����Ĭ��ֵ��
	TKdvTime       m_tNextStartTime �ݲ���ȡ����Ĭ��ֵ��
	*/
	TVideoStreamCap atMainStreamCap[MAX_CONF_CAP_EX_NUM];
	TVideoStreamCap atDoubleStreamCap[MAX_CONF_CAP_EX_NUM];
	TAudioTypeDesc  atAudioDesc[MAXNUM_CONF_AUDIOTYPE];

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetConfInfoExFromJson] json_loads err!\n" );
		return FALSE;
	}
	// ˫��
	json_t_ptr pjSecVideoFormatArray = json_object_get_s( pjRoot, JSON_SECVIDEOFORMAT );
	if ( NULL != pjSecVideoFormatArray )
	{
		u16 wSecVideoFromatNum = json_array_size( pjSecVideoFormatArray );
		wSecVideoFromatNum = wSecVideoFromatNum <= 3 ? wSecVideoFromatNum : 3;
		u16 wSecVideoFormatIdx = 0;
		for ( wSecVideoFormatIdx = 0; wSecVideoFormatIdx < wSecVideoFromatNum; wSecVideoFormatIdx++ )
		{
			json_t_ptr pjSecVideoFormatInfo = json_array_get_s( pjSecVideoFormatArray, wSecVideoFormatIdx );
			if ( NULL == pjSecVideoFormatInfo )
			{
				continue;
			}

			json_t_ptr pjMediaType    = json_object_get_s( pjSecVideoFormatInfo, JSON_MEDIATYPE );
			//if ( NULL != pjMediaType )
			{
				atDoubleStreamCap[wSecVideoFormatIdx].SetMediaType( MEDIA_TYPE_H264 );
			}

			json_t_ptr pjMediaRes     = json_object_get_s( pjSecVideoFormatInfo, JSON_MEDIARES );
			if ( NULL != pjMediaRes )
			{
				atDoubleStreamCap[wSecVideoFormatIdx].SetResolution( (u8)atoi( json_string_value( pjMediaRes ) ) );
			}

			json_t_ptr pjMediaFrame   = json_object_get_s( pjSecVideoFormatInfo, JSON_MEDIAFRAME );
			if ( NULL != pjMediaFrame )
			{
				if( MEDIA_TYPE_H264 == atDoubleStreamCap[wSecVideoFormatIdx].GetMediaType() )
				{
					atDoubleStreamCap[wSecVideoFormatIdx].SetUserDefFrameRate( (u8)atoi( json_string_value( pjMediaFrame ) ) );
				}
				else
				{
					atDoubleStreamCap[wSecVideoFormatIdx].SetFrameRate( (u8)atoi( json_string_value( pjMediaFrame ) ) );
				}

			}

			json_t_ptr pjMediaH264 = json_object_get_s( pjSecVideoFormatInfo, JSON_MEDIAH264 );
			if ( NULL != pjMediaH264 )
			{
				u16 wH264Profile = (u16)atoi( json_string_value( pjMediaH264 ) );
				emProfileAttrb emProfile = ( 1 == wH264Profile ) ? emHpAttrb : emBpAttrb;
				atDoubleStreamCap[wSecVideoFormatIdx].SetH264ProfileAttrb( emProfile );
			}
		}

		// �˽ӿ��ڲ�ʵ��ð������������ķŵ���ǰ��
		tConfInfoEx.SetDoubleStreamCapEx( atDoubleStreamCap, (u8)wSecVideoFromatNum );
	}
	else
	{
		OspPrintf( TRUE, FALSE, "[GetConfInfoExFromJson]json_object_get pjSecVideoFormatArray is null, return!\n" );
	}

	// ����
	json_t_ptr pjVideoFormatArray = json_object_get_s( pjRoot, JSON_VIDEOFORMAT );
	if ( NULL != pjVideoFormatArray )
	{
		u16 wVideoFromatNum = json_array_size( pjVideoFormatArray );
		wVideoFromatNum = wVideoFromatNum <= 4 ? wVideoFromatNum : 4;
		u16 wVideoFormatIdx = 0;
		for ( wVideoFormatIdx = 0; wVideoFormatIdx < wVideoFromatNum; wVideoFormatIdx++ )
		{
			json_t_ptr pjVideoFormatInfo = json_array_get_s( pjVideoFormatArray, wVideoFormatIdx );
			if ( NULL == pjVideoFormatInfo )
			{
				continue;
			}

			json_t_ptr pjMediaType    = json_object_get_s( pjVideoFormatInfo, JSON_MEDIATYPE );
			// Ŀǰ����ֻʹ��H264
			//if ( NULL != pjMediaType )
			{
				atMainStreamCap[wVideoFormatIdx].SetMediaType( MEDIA_TYPE_H264 );
			}

			json_t_ptr pjMediaBitrate = json_object_get_s( pjVideoFormatInfo, JSON_MEDIABITRATE );
			if ( NULL != pjMediaBitrate )
			{
				u16 wBitrate = (u16)atoi( json_string_value( pjMediaBitrate ) );
				//emProfileAttrb emProfile = ( MIN_BITRATE_720P <= wBitrate ) ? emHpAttrb : emBpAttrb;

				atMainStreamCap[wVideoFormatIdx].SetMaxBitRate( wBitrate );
				//atMainStreamCap[wVideoFormatIdx].SetH264ProfileAttrb( emProfile );
			}

			json_t_ptr pjMediaRes     = json_object_get_s( pjVideoFormatInfo, JSON_MEDIARES );
			if ( NULL != pjMediaRes )
			{
				atMainStreamCap[wVideoFormatIdx].SetResolution( (u8)atoi( json_string_value( pjMediaRes ) ) );
			}

			json_t_ptr pjMediaFrame   = json_object_get_s( pjVideoFormatInfo, JSON_MEDIAFRAME );
			if ( NULL != pjMediaFrame )
			{
				if( MEDIA_TYPE_H264 == atMainStreamCap[wVideoFormatIdx].GetMediaType() )
				{
					atMainStreamCap[wVideoFormatIdx].SetUserDefFrameRate( (u8)atoi( json_string_value( pjMediaFrame ) ) );
				}
				else
				{
					atMainStreamCap[wVideoFormatIdx].SetFrameRate( (u8)atoi( json_string_value( pjMediaFrame ) ) );
				}				
			}

			json_t_ptr pjMediaH264 = json_object_get_s( pjVideoFormatInfo, JSON_MEDIAH264 );
			if ( NULL != pjMediaH264 )
			{
				u16 wH264Profile = (u16)atoi( json_string_value( pjMediaH264 ) );
				emProfileAttrb emProfile = ( 1 == wH264Profile ) ? emHpAttrb : emBpAttrb;
				atMainStreamCap[wVideoFormatIdx].SetH264ProfileAttrb( emProfile );
			}

			// 			u16 wBitrate = (u16)atoi( json_string_value( pjMediaBitrate ) );
			// 			emProfileAttrb emProfile = ( MIN_BITRATE_720P <= wBitrate ) ? emHpAttrb : emBpAttrb;
			// 
			// 			TVideoStreamCap tVideoStreamCap( (u8)atoi( json_string_value( pjMediaType ) ), 
			// 				                             (u8)atoi( json_string_value( pjMediaRes ) ),
			// 											 (u8)atoi( json_string_value( pjMediaFrame ) ), 
			// 											 emProfile, 
			// 											 (u16)atoi( json_string_value( pjMediaBitrate ) ) );
			// 
			// 			atMainStreamCap[wVideoFormatIdx] = tVideoStreamCap;
		}

		// �˽ӿ��ڲ�ʵ��ð������������ķŵ���ǰ��
		tConfInfoEx.SetMainStreamCapEx( atMainStreamCap, (u8)wVideoFromatNum );
	}
	else
	{
		OspPrintf( TRUE, FALSE, "[GetConfInfoExFromJson]json_object_get pjVideoFormatArray is null, return!\n" );
	}

	// ��Ƶ
	json_t_ptr pjAudioFormatArray = json_object_get_s( pjRoot, JSON_AUDIOFORMAT );
	if ( NULL != pjAudioFormatArray )
	{
		u16 wAudioFromatNum = json_array_size( pjAudioFormatArray );
		wAudioFromatNum = wAudioFromatNum <= 4 ? wAudioFromatNum : 4;
		u16 wAudioFormatIdx = 0;
		for ( wAudioFormatIdx = 0; wAudioFormatIdx < wAudioFromatNum; wAudioFormatIdx++ )
		{
			json_t_ptr pjAudioFormatInfo = json_array_get_s( pjAudioFormatArray, wAudioFormatIdx );
			if ( NULL == pjAudioFormatInfo )
			{
				continue;
			}

			json_t_ptr pjAudioType = json_object_get_s( pjAudioFormatInfo, JSON_AUDIOTYPE );

			if ( NULL == pjAudioType )
			{
				continue;
			}

			atAudioDesc[wAudioFormatIdx].SetAudioMediaType( (u8)atoi( json_string_value( pjAudioType ) ) );
			if ( MEDIA_TYPE_AACLC == atAudioDesc[wAudioFormatIdx].GetAudioMediaType() 
				|| MEDIA_TYPE_AACLD == atAudioDesc[wAudioFormatIdx].GetAudioMediaType() )
			{
				atAudioDesc[wAudioFormatIdx].SetAudioTrackNum( 2 );
			}
			else
			{
				atAudioDesc[wAudioFormatIdx].SetAudioTrackNum( 1 );
			}
		}

		tConfInfoEx.SetAudioTypeDesc( atAudioDesc, (u8)wAudioFromatNum );
	}
	else
	{
		OspPrintf( TRUE, FALSE, "[GetConfInfoExFromJson]json_object_get pjAudioFormatArray is null, return!\n" );
	}

	// ������moid
	json_t_ptr pjCreatorMoId = json_object_get_s(pjRoot, JSON_CREATORMOID);
	if (NULL == pjCreatorMoId)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoExFromJson] json_object_get pjCreatorMoId is NULL!\n");
	}
	else
	{
		tConfInfoEx.SetCreatorMoid(json_string_value(pjCreatorMoId));
	}

	return TRUE;
}

static BOOL32 GetConfrenceResolutionFromJson(const s8* pchJsonBuf, u8& byConfResolution)
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetConfResolutionFromJson] pchJsonBuf is NULL, retur FALSE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetResolutionFromJson] json_loads err!\n" );
		return FALSE;
	}
	json_t_ptr pjMediaRes = json_object_get_s( pjRoot, JSON_RES);
	if (pjMediaRes == NULL)
	{
		OspPrintf( TRUE, FALSE, "[GetResolutionFromJson] json_loads err!\n" );
		return FALSE;
	}

	byConfResolution = (u8)(atoi(json_string_value(pjMediaRes)));
	return TRUE;
}

static BOOL32 GetVmpModuleFromJson(json_t_ptr pjRoot, TVmpModuleInfo &tVmpModuleInfo)
{
	if (!pjRoot)
	{
		return FALSE;
	}
	TVMPParam tVMPParam;
	memset(&tVMPParam, 0, sizeof(tVMPParam));

	json_t_ptr pjVmpModule = json_object_get_s(pjRoot, JSON_VMPMODULE);
	if (NULL == pjVmpModule)
	{
		OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpModule is NUll, return FALSE!\n");
		return FALSE;
	}

	BOOL32 bIsHasVmpModule = (u8)atoi(json_string_value(pjVmpModule)) == 0 ? FALSE : TRUE;

	tVmpModuleInfo.Clear();
	tVmpModuleInfo.m_tVmpCfgInfo.ResetDefaultColor();
	if (bIsHasVmpModule)
	{
		json_t_ptr pjVmpParam = json_object_get_s(pjRoot, JSON_VMPPARAM);
		if (NULL == pjVmpParam)
		{
			OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpParam is NUll, return FALSE!\n");
			return FALSE;
		}

		json_t_ptr pjVmpAddAlias = json_object_get_s(pjVmpParam, JSON_VMPADDALIAS);   //�Ƿ���ʾ�ն˱���
		if (NULL == pjVmpAddAlias)
		{
			OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get_s VmpAddAlias is NUll!\n");
			tVMPParam.SetIsAddMmbAlias(FALSE);
		}
		else
		{
			BOOL32 bIsAddMbbAlias = (u8)(atoi(json_string_value(pjVmpAddAlias))) == 1 ? TRUE : FALSE;
			tVMPParam.SetIsAddMmbAlias(bIsAddMbbAlias);
		}

		json_t_ptr pjVmpBrdst = json_object_get_s(pjVmpParam, JSON_VMPBRDST);   //�Ƿ����ն˹㲥
		if (NULL == pjVmpBrdst)
		{
			OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpBrdst is NUll!\n");
			tVMPParam.SetVMPBrdst(FALSE);
		}
		else
		{
			tVMPParam.SetVMPBrdst((u8)atoi(json_string_value(pjVmpBrdst)));
		}

		json_t_ptr pjVmpStyle = json_object_get_s(pjVmpParam, JSON_VMPSTYLE);  //����ϳɷ��
		if (NULL == pjVmpStyle)
		{
			OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpStyle is NUll!\n");
			tVMPParam.SetVMPStyle(VMP_STYLE_DYNAMIC);
		}
		else
		{
			tVMPParam.SetVMPStyle((u8)atoi(json_string_value(pjVmpStyle)));
		}

		json_t_ptr pjVmpMode = json_object_get_s(pjVmpParam, JSON_VMPMODE);   //�ϳ�ģʽ
		if (NULL == pjVmpMode)
		{
			OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpMode is NUll!\n");
			tVMPParam.SetVMPMode(CONF_VMPMODE_AUTO);
			tVMPParam.SetVMPAuto(TRUE);
		}
		else
		{
			tVMPParam.SetVMPMode((u8)(atoi(json_string_value(pjVmpMode))));
			if (tVMPParam.GetVMPMode() == CONF_VMPMODE_AUTO)
			{
				tVMPParam.SetVMPAuto(TRUE);
			}
			else if (tVMPParam.GetVMPMode() == CONF_VMPMODE_BATCH)
			{
				tVMPParam.SetVMPBatchPoll(TRUE);
			}
		}

		json_t_ptr pjVmpPrim = json_object_get_s(pjVmpParam, JSON_VMPPRIM);   //�Ƿ�ʹ�ñ߿�
		if (NULL == pjVmpPrim)
		{
			OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpPrim is NUll!\n");
			tVMPParam.SetIsRimEnabled(FALSE);
		}
		else
		{
			tVMPParam.SetIsRimEnabled((u8)(atoi(json_string_value(pjVmpPrim))));
		}

		json_t_ptr pjVmpVoiceHint = json_object_get_s(pjVmpParam, JSON_VMPVOICEHINT);  // �Ƿ���ʾ������ʾ��
		if (NULL == pjVmpVoiceHint)
		{
			OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpVoiceHint is NUll!\n");
			tVMPParam.SetVoiceHint(FALSE);
		}
		else
		{
			tVMPParam.SetVoiceHint((atoi(json_string_value(pjVmpVoiceHint)) == 0) ? FALSE : TRUE);
		}

		if (tVMPParam.GetVMPMode() == CONF_VMPMODE_CTRL)
		{
			// �ϳɳ�Ա�б�
			json_t_ptr pjVmpMemValueArray = json_object_get_s(pjVmpParam, JSON_VMPMEMBERS);
			if (NULL == pjVmpMemValueArray)
			{
				OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpMemValueArray is NUll, return FALSE!\n");
				return FALSE;
			}

			u32 dwVmpMemNum = (u32)json_array_size(pjVmpMemValueArray);
			u32 dwVmpMemLoop = 0;

			TVMPMember  tVmpMember;
			for (dwVmpMemLoop = 0; dwVmpMemLoop < dwVmpMemNum; dwVmpMemLoop++)
			{
				json_t_ptr pjVmpMemValue = json_array_get_s(pjVmpMemValueArray, dwVmpMemLoop);
				if (NULL == pjVmpMemValue)
				{
					OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_array_get<Idx.%d> VmpMemValue is NUll, continue!\n", dwVmpMemLoop);
					continue;
				}

				tVmpMember.Clear();

				u8 byVmpChnIdx = MAXNUM_VMP_MEMBER;
				json_t_ptr pjVmpChnIdx = json_object_get_s(pjVmpMemValue, JSON_VMPCHNIDX);
				if (NULL == pjVmpChnIdx)
				{
					OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get<Idx.%d> VmpChnIdx is NUll!\n", dwVmpMemLoop);
					continue;
				}

				byVmpChnIdx = (u8)atoi(json_string_value(pjVmpChnIdx));
				if (byVmpChnIdx < MAXNUM_VMP_MEMBER)
				{
					tVMPParam.SetVmpMember((u8)atoi(json_string_value(pjVmpChnIdx)), tVmpMember);
				}
				else
				{
					continue;
				}

				json_t_ptr pjVmpType = json_object_get_s(pjVmpMemValue, JSON_VMPTYPE);
				if (NULL == pjVmpType)
				{
					OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get<Idx.%d> VmpType is NUll!\n", dwVmpMemLoop);
					tVmpMember.SetMemberType(VMP_MEMBERTYPE_MCSSPEC);
					tVmpModuleInfo.m_abyMemberType[byVmpChnIdx] = VMP_MEMBERTYPE_MCSSPEC;
				}
				else
				{
					tVmpMember.SetMemberType((u8)atoi(json_string_value(pjVmpType)));
					tVmpModuleInfo.m_abyMemberType[byVmpChnIdx] = (u8)atoi(json_string_value(pjVmpType));
				}

				json_t_ptr pjVmpIndex = json_object_get_s(pjVmpMemValue, JSON_VMPINDEX);
				if (NULL == pjVmpIndex)
				{
					OspPrintf(TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get<Idx.%d> VmpIndex is NUll!\n", dwVmpMemLoop);
				}
				else if (MAXNUM_CONF_MT >= (u8)atoi(json_string_value(pjVmpIndex)))
				{
					tVmpModuleInfo.m_abyVmpMember[byVmpChnIdx] = (u8)atoi(json_string_value(pjVmpIndex));
				}
			}

			// ��ͨ����ѯ����
			// ģ�治��֧�ֵ�ͨ����ѯ by mxm 20150518
			/*json_t_ptr pjVmpChnPollArray = json_object_get( pjVmpParam, JSON_VMPPOLLPARAM );
			if ( NULL == pjVmpChnPollArray )
			{
		
				OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get pjVmpChnPollArray is NUll, return FALSE!\n" );
				return FALSE;
			}

			u32 dwPollChnNum = (u32)json_array_size( pjVmpChnPollArray );
			u32 dwParamLoop = 0;

			TVmpChnPollParam tChnPollParam;
			for ( dwParamLoop = 0; dwParamLoop < dwPollChnNum; dwParamLoop++ )
			{
				json_t_ptr pjChnPollParam = json_array_get( pjVmpChnPollArray, dwParamLoop );
				if ( NULL == pjChnPollParam )
				{
					OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_array_get pjVmpChnPollArray Loop.%u failed, contiue!\n", dwParamLoop );
					continue;
				}

				tChnPollParam.Clear();

				json_t_ptr pjPollChnIdx = json_object_get( pjChnPollParam, JSON_VMPCHNIDX );
				if ( NULL == pjPollChnIdx )
				{
					OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get pjPollChnIdx failed, contiue!\n" );
					continue;
				}
				else
				{
					tChnPollParam.SetChnIdx( (u8)atoi(json_string_value(pjPollChnIdx)) );
				}

				json_t_ptr pjPollNum = json_object_get( pjChnPollParam, JSON_POLLNUM );
				if ( NULL == pjPollNum )
				{
					tChnPollParam.SetPollingNumber( 0 );
				}
				else
				{
					tChnPollParam.SetPollingNumber( (u32)strtoul(json_string_value(pjPollNum), 0, 10) );
				}

				json_t_ptr pjPollKeepTime = json_object_get( pjChnPollParam, JSON_POLLKEEPTIME );
				if ( NULL == pjPollKeepTime )
				{
					tChnPollParam.SetKeepTime( 5 );
				}
				else
				{
					tChnPollParam.SetKeepTime( (u32)strtoul(json_string_value(pjPollKeepTime), 0, 10) );
				}

				tVmpModuleInfo.m_tVmpChnPollInfo.SetChnPollParam( tChnPollParam.GetChnIdx(), tChnPollParam );

				json_t_ptr pjChnPollMmbArray = json_object_get( pjChnPollParam, JSON_POLLMT );
				if ( NULL == pjChnPollMmbArray )
				{
					continue;
				}

				u32 dwPollMmbNum = (u32)json_array_size( pjChnPollMmbArray );
				u32 dwMmbLoop = 0;
				u32 dwValidIdx = 0;
				for ( dwMmbLoop = 0; dwMmbLoop < dwPollMmbNum; dwMmbLoop++ )
				{
					json_t_ptr pjPollMmb = json_array_get( pjChnPollMmbArray, dwMmbLoop );
					if ( NULL == pjPollMmb )
					{
						OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get pjPollMmb Loop.%u failed, contiue!\n", dwMmbLoop );
						continue;
					}

					json_t_ptr pjMtIdx = json_object_get( pjPollMmb, JSON_VMPINDEX );
					if ( NULL == pjMtIdx )
					{
						OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get pjMtIdx failed, contiue!\n" );
						continue;
					}
					else
					{
						tVmpModuleInfo.m_abyChnPollMt[tChnPollParam.GetChnIdx()][dwValidIdx] = (u8)atoi( json_string_value(pjMtIdx) );
						dwValidIdx++;
					}
				}
			}*/

		}
	}
	else
	{
		tVMPParam.SetVMPStyle(VMP_STYLE_DYNAMIC);							//����ϳɷ��
		tVMPParam.SetIsAddMmbAlias(TRUE);									//��ʾ�ն˱���
		tVMPParam.SetVMPMode(CONF_VMPMODE_AUTO);							//2 - �Զ�ͼ�񸴺�(��̬���������ó�Ա)
		tVMPParam.SetVMPBrdst(1);											//1 - �ϳ�ͼ���Ƿ����ն˹㲥
		tVMPParam.SetIsRimEnabled(1);										//�Ƿ�ʹ�ñ߿�
	}

	// ����ϳ�ģ�� δ������� todo(������ѯ) 
	tVmpModuleInfo.SetVmpParam(tVMPParam);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetVmpModuleFromJson
��    �ܣ� Jsonת��ΪTVmpModule
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetVmpModuleFromJson(const s8 * pchJsonBuf, TVmpModuleInfo & tVmpModuleInfo )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] pchJsonBuf is NULL, retur FALSE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_loads err!\n" );
		return FALSE;
	}
	
	BOOL32 bRet = GetVmpModuleFromJson(pjRoot, tVmpModuleInfo);

	return bRet;
}
static BOOL32 GetVmpParamFromJson( json_t_ptr pjVmpParam, TVMPParam & tVMPParam )
{
	if ( NULL == pjVmpParam )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpParamFromJson] pjVmpParam is NULL, return FALSE!\n" );
		return FALSE;
	}
	//�Ƿ����ڻ���ϳ�
	json_t_ptr pjVmpIsCaping = json_object_get_s( pjVmpParam, JSON_VMPISCAPING );
	if ( NULL == pjVmpIsCaping )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpParamFromJson] json_object_get pjVmpIsCaping is NUll!\n" );
		tVMPParam.SetIsCping( FALSE );
	}
	else
	{
		BOOL32 bIsCaping = (u8)( atoi( json_string_value( pjVmpIsCaping ) ) ) == 1 ? TRUE : FALSE;
		tVMPParam.SetIsCping( bIsCaping );
	}
	//�Ƿ����Զ�����ϳ� 0-�� 1-��
	json_t_ptr pjVmpIsAuto = json_object_get_s( pjVmpParam, JSON_VMPAUTO );
	if ( NULL == pjVmpIsAuto )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpParamFromJson] json_object_get pjVmpIsAuto is NUll!\n" );
		tVMPParam.SetVMPAuto( FALSE );
	}
	else
	{
		BOOL32 bIsAuto = (u8)( atoi( json_string_value( pjVmpIsAuto ) ) ) == 1 ? TRUE : FALSE;
		tVMPParam.SetVMPAuto( bIsAuto );
	}
	//�Ƿ����ն˹㲥
	json_t_ptr pjVmpBrdst = json_object_get_s( pjVmpParam, JSON_VMPBRDST );
	if ( NULL == pjVmpBrdst )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpParamFromJson] json_object_get VmpBrdst is NUll!\n" );
		tVMPParam.SetVMPBrdst( FALSE );
	}
	else
	{
		tVMPParam.SetVMPBrdst( (u8)atoi(json_string_value( pjVmpBrdst ) ) );
	}
	//����ϳɷ��
	json_t_ptr pjVmpStyle = json_object_get_s( pjVmpParam, JSON_VMPSTYLE );
	if ( NULL == pjVmpStyle )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpStyle is NUll!\n" );
		tVMPParam.SetVMPStyle( VMP_STYLE_DYNAMIC );
	}
	else
	{
		tVMPParam.SetVMPStyle( (u8)atoi( json_string_value( pjVmpStyle ) ) );
	}
	//�ϳɷ�񷽰����,���֧��5�׷���,1-5
	json_t_ptr pjVMPSchemeId = json_object_get_s( pjVmpParam, JSON_VMPSCHEMEID );
	if ( NULL == pjVMPSchemeId )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get pjVMPSchemeId is NUll!\n" );
		tVMPParam.SetVMPSchemeId( 0 );
	}
	else
	{
		tVMPParam.SetVMPSchemeId( (u8)atoi( json_string_value( pjVMPSchemeId ) ) );
	}
	//�ϳ�ģʽ
	json_t_ptr pjVmpMode = json_object_get_s( pjVmpParam, JSON_VMPMODE );
	if ( NULL == pjVmpMode )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpMode is NUll!\n" );
		tVMPParam.SetVMPMode( CONF_VMPMODE_AUTO );
		tVMPParam.SetVMPAuto( TRUE );
	}
	else
	{
		tVMPParam.SetVMPMode( (u8)( atoi( json_string_value( pjVmpMode ) ) ) );
		if ( tVMPParam.GetVMPMode() == CONF_VMPMODE_AUTO )
		{
			tVMPParam.SetVMPAuto( TRUE );
		}
		else if ( tVMPParam.GetVMPMode() == CONF_VMPMODE_BATCH )
		{
			tVMPParam.SetVMPBatchPoll( TRUE );
		}
	}
	//�Ƿ�ʹ�ñ߿�
	json_t_ptr pjVmpPrim = json_object_get_s( pjVmpParam, JSON_VMPPRIM );
	if ( NULL == pjVmpPrim )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpPrim is NUll!\n" );
		tVMPParam.SetIsRimEnabled( FALSE );
	}
	else
	{
		tVMPParam.SetIsRimEnabled( (u8)( atoi( json_string_value( pjVmpPrim ) ) ) );
	}
	//�Ƿ���ʾ�ն˱���
	json_t_ptr pjVmpAddAlias = json_object_get_s( pjVmpParam, JSON_VMPADDALIAS );
	if ( NULL == pjVmpAddAlias )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpParamFromJson] json_object_get VmpAddAlias is NUll!\n" );
		tVMPParam.SetIsAddMmbAlias( FALSE );
	}
	else
	{
		BOOL32 bIsAddMbbAlias = (u8)( atoi( json_string_value( pjVmpAddAlias ) ) ) == 1 ? TRUE : FALSE;
		tVMPParam.SetIsAddMmbAlias( bIsAddMbbAlias );
	}
	// // ��ѯ���
	json_t_ptr pjVmpBatchPollTime = json_object_get_s( pjVmpParam, JSON_VMPBATCHPOLLTIME );
	if ( NULL == pjVmpBatchPollTime )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpParamFromJson] json_object_get pjVmpBatchPollTime is NUll!\n" );
		tVMPParam.SetVMPBatchPollKeepTime( 0 );
	}
	else
	{
		tVMPParam.SetVMPBatchPollKeepTime( (u8)( atoi( json_string_value( pjVmpBatchPollTime ) ) ) );
	}
	// ��ѯ����
	json_t_ptr pjVmpBatchPollNum = json_object_get_s( pjVmpParam, JSON_VMPBATCHPOLLNUM );
	if ( NULL == pjVmpBatchPollNum )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpParamFromJson] json_object_get pjVmpBatchPollNum is NUll!\n" );
		tVMPParam.SetVMPBatchPollPollNum( 0 );
	}
	else
	{
		tVMPParam.SetVMPBatchPollPollNum( (u8)( atoi( json_string_value( pjVmpBatchPollNum ) ) ) );
	}
	// �Ƿ���ʾ������ʾ��
	json_t_ptr pjVmpVoiceHint = json_object_get_s( pjVmpParam, JSON_VMPVOICEHINT );
	if ( NULL == pjVmpVoiceHint )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpVoiceHint is NUll!\n" );
		tVMPParam.SetVoiceHint( FALSE );
	}
	else
	{
		tVMPParam.SetVoiceHint( (atoi(json_string_value( pjVmpVoiceHint)) == 0) ? FALSE : TRUE );
	}

	// �ϳɳ�Ա�б�
	json_t_ptr pjVmpMemValueArray = json_object_get_s( pjVmpParam, JSON_VMPMEMBERS );
	if ( NULL == pjVmpMemValueArray )
	{
		OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get VmpMemValueArray is NUll, return FALSE!\n" );
		return FALSE;
	}

	u32 dwVmpMemNum = (u32)json_array_size( pjVmpMemValueArray );
	u32 dwVmpMemLoop = 0;

	TVMPMember  tVmpMember;
	for ( dwVmpMemLoop = 0; dwVmpMemLoop < dwVmpMemNum; dwVmpMemLoop++ )
	{
		json_t_ptr pjVmpMemValue = json_array_get_s( pjVmpMemValueArray, dwVmpMemLoop );
		if ( NULL == pjVmpMemValue )
		{
			OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_array_get<Idx.%d> VmpMemValue is NUll, continue!\n", dwVmpMemLoop );
			continue;
		}

		tVmpMember.Clear();

		u8 byVmpChnIdx = MAXNUM_VMP_MEMBER;
		json_t_ptr pjVmpChnIdx = json_object_get_s( pjVmpMemValue, JSON_VMPCHNIDX );
		if ( NULL == pjVmpChnIdx )
		{
			OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get<Idx.%d> VmpChnIdx is NUll!\n", dwVmpMemLoop );
			continue;
		}

		byVmpChnIdx = (u8)atoi( json_string_value( pjVmpChnIdx ) );
		if ( byVmpChnIdx < MAXNUM_VMP_MEMBER )
		{
			tVmpMember.SetChnIdx(byVmpChnIdx);
		}
		else
		{
			continue;
		}

		json_t_ptr pjVmpType = json_object_get_s( pjVmpMemValue, JSON_VMPTYPE );
		if ( NULL == pjVmpType )
		{
			OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get<Idx.%d> VmpType is NUll!\n", dwVmpMemLoop );
			tVmpMember.SetMemberType( VMP_MEMBERTYPE_MCSSPEC );
		}
		else
		{
			tVmpMember.SetMemberType( (u8)atoi( json_string_value( pjVmpType ) ) );
		}

		json_t_ptr pjVmpStatus = json_object_get_s( pjVmpMemValue, JSON_VMPSTATUS );
		if ( NULL == pjVmpStatus )
		{
			OspPrintf( TRUE, FALSE, "[GetVmpModuleFromJson] json_object_get<Idx.%d> pjVmpStatus is NUll!\n", dwVmpMemLoop );
		}
		else 
		{
			tVmpMember.SetMemStatus((u8)atoi( json_string_value( pjVmpType )));
		}
		tVMPParam.SetVmpMember(dwVmpMemLoop, tVmpMember);
	}

	return TRUE;
}
static BOOL32 GetMixParamFromJson( json_t_ptr pjMixParam, TMixParam & tMixParam )
{
	if ( NULL == pjMixParam )
	{
		OspPrintf( TRUE, FALSE, "[GetMixParamFromJson] pjMixParam is NULL, return FALSE!\n" );
		return FALSE;
	}
	//����ģʽ
	json_t_ptr pjMixMode = json_object_get_s( pjMixParam, JSON_MIXMODE );
	if ( NULL == pjMixMode )
	{
		OspPrintf( TRUE, FALSE, "[GetMixParamFromJson] json_object_get MixMode is NUll!\n" );
	}
	else
	{
		tMixParam.SetMode( (u8)atoi( json_string_value( pjMixMode ) ) );
	}


	json_t_ptr pjMixMembArray = json_object_get_s( pjMixParam, JSON_MIXMEMBER );
	if ( NULL == pjMixMembArray )
	{
		OspPrintf( TRUE, FALSE, "[GetMixParamFromJson] json_object_get MixMemValueArray is NUll, return FALSE!\n" );
		return FALSE;
	}

	u32 dwMixMemNum = (u32)json_array_size( pjMixMembArray );
	u32 dwMixMtLoop = 0;
	for ( dwMixMtLoop = 0; dwMixMtLoop < dwMixMemNum; dwMixMtLoop++ )
	{
		json_t_ptr pjMixMemValue = json_array_get_s( pjMixMembArray, dwMixMtLoop );
		if ( NULL == pjMixMemValue )
		{
			OspPrintf( TRUE, FALSE, "[GetMixParamFromJson] json_array_get<Idx.%d> MixMemIdx is NUll, continue!\n", dwMixMtLoop );
			continue;
		}

		json_t_ptr pjMixIndex = json_object_get_s( pjMixMemValue, JSON_MIXINDEX );
		if ( NULL == pjMixIndex )
		{
			OspPrintf( TRUE, FALSE, "[GetMixParamFromJson] json_object_get<Idx.%d> MixMemIdx is NUll!\n", dwMixMtLoop );
			continue;
		}
		u8 byMtId = (u8)atoi( json_string_value( pjMixIndex ) );
		if ( MAXNUM_CONF_MT < byMtId )
		{
			OspPrintf( TRUE, FALSE, "[GetMixParamFromJson] json_object_get<loopId.%d> MixMemIdx,exceptional value:%d !\n", 
				dwMixMtLoop,  byMtId);
			continue;
		}
		tMixParam.AddMember(byMtId);
	}

	return TRUE;
}
/*=============================================================================
�� �� ���� GetPollModuleFromJson
��    �ܣ� Jsonת��ΪTPollModule
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetPollModuleFromJson(const s8 * pchJsonBuf, TPollModule & tPollModule )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] pchJsonBuf is NULL, retur FALSE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_loads err!\n" );
		return FALSE;
	}
	
	TPollParam tPollParam;
	TMtPollParam tMtPollParam;
	tPollParam.Clear();
	u32 dwPollnum = 0;
	u16 wKeeptime = 0; 

	json_t_ptr pjPollModule = json_object_get_s( pjRoot, JSON_POLLMODULE );
	if ( NULL == pjPollModule )
	{
		OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_object_get PollModule is NUll, return FALSE!\n" );
		return FALSE;
	}
	
	BOOL32 bIsHasPollModule  = (u8)atoi( json_string_value( pjPollModule ) ) == 0 ? FALSE : TRUE;
	if ( bIsHasPollModule )
	{
		json_t_ptr pjPollParam = json_object_get_s( pjRoot, JSON_POLLPARAM );
		if ( NULL == pjPollParam )
		{
			OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_object_get PollParam is NUll, return FALSE!\n" );
			return FALSE;
		}
		
		json_t_ptr pjPollMode = json_object_get_s( pjPollParam, JSON_POLLMODE );   //��ѯģʽ
		if ( NULL == pjPollMode )
		{
			OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_object_get PollMode is NUll!\n" );
		}
		else
		{
			tPollParam.SetMediaMode( (u8)atoi( json_string_value( pjPollMode ) ) );
		}
		
		json_t_ptr pjPollNum = json_object_get_s( pjPollParam, JSON_POLLNUM );   //��ѯ����
		if ( NULL == pjPollNum )
		{
			OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_object_get PollNum is NUll!\n" );
		}
		else
		{
			dwPollnum = (u32)strtoul( json_string_value( pjPollNum ), 0, 10 );
			tPollParam.SetPollNum( dwPollnum );
		}

		json_t_ptr pjKeepTime = json_object_get_s( pjPollParam, JSON_POLLKEEPTIME );   //��ѯ���
		if ( NULL == pjKeepTime )
		{
			OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_object_get KeepTime is NUll, return FALSE!\n" );
		}
		else
		{
			wKeeptime = (u16)atoi( json_string_value( pjKeepTime ) );
		}
		
		json_t_ptr pjPollMemValueArray = json_object_get_s( pjPollParam, JSON_POLLMT );
		if ( NULL == pjPollMemValueArray )
		{
			OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_object_get PollMemValueArray is NUll, return FALSE!\n" );
			return FALSE;
		}
		
		u32 dwPollMemNum = (u32)json_array_size( pjPollMemValueArray );
		u32 dwPollLoop = 0;
		u32 dwValidIdx = 0;
		for ( dwPollLoop = 0; dwPollLoop < dwPollMemNum; dwPollLoop++ )
		{
			json_t_ptr pjPollMemValue = json_array_get_s( pjPollMemValueArray, dwPollLoop );
			if ( NULL == pjPollMemValue )
			{
				OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_array_get<Idx.%d> PollMemValue is NUll, continue!\n", dwPollLoop );
				continue;
			}
			
			json_t_ptr pjPollIndex = json_object_get_s( pjPollMemValue, JSON_POLLIDX );
			if ( NULL == pjPollIndex )
			{
				OspPrintf( TRUE, FALSE, "[GetPollModuleFromJson] json_object_get<Idx.%d> PollIndex is NUll!\n", dwPollLoop );
				continue;
			}
			if ( MAXNUM_CONF_MT < (u32)strtoul( json_string_value( pjPollIndex ), 0, 10 ) )
			{
				continue;
			}

			tMtPollParam.Clear();
			tMtPollParam.SetKeepTime( wKeeptime );
			tMtPollParam.SetPollNum( dwPollnum );
			
			tPollParam.SetPollMember( (u8)dwValidIdx, tMtPollParam );
			tPollModule.m_abyPollMember[dwValidIdx] = (u8)atoi( json_string_value( pjPollIndex ) );
			dwValidIdx++;
			//tPollModule.SetPollMember( dwPollLoop, (u8)atoi( json_string_value( pjPollIndex ) ) );
		}
		tPollModule.SetPollParam( tPollParam );
	}
	else
	{
		tPollModule.EmptyMember();
	}

	return TRUE;
}

static BOOL32 GetMixModuleFromJson(json_t_ptr pjRoot, TMixModule &tMixModule)
{
	if (!pjRoot)
	{
		return FALSE;
	}
	u32 dwPollnum = 0;
	u16 wKeeptime = 0;

	json_t_ptr pjMixModule = json_object_get_s(pjRoot, JSON_MIXMODULE);
	if (NULL == pjMixModule)
	{
		OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_object_get PollModule is NUll, return FALSE!\n");
		return FALSE;
	}

	BOOL32 bIsHasMixModule = (u8)atoi(json_string_value(pjMixModule)) == 0 ? FALSE : TRUE;
	OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_object_get MixModule is %d !\n", bIsHasMixModule);

	if (bIsHasMixModule)
	{
		json_t_ptr pjMixParam = json_object_get_s(pjRoot, JSON_MIXPARAM);
		if (NULL == pjMixParam)
		{
			OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_object_get mixparam is NUll, return FALSE!\n");
			return FALSE;
		}

		json_t_ptr pjMixMode = json_object_get_s(pjMixParam, JSON_MIXMODE);   //����ģʽ
		if (NULL == pjMixMode)
		{
			OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_object_get MixMode is NUll!\n");
		}
		else
		{
			tMixModule.SetModuleMixMode((u8)atoi(json_string_value(pjMixMode)));
		}

		json_t_ptr pjVacInterVal = json_object_get_s(pjMixParam, JSON_VACINTERVAL);   //����ʱ����
		if (NULL == pjVacInterVal)
		{
			OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_object_get VacTime is NUll!\n");
		}
		else
		{
			tMixModule.SetVACPeriodTime((u8)atoi(json_string_value(pjVacInterVal)));
		}


		json_t_ptr pjMixMembArray = json_object_get_s(pjMixParam, JSON_MIXMEMBER);
		if (NULL == pjMixMembArray)
		{
			OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_object_get MixMemValueArray is NUll, return FALSE!\n");
			return FALSE;
		}

		u32 dwMixMemNum = (u32)json_array_size(pjMixMembArray);
		u32 dwMixMtLoop = 0;
		u32 dwValidIdx = 0;
		for (dwMixMtLoop = 0; dwMixMtLoop < dwMixMemNum; dwMixMtLoop++)
		{
			json_t_ptr pjMixMemValue = json_array_get_s(pjMixMembArray, dwMixMtLoop);
			if (NULL == pjMixMemValue)
			{
				OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_array_get<Idx.%d> MixMemIdx is NUll, continue!\n", dwMixMtLoop);
				continue;
			}

			json_t_ptr pjMixIndex = json_object_get_s(pjMixMemValue, JSON_MIXINDEX);
			if (NULL == pjMixIndex)
			{
				OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_object_get<Idx.%d> MixMemIdx is NUll!\n", dwMixMtLoop);
				continue;
			}
			u8 byMtId = (u8)atoi(json_string_value(pjMixIndex));
			if (MAXNUM_CONF_MT < byMtId)
			{
				OspPrintf(TRUE, FALSE, "[GetMixModuleFromJson] json_object_get<loopId.%d> MixMemIdx,exceptional value:%d !\n",
					dwMixMtLoop, byMtId);
				continue;
			}

			tMixModule.SetMixMtIdx(dwValidIdx, byMtId);
			dwValidIdx++;
		}
	}
	else
	{
		tMixModule.Clear();
	}
	tMixModule.PrintMixModule();
	return TRUE;
}

/*=============================================================================
�� �� ���� GetPollModuleFromJson
��    �ܣ� Jsonת��ΪTPollModule
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015-7-14	5.0         ��ʤ��                ����
=============================================================================*/
static BOOL32 GetMixModuleFromJson(const s8 * pchJsonBuf, TMixModule &tMixModule )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetMixModuleFromJson] pchJsonBuf is NULL, retur FALSE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMixModuleFromJson] json_loads err!\n" );
		return FALSE;
	}

	BOOL32 bRet = FALSE;
	bRet = GetMixModuleFromJson(pjRoot, tMixModule);

	return bRet;
}

/*=============================================================================
�� �� ���� GetHduModuleFromJson
��    �ܣ� Jsonת��ΪTPollModule
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/02/13  5.0         ����                    ����
=============================================================================*/
static BOOL32 GetHduModuleFromJson(const s8 * pchJsonBuf, THduVmpModuleOrTHDTvWall &tHduModule )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] pchJsonBuf is NULL, return FALSE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_loads err!\n" );
		return FALSE;
	}
	
	THduVmpChannlInfo atHduChnInfo[(HDUID_MAX-HDUID_MIN+1)*MAXNUM_HDU_CHANNEL];
	TPollParam tPollParam;
	TMtPollParam tMtPollParam;
	tPollParam.Clear();

	BOOL32 bIsHasHduModule = 0;
	json_t_ptr pjHduModule = json_object_get_s( pjRoot, JSON_HDUMODULE );
	if ( NULL == pjHduModule )
	{
		OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get HduModule is NUll!\n" );
	}
	else
	{
		bIsHasHduModule = (u8)atoi( json_string_value( pjHduModule ) ) == 0 ? FALSE : TRUE;
	}
	
	if ( !bIsHasHduModule )
	{
		OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson]Do't has hdu module.\n" );
		tHduModule.Clear();
	}
	else
	{
		json_t_ptr pjHduParamArray = json_object_get_s( pjRoot, JSON_HDUPARAM );
		u8 byHduParamNum = json_array_size( pjHduParamArray );
		if ( NULL == pjHduParamArray )
		{
			OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get HduParamArray is NUll!\n" );
		}
		else
		{	
			u8 byHduParamLoop = 0;
			u8 byValidIdx = 0;
			for ( byHduParamLoop = 0; byHduParamLoop < byHduParamNum; byHduParamLoop++ )
			{
				json_t_ptr pjHduParamObj = json_array_get_s( pjHduParamArray, byHduParamLoop );
				if ( NULL == pjHduParamObj )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d HduParamObj is NUll!\n", byHduParamLoop );
					continue;
				}
			
				json_t_ptr pjHduId = json_object_get_s( pjHduParamObj, JSON_HDUID );
				if ( NULL == pjHduId )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduId is NUll!\n", byHduParamLoop );
					continue;
				}
				u8 byHduId = (u8)atoi(json_string_value( pjHduId ) ) ;
				
				if ( byHduId == 0 )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduId is 0!\n", byHduParamLoop );
					continue;
				}
				
				atHduChnInfo[byValidIdx].m_byHduEqpId = byHduId;
				

				json_t_ptr pjHduChnIdx = json_object_get_s( pjHduParamObj, JSON_HDUCHLIDX );
				if ( NULL == pjHduChnIdx )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduChnIdx is NUll!\n", byHduParamLoop );
				}
				else
				{
					atHduChnInfo[byValidIdx].m_byChIdx = (u8)atoi(json_string_value( pjHduChnIdx ) );
				}

				json_t_ptr pjHduStyle = json_object_get_s( pjHduParamObj, JSON_HDUSTYLE );
				if ( NULL == pjHduStyle )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduStyle is NUll!\n", byHduParamLoop );
				}
				else
				{
					atHduChnInfo[byValidIdx].m_byVmpStyle = (u8)atoi(json_string_value( pjHduStyle ) );
				}

				json_t_ptr pjHduMemArray = json_object_get_s( pjHduParamObj, JSON_HDUMEMBER );
				if ( NULL == pjHduMemArray )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduMemArray is NUll!\n", byHduParamLoop );
				}
				else
				{
					u8 byHduMemNum = json_array_size( pjHduMemArray );
					u8 byHduMemIdx = 0;
					if ( HDUCHN_MODE_FOUR == atHduChnInfo[byHduParamLoop].m_byVmpStyle )
					{
						for ( byHduMemIdx = 0; byHduMemIdx < byHduMemNum; byHduMemIdx++ )
						{
							json_t_ptr pjHduMemObj = json_array_get_s( pjHduMemArray, byHduMemIdx );
							if ( NULL == pjHduMemObj )
							{
								OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Param Idx.%d MemIdx.%d pjHduMemObj is NUll!\n", byHduParamLoop, byHduMemIdx );
								continue;
							}

							u8 bySubChnIdx = 0;
							json_t_ptr pjSubchnidx = json_object_get_s( pjHduMemObj, JSON_HDUSUBCHLIDX );
							if ( NULL == pjSubchnidx )
							{
								LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get Subchnidx is NUll!\n" );
							}
							else
							{
								bySubChnIdx = (u8)atoi( json_string_value( pjSubchnidx ) );
							}

							json_t_ptr pjHduIndex = json_object_get_s( pjHduMemObj, JSON_HDU_INDEX );
							if ( NULL == pjHduIndex )
							{
								LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get VmpType is NUll!\n" );
							}
							else
							{
								atHduChnInfo[byValidIdx].m_abyTvWallMember[bySubChnIdx] = (u8)atoi(json_string_value( pjHduIndex ) );
							}
							
							json_t_ptr pjVmpType = json_object_get_s( pjHduMemObj, JSON_VMPTYPE );
							if ( NULL == pjVmpType )
							{
								LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get VmpType is NUll!\n" );
							}
							else
							{
								atHduChnInfo[byValidIdx].m_abyMemberType[bySubChnIdx] = (u8)atoi(json_string_value( pjVmpType ) );
							}
							
							json_t_ptr pjHduMtChnid = json_object_get_s( pjHduMemObj, JSON_MTCHNID );
							if ( NULL == pjHduMtChnid )
							{
								LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get HduMtChnid is NUll!\n" );
							}
							else
							{
								atHduChnInfo[byValidIdx].m_abyHduMemChnIdx[bySubChnIdx] = (u8)atoi(json_string_value( pjHduMtChnid ) );
							}
						}	
					}
					else if ( HDUCHN_MODE_ONE == atHduChnInfo[byHduParamLoop].m_byVmpStyle )
					{
						json_t_ptr pjHduMemObj = json_array_get_s( pjHduMemArray, 0 );
						if ( NULL == pjHduMemObj )
						{
							OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Param Idx.%d MemIdx.%d pjHduMemObj is NUll!\n", byHduParamLoop );
							continue;
						}
						
						u8 bySubChnIdx = 0;					
						json_t_ptr pjHduIndex = json_object_get_s( pjHduMemObj, JSON_HDU_INDEX );
						if ( NULL == pjHduIndex )
						{
							LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get VmpType is NUll!\n" );
						}
						else
						{
							atHduChnInfo[byValidIdx].m_abyTvWallMember[bySubChnIdx] = (u8)atoi(json_string_value( pjHduIndex ) );
						}
						
						json_t_ptr pjVmpType = json_object_get_s( pjHduMemObj, JSON_VMPTYPE );
						if ( NULL == pjVmpType )
						{
							LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get VmpType is NUll!\n" );
						}
						else
						{
							atHduChnInfo[byValidIdx].m_abyMemberType[bySubChnIdx] = (u8)atoi(json_string_value( pjVmpType ) );
						}
						
						json_t_ptr pjHduMtChnid = json_object_get_s( pjHduMemObj, JSON_MTCHNID );
						if ( NULL == pjHduMtChnid )
						{
							LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get HduMtChnid is NUll!\n" );
						}
						else
						{
							atHduChnInfo[byValidIdx].m_abyHduMemChnIdx[bySubChnIdx] = (u8)atoi(json_string_value( pjHduMtChnid ) )-1;
						}
					}
				}
			}
		}

		tHduModule.SetHduVmpChnnlInfo( atHduChnInfo, byHduParamNum );
	}

	return TRUE;
}

/*=============================================================================
�� �� ���� GetMixModuleFromJson
��    �ܣ� Jsonת��ΪTPollModule
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/05/07  5.0         �ܹ��                    ����
=============================================================================*/
static BOOL32 GetMixModuleFromJson(const s8 * pchJsonBuf, THduVmpModuleOrTHDTvWall &tHduModule )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] pchJsonBuf is NULL, return FALSE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_loads err!\n" );
		return FALSE;
	}
	
	THduVmpChannlInfo atHduChnInfo[(HDUID_MAX-HDUID_MIN+1)*MAXNUM_HDU_CHANNEL];
	TPollParam tPollParam;
	TMtPollParam tMtPollParam;
	tPollParam.Clear();

	BOOL32 bIsHasHduModule = 0;
	json_t_ptr pjHduModule = json_object_get_s( pjRoot, JSON_HDUMODULE );
	if ( NULL == pjHduModule )
	{
		OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get HduModule is NUll!\n" );
	}
	else
	{
		bIsHasHduModule = (u8)atoi( json_string_value( pjHduModule ) ) == 0 ? FALSE : TRUE;
	}
	
	if ( !bIsHasHduModule )
	{
		OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson]Do't has hdu module.\n" );
		tHduModule.Clear();
	}
	else
	{
		json_t_ptr pjHduParamArray = json_object_get_s( pjRoot, JSON_HDUPARAM );
		u8 byHduParamNum = json_array_size( pjHduParamArray );
		if ( NULL == pjHduParamArray )
		{
			OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get HduParamArray is NUll!\n" );
		}
		else
		{	
			u8 byHduParamLoop = 0;
			u8 byValidIdx = 0;
			for ( byHduParamLoop = 0; byHduParamLoop < byHduParamNum; byHduParamLoop++ )
			{
				json_t_ptr pjHduParamObj = json_array_get_s( pjHduParamArray, byHduParamLoop );
				if ( NULL == pjHduParamObj )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d HduParamObj is NUll!\n", byHduParamLoop );
					continue;
				}
			
				json_t_ptr pjHduId = json_object_get_s( pjHduParamObj, JSON_HDUID );
				if ( NULL == pjHduId )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduId is NUll!\n", byHduParamLoop );
					continue;
				}
				u8 byHduId = (u8)atoi(json_string_value( pjHduId ) ) ;
				
				if ( byHduId == 0 )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduId is 0!\n", byHduParamLoop );
					continue;
				}
				
				atHduChnInfo[byValidIdx].m_byHduEqpId = byHduId;
				

				json_t_ptr pjHduChnIdx = json_object_get_s( pjHduParamObj, JSON_HDUCHLIDX );
				if ( NULL == pjHduChnIdx )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduChnIdx is NUll!\n", byHduParamLoop );
				}
				else
				{
					atHduChnInfo[byValidIdx].m_byChIdx = (u8)atoi(json_string_value( pjHduChnIdx ) );
				}

				json_t_ptr pjHduStyle = json_object_get_s( pjHduParamObj, JSON_HDUSTYLE );
				if ( NULL == pjHduStyle )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduStyle is NUll!\n", byHduParamLoop );
				}
				else
				{
					atHduChnInfo[byValidIdx].m_byVmpStyle = (u8)atoi(json_string_value( pjHduStyle ) );
				}

				json_t_ptr pjHduMemArray = json_object_get_s( pjHduParamObj, JSON_HDUMEMBER );
				if ( NULL == pjHduMemArray )
				{
					OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Idx.%d pjHduMemArray is NUll!\n", byHduParamLoop );
				}
				else
				{
					u8 byHduMemNum = json_array_size( pjHduMemArray );
					u8 byHduMemIdx = 0;
					if ( HDUCHN_MODE_FOUR == atHduChnInfo[byHduParamLoop].m_byVmpStyle )
					{
						for ( byHduMemIdx = 0; byHduMemIdx < byHduMemNum; byHduMemIdx++ )
						{
							json_t_ptr pjHduMemObj = json_array_get_s( pjHduMemArray, byHduMemIdx );
							if ( NULL == pjHduMemObj )
							{
								OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Param Idx.%d MemIdx.%d pjHduMemObj is NUll!\n", byHduParamLoop, byHduMemIdx );
								continue;
							}

							u8 bySubChnIdx = 0;
							json_t_ptr pjSubchnidx = json_object_get_s( pjHduMemObj, JSON_HDUSUBCHLIDX );
							if ( NULL == pjSubchnidx )
							{
								LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get Subchnidx is NUll!\n" );
							}
							else
							{
								bySubChnIdx = (u8)atoi( json_string_value( pjSubchnidx ) );
							}

							json_t_ptr pjHduIndex = json_object_get_s( pjHduMemObj, JSON_HDU_INDEX );
							if ( NULL == pjHduIndex )
							{
								LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get VmpType is NUll!\n" );
							}
							else
							{
								atHduChnInfo[byValidIdx].m_abyTvWallMember[bySubChnIdx] = (u8)atoi(json_string_value( pjHduIndex ) );
							}
							
							json_t_ptr pjVmpType = json_object_get_s( pjHduMemObj, JSON_VMPTYPE );
							if ( NULL == pjVmpType )
							{
								LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get VmpType is NUll!\n" );
							}
							else
							{
								atHduChnInfo[byValidIdx].m_abyMemberType[bySubChnIdx] = (u8)atoi(json_string_value( pjVmpType ) );
							}
							
							json_t_ptr pjHduMtChnid = json_object_get_s( pjHduMemObj, JSON_MTCHNID );
							if ( NULL == pjHduMtChnid )
							{
								LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get HduMtChnid is NUll!\n" );
							}
							else
							{
								atHduChnInfo[byValidIdx].m_abyHduMemChnIdx[bySubChnIdx] = (u8)atoi(json_string_value( pjHduMtChnid ) );
							}
						}	
					}
					else if ( HDUCHN_MODE_ONE == atHduChnInfo[byHduParamLoop].m_byVmpStyle )
					{
						json_t_ptr pjHduMemObj = json_array_get_s( pjHduMemArray, 0 );
						if ( NULL == pjHduMemObj )
						{
							OspPrintf( TRUE, FALSE, "[GetHduModuleFromJson] json_object_get Param Idx.%d MemIdx.%d pjHduMemObj is NUll!\n", byHduParamLoop );
							continue;
						}
						
						u8 bySubChnIdx = 0;					
						json_t_ptr pjHduIndex = json_object_get_s( pjHduMemObj, JSON_HDU_INDEX );
						if ( NULL == pjHduIndex )
						{
							LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get VmpType is NUll!\n" );
						}
						else
						{
							atHduChnInfo[byValidIdx].m_abyTvWallMember[bySubChnIdx] = (u8)atoi(json_string_value( pjHduIndex ) );
						}
						
						json_t_ptr pjVmpType = json_object_get_s( pjHduMemObj, JSON_VMPTYPE );
						if ( NULL == pjVmpType )
						{
							LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get VmpType is NUll!\n" );
						}
						else
						{
							atHduChnInfo[byValidIdx].m_abyMemberType[bySubChnIdx] = (u8)atoi(json_string_value( pjVmpType ) );
						}
						
						json_t_ptr pjHduMtChnid = json_object_get_s( pjHduMemObj, JSON_MTCHNID );
						if ( NULL == pjHduMtChnid )
						{
							LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN,  "[GetHduSwitchInfoFromJson] json_object_get HduMtChnid is NUll!\n" );
						}
						else
						{
							atHduChnInfo[byValidIdx].m_abyHduMemChnIdx[bySubChnIdx] = (u8)atoi(json_string_value( pjHduMtChnid ) )-1;
						}
					}
				}
			}
		}

		tHduModule.SetHduVmpChnnlInfo( atHduChnInfo, byHduParamNum );
	}

	return TRUE;
}

/*=============================================================================
�� �� ���� GetAutoRecInfoFromJson
��    �ܣ� Jsonת�� :�����Զ�¼����������ݣ�¼�������д�� tConfInfoEx �ṹ�壬
			 ��������д�� tConfInfo�ṹ��
		  
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/03/19  5.0         ������                  ����
=============================================================================*/
static BOOL32 GetAutoRecInfoFromJson(s8 *pchJsonBuf, TConfInfo &tConfInfo, TConfInfoEx &tconfInfoEx)
{
	if ( NULL == pchJsonBuf )
	{
		LogPrint( LOG_LVL_KEYSTATUS, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson] pchJsonBuf is NULL, return FALSE!\n");
		return FALSE;
	}
	TConfAutoRecAttrb tRecAttr;
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		LogPrint( LOG_LVL_KEYSTATUS, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson] json_loads err!\n");
		return FALSE;
	}
	//��ȡ�Ƿ���Զ�¼��
	json_t_ptr pjAutoRecAttrb = json_object_get_s( pjRoot, JSON_AUTORECATTRB );
	if( pjAutoRecAttrb == NULL )
	{
		LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson]pjAutoRecAttrb is NULL, return!\n" );
		return FALSE;
	}
	//autorec : 1¼  0 ��
	BOOL32 bIsAutoRec = FALSE;
	json_t_ptr pjAutoRec = json_object_get_s( pjAutoRecAttrb, JSON_AUTOREC );
	if (pjAutoRec == NULL)
	{
		LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson]AutoRec is NULL, return!\n" );
		return FALSE;
	}

	bIsAutoRec = (u8)strtoul(json_string_value(pjAutoRec), 0, 10);
	tRecAttr.SetAutoRec(bIsAutoRec);
	if (bIsAutoRec)
	{
		//����ģʽ���Ƿ�¼˫��������
		TRecStartPara tRecStartPara;
		json_t_ptr pjPublishMode =  json_object_get_s(pjAutoRecAttrb, JSON_PUBLISH_MODE);
		json_t_ptr pjIsRecDStream = json_object_get_s(pjAutoRecAttrb, JSON_IS_REC_DSTREAM);
		json_t_ptr pjIsRecMStream = json_object_get_s(pjAutoRecAttrb, JSON_IS_REC_MAIN_VID);
		if (pjPublishMode == NULL || pjIsRecDStream == NULL || pjIsRecDStream == NULL)
		{
			LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson] mode or isRecD/MStream is Null!\n" );
			return FALSE;
		}
		u8 byPublishMode = strtoul( json_string_value(pjPublishMode), 0, 10 );
		u8 byIsRecDStream = strtoul(json_string_value(pjIsRecDStream), 0, 10);
		u8 byIsRecMStream = strtoul(json_string_value(pjIsRecMStream), 0, 10);
		
		tRecStartPara.SetIsRecDStream(byIsRecDStream);
		tRecStartPara.SetIsRecMainVideo(byIsRecMStream);
		tRecStartPara.SetPublishMode(byPublishMode);

		tRecAttr.SetRecParam(tRecStartPara);
		//���¼�����ݵ� tConfInfo
		tConfInfo.SetAutoRecAttrb(tRecAttr);
	
		//vrs�ն˱���  ��  TConfInfoEx ��
		//��ȡ�Զ�¼��vrs �ı���
		TMtAlias tVrsAlias;
		json_t_ptr pjVrsAlias = json_object_get_s( pjAutoRecAttrb, JSON_VRS_ALIAS );
		if (pjVrsAlias == NULL)
		{
			LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson]pjVrsAlias is NULL, return!\n" );
			return FALSE;
		}
		json_t_ptr pjAliasType = json_object_get_s( pjVrsAlias, JSON_ALIAS_TYPE );
		if (pjAliasType == NULL)
		{
			LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson]pjAliasType is NULL, return!\n" );
			return FALSE;
		}
		u8 byAliasType = (u8)strtoul( json_string_value(pjAliasType), 0, 10 );
		tVrsAlias.m_AliasType = byAliasType;
		if ( byAliasType == mtAliasTypeTransportAddress )//�����ַ
		{
			json_t_ptr pjAddr = json_object_get_s( pjVrsAlias, JSON_ADDR );
			if( pjAddr == NULL )
			{
				LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson]addr is NULL, return!\n" );
				return FALSE;
			}
			TTransportAddr &tAddr = tVrsAlias.m_tTransportAddr;
			tAddr.SetIpAddr( ntohl( inet_addr( json_string_value( pjAddr ) ) ) );
			tAddr.SetPort( 0 );				
		}
		else if ( byAliasType == mtAliasTypeE164 )//E164��
		{
			json_t_ptr pjVrsNo = json_object_get_s( pjVrsAlias, JSON_VRSNO );
			if( pjVrsNo == NULL )
			{
				LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson]vrsno is NULL, return!\n" );
				return FALSE;
			}
			strncpy( tVrsAlias.m_achAlias, json_string_value(pjVrsNo), MAXLEN_ALIAS );
		}
		else
		{
			LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson]invalid pjVrsAlias %d , return!\n", byAliasType );
			return FALSE;
		}
		//������ӵ� tconfInfoEx�ṹ��
		tconfInfoEx.SetAutoRecAlias(tVrsAlias);
		return TRUE;
	}

	LogPrint( LOG_LVL_KEYSTATUS, MID_MCU_MAUSSN, "[GetAutoRecInfoFromJson]autorec is closed %d !\n");
	return FALSE;

}
/*=============================================================================
�� �� ���� GetConfIdxFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetConfIdxFromJson(const s8* pchJsonBuf, u8 &byConfIdx )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetConfIdxFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfIdxFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjConfIdx = json_object_get_s( pjRoot, JSON_CONFIDX );
	if ( NULL == pjConfIdx )
	{
		OspPrintf( TRUE, FALSE, "[GetConfIdxFromJson] json_object_get ConfIdx is NULL, retur FALSE!\n" );
		return FALSE;
	}
	
	byConfIdx = (u32)strtoul( json_string_value( pjConfIdx ), 0, 10 );
	
	return TRUE;
}

/*=============================================================================
�� �� ���� GetErrCodeFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetErrCodeFromJson(const s8* pchJsonBuf, u16 &wErrCode )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetErrCodeFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetErrCodeFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjErrCode = json_object_get_s( pjRoot, JSON_ERRCODE );
	if ( NULL == pjErrCode )
	{
		OspPrintf( TRUE, FALSE, "[GetErrCodeFromJson] json_object_get ErrCode is NULL, retur FALSE!\n" );
		return FALSE;
	}
	
	wErrCode = (u32)strtoul( json_string_value( pjErrCode ), 0, 10 );
	
	return TRUE;
}

/*=============================================================================
�� �� ���� GetMsgTypeFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetMsgTypeFromJson( const s8 * pchJsonBuf, s8 * pchMsgType, u32 dwMsgTypeLen )
{
	if ( NULL == pchJsonBuf || NULL == pchMsgType || 0 == dwMsgTypeLen )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgTypeFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgTypeFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjMsgType = json_object_get_s( pjRoot, JSON_MSGTYPE );
	if ( NULL == pjMsgType )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgTypeFromJson] json_object_get MsgType is NULL, retur FALSE!\n" );
		return FALSE;
	}
	
	strncpy(pchMsgType, json_string_value(pjMsgType), dwMsgTypeLen);
	
	return TRUE;
}

static BOOL32 GetMsgEventFromJson( s8 * pchJsonBuf, s8 * pchEventType, u32 dwEventTypeLen )
{
	if ( NULL == pchJsonBuf || NULL == pchEventType || 0 == dwEventTypeLen )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgEventTypeFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgTypeFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjMsgType = json_object_get_s( pjRoot, "event" );
	if ( NULL == pjMsgType )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgTypeFromJson] json_object_get MsgType is NULL, retur FALSE!\n" );
		return FALSE;
	}
	
	strncpy(pchEventType, json_string_value(pjMsgType), dwEventTypeLen);
	
	return TRUE;
}

static BOOL32 GetMsgDataFromJson(const s8 * pchJsonBuf, s8 * pchData )
{
	if ( NULL == pchJsonBuf || NULL == pchData )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgEventTypeFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgTypeFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjMsgData = json_object_get_s( pjRoot, "data" );
	if ( NULL == pjMsgData )
	{
		OspPrintf( TRUE, FALSE, "[GetMsgTypeFromJson] json_object_get MsgType is NULL, retur FALSE!\n" );
		return FALSE;
	}
	s8 *pData = json_dumps( pjMsgData, 0 );
	//u32 dwLen = MAXLEN_MSGTYPE >= dwMsgTypeLen ? dwMsgTypeLen : MAXLEN_MSGTYPE;
// 	u32 dwLen = MAXLEN_JSONBUF;
 	memcpy( pchData, pData, strlen(pData) + 1 );

	json_free(pData);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetConfIdFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetConfIdFromJson(const s8* pchJsonBuf, CConfId &cConfId )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetConfIdFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfIdFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjConfId = json_object_get_s( pjRoot, JSON_CONFID );
	if ( NULL == pjConfId )
	{
		OspPrintf( TRUE, FALSE, "[GetConfIdFromJson] json_object_get ConfId is NULL, retur FALSE!\n" );
		return FALSE;
	}
	
	cConfId.SetConfId( json_string_value( pjConfId ) );
	
	return TRUE;
}

/*=============================================================================
�� �� ���� GetAddMtTypeFromJson
��    �ܣ� ��Json�л�ȡ�ն���᷽ʽ
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/06/11     5.0        �Ա�                  ����
=============================================================================*/
static BOOL32 GetAddMtTypeFromJson(const s8 * pchJsonBuf, u8 &byAddMtType)
{
	if (NULL == pchJsonBuf)
	{
		OspPrintf( TRUE, FALSE, "[GetAddMtTypeFromJson] Param is null return!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfNameFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjAddMtType = json_object_get_s( pjRoot, JSON_ADDMT_TYPE );
	
	if ( NULL == pjAddMtType )
	{
		OspPrintf( TRUE, FALSE, "[GetAddMtTypeFromJson] json_object_get AddMtType is NULL, return FALSE!\n" );
		return FALSE;
	}
	
	byAddMtType = (u8)atoi( json_string_value( pjAddMtType ) );	
	
	return TRUE;
}
/*=============================================================================
�� �� ���� GetReqHeadFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static void GetReqHeadFromJson( const s8 * pchJsonBuf, TReqHeadInfo &tReqHeadInfo )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] Param is NULL, return FLASE!\n" );
		return;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_loads err, retur FALSE!\n" );
		return;
	}

	json_t_ptr pjReqHeadInfo = json_object_get_s( pjRoot, JSON_REQHEADINFO );
	if ( NULL == pjReqHeadInfo )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get ReqHeadInfo is NUll, return FALSE!\n" );
		return;
	}
	
	json_t_ptr pjConfE164 = json_object_get_s( pjReqHeadInfo, JSON_CONFE164 );
	if ( NULL == pjConfE164 )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get ConfE164 is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetConfE164( json_string_value( pjConfE164 ) );
	}

	json_t_ptr pjMtType = json_object_get_s( pjReqHeadInfo, JSON_MTTYPE );
	if ( NULL == pjMtType )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjMtType is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetMtType( (u8)atoi( json_string_value( pjMtType ) ) );
	}

	json_t_ptr pjMtNO = json_object_get_s( pjReqHeadInfo, JSON_MTNO );
	if ( NULL == pjMtNO )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get MtNO is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetSrcMtE164( json_string_value( pjMtNO ) );
	}

	json_t_ptr pjMtAlias = json_object_get_s( pjReqHeadInfo, JSON_MTALIAS );
	if ( NULL == pjMtAlias )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjMtAlias is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetMtAlias( json_string_value( pjMtAlias ) );
	}

	json_t_ptr pjEventId = json_object_get_s( pjReqHeadInfo, JSON_REQHEAD_EVENTID );
	if ( NULL == pjEventId )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjEventId is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetReqEventID( (u32)strtoul( json_string_value( pjEventId ), 0, 10 ) );
	}

	json_t_ptr pjErrId = json_object_get_s( pjReqHeadInfo, JSON_ERRCODE );
	if ( NULL == pjErrId )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjErrId is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetErrID( (u32)strtoul( json_string_value( pjErrId ), 0, 10 ) );
	}

	json_t_ptr pjSrcId = json_object_get_s( pjReqHeadInfo, JSON_REQHEAD_SRCID );
	if ( NULL == pjSrcId )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjSrcId is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetReqSrcID( (u32)strtoul( json_string_value( pjSrcId ), 0, 10 ) );
	}

	json_t_ptr pjMtReqId = json_object_get_s( pjReqHeadInfo, JSON_REQHEAD_MTREQID );
	if ( NULL == pjMtReqId )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjMtReqId is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetMtReqID( (u32)strtoul( json_string_value( pjMtReqId ), 0, 10 ) );
	}

	json_t_ptr pjUniqueId = json_object_get_s( pjReqHeadInfo, JSON_REQHEAD_UNIQUEID );
	if ( NULL == pjUniqueId )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjUniqueId is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetUniqueID( (u32)strtoul( json_string_value( pjUniqueId ), 0, 10 ) );
	}

	json_t_ptr pjConfCreateBy = json_object_get_s( pjReqHeadInfo, JSON_CONFCREATEBY );
	if ( NULL == pjConfCreateBy )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get ConfCreateBy is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetConfCreateBy( (u8)atoi( json_string_value( pjConfCreateBy ) ) );
	}

	json_t_ptr pjMtCallBitrate = json_object_get_s( pjReqHeadInfo, JSON_BITRATE );
	if ( NULL == pjMtCallBitrate )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjMtCallBitrate is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetMtCallBitrate( (u32)strtoul( json_string_value( pjMtCallBitrate ), 0, 10 ) );
	}

	json_t_ptr pjConfName = json_object_get_s( pjReqHeadInfo, JSON_CONFNAME );
	if ( NULL == pjConfName )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjConfName is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetConfName( json_string_value( pjConfName ) );
	}

	json_t_ptr pjMOID = json_object_get_s( pjReqHeadInfo, JSON_MOID );
	if ( NULL == pjMOID )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjMOID is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetDomainMOID( json_string_value( pjMOID ) );
	}

	json_t_ptr pjRpc = json_object_get_s( pjReqHeadInfo, JSON_REQHEAD_RPC );
	if ( NULL == pjRpc )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjRpc is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetMQName( json_string_value( pjRpc ) );
	}

	json_t_ptr pjRpcId = json_object_get_s( pjReqHeadInfo, JSON_REQHEAD_RPCID );
	if ( NULL == pjRpcId )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjRpcId is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetMQCorrelationId( json_string_value( pjRpcId ) );
	}
	
	json_t_ptr pjProductId = json_object_get_s( pjReqHeadInfo, JSON_REQHEAD_PRODUCTID );
	if ( NULL == pjProductId )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjProductId is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetProductId( json_string_value( pjProductId ) );
	}

	json_t_ptr pjVersionId = json_object_get_s( pjReqHeadInfo, JSON_REQHEAD_VERID );
	if ( NULL == pjVersionId )
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjVersionId is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetVersionId( json_string_value( pjVersionId ) );
	}

	json_t_ptr pjProtocolType = json_object_get_s(pjReqHeadInfo, JSON_PROTOCOL);
	if (NULL == pjProtocolType)
	{
		OspPrintf( TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjProctocolType is NULL, retur FALSE!\n" );
	}
	else
	{
		tReqHeadInfo.SetProctocolType(json_string_value(pjProtocolType));
	}

	json_t_ptr pjTimeId = json_object_get_s(pjReqHeadInfo, JSON_TIMEID);
	if (NULL == pjTimeId)
	{
		OspPrintf(TRUE, FALSE, "[GetReqHeadFromJson] json_object_get pjTimeId is NULL, retur FALSE!\n");
	}
	else
	{
		tReqHeadInfo.SetTimeId(json_string_value(pjTimeId));
	}

	return;
}

static BOOL32 SetMtAliasListToJson(json_t_ptr pjRoot, const TMtAlias * ptMtAlias, const u16* awBitRate, u16 wMtNum)
{
	json_t_ptr pjMtInfoArray = json_array();
	if (NULL == pjMtInfoArray)
	{
		OspPrintf(TRUE, FALSE, "[SetMtAliasListToJson] json_array pjMtInfoArray is NULL, return!\n");
		return FALSE;
	}

	u16 wMtIdx = 0;
	for (wMtIdx = 0; wMtIdx < wMtNum; wMtIdx++)
	{
		json_t_ptr pjMtInfo = json_object();
		if (NULL == pjMtInfo)
		{
			continue;
		}

		u8 byMtType = 0;
		if (mtAliasTypePartNumber == ptMtAlias[wMtIdx].m_AliasType)
		{
			byMtType = 3;
		}
		else
		{
			byMtType = 1;
		}

		if (!SetUIntAsStringToJson(pjMtInfo, JSON_MTTYPE, byMtType))
		{
			continue;
		}
		
		if (!SetUIntAsStringToJson(pjMtInfo, JSON_BITRATE, awBitRate[wMtIdx]))
		{
			continue;
		}

		json_t_ptr pjMtNO = NULL;
		u8 byProtocol = 0;
		BOOL32 bHasProtocol = FALSE;
		if (mtAliasTypeTransportAddress == ptMtAlias[wMtIdx].m_AliasType ||
			mtAliasTypeIpSIP == ptMtAlias[wMtIdx].m_AliasType)
		{
			byProtocol = (mtAliasTypeTransportAddress == ptMtAlias[wMtIdx].m_AliasType) ? 0 : 1;
			bHasProtocol = TRUE;
			in_addr addr;
			addr.s_addr = ptMtAlias[wMtIdx].m_tTransportAddr.GetNetSeqIpAddr();
			const s8* pchIp = inet_ntoa(addr);
			if (!SetStringToJson(pjMtInfo, JSON_MTNO, pchIp))
			{
				continue;
			}
		}
		else
		{
			if (!SetStringToJson(pjMtInfo, JSON_MTNO, ptMtAlias[wMtIdx].m_achAlias))
			{
				continue;
			}
		}

		if (bHasProtocol)
		{
			if (!SetUIntAsStringToJson(pjMtInfo, JSON_PROTOCOL, byProtocol))
			{
				continue;
			}
		}

		json_array_append_s(pjMtInfoArray, pjMtInfo);
	}
	json_object_set_s(pjRoot, JSON_MT, pjMtInfoArray);

	return TRUE;
}

/*=============================================================================
�� �� ���� SetMtAliasListToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 SetMtAliasListToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, const TMtAlias *ptMtAlias, const u16* awBitRate, u16 wMtNum )
{
	if ( NULL == pchJsonBuf || NULL == ptMtAlias || 0 == wMtNum )
	{
		OspPrintf( TRUE, FALSE, "[SetMtAliasListToJson] Param is NULL, retur!\n" );
		return FALSE;
	}

	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetMtAliasListToJson(pjRoot, ptMtAlias, awBitRate, wMtNum));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetConfInfoExToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static void SetConfInfoExToJson(s8 * pchJsonBuf, u32 &dwJsonBufLen, TConfInfoEx tConfInfoEx )
{
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;
	
	TVideoStreamCap atMainStreamCap[MAX_CONF_CAP_EX_NUM];
	TVideoStreamCap atDoubleStreamCap[MAX_CONF_CAP_EX_NUM];
	TAudioTypeDesc  atAudioDesc[MAXNUM_CONF_AUDIOTYPE];
	
	// ����
	json_t_ptr pjVideoFormatArray = json_array();
	if ( NULL == pjVideoFormatArray )
	{

		OspPrintf( TRUE, FALSE, "[SetConfInfoExToJson]json_array pjVideoFormatArray is NULL, retur!\n" );
		return;
	}

	u8 byCapIdx = 0;
	u8 byCapNum = MAX_CONF_CAP_EX_NUM;
	if ( tConfInfoEx.GetMainStreamCapEx( atMainStreamCap, byCapNum ) )
	{
		byCapNum = byCapNum > 4 ? 4 : byCapNum;

		for ( byCapIdx = 0; byCapIdx < byCapNum; byCapIdx++ )
		{
			json_t_ptr pjVideoMediaInfo = json_object();
			if ( NULL == pjVideoMediaInfo )
			{
				OspPrintf( TRUE, FALSE, "[SetConfInfoExToJson]json_object pjVideoMediaInfo is NULL, continue!\n" );
				continue;
			}

			SetUIntAsStringToJson(pjVideoMediaInfo, JSON_MEDIATYPE, atMainStreamCap[byCapIdx].GetMediaType());
			SetUIntAsStringToJson(pjVideoMediaInfo, JSON_MEDIABITRATE, atMainStreamCap[byCapIdx].GetMaxBitRate());
			SetUIntAsStringToJson(pjVideoMediaInfo, JSON_MEDIARES, atMainStreamCap[byCapIdx].GetResolution());
			SetUIntAsStringToJson(pjVideoMediaInfo, JSON_MEDIAFRAME, atMainStreamCap[byCapIdx].GetFrameRate());
			SetUIntAsStringToJson(pjVideoMediaInfo, JSON_MEDIAH264, atMainStreamCap[byCapIdx].GetH264ProfileAttrb());

			json_array_append_s( pjVideoFormatArray, pjVideoMediaInfo );
		}

		json_object_set_s( pjRoot, JSON_VIDEOFORMAT, pjVideoFormatArray );
	}

	// ˫��
	json_t_ptr pjSecVideoFormatArray = json_array();
	if ( NULL == pjSecVideoFormatArray )
	{
		OspPrintf( TRUE, FALSE, "[SetConfInfoExToJson]json_array pjSecVideoFormatArray is NULL, retur!\n" );
		return;
	}

	byCapNum = MAX_CONF_CAP_EX_NUM;
	if ( tConfInfoEx.GetDoubleStreamCapEx( atDoubleStreamCap, byCapNum ) )
	{
		byCapNum = byCapNum > 4 ? 4 : byCapNum;
		for ( byCapIdx = 0; byCapIdx < byCapNum; byCapIdx++ )
		{
			json_t_ptr pjSecVideoMediaInfo = json_object();
			if ( NULL == pjSecVideoMediaInfo )
			{
				OspPrintf( TRUE, FALSE, "[SetConfInfoExToJson]json_object SecVideoMediaInfo is NULL, continue!\n" );
				continue;
			}
			
			SetUIntAsStringToJson(pjSecVideoMediaInfo, JSON_MEDIATYPE, atDoubleStreamCap[byCapIdx].GetMediaType());
			SetUIntAsStringToJson(pjSecVideoMediaInfo, JSON_MEDIARES, atDoubleStreamCap[byCapIdx].GetResolution());
			SetUIntAsStringToJson(pjSecVideoMediaInfo, JSON_MEDIAFRAME, atDoubleStreamCap[byCapIdx].GetFrameRate());
			SetUIntAsStringToJson(pjSecVideoMediaInfo, JSON_MEDIAH264, atDoubleStreamCap[byCapIdx].GetH264ProfileAttrb());

			json_array_append_s( pjSecVideoFormatArray, pjSecVideoMediaInfo );
		}
		
		json_object_set_s( pjRoot, JSON_SECVIDEOFORMAT, pjSecVideoFormatArray );
	}

	// ��Ƶ
	json_t_ptr pjAudioFormatArray = json_array();
	if ( NULL == pjAudioFormatArray )
	{
		OspPrintf( TRUE, FALSE, "[SetConfInfoExToJson]json_array pjAudioFormatArray is NULL, retur!\n" );
		return;
	}

	byCapNum = tConfInfoEx.GetAudioTypeDesc( atAudioDesc );
	for ( byCapIdx = 0; byCapIdx < byCapNum; byCapIdx++ )
	{
		for ( byCapIdx = 0; byCapIdx < byCapNum; byCapIdx++ )
		{
			json_t_ptr pjAudioMediaInfo = json_object();
			if ( NULL == pjAudioMediaInfo )
			{
				OspPrintf( TRUE, FALSE, "[SetConfInfoExToJson]json_object AudioMediaInfo is NULL, continue!\n" );
				continue;
			}
			
			SetUIntAsStringToJson(pjAudioMediaInfo, JSON_AUDIOTYPE, atAudioDesc[byCapIdx].GetAudioMediaType());
			
			json_array_append_s( pjAudioFormatArray, pjAudioMediaInfo );
		}
		
		json_object_set_s( pjRoot, JSON_AUDIOFORMAT, pjAudioFormatArray );
	}
	
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetMsgTypeToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
#define SetMsgTypeToJsonObj(pjRoot, pchMsgType) SetStringToJson(pjRoot, JSON_MSGTYPE, pchMsgType)

static BOOL32 SetMsgTypeToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, const s8 * pchMsgType )
{
	if ( NULL == pchJsonBuf || NULL ==pchMsgType )
	{
		OspPrintf( TRUE, FALSE, "[SetMsgTypeToJson] Param is NULL, return!\n" );
		return FALSE;
	}	
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetMsgTypeToJsonObj(pjRoot, pchMsgType));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetConfIdxToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 SetConfIdxToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u8 byConfIdx )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetUIntAsStringToJson(pjRoot, JSON_CONFIDX, byConfIdx));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetConfDurationToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/07/08  5.0         Ϳ�ı�                    ����
=============================================================================*/
#define SetConfDurationToJsonObj(pjRoot, wConfDuration) SetUIntAsStringToJson(pjRoot, JSON_DURATION, wConfDuration)

static BOOL32 SetConfDurationToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u16 wConfDuration )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetConfDurationToJsonObj(pjRoot, wConfDuration));
	return 	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� GetConfDurationFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/07/08  5.0         Ϳ�ı�                    ����
=============================================================================*/
static BOOL32 GetConfDurationFromJson(json_t_ptr pjRoot, u16 &wConfDuration)
{
	json_t_ptr pjDuration = json_object_get_s(pjRoot, JSON_DURATION);
	if (NULL == pjDuration)
	{
		OspPrintf(TRUE, FALSE, "[GetConfDurationFromJson] json_object_get Duration is NULL, return FALSE!\n");
		return FALSE;
	}
	wConfDuration = atoi(json_string_value(pjDuration));
	return TRUE;
}

static BOOL32 GetConfDurationFromJson(const s8 * pchJsonBuf, u16 &wConfDuration )
{
	wConfDuration = 0;
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetConfDurationFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfDurationFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}

	return GetConfDurationFromJson(pjRoot, wConfDuration);
}

/*=============================================================================
�� �� ���� SetCmuIpToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
#define SetCmuIpToJsonObj(pjRoot, pchCmuIp) SetStringToJson(pjRoot, JSON_CMUIP, pchCmuIp)

static BOOL32 SetCmuIpToJson(s8 * pchJsonBuf, u32 &dwJsonBufLen, const s8 *pchCmuIp )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetCmuIpToJsonObj(pjRoot, pchCmuIp));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

#define SetCmuPidToJsonObj(pjRoot, wCmuPid) SetUIntAsStringToJson(pjRoot, JSON_CMUPID, wCmuPid)
static BOOL32 SetCmuPidToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u32 dwCmuPid)
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetCmuPidToJsonObj(pjRoot, dwCmuPid));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetCmuIdentifyToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2016/02/16  5.0         gsp                    ����
=============================================================================*/
static BOOL32 SetCmuIdentifyToJson(s8 * pchJsonBuf, u32 &dwJsonBufLen, s8* pchCmuIp, u32 dwCmuPid)
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetCmuIpToJsonObj(pjRoot, pchCmuIp));
	ReturnIfFailed(SetCmuPidToJsonObj(pjRoot, dwCmuPid));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}
/*=============================================================================
�� �� ���� GetCmuIdFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetCmuIdFromJson(const s8 * pchJsonBuf, u16 &wCmuId )
{
	wCmuId = 0;
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetConnectInfoFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConnectInfoFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjCmuId = json_object_get_s( pjRoot, JSON_CMUID );
	if ( NULL == pjCmuId )
	{

		OspPrintf( TRUE, FALSE, "[GetConnectInfoFromJson] json_object_get CmuId is NULL, retur FALSE!\n" );
		return FALSE;
	}

	wCmuId = atoi( json_string_value( pjCmuId ) );

	return TRUE;
}

static BOOL32 GetMcuUrlFromJson(json_t_ptr pjRoot, s8 * pchMcuUrl, u32 dwMcuUrlLen)
{
	if (NULL == pjRoot)
	{
		OspPrintf(TRUE, FALSE, "[GetMcuUrlFromJson] json_loads err, retur FALSE!\n");
		return FALSE;
	}
	json_t_ptr pjUrl = json_object_get_s(pjRoot, JSON_URL);
	if (NULL == pjUrl)
	{
		OspPrintf(TRUE, FALSE, "[GetMcuUrlFromJson] json_object_get pjCmuIp is NULL, retur FALSE!\n");
		return FALSE;
	}

	strncpy(pchMcuUrl, json_string_value(pjUrl), dwMcuUrlLen);
	return TRUE;
}

static BOOL32 GetMcuUrlFromJson(const s8 * pchJsonBuf, s8 *pchMcuUrl, u32 dwMcuUrlLen)
{
	if (NULL == pchJsonBuf || NULL == pchMcuUrl || 0 == dwMcuUrlLen)
	{
		OspPrintf(TRUE, FALSE, "[GetCmuIpFromJson] Param is NULL, return FLASE!\n");
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads(pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason);

	return GetMcuUrlFromJson(pjRoot, pchMcuUrl, dwMcuUrlLen);
}

#define GetCmuPidFromJsonObj(node, value) GetStringAsUIntFromJson(pjRoot, JSON_CMUPID, value)

static BOOL32 GetCmuPidFromJson(const s8 * pchJsonBuf, u32& dwCmuPid)
{
	if (NULL == pchJsonBuf)
	{
		OspPrintf(TRUE, FALSE, "[GetCmuPidFromJson] Param is NULL, return FLASE!\n");
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads(pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason);

	return GetCmuPidFromJsonObj(pjRoot, dwCmuPid);
}

static BOOL32 GetCmuIpFromJson(json_t_ptr pjRoot, s8 * pchCmuIp, u32 dwCmuIpLen)
{
	if (NULL == pjRoot)
	{
		OspPrintf(TRUE, FALSE, "[GetCmuIpFromJson] json_loads err, retur FALSE!\n");
		return FALSE;
	}
	json_t_ptr pjCmuIp = json_object_get_s(pjRoot, JSON_CMUIP);
	if (NULL == pjCmuIp)
	{
		OspPrintf(TRUE, FALSE, "[GetCmuIpFromJson] json_object_get pjCmuIp is NULL, retur FALSE!\n");
		return FALSE;
	}

	u32 dwLen = MAXLEN_ALIAS >= dwCmuIpLen ? dwCmuIpLen : MAXLEN_ALIAS;
	strncpy(pchCmuIp, json_string_value(pjCmuIp), dwLen);
	return TRUE;
}

/*=============================================================================
�� �� ���� GetCmuIpFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetCmuIpFromJson(const s8 * pchJsonBuf, s8 *pchCmuIp, u32 dwCmuIpLen )
{
	if ( NULL == pchJsonBuf || NULL == pchCmuIp || 0 == dwCmuIpLen )
	{
		OspPrintf( TRUE, FALSE, "[GetCmuIpFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );

	return GetCmuIpFromJson(pjRoot, pchCmuIp, dwCmuIpLen);
}

#define SetConfStartTimeToJsonObj(pjRoot, pchConStartTime)	SetStringToJson(pjRoot, JSON_CONFSTARTTIME, pchConStartTime)
/*=============================================================================
�� �� ���� SetConfE164ToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
#define SetConfE164ToJsonObj(pjRoot, pchE164)	SetStringToJson(pjRoot, JSON_CONFE164, pchE164)

static BOOL32 SetConfE164ToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, const s8 * pchE164 )
{
	if (NULL == pchJsonBuf || NULL == pchE164)
	{
		OspPrintf(TRUE, FALSE, "[SetConfE164ToJson] Param is NULL, retur!\n");
		return FALSE;
	}

	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetConfE164ToJsonObj(pjRoot, pchE164));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

#define SetConfMoidToJsonObj(pjRoot, pchMoid) SetStringToJson(pjRoot, JSON_MOID, pchMoid)

static BOOL32 SetConfMoidToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, const s8 * pchMoid )
{
	if (NULL == pchJsonBuf || NULL == pchMoid)
	{
		OspPrintf(TRUE, FALSE, "[SetConfMoidToJson] Param is NULL, return!\n");
		return FALSE;
	}
	
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetConfMoidToJsonObj(pjRoot, pchMoid));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=================================================================/*=============================================================================
�� �� ���� SetErrCodeToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
#define SetErrCodeToJsonObj(pjRoot, wErrCode) SetUIntAsStringToJson(pjRoot, JSON_ERRCODE, wErrCode)

static BOOL32 SetErrCodeToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u16 wErrCode )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetErrCodeToJsonObj(pjRoot, wErrCode));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetConfIdToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 SetConfIdToJsonObj(const json_t_ptr& pjObject, const CConfId& cConfId)
{
	s8 achConfId[MAXLEN_CONFID * 2 + 1] = { 0 };
	cConfId.GetConfIdString(achConfId, sizeof(achConfId));
	return SetStringToJson(pjObject, JSON_CONFID, achConfId);
}

static BOOL32 SetConfIdToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, const CConfId& cConfId )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetConfIdToJsonObj(pjRoot, cConfId));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

static BOOL32 SetReqHeadToJsonObj(const json_t_ptr& pjRoot, TReqHeadInfo &tReqHeadInfo)
{
	json_t_ptr pjReqInfo = json_object();
	if (NULL == pjReqInfo)
	{
		OspPrintf(TRUE, FALSE, "[SetReqHeadToJson] json_object pjReqInfo is NULL, return!\n");
		return FALSE;
	}

	SetUIntAsStringToJson(pjReqInfo, JSON_REQHEAD_UNIQUEID, tReqHeadInfo.GetUniqueID());
	SetUIntAsStringToJson(pjReqInfo, JSON_REQHEAD_EVENTID, tReqHeadInfo.GetReqEventID());
	SetUIntAsStringToJson(pjReqInfo, JSON_REQHEAD_SRCID, tReqHeadInfo.GetReqSrcID());
	SetUIntAsStringToJson(pjReqInfo, JSON_REQHEAD_MTREQID, tReqHeadInfo.GetMtReqID());
	SetStringToJson(pjReqInfo, JSON_CONFE164, tReqHeadInfo.GetConfE164());
	SetStringToJson(pjReqInfo, JSON_MTNO, tReqHeadInfo.GetSrcMtE164());
	SetStringToJson(pjReqInfo, JSON_MTALIAS, tReqHeadInfo.GetMtAlias());
	SetUIntAsStringToJson(pjReqInfo, JSON_MTTYPE, tReqHeadInfo.GetMtType());
	SetUIntAsStringToJson(pjReqInfo, JSON_CONFCREATEBY, tReqHeadInfo.GetConfCreateBy());
	SetUIntAsStringToJson(pjReqInfo, JSON_BITRATE, tReqHeadInfo.GetMtCallBitrate());
	SetUIntAsStringToJson(pjReqInfo, JSON_ERRCODE, tReqHeadInfo.GetErrID());
	SetStringToJson(pjReqInfo, JSON_CONFNAME, tReqHeadInfo.GetConfName());
	SetStringToJson(pjReqInfo, JSON_MOID, tReqHeadInfo.GetDomainMOID());
	SetStringToJson(pjReqInfo, JSON_REQHEAD_RPC, tReqHeadInfo.GetMQName());
	SetStringToJson(pjReqInfo, JSON_REQHEAD_RPCID, tReqHeadInfo.GetMQCorrelationId());
	SetStringToJson(pjReqInfo, JSON_REQHEAD_PRODUCTID, tReqHeadInfo.GetProductId());
	SetStringToJson(pjReqInfo, JSON_REQHEAD_VERID, tReqHeadInfo.GetVersionId());
	SetStringToJson(pjReqInfo, JSON_PROTOCOL, tReqHeadInfo.GetProctocolType());
	SetStringToJson(pjReqInfo, JSON_TIMEID, tReqHeadInfo.GetTimeId());

	json_object_set_s(pjRoot, JSON_REQHEADINFO, pjReqInfo);
	return TRUE;
}

/*=============================================================================
�� �� ���� SetReqHeadToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 SetReqHeadToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, TReqHeadInfo tReqHeadInfo )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetReqHeadToJsonObj(pjRoot, tReqHeadInfo));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetMeetingIDToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/09/24  5.0         rnn                   ����
=============================================================================*/
#define SetMeetingIDToJsonObj(pjRoot, nMeetingID) SetIntAsStringToJson(pjRoot, JSON_MEETINTID, nMeetingID)
static BOOL32 SetMeetingIDToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, s32 nMeetingID)
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetMeetingIDToJsonObj(pjRoot, nMeetingID));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetDelayToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/11/11  5.0         rnn                   ����
=============================================================================*/
static BOOL32 SetDelayToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u16 wDelay )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	//���ĵ�ʱ����
	ReturnIfFailed(SetUIntAsStringToJson(pjRoot, JSON_DELAY, wDelay));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetDomainListToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/11/11  5.0         rnn                   ����
=============================================================================*/
static void SetDomainListToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, CKdvDomainInfo * pcDomainInfo, u32 dwDomainInfoNum, BOOL32 bDel = FALSE )
{
	if ( NULL == pchJsonBuf || 0 == dwJsonBufLen || NULL == pcDomainInfo || 0 == dwDomainInfoNum )
	{
		return;
	}

	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;

	// �Ƿ�ɾ����ʾ
	SetUIntAsStringToJson(pjRoot, JSON_DELFLAG, bDel);

	// CKdvDomainInfoList
	json_t_ptr pjDomainInfoArray = json_array();
	if ( NULL == pjDomainInfoArray )
	{

		OspPrintf( TRUE, FALSE, "[SetDomainListToJson] json_array pjDomainInfoArray is NULL, return!\n" );
		return;
	}
	
	u32 dwDomainInfoIdx = 0;
	for ( dwDomainInfoIdx = 0; dwDomainInfoIdx < dwDomainInfoNum; dwDomainInfoIdx++ )
	{
		json_t_ptr pjDomainInfo = json_object();
		if ( NULL == pjDomainInfo )
		{
			continue;
		}
		
		// ��GUID
		if(!SetStringToJson(pjDomainInfo, JSON_GUID, pcDomainInfo[dwDomainInfoIdx].GetDomainGUID()))
		{
			continue;
		}
		// ��MOID
		if (!SetStringToJson(pjDomainInfo, JSON_MOID, pcDomainInfo[dwDomainInfoIdx].GetDomainMOID()))
		{
			continue;
		}
		// �ϼ����MOID
		if (!SetStringToJson(pjDomainInfo, JSON_SMOID, pcDomainInfo[dwDomainInfoIdx].GetSDomainMOID()))
		{
			continue;
		}		
		// ������
		if (!SetStringToJson(pjDomainInfo, JSON_DOMAINNAME, pcDomainInfo[dwDomainInfoIdx].GetWholeName()))
		{
			continue;
		}
		// ƽ̨��ǰ׺
		if (!SetStringToJson(pjDomainInfo, JSON_PLATFORMPREFIX, pcDomainInfo[dwDomainInfoIdx].GetPlatformPrefix()))
		{
			continue;
		}
		// �򼶱�
		if (!SetUIntAsStringToJson(pjDomainInfo, JSON_DOMAINLVL, pcDomainInfo[dwDomainInfoIdx].GetDomainLevel()))
		{
			continue;
		}
		// �������������ٿ���
		if (!SetUIntAsStringToJson(pjDomainInfo, JSON_MAXCONFNUM, pcDomainInfo[dwDomainInfoIdx].GetMaxConfNum()))
		{
			continue;
		}
		// �����������������
		if (!SetUIntAsStringToJson(pjDomainInfo, JSON_MAXCCONFNUM, pcDomainInfo[dwDomainInfoIdx].GetMaxCascadeConfNum()))
		{
			continue;
		}
		
		json_array_append_s( pjDomainInfoArray, pjDomainInfo );
	}
	
	
	json_object_set_s( pjRoot, JSON_DOMAIN, pjDomainInfoArray );
	
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetMtListToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/11/11  5.0         rnn                   ����
=============================================================================*/
static void SetMtListToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, CKdvMtInfo * pcMtInfo, u32 dwMtInfoNum, BOOL32 bDel = FALSE )
{
	if ( NULL == pchJsonBuf || 0 == dwJsonBufLen || NULL == pcMtInfo || 0 == dwMtInfoNum )
	{
		return;
	}

	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;

	// �Ƿ�ɾ����ʾ
	SetBoolAsStringToJson(pjRoot, JSON_DELFLAG, bDel);

	// CKdvMtInfoList
	json_t_ptr pjMtInfoArray = json_array();
	if ( NULL == pjMtInfoArray )
	{

		OspPrintf( TRUE, FALSE, "[SetMtListToJson] json_array pjMtInfoArray is NULL, return!\n" );
		return;
	}
	
	u32 dwMtInfoIdx = 0;
	for ( dwMtInfoIdx = 0; dwMtInfoIdx < dwMtInfoNum; dwMtInfoIdx++ )
	{
		json_t_ptr pjMtInfo = json_object();
		if ( NULL == pjMtInfo )
		{
			continue;
		}
		
		// ��GUID
		if (!SetStringToJson(pjMtInfo, JSON_GUID, pcMtInfo[dwMtInfoIdx].GetDomainGUID()))
		{
			continue;
		}

		// ��MOID
		if (!SetStringToJson(pjMtInfo, JSON_MOID, pcMtInfo[dwMtInfoIdx].GetDomainMOID()))
		{
			continue;
		}

		// mtNO
		if (!SetStringToJson(pjMtInfo, JSON_MTNO, pcMtInfo[dwMtInfoIdx].GetE164()))
		{
			continue;
		}

		// mtType
		if (!SetUIntAsStringToJson(pjMtInfo, JSON_MTTYPE, pcMtInfo[dwMtInfoIdx].GetMtType()))
		{
			continue;
		}

		// �Ƿ����绰����
		if (!SetUIntAsStringToJson(pjMtInfo, JSON_TELCONFFLAG, pcMtInfo[dwMtInfoIdx].GetTelConfFlag()))
		{
			continue;
		}

		// �Ƿ������˺�
		if (!SetUIntAsStringToJson(pjMtInfo, JSON_LIMITEDFLAG, pcMtInfo[dwMtInfoIdx].GetLimitedFlag()))
		{
			continue;
		}
		
		json_array_append_s( pjMtInfoArray, pjMtInfo );
	}
	
	
	json_object_set_s( pjRoot, JSON_MT, pjMtInfoArray );
	
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� GetDelayFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/11/11  5.0         rnn                   ����
=============================================================================*/
static BOOL32 GetDelayFromJson( const s8* pchJsonBuf, u16 &wDelayTime )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetDelayFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetDelayFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjDelaytime = json_object_get_s( pjRoot, JSON_DELAY );
	if ( NULL == pjDelaytime )
	{

		OspPrintf( TRUE, FALSE, "[GetDelayFromJson] json_object_get Delaytime is NULL, return FALSE!\n" );
		return FALSE;
	}
	
	wDelayTime = (u32)strtoul( json_string_value( pjDelaytime ), 0, 10 );
	
	
	return TRUE;
}

//rnn test
/*=============================================================================
�� �� ���� SetTempInfoToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/09/24  5.0         rnn                   ����
=============================================================================*/
static void SetTempInfoToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[SetTempInfoToJson] Param is NULL, return!\n" );
		return;
	}
	
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;

	//type
// 	json_t_ptr pjMsgType = json_string( "CM_MAU_CREATETEMPLATE_REQ" );
// 	if ( NULL == pjMsgType )
// 	{
// 
// 		OspPrintf( TRUE, FALSE, "[SetTempInfoToJson] json_string pjMsgType is NULL, return!\n" );
// 		return;
// 	}
// 
// 	json_object_set_new( pjRoot, JSON_MSGTYPE, pjMsgType );

	//isportconf
	SetUIntAsStringToJson( pjRoot, "isportconf", 0);
	//psw
	SetStringToJson(pjRoot, "psw", "");
	//duration
	SetUIntAsStringToJson(pjRoot, "duration", 60);
	//encryptmode
	SetUIntAsStringToJson(pjRoot, "encryptmode", 0);
	//mixmode
	SetUIntAsStringToJson(pjRoot, "mixmode", 0);
	//vacinterval
	SetUIntAsStringToJson(pjRoot, "vacinterval", 0);
	//videoprior
	SetUIntAsStringToJson(pjRoot, "videoprior", 0);
	//allmute
	SetUIntAsStringToJson(pjRoot, "allmute", 0);
	//dualmode
	SetUIntAsStringToJson(pjRoot, "dualmode", 1);
	//callmode
	SetUIntAsStringToJson(pjRoot, "callmode", 2);
	//callinterval
	SetUIntAsStringToJson(pjRoot, "callinterval", 20);
	//calltimes
	SetUIntAsStringToJson(pjRoot, "calltimes", 3);
	//openmode
	SetUIntAsStringToJson(pjRoot, "openmode", 1);
	//confE164
	SetStringToJson(pjRoot, "confE164", "");
	//chairman
	SetStringToJson(pjRoot, "chairman", "0512680000303");
	//speaker
	SetStringToJson(pjRoot, "speaker", "0512680000306");
	//speakersrc
	SetUIntAsStringToJson(pjRoot, "speakersrc", 0);
	//sat
	SetUIntAsStringToJson(pjRoot, "sat", 0);
	//satbandwidth
	SetUIntAsStringToJson(pjRoot, "satbandwidth", 256);
	//publicconf
	SetUIntAsStringToJson(pjRoot, "publicconf", 1);
	//vmpmodule
	SetUIntAsStringToJson(pjRoot, "vmpmodule", 0);
	//pollmodule
	SetUIntAsStringToJson(pjRoot, "pollmodule", 0);
	//allsilence
	SetUIntAsStringToJson(pjRoot, "allsilence", 0);
	//shareconf
	SetUIntAsStringToJson(pjRoot, "shareconf", 0);

	//ʣ�µ���ʱ����
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetDelTempListToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/10/20  5.0         rnn                   ����
=============================================================================*/
static void SetDelTempListToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, const s8 *pchDelTempList )
{

	if ( NULL == pchJsonBuf || NULL == pchDelTempList)
	{
		OspPrintf( TRUE, FALSE, "[SetDelTempListToJson] Param is NULL, return!\n" );
		return;
	}
	
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;

	//templateinfo
	json_t_ptr pjtemplistarray = json_array();
	if ( NULL == pjtemplistarray )
	{

		OspPrintf( TRUE, FALSE, "[SetDelTempListToJson] json_object pjtemplistarray is NULL, return!\n" );
		return;
	}

	u16 wIdx = 0;
	u16 wDelTempNum = 0;
	wDelTempNum = strlen( pchDelTempList )/11;
	s8 achTemp[MAXLEN_CONFE164+1] = {0};
	OspPrintf( TRUE, TRUE, "[rnn-test]wDelTempNum = %d.\n", wDelTempNum );
	for ( wIdx = 0; wIdx < wDelTempNum; wIdx++ )
	{
		json_t_ptr pjTempInfo = json_object();
		if ( NULL == pjTempInfo )
		{
			continue;
		}

		memset(achTemp, 0, sizeof(achTemp));
		memcpy(achTemp, pchDelTempList, sizeof(achTemp) - 1);
		
		SetStringToJson(pjTempInfo, JSON_CONFE164, achTemp);
		
		json_array_append_s( pjtemplistarray, pjTempInfo );
		pchDelTempList += MAXLEN_CONFE164;
	}
	
	json_object_set_s( pjRoot, JSON_TEMPLATELIST, pjtemplistarray );

	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetBookListToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/10/20  5.0         rnn                   ����
=============================================================================*/
static void SetBookListToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, const s8 *pchBookList )
{
	
	if ( NULL == pchJsonBuf || NULL == pchBookList)
	{
		OspPrintf( TRUE, FALSE, "[SetBookListToJson] Param is NULL, return!\n" );
		return;
	}
	
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;
	
	//confinfo
	json_t_ptr pjbooklistarray = json_array();
	if ( NULL == pjbooklistarray )
	{

		OspPrintf( TRUE, FALSE, "[SetBookListToJson] json_object pjbooklistarray is NULL, return!\n" );
		return;
	}
	
	u16 wIdx = 0;
	u16 wBookConfNum = 0;
	wBookConfNum = strlen( pchBookList )/52;
	s8 achBookId[3+1] = {0};
	s8 achBookE164[11+1] = {0};
	s8 achStartTime[19+1] = {0};
	s8 achEndTime[19+1] = {0};
	OspPrintf( TRUE, TRUE, "[rnn-test]wBookConfNum = %d.\n", wBookConfNum );
	for ( wIdx = 0; wIdx < wBookConfNum; wIdx++ )
	{
		json_t_ptr pjconfinfo = json_object();
		if ( NULL == pjconfinfo )
		{
			continue;
		}
		
		memset( achBookId, 0, sizeof(achBookId) );
		memset( achBookE164, 0, sizeof(achBookE164) );
		memset( achStartTime, 0, sizeof(achStartTime) );
		memset( achEndTime, 0, sizeof(achEndTime) );
		memcpy( achBookId, pchBookList, sizeof(achBookId) -1 );
		memcpy( achBookE164, pchBookList+3, sizeof(achBookE164) - 1 );
		memcpy( achStartTime, pchBookList+14, sizeof(achStartTime) - 1 );
		memcpy( achEndTime, pchBookList+33, sizeof(achEndTime) - 1 );

		//meetingID
		SetStringToJson(pjconfinfo, "meetingID", achBookId);
		//confE164
		SetStringToJson(pjconfinfo, "confE164", achBookE164);
		//starttime
		SetStringToJson(pjconfinfo, "starttime", achStartTime);
		//endtime
		SetStringToJson(pjconfinfo, "endtime", achEndTime);

		json_array_append_s( pjbooklistarray, pjconfinfo );
		pchBookList += 52;
	}
	
	json_object_set_s( pjRoot, "confinfo", pjbooklistarray );
	
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetTestReqToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/10/20  5.0         rnn                   ����
=============================================================================*/
static void SetTestReqToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, s8 * pchConfE164 )
{
	
	if ( NULL == pchJsonBuf || NULL == pchConfE164)
	{
		OspPrintf( TRUE, FALSE, "[SetTestReqToJson] Param is NULL, return!\n" );
		return;
	}
	
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;
	
	//confe164
	SetStringToJson(pjRoot, JSON_CONFE164, pchConfE164);
	//confname
	SetStringToJson(pjRoot, JSON_CONFNAME, "book4");
	//moid
	SetStringToJson(pjRoot, JSON_MOID, "ttz3z0iz9s455shj4x0jkz86");
	//meetingid
	SetUIntAsStringToJson(pjRoot, JSON_MEETINTID, 149);

	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetConfSafeToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/10/20  5.0         rnn                   ����
=============================================================================*/
static void SetConfSafeToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u32 dwOpenmode )
{
	json_t_ptr pjRoot = NULL;
	if(!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;
	//���ĵ�ʱ����
	SetUIntAsStringToJson(pjRoot, JSON_OPENMODE, dwOpenmode);
	SetStringToJson(pjRoot, JSON_PSW, "12025521155515");
	
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetForceBrdReqToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/10/20  5.0         rnn                   ����
=============================================================================*/
static BOOL32 SetForceBrdReqToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u32 dwForceBrd )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	//���ĵ�ʱ����
	ReturnIfFailed(SetUIntAsStringToJson(pjRoot, JSON_FORCEBRD, dwForceBrd));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}


/*=============================================================================
�� �� ���� SetMtNOInfoToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/10/20  5.0         rnn                   ����
=============================================================================*/
static void SetMtNOInfoToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, s8 * pchMtNO )
{
	if ( NULL == pchJsonBuf || NULL == pchMtNO )
	{
		OspPrintf( TRUE, FALSE, "[SetMtNOInfoToJson] Param is NULL, retur!\n" );
		return;
	}
	
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;
	
	json_t_ptr pjMtInfo = json_object();
	if ( NULL == pjMtInfo )
	{

		OspPrintf( TRUE, FALSE, "[SetMtNOInfoToJson] json_object pjMtInfo is NULL!\n" );
		return;
	}

	if (!SetStringToJson(pjMtInfo, JSON_MTNO, pchMtNO))
	{
		return;
	}
	
	json_object_set_s( pjRoot, JSON_MT, pjMtInfo );
	
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetTestVmpParamToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/12/02  5.0         rnn                   ����
=============================================================================*/
static void SetTestVmpParamToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, TVMPParam tVmpParam, TMtAlias *ptMtAlias, TVmpChnPollArray tVmpChnPollArray, TMtAlias *ptPollMtAlias )
{
	if ( NULL == pchJsonBuf || NULL == ptMtAlias )
	{
		OspPrintf( TRUE, FALSE, "[SetTestVmpParamToJson]Param is NULL, return!\n" );
		return;
	}
	
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;

	// enable
	SetBoolAsStringToJson(pjRoot, JSON_VMPISCAPING, tVmpParam.IsCping());
	// vmpbrdst
	SetBoolAsStringToJson(pjRoot, JSON_VMPBRDST, tVmpParam.IsVMPBrdst());
	// vmprim
	SetBoolAsStringToJson(pjRoot, JSON_VMPPRIM, tVmpParam.GetIsRimEnabled());
	// vmpaddalias
	SetBoolAsStringToJson(pjRoot, JSON_VMPADDALIAS, tVmpParam.IsAddMmbAlias());
	// vmpmode
	SetUIntAsStringToJson(pjRoot, JSON_VMPMODE, tVmpParam.GetVMPMode());
	// vmpstyle
	SetUIntAsStringToJson(pjRoot, JSON_VMPSTYLE, tVmpParam.GetVMPStyle());
	// batchpolltime
	SetUIntAsStringToJson(pjRoot, JSON_VMPBATCHPOLLTIME, 10);
	// batchpollnum
	SetUIntAsStringToJson(pjRoot, JSON_VMPBATCHPOLLNUM, 0);
	// voicehint
	SetUIntAsStringToJson(pjRoot, JSON_VMPVOICEHINT, 1);
		
	// ����ϳɳ�Ա
	u8 byMtType = 0;
	u8 byMtStatus = 0;
	u8 byVmpMtNum = tVmpParam.GetVMPMemberNum();
	json_t_ptr pjVmpMtArray = json_array();
	if ( NULL == pjVmpMtArray )
	{
		OspPrintf( TRUE, FALSE, "[SetTestVmpParamToJson] json_object VmpMtArray is NULL!\n" );
	}
	else
	{
		u8 byMtIdx = 0;
		for ( byMtIdx = 0; byMtIdx < byVmpMtNum; byMtIdx++ )
		{
			json_t_ptr pjVmpMtObj = json_object();
			if ( NULL == pjVmpMtObj )
			{
				OspPrintf( TRUE, FALSE, "[SetTestVmpParamToJson] json_object VmpMtObj is NULL!\n" );
				continue;
			}

			byMtType = MT_TYPE_MT;

			TVMPMember tVmpMem;
			tVmpMem = *tVmpParam.GetVmpMember( byMtIdx );

			SetStringToJson(pjVmpMtObj, JSON_MTNO, ptMtAlias[byMtIdx].m_achAlias);
			SetUIntAsStringToJson(pjVmpMtObj, JSON_MTTYPE, byMtType);
			SetUIntAsStringToJson(pjVmpMtObj, JSON_VMPPOLLIDX, tVmpParam.GetChlOfMtInMember(tVmpMem));
			SetUIntAsStringToJson(pjVmpMtObj, JSON_VMPTYPE, tVmpMem.GetMemberType());
			SetUIntAsStringToJson(pjVmpMtObj, JSON_VMPSTATUS, tVmpMem.GetMemStatus());

			json_array_append_s( pjVmpMtArray, pjVmpMtObj );
		}
	}

	json_object_set_s( pjRoot, JSON_VMPMEMBERS, pjVmpMtArray );

	//���ƻ���ϳ�ʱ����ͨ����ѯ����
	if ( CONF_VMPMODE_CTRL == tVmpParam.GetVMPMode() )
	{
		json_t_ptr pjVmpPollChnArray = json_array();
		if ( NULL == pjVmpPollChnArray )
		{
			OspPrintf( TRUE, FALSE, "[SetTestVmpParamToJson] json_object VmpPollChnArray is NULL!\n" );
		}
		else
		{
			u8 byVmpPollChlIdx = 0;
			for ( byVmpPollChlIdx = 0; byVmpPollChlIdx < MAXNUM_VMP_MEMBER; byVmpPollChlIdx++ )
			{
				TVmpChnPollParam tVmpChnPollParam;
				tVmpChnPollParam.Clear();
				tVmpChnPollParam =  tVmpChnPollArray.GetChnPollParam(byVmpPollChlIdx);
				if ( !tVmpChnPollParam.IsValid() )
				{
					continue;
				}

				json_t_ptr pjVmpChnPollObj = json_object();
				if ( NULL == pjVmpChnPollObj )
				{
					OspPrintf( TRUE, FALSE, "[SetTestVmpParamToJson] json_object VmpChnPollObj is NULL!\n" );
					continue;
				}

				SetUIntAsStringToJson(pjVmpChnPollObj, JSON_VMPPOLLIDX, tVmpChnPollParam.GetChnIdx());
				SetUIntAsStringToJson(pjVmpChnPollObj, JSON_POLLNUM, tVmpChnPollParam.GetPollingNumber());
				SetUIntAsStringToJson(pjVmpChnPollObj, JSON_POLLKEEPTIME, tVmpChnPollParam.GetKeepTime());

				json_t_ptr pjVmpPollMtArray = json_array();
				if ( NULL == pjVmpPollMtArray )
				{
					OspPrintf( TRUE, FALSE, "[SetTestVmpParamToJson] json_object VmpPollMtArray is NULL!\n" );
				}
				else
				{
					u8 byVmpPollObjIdx = 0;
					TVcMtChnObj tVmpPollObj;
					u8 byVmpPollObjNum = tVmpChnPollParam.GetPolledObjNum();					
					for ( byVmpPollObjIdx = 0; byVmpPollObjIdx < byVmpPollObjNum; byVmpPollObjIdx++ )
					{
						tVmpPollObj.Clear();
						tVmpPollObj = tVmpChnPollParam.GetPollObjByIdx( byVmpPollObjIdx );
						json_t_ptr pjVmpPollMtObj = json_object();
						if ( NULL == pjVmpPollMtObj )
						{
							OspPrintf( TRUE, FALSE, "[SetTestVmpParamToJson] json_object VmpPollMtObj is NULL!\n" );
							continue;
						}

						SetStringToJson(pjVmpPollMtObj, JSON_MTNO, ptPollMtAlias[byVmpPollObjIdx].m_achAlias);
						SetUIntAsStringToJson(pjVmpPollMtObj, JSON_MTTYPE, 3);

						json_array_append_s( pjVmpPollMtArray, pjVmpPollMtObj );
					}
				}

				json_object_set_s( pjVmpChnPollObj, JSON_VMPPOLLMT, pjVmpPollMtArray );
				json_array_append_s( pjVmpPollChnArray, pjVmpChnPollObj );
			}
		}

		json_object_set_s( pjRoot, JSON_VMPPOLLPARAM, pjVmpPollChnArray );				
	}

	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetTestRollCallInfoToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/12/02  5.0         rnn                   ����
=============================================================================*/
static void SetTestRollCallInfoToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen,  u8 byRollCallMode, TMtAlias tRollCaller, TMtAlias tRollCallee )
{
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;

	// rollcallmode
	SetUIntAsStringToJson(pjRoot, JSON_ROLLCALLMODE, byRollCallMode);
	SetStringToJson(pjRoot, JSON_ROLLCALLER, tRollCaller.m_achAlias);
	SetStringToJson(pjRoot, JSON_ROLLCALLEE, tRollCallee.m_achAlias);

	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetTestVipListToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/12/02  5.0         rnn                   ����
=============================================================================*/
static void SetTestVipListToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen,  u16 wVipNum, TMtAlias *ptVipMt )
{
	if ( NULL == pchJsonBuf || NULL == ptVipMt )
	{
		OspPrintf( TRUE, FALSE, "[SetTestVipListToJson]Param is NULL, return!\n" );
		return;
	}
	
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;
	
	u16 wVipIdx = 0;
	json_t_ptr pjVipArray = json_array();
	if ( NULL == pjVipArray )
	{
		OspPrintf( TRUE, FALSE, "[SetTestVipListToJson] json_object VipArray is NULL!\n" );
	}
	else
	{
		for ( wVipIdx = 0; wVipIdx < wVipNum; wVipIdx++ )
		{
			json_t_ptr pjVipMtObj = json_object();
			if ( NULL == pjVipMtObj )
			{
				OspPrintf( TRUE, FALSE, "[SetTestVipListToJson] json_object VipMtObj is NULL!\n" );
				continue;
			}

			SetStringToJson(pjVipMtObj, JSON_MTNO, ptVipMt[wVipIdx].m_achAlias);

			json_array_append_s( pjVipArray, pjVipMtObj );
		}
	}
	
	json_object_set_s( pjRoot, JSON_VIPMT, pjVipArray );
	
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}


#define SetDomainMoidToJsonObj(pjRoot, abyDomainMoid) SetStringToJson(pjRoot, JSON_MOID, abyDomainMoid)
/*=============================================================================
�� �� ���� SetTestMixToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/12/02  5.0         rnn                   ����
=============================================================================*/
static void SetTestMixToJson(s8 * pchJsonBuf, u32 &dwJsonBufLen, u8 byMixMode, u16 wMixNum, TMtAlias *ptMixMt)
{
	if (NULL == pchJsonBuf || NULL == ptMixMt)
	{
		OspPrintf(TRUE, FALSE, "[SetTestMixToJson]Param is NULL, return!\n");
		return;
	}

	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;

	// mixmode
	SetUIntAsStringToJson(pjRoot, JSON_MIXMODE, byMixMode);

	u16 wMixIdx = 0;
	json_t_ptr pjMixArray = json_array();
	if ( NULL == pjMixArray )
	{
		OspPrintf( TRUE, FALSE, "[SetTestMixToJson] json_object VipArray is NULL!\n" );
	}
	else
	{
		for ( wMixIdx = 0; wMixIdx < wMixNum; wMixIdx++ )
		{
			json_t_ptr pjMixMtObj = json_object();
			if ( NULL == pjMixMtObj )
			{
				OspPrintf( TRUE, FALSE, "[SetTestMixToJson] json_object VipMtObj is NULL!\n" );
				continue;
			}
			
			SetStringToJson(pjMixMtObj, JSON_MTNO, ptMixMt[wMixIdx].m_achAlias);
			
			json_array_append_s( pjMixArray, pjMixMtObj );
		}
	}
	
	json_object_set_s( pjRoot, JSON_MIXMEMBER, pjMixArray );
	
	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetMonitorListDataToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/10/10  5.0        ������                   ����
=============================================================================*/
static BOOL32 SetMonitorListDataToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, TMpcConfMonitorData * ptData, u16 wDataNum )
{
	if ( NULL == pchJsonBuf || NULL == ptData || 0 == wDataNum )
	{
		OspPrintf( TRUE, FALSE, "[SetMonitorListDataToJson] Param is NULL, retur!\n" );
		return FALSE;
	}
	
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	
	json_t_ptr pjConfDataArray = json_array();
	if ( NULL == pjConfDataArray )
	{

		OspPrintf( TRUE, FALSE, "[SetMonitorListDataToJson] json_array pjConfDataArray is NULL, return!\n" );
		return FALSE;
	}
	
    s8 achTmpBuf[256] = {0};
	
	u16 wConfDataIdx = 0;
	for (; wConfDataIdx < wDataNum; wConfDataIdx++ )
	{
		json_t_ptr pjConfDataInfo = json_object();
		if ( NULL == pjConfDataInfo )
		{
			continue;
		}
		//cmuid
		SetUIntAsStringToJson(pjConfDataInfo, JSON_CMUID, ptData[wConfDataIdx].GetCmuID());
		//ConfE164
		SetStringToJson(pjConfDataInfo, JSON_CONFE164, ptData[wConfDataIdx].GetConfE164());
		//meetId
		SetUIntAsStringToJson(pjConfDataInfo, JSON_CONFID, ptData[wConfDataIdx].GetConfIdx());
		//domain moid
		SetDomainMoidToJsonObj(pjConfDataInfo, ptData[wConfDataIdx].GetDomainMOID());
		//pjVidAddrArray
		json_t_ptr pjVidAddrArray = json_array();
		if ( NULL == pjVidAddrArray )
		{
			OspPrintf( TRUE, FALSE, "[SetConfDataToJson] json_array pjAudAddrArray is NULL, return!\n" );
			return FALSE;
		}
		
		std::vector<TTransportAddr>::iterator tVidAddrIter = ptData[wConfDataIdx].m_tTVidAddr.begin();
		for (; tVidAddrIter != ptData[wConfDataIdx].m_tTVidAddr.end(); tVidAddrIter++)
		{
			json_t_ptr pjVidinfo = json_object();
			if ( NULL == pjVidinfo )
			{
				continue;
			}
			//ip
			memset( achTmpBuf, 0, sizeof( achTmpBuf ) );
			u32 dwIp = tVidAddrIter->GetIpAddr();
			sprintf( achTmpBuf, "%u.%u.%u.%u", (dwIp>>24)&0xff, (dwIp>>16)&0xff, (dwIp>>8)&0xff, dwIp&0xff );
			SetStringToJson(pjVidinfo, JSON_IP, achTmpBuf);
			//port
			SetUIntAsStringToJson(pjVidinfo, JSON_PORT, tVidAddrIter->GetPort());
			
			json_array_append_s( pjVidAddrArray, pjVidinfo );
		}
		json_object_set_s( pjConfDataInfo, JSON_DSTVIDADDR, pjVidAddrArray );
		
		// ttAudaddr
		json_t_ptr pjAudAddrArray = json_array();
		if ( NULL == pjAudAddrArray )
		{
			OspPrintf( TRUE, FALSE, "[SetConfDataToJson] json_array pjAudAddrArray is NULL, return!\n" );
			return FALSE;
		}
	
		std::vector<TTransportAddr>::iterator tAudAddrIter = ptData[wConfDataIdx].m_tTAudAddr.begin();
		for (; tAudAddrIter != ptData[wConfDataIdx].m_tTAudAddr.end(); tAudAddrIter++)
		{
			json_t_ptr pjAudinfo = json_object();
			if ( NULL == pjAudinfo )
			{
				continue;
			}
			//ip
			memset( achTmpBuf, 0, sizeof( achTmpBuf ) );
			u32 dwIp = tAudAddrIter->GetIpAddr();
			sprintf( achTmpBuf, "%u.%u.%u.%u", (dwIp>>24)&0xff, (dwIp>>16)&0xff, (dwIp>>8)&0xff, dwIp&0xff );
			SetStringToJson(pjAudinfo, JSON_IP, achTmpBuf);
			//port
			SetUIntAsStringToJson(pjAudinfo, JSON_PORT, tAudAddrIter->GetPort());
	
			json_array_append_s( pjAudAddrArray, pjAudinfo );
		}
		json_object_set_s( pjConfDataInfo, JSON_DSTAUDADDR, pjAudAddrArray );
		
			
		json_array_append_s( pjConfDataArray, pjConfDataInfo );
	}

	json_object_set_s( pjRoot, JSON_MONITOR, pjConfDataArray );

	return 	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

static BOOL32 AddMpcConfDataToJsonObj(const json_t_ptr& pjConfArray, const TMpcConfData& tConfData)
{
	json_t_ptr pjConfDataInfo = json_object();
	if (NULL == pjConfDataInfo)
	{
		return FALSE;
	}

	// URL
	SetStringToJson(pjConfDataInfo, JSON_URL, tConfData.GetMcuUrl());
	// ConfE164
	SetStringToJson(pjConfDataInfo, JSON_CONFE164, tConfData.GetConfIdAttr().GetConfE164());
	// ConfName
	SetStringToJson(pjConfDataInfo, JSON_CONFNAME, tConfData.GetConfIdAttr().GetConfName());
	// ConfPwd
	SetStringToJson(pjConfDataInfo, JSON_PSW, tConfData.GetConfIdAttr().GetConfPwd());
	// MOID
	SetStringToJson(pjConfDataInfo, JSON_MOID, tConfData.GetConfIdAttr().GetDomainMOID());
	// DomainName
	SetStringToJson(pjConfDataInfo, JSON_DOMAINNAME, tConfData.GetConfIdAttr().GetDomainName());
	// StartTime
	time_t tTime;
	tConfData.GetStartTime().GetTime(tTime);
	SetUIntAsStringToJson(pjConfDataInfo, JSON_CONFSTARTTIME, (u32)tTime);
	// ConfId
	s8 achConfId[MAXLEN_CONFID * 2 + 1] = { 0 };
	tConfData.GetConfId().GetConfIdString(achConfId, sizeof(achConfId));
	SetStringToJson(pjConfDataInfo, JSON_CONFID, achConfId);
	// Duration
	SetUIntAsStringToJson(pjConfDataInfo, JSON_DURATION, tConfData.GetDuration());
	// MtNum
	SetUIntAsStringToJson(pjConfDataInfo, JSON_CONFMTNUM, tConfData.GetMtNum());
	// OpenMode
	SetUIntAsStringToJson(pjConfDataInfo, JSON_OPENMODE, tConfData.GetOpenMode());
	// DualMode
	SetUIntAsStringToJson(pjConfDataInfo, JSON_DUALMODE, tConfData.GetDualMode());
	// PublicConf
	SetUIntAsStringToJson(pjConfDataInfo, JSON_PUBLISHCONF, tConfData.GetPublicConf());
	// ConfNoDisturb
	SetUIntAsStringToJson(pjConfDataInfo, JSON_NODISTURB, tConfData.GetConfNoDisturb());
	// ConfIdx
	SetUIntAsStringToJson(pjConfDataInfo, JSON_CONFIDX, tConfData.GetConfIdx());
	// Bitrate
	SetUIntAsStringToJson(pjConfDataInfo, JSON_MEDIABITRATE, tConfData.GetBitRate());
	// Res
	SetUIntAsStringToJson(pjConfDataInfo, JSON_MEDIARES, tConfData.GetResolution());

	json_array_append_s(pjConfArray, pjConfDataInfo);

	return TRUE;
}

/*=============================================================================
�� �� ���� SetConfDataToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 SetConfDataToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, TMpcConfData*ptData, u16 wDataNum )
{
	if ( NULL == pchJsonBuf || NULL == ptData || 0 == wDataNum )
	{
		OspPrintf( TRUE, FALSE, "[SetConfDataToJson] Param is NULL, retur!\n" );
		return FALSE;
	}
	
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	
	json_t_ptr pjConfDataArray = json_array();
	if ( NULL == pjConfDataArray )
	{

		OspPrintf( TRUE, FALSE, "[SetConfDataToJson] json_array pjConfDataArray is NULL, return!\n" );
		return FALSE;
	}
	
	u16 wConfDataIdx = 0;
	for ( wConfDataIdx = 0; wConfDataIdx < wDataNum; wConfDataIdx++ )
	{
		AddMpcConfDataToJsonObj(pjConfDataArray, ptData[wConfDataIdx]);
	}
	
	json_object_set_s( pjRoot, JSON_CONFDATAINFO, pjConfDataArray );

	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

static BOOL32 SetOnereforming(s8 * pchJsonBuf, u32 &dwJsonBufLen, u8 byOnereforming )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetUIntAsStringToJson(pjRoot, JSON_ONEREFORMING, byOnereforming));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetHasXmpuSerToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/03/28  5.0         ����                   ����
=============================================================================*/
#define SetHasXmpuSerToJsonObj(pjRoot, byHasXmpuSer) SetBoolAsStringToJson(pjRoot, JSON_HASXMPUSER, byHasXmpuSer)

static BOOL32 SetHasXmpuSerToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u8 byHasXmpuSer )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetHasXmpuSerToJsonObj(pjRoot, byHasXmpuSer));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetConfStateTypeFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/03/28  5.0         ����                   ����
=============================================================================*/
static BOOL32 SetConfStateTypeFromJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, u8 byConfStateType )
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetUIntAsStringToJson(pjRoot, JSON_CONFSTATETYPE, byConfStateType));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� GetConfStateTypeFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/04/22  5.0         ����                   ����
=============================================================================*/
static BOOL32 GetConfStateTypeFromJson( s8* pchJsonBuf, u8 &byConfStateType )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetConfStateTypeFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfStateTypeFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjConfStateType = json_object_get_s( pjRoot, JSON_CONFSTATETYPE );
	if ( NULL == pjConfStateType )
	{
		OspPrintf( TRUE, FALSE, "[GetConfStateTypeFromJson] json_object_get ConfStateType is NULL, retur FALSE!\n" );
	}
	else
	{
		byConfStateType = (u32)strtoul( json_string_value( pjConfStateType ), 0, 10 );
	}

	return TRUE;
}

/*=============================================================================
�� �� ���� SetConfNameToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/04/22  5.0         ����                   ����
=============================================================================*/
#define SetConfNameToJsonObj(pjRoot, pchConfName) SetStringToJson(pjRoot, JSON_CONFNAME, pchConfName)
static BOOL32 SetConfNameToJson( s8 * pchJsonBuf, const s8 * pchConfName, u32 &dwJsonBufLen)
{
	if ( NULL == pchJsonBuf || NULL == pchConfName )
	{
		OspPrintf( TRUE, FALSE, "[SetConfNameToJson] Param is NULL, retur!\n" );
		return FALSE;
	}

	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetConfNameToJsonObj(pjRoot, pchConfName));

	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

#define SetAddMtTypeToJsonObj(pjRoot, byAddMtType) SetUIntAsStringToJson(pjRoot, JSON_ADDMT_TYPE, byAddMtType)

//����ն˵�ģʽ
static BOOL32 SetAddMtTypeToJson(char* pchJsonBuf, u32& dwJsonBufLen, u8 byAddMtType)
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetAddMtTypeToJsonObj(pjRoot, byAddMtType));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

#define SetConfTimeLeftToJsonObj(pjRoot, wTimeLeft) SetUIntAsStringToJson(pjRoot, JSON_LEFTTIME, wTimeLeft)

static BOOL32 SetConfTimeLeftToJson(char* pchJsonBuf, u32& dwJsonBufLen, u16 wTimeLeft)
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetConfTimeLeftToJsonObj(pjRoot, wTimeLeft));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

static BOOL32 GetConfTimeLeftFromJson( s8* pchJsonBuf, u16& wTimeLeft )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetConfTimeLeftFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfTimeLeftFromJson] json_loads err, return FALSE!\n" );
		return FALSE;
	}

	json_t_ptr pjLeftTime = json_object_get_s( pjRoot, JSON_LEFTTIME );
	if ( NULL == pjLeftTime )
	{
		OspPrintf( TRUE, FALSE, "[GetConfTimeLeftFromJson] json_object_get pjLeftTime is NULL, return FALSE!\n" );
	}
	else
	{
		wTimeLeft = (u32)strtoul( json_string_value( pjLeftTime ), 0, 10 );
	}

	return TRUE;
}

/*=============================================================================
�� �� ���� CreatCascadeSetJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� const TCascadeSetToCM &tCascadeSet - ��������
�� �� ֵ�� json_t_ptr json - tCascadeSet��json�ڵ� 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/04/09  5.0         �ܹ��                    ����
=============================================================================*/
static json_t_ptr CreatCascadeSetJson( const TCascadeSetToCM &tCascadeSet )
{
	json_t_ptr pjCascadeSet = json_object();
	if ( NULL == pjCascadeSet )
	{
		OspPrintf( TRUE, FALSE, "[CreatCascadeSetJson] pjCascadeSet is NULL, return!\n" );
		return NULL;
	}
	
	// CascadeMode
	SetUIntAsStringToJson(pjCascadeSet, JSON_CASCADEMODE, tCascadeSet.m_byCascadeMode);
	// IsUpload
	SetUIntAsStringToJson(pjCascadeSet, JSON_CASCADEISUPLOAD, tCascadeSet.m_byIsUpload);
	// IsSpy
	SetUIntAsStringToJson(pjCascadeSet, JSON_CASCADEISSPY, tCascadeSet.m_byIsSpy);
	// SpyBW
	SetUIntAsStringToJson(pjCascadeSet, JSON_CASCADESPYBW, tCascadeSet.m_dwSpyBW);
	
	return pjCascadeSet;
}

static json_t_ptr CreatSatConfigJson(const BOOL32 bSatConf, const u32 ipAddr, const u32 port, const u32 num)
{
	json_t_ptr pjSatConfig = json_object();
	if (NULL == pjSatConfig)
	{
		OspPrintf( TRUE, FALSE, "[CreatSatConfigJson] pjSatConfig is NULL, return!\n" );
		return NULL;
	}

	// �Ƿ����ǻ���
	SetBoolAsStringToJson(pjSatConfig, JSON_SAT, bSatConf);

	//���ǻ���ip
	SetUIntAsStringToJson(pjSatConfig, JSON_SATIP, ipAddr);

	//���ǻ���˿�
	SetUIntAsStringToJson(pjSatConfig, JSON_SATPORT, port);

	//���ǻ���ش���
	SetUIntAsStringToJson(pjSatConfig, JSON_SATSPYNUM, num);
	return pjSatConfig;
}

static json_t_ptr CreatMixParamSetJson( TMixParam &tMixParam )
{
	json_t_ptr pjMixSet = json_object();
	if ( NULL == pjMixSet )
	{
		OspPrintf( TRUE, FALSE, "[CreatMixParamSetJson] pjMixSet is NULL, return!\n" );
		return NULL;
	}

	SetUIntAsStringToJson(pjMixSet, JSON_MIXMODE, tMixParam.GetMode());
	SetUIntAsStringToJson(pjMixSet, JSON_MIXNUM, tMixParam.GetMemberNum());
	SetUIntAsStringToJson(pjMixSet, JSON_MIXMAXNUM, tMixParam.GetMtMaxNum());

	u8 byMixIdx = 0;
	json_t_ptr pjMixArray = json_array();
	if ( NULL == pjMixArray )
	{
		OspPrintf( TRUE, FALSE, "[CreatMixParamSetJson] json_object VipArray is NULL!\n" );
	}
	else
	{
		for ( byMixIdx = 0; byMixIdx < tMixParam.GetMemberNum(); byMixIdx++ )
		{
			json_t_ptr pjMixMtObj = json_object();
			if ( NULL == pjMixMtObj )
			{
				OspPrintf( TRUE, FALSE, "[CreatMixParamSetJson] json_object VipMtObj is NULL!\n" );
				continue;
			}

			SetUIntAsStringToJson(pjMixMtObj, JSON_MTTYPE, tMixParam.GetMemberByIdx(byMixIdx));

			json_array_append_s( pjMixArray, pjMixMtObj );
		}
	}

	json_object_set_s( pjMixSet, JSON_MIXMEMBER, pjMixArray );
	
	return pjMixSet;
}

static json_t_ptr CreatMixModuleSetJson( TMixModule &tMixModule )
{
	json_t_ptr pjMixSet = json_object();
	if ( NULL == pjMixSet )
	{
		OspPrintf( TRUE, FALSE, "[CreatMixModuleSetJson] pjMixSet is NULL, return!\n" );
		return NULL;
	}

	SetUIntAsStringToJson(pjMixSet, JSON_MIXMODE, tMixModule.GetModuleMixMode());
	SetUIntAsStringToJson(pjMixSet, JSON_VACINTERVAL, tMixModule.GetVACPeriodTime());

	u8 byMixIdx = 0;
	json_t_ptr pjMixArray = json_array();
	if ( NULL == pjMixArray )
	{
		OspPrintf( TRUE, FALSE, "[CreatMixParamSetJson] json_object VipArray is NULL!\n" );
	}
	else
	{
		for ( byMixIdx = 0; byMixIdx < MAXNUM_CONF_MT; byMixIdx++ )
		{
			json_t_ptr pjMixMtObj = json_object();
			if ( NULL == pjMixMtObj )
			{
				OspPrintf( TRUE, FALSE, "[CreatMixParamSetJson] json_object VipMtObj is NULL!\n" );
				continue;
			}

			u8 byMtIdx = tMixModule.GetMixMtIdx(byMixIdx);
			if (byMtIdx == 0)
			{
				continue;
			}

			SetUIntAsStringToJson(pjMixMtObj, JSON_MIXINDEX, byMtIdx);

			json_array_append_s( pjMixArray, pjMixMtObj );
		}
	}

	json_object_set_s( pjMixSet, JSON_MIXMEMBER, pjMixArray );

	return pjMixSet;
}

static json_t_ptr CreatVmpParamSetJson( TVMPParam &tVmpParam )
{
	json_t_ptr pjVmpSet = json_object();
	if ( NULL == pjVmpSet )
	{
		OspPrintf( TRUE, FALSE, "[CreatVmpParamSetJson] pjVmpSet is NULL, return!\n" );
		return NULL;
	}

	// enable
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPISCAPING, tVmpParam.IsCping());
	// vmpauto
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPAUTO, tVmpParam.IsVMPAuto());
	// vmpbrdst
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPBRDST, tVmpParam.IsVMPBrdst());
	// vmpstyle
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPSTYLE, tVmpParam.GetVMPStyle());
	//SchemeId
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPSCHEMEID, tVmpParam.GetVMPSchemeId());
	// vmpmode
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPMODE, tVmpParam.GetVMPMode());
	// vmprim
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPPRIM, tVmpParam.GetIsRimEnabled());
	// vmpaddalias
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPADDALIAS, tVmpParam.IsAddMmbAlias());
	// batchpolltime
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPBATCHPOLLTIME, tVmpParam.GetVMPBatchPollKeepTime());
	// batchpollnum
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPBATCHPOLLNUM, tVmpParam.GetVMPBatchPollPollNum());

	// ����ϳɳ�Ա
	u8 byMtType = 0;
	u8 byMtStatus = 0;
	u8 byVmpMtNum = tVmpParam.GetVMPMemberNum();
	json_t_ptr pjVmpMtArray = json_array();
	if ( NULL == pjVmpMtArray )
	{
		OspPrintf( TRUE, FALSE, "[CreatVmpParamSetJson] json_object VmpMtArray is NULL!\n" );
	}
	else
	{
		u8 byMtIdx = 0;
		for ( byMtIdx = 0; byMtIdx < byVmpMtNum; byMtIdx++ )
		{
			json_t_ptr pjVmpMtObj = json_object();
			if ( NULL == pjVmpMtObj )
			{
				OspPrintf( TRUE, FALSE, "[CreatVmpParamSetJson] json_object VmpMtObj is NULL!\n" );
				continue;
			}

			byMtType = MT_TYPE_NONE;

			const TVMPMember* ptVmpMem = tVmpParam.GetVmpMember( byMtIdx );

			SetUIntAsStringToJson(pjVmpMtObj, JSON_MTTYPE, ptVmpMem->GetChnIdx());
			SetUIntAsStringToJson(pjVmpMtObj, JSON_VMPTYPE, ptVmpMem->GetMemberType());
			SetUIntAsStringToJson(pjVmpMtObj, JSON_VMPSTATUS, ptVmpMem->GetMemStatus());

			json_array_append_s( pjVmpMtArray, pjVmpMtObj );
		}
	}

	json_object_set_s( pjVmpSet, JSON_VMPMEMBERS, pjVmpMtArray );
	return pjVmpSet;
}

static json_t_ptr CreatVmpModuleSetJson( TVmpModuleInfo &tVmpModule )
{
	json_t_ptr pjVmpSet = json_object();
	if ( NULL == pjVmpSet )
	{
		OspPrintf( TRUE, FALSE, "[CreatVmpModuleSetJson] pjVmpSet is NULL, return!\n" );
		return NULL;
	}

	// enable
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPVOICEHINT, tVmpModule.GetVmpParam().IsVoiceHint());
	// vmpauto
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPAUTO, tVmpModule.GetVmpParam().IsVMPAuto());
	// vmpbrdst
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPBRDST, tVmpModule.GetVmpParam().IsVMPBrdst());
	// vmpstyle
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPSTYLE, tVmpModule.GetVmpParam().GetVMPStyle());
	//SchemeId
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPSCHEMEID, tVmpModule.GetVmpParam().GetVMPSchemeId());
	// vmpmode
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPMODE, tVmpModule.GetVmpParam().GetVMPMode());
	// vmprim
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPPRIM, tVmpModule.GetVmpParam().GetIsRimEnabled());
	// vmpaddalias
	SetBoolAsStringToJson(pjVmpSet, JSON_VMPADDALIAS, tVmpModule.GetVmpParam().IsAddMmbAlias());
	// batchpolltime
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPBATCHPOLLTIME, tVmpModule.GetVmpParam().GetVMPBatchPollKeepTime());
	// batchpollnum
	SetUIntAsStringToJson(pjVmpSet, JSON_VMPBATCHPOLLNUM, tVmpModule.GetVmpParam().GetVMPBatchPollPollNum());

	// ����ϳɳ�Ա
	u8 byVmpMtNum = MAXNUM_VMP_MEMBER;

	json_t_ptr pjVmpMtArray = json_array();
	if ( NULL == pjVmpMtArray )
	{
		OspPrintf( TRUE, FALSE, "[CreatVmpParamSetJson] json_object VmpMtArray is NULL!\n" );
	}
	else
	{
		u8 byChnIdx = 0;
		for ( byChnIdx = 0; byChnIdx < byVmpMtNum; byChnIdx++ )
		{
			if (tVmpModule.m_abyMemberType[byChnIdx] == VMP_MEMBERTYPE_NULL)
			{
				continue;
			}

			json_t_ptr pjVmpMtObj = json_object();
			if ( NULL == pjVmpMtObj )
			{
				OspPrintf( TRUE, FALSE, "[CreatVmpParamSetJson] json_object VmpMtObj is NULL!\n" );
				continue;
			}

			SetUIntAsStringToJson(pjVmpMtObj, JSON_VMPINDEX, tVmpModule.m_abyVmpMember[byChnIdx]);
			SetUIntAsStringToJson(pjVmpMtObj, JSON_VMPTYPE, tVmpModule.m_abyMemberType[byChnIdx]);
			SetUIntAsStringToJson(pjVmpMtObj, JSON_VMPCHNIDX, byChnIdx);

			json_array_append_s( pjVmpMtArray, pjVmpMtObj );
		}
	}

	json_object_set_s( pjVmpSet, JSON_VMPMEMBERS, pjVmpMtArray );
	return pjVmpSet;
}

static BOOL32 SetVmpModuleInfoToJsonObj(json_t_ptr pjRoot, TVmpModuleInfo tVmpModuleInfo)
{
	//vmp��Ϣ
	json_t_ptr pjVmpParam = CreatVmpModuleSetJson(tVmpModuleInfo);
	if (pjVmpParam)
	{
		json_object_set_s(pjRoot, JSON_VMPPARAM, pjVmpParam);
		return TRUE;
	}
	return FALSE;
}

static BOOL32 SetRecordInfoToJsonObj(json_t_ptr pjRoot, const TRecord& tRecord)
{
	json_t_ptr pjRecordConfig = json_object();
	if ( NULL == pjRecordConfig)
	{
		OspPrintf( TRUE, FALSE, "[SetRecordInfoToJsonObj] pjRecordConfig is NULL, return!\n" );
		return FALSE;
	}

	SetBoolAsStringToJson(pjRecordConfig, JSON_RECENABLE, tRecord.GetEnable());
	SetBoolAsStringToJson(pjRecordConfig, JSON_RECPUBLISH, tRecord.GetPublish());
	SetBoolAsStringToJson(pjRecordConfig, JSON_IS_REC_MAIN_VID, tRecord.GetMainFlowEnable());
	SetBoolAsStringToJson(pjRecordConfig, JSON_IS_REC_DSTREAM, tRecord.GetDoubleFlowEnable());
	json_object_set_s(pjRoot, JSON_RECORDCONF, pjRecordConfig);
	return TRUE;
}

static BOOL32 SetVmpModuleInfoToJson(s8 * pchJsonBuf, u32 &dwJsonBufLen, TVmpModuleInfo tVmpModuleInfo)
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetVmpModuleInfoToJsonObj(pjRoot, tVmpModuleInfo));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

static BOOL32 SetRecordInfoToJson(s8* pchJsonBuf, u32 dwJsonBufLen, const TRecord& tRecord)
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetRecordInfoToJsonObj(pjRoot, tRecord));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

static BOOL32 SetMixModuleToJsonObj(json_t_ptr pjRoot, TMixModule& tMixModule)
{
	//mix��Ϣ
	json_t_ptr pjVmpParam = CreatMixModuleSetJson(tMixModule);
	if (pjVmpParam)
	{
		json_object_set_s(pjRoot, JSON_MIXPARAM, pjVmpParam);
		return TRUE;
	}
	return FALSE;
}

static BOOL32 SetMixModuleToJson(s8 * pchJsonBuf, u32 &dwJsonBufLen, TMixModule& tMixModule)
{
	json_t_ptr pjRoot = NULL;

	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetMixModuleToJsonObj(pjRoot, tMixModule));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� GetCascadeSetFromJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� json_t_ptr pjCascadeSet
		   TCascadeSetToCM &tCascadeSet
�� �� ֵ�� BOOL32
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2015/04/09  5.0         �ܹ��                    ����
=============================================================================*/
static BOOL32 GetCascadeSetFromJson( json_t_ptr pjCascadeSet, TCascadeSetToCM &tCascadeSet )
{
	if ( NULL == pjCascadeSet )
	{
		OspPrintf( TRUE, FALSE, "[GetCascadeSetFromJson] pjCascadeSet is NULL, return FALSE!\n" );
		return FALSE;
	}
	
	// CascadeMode
	json_t_ptr pjCascadeMode = json_object_get_s( pjCascadeSet, JSON_CASCADEMODE );
	if ( NULL == pjCascadeMode )
	{
		OspPrintf( TRUE, FALSE, "[GetCascadeSetFromJson] json_string CascadeMode is NULL, return FALSE!\n" );
		return FALSE;
	}
	tCascadeSet.m_byCascadeMode = atoi(json_string_value(pjCascadeMode));
	
	// IsUpload
	json_t_ptr pjIsUpload = json_object_get_s( pjCascadeSet, JSON_CASCADEISUPLOAD );
	if ( NULL == pjIsUpload )
	{
		OspPrintf( TRUE, FALSE, "[GetCascadeSetFromJson] json_string IsUpload is NULL, return FALSE!\n" );
		return FALSE;
	}
	tCascadeSet.m_byIsUpload = atoi(json_string_value(pjIsUpload));
	
	// IsSpy
	json_t_ptr pjIsSpy = json_object_get_s( pjCascadeSet, JSON_CASCADEISSPY );
	if ( NULL == pjIsSpy )
	{
		OspPrintf( TRUE, FALSE, "[GetCascadeSetFromJson] json_string IsSpy is NULL, return FALSE!\n" );
		return FALSE;
	}
	tCascadeSet.m_byIsSpy = atoi(json_string_value(pjIsSpy));
	
	// SpyBW
	json_t_ptr pjSpyBW = json_object_get_s( pjCascadeSet, JSON_CASCADESPYBW );
	if ( NULL == pjSpyBW )
	{
		OspPrintf( TRUE, FALSE, "[GetCascadeSetFromJson] json_string SpyBW is NULL, return FALSE!\n" );
		return FALSE;
	}
	tCascadeSet.m_dwSpyBW = atoi(json_string_value(pjSpyBW));
	
	return TRUE;
}

static BOOL32 GetConfInfoFromJson(json_t_ptr pjRoot, TConfInfo &tConfInfo)
{
	if (!pjRoot)
	{
		return FALSE;
	}
	TSimCapSet tMain;
	TSimCapSet tSecond;
	TMtAlias tMtAlias;
	TMediaEncrypt tMediaEncrypt;
	TCapSupport tCapSupport;
	TCapSupportEx tCapSupportEx;
	TConfAttrb tConfAttrb;

	tMain.Clear();
	tSecond.Clear();
	tMtAlias.SetNull();
	tConfInfo.Reset();
	tMediaEncrypt.Reset();
	tCapSupport.Clear();
	tCapSupportEx.Clear();

	// ConfE164
	json_t_ptr pjConfE164 = json_object_get_s(pjRoot, JSON_CONFE164);
	if (NULL == pjConfE164)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get ConfE164 is NULL!\n");
	}
	else
	{
		tConfInfo.SetConfE164(json_string_value(pjConfE164));
	}

	// ConfName
	json_t_ptr pjConfName = json_object_get_s(pjRoot, JSON_CONFNAME);
	if (NULL == pjConfName)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get ConfName is NULL!\n");
	}
	else
	{
		tConfInfo.SetConfName(json_string_value(pjConfName));
	}

	// �����߱���
	json_t_ptr pjCreatorName = json_object_get_s(pjRoot, JSON_CREATORNAME);
	if (NULL == pjCreatorName)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get CreatorName is NULL!\n");
	}
	else
	{
		tConfInfo.SetCreaterAlias(json_string_value(pjCreatorName));
	}

	//ConfId
	s8 achConfId[MAXLEN_CONFID * 2 + 1] = { 0 };
	tConfInfo.GetConfId().GetConfIdString(achConfId, sizeof(achConfId));	json_t_ptr pjConfId = json_object_get_s(pjRoot, JSON_CONFID);
	if (NULL == pjConfId)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get ConfName is NULL!\n");
	}
	else
	{
		CConfId cConfId;
		cConfId.SetConfId(json_string_value(pjConfId));
		tConfInfo.SetConfId(cConfId);
	}

	//�Ƿ�˿ڻ���
	json_t_ptr pjIsPortConf = json_object_get_s(pjRoot, JSON_ISPORTCONF);
	if (NULL == pjIsPortConf)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get IsPortConf is NULL!\n");
	}
	else
	{
		const char* pchd = json_string_value(pjIsPortConf);
		BOOL32 bIsPortConf = (1 == atoi(json_string_value(pjIsPortConf))) ? TRUE : FALSE;
		tConfAttrb.SetPortConfFlag(bIsPortConf);
	}

	//�������
	json_t_ptr pjConfPwd = json_object_get_s(pjRoot, JSON_PSW);
	if (NULL == pjConfPwd)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get ConfPwd is NULL!\n");
	}
	else
	{
		if (0 != strlen(json_string_value(pjConfPwd)))
		{
			tConfAttrb.SetNeedConfPwd(TRUE);
			tConfInfo.SetConfPwd(json_string_value(pjConfPwd));
		}
		else
		{
			tConfAttrb.SetNeedConfPwd(FALSE);
		}
	}

	json_t_ptr pjBandWidth = json_object_get_s(pjRoot, JSON_BANDWIDTH);
	if (NULL == pjBandWidth)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get BandWidth is NULL!\n");
	}
	else
	{
		tConfInfo.SetBitRate((u16)atoi(json_string_value(pjBandWidth)));
	}

	json_t_ptr pjConfRes = json_object_get_s(pjRoot, JSON_RES);
	if (NULL == pjConfRes)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get ConfRes is NULL!\n");
	}
	else
	{
		tConfInfo.SetMainVideoFormat((u8)atoi(json_string_value(pjConfRes)));
	}

	//����ʱ��
	json_t_ptr pjDuration = json_object_get_s(pjRoot, JSON_DURATION);
	if (NULL == pjDuration)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get Duration is NULL!\n");
	}
	else
	{
		tConfInfo.SetDuration((u16)atoi(json_string_value(pjDuration)));
	}

	//�Ƿ��Զ�����
	json_t_ptr pjEncryptManual = json_object_get_s(pjRoot, JSON_ENCRYPT_MANUAL);
	if (NULL == pjEncryptManual)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get pjEncryptManual is NULL!\n");
	}
	else
	{
		//tMediaEncrypt.SetEncryptMode( (u8)atoi( json_string_value( pjEncryptManual ) ) );
		//tConfInfo.SetMediaKey( tMediaEncrypt );
		tConfAttrb.SetEncKeyManual(((u8)atoi(json_string_value(pjEncryptManual))) > 0);
	}

	//��������ģʽ
	json_t_ptr pjEncryptMode = json_object_get_s(pjRoot, JSON_ENCRYPTMODE);
	if (NULL == pjEncryptMode)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get EncryptMode is NULL!\n");
	}
	else
	{
		if (tConfAttrb.IsEncKeyManual())
		{
			tMediaEncrypt.SetEncryptMode((u8)atoi(json_string_value(pjEncryptMode)));
			tConfInfo.SetMediaKey(tMediaEncrypt);
		}

		tConfAttrb.SetEncryptMode((u8)atoi(json_string_value(pjEncryptMode)));
	}


	//����������Կ
	json_t_ptr pjEncryptKey = json_object_get_s(pjRoot, JSON_ENCRYPTKEY);
	if (NULL == pjEncryptKey)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get pjEncryptKey is NULL!\n");
	}
	else
	{
		if (CONF_ENCRYPTMODE_NONE != tConfAttrb.GetEncryptMode() &&
			tConfAttrb.IsEncKeyManual())
		{
			u8  m_abyEncKey[MAXLEN_KEY];
			memset(m_abyEncKey, 0, sizeof(m_abyEncKey));
			u8 byLen = strlen(json_string_value(pjEncryptKey));
			if (byLen > MAXLEN_KEY)
			{
				byLen = MAXLEN_KEY;
			}
			memcpy(m_abyEncKey, (u8*)json_string_value(pjEncryptKey), byLen);
			tMediaEncrypt.SetEncryptKey((u8*)&m_abyEncKey[0], MAXLEN_KEY);

			tConfInfo.SetMediaKey(tMediaEncrypt);
		}
	}

	//��ϯ
	json_t_ptr pjChairMan = json_object_get_s(pjRoot, JSON_CHAIRMANALIAS);
	if (NULL == pjChairMan)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get ChairMan is NULL!\n");
	}
	else
	{
		tMtAlias.SetNull();
		tMtAlias.SetE164Alias(json_string_value(pjChairMan));
		tConfInfo.SetChairAlias(tMtAlias);
		tConfInfo.m_tStatus.m_tChairman.SetNull();
	}

	//������
	json_t_ptr pjSpeaker = json_object_get_s(pjRoot, JSON_SPEAKERALIAS);
	if (NULL == pjSpeaker)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get Speaker is NULL!\n");
	}
	else
	{
		tMtAlias.SetNull();
		tMtAlias.SetE164Alias(json_string_value(pjSpeaker));
		tConfInfo.SetSpeakerAlias(tMtAlias);
		tConfInfo.m_tStatus.m_tSpeaker.SetNull();
	}

	//����ģʽ
	json_t_ptr pjMixMode = json_object_get_s(pjRoot, JSON_MIXMODE);
	if (NULL == pjMixMode)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get MixMode is NULL!\n");
	}
	else
	{
		BOOL32 bIsDisccussConf = (u8)atoi(json_string_value(pjMixMode)) == 0 ? FALSE : TRUE;
		tConfAttrb.SetDiscussConf(bIsDisccussConf);
		tConfInfo.m_tStatus.SetMixerMode((u8)atoi(json_string_value(pjMixMode)));
	}

	//ȫ������
	json_t_ptr pjAllMute = json_object_get_s(pjRoot, JSON_ALLMUTE);
	if (NULL == pjAllMute)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get AllMute is NULL!\n");
	}
	else
	{
		BOOL32 bIsAllInitdump = (u8)atoi(json_string_value(pjAllMute)) == 0 ? FALSE : TRUE;
		tConfAttrb.SetAllInitDumb(bIsAllInitdump);
	}

	//ȫ�徲��
	json_t_ptr pjAllSilence = json_object_get_s(pjRoot, JSON_ALLSILENCE);
	if (NULL == pjAllSilence)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get AllSilence is NULL!\n");
	}
	else
	{
		BOOL32 bIsAllInitSilence = (u8)atoi(json_string_value(pjAllSilence)) == 0 ? FALSE : TRUE;
		tConfAttrb.SetAllInitSilence(bIsAllInitSilence);
	}

	// ˫��ģʽ DualMode
	json_t_ptr pjDualMode = json_object_get_s(pjRoot, JSON_DUALMODE);
	if (NULL == pjDualMode)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get DualMode is NULL!\n");
	}
	else
	{
		tConfAttrb.SetDualMode((u8)atoi(json_string_value(pjDualMode)));
	}

	//�����˽�����ƵԴ
	json_t_ptr pjSpeakerSrc = json_object_get_s(pjRoot, JSON_SPEAKERSRC);
	if (NULL == pjSpeakerSrc)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get SpeakerSrc is NULL!\n");
	}
	else
	{
		tConfAttrb.SetSpeakerSrc((u8)atoi(json_string_value(pjSpeakerSrc)));
	}


	//����ģʽ
	json_t_ptr pjCallMode = json_object_get_s(pjRoot, JSON_CALLMODE);
	if (NULL == pjCallMode)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get CallMode is NULL!\n");
	}
	else
	{
		tConfInfo.m_tStatus.SetCallMode((u8)atoi(json_string_value(pjCallMode)));
	}

	//���м��
	json_t_ptr pjCallInterval = json_object_get_s(pjRoot, JSON_CALLINTERVAL);
	if (NULL == pjCallInterval)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get CallInterval is NULL!\n");
	}
	else
	{
		tConfInfo.m_tStatus.SetCallInterval((u32)strtoul(json_string_value(pjCallInterval), 0, 10));
	}

	//���д���
	json_t_ptr pjCallTimes = json_object_get_s(pjRoot, JSON_CALLTIMES);
	if (NULL == pjCallTimes)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get CallTimes is NULL!\n");
	}
	else
	{
		tConfInfo.m_tStatus.SetCallTimes((u32)strtoul(json_string_value(pjCallTimes), 0, 10));
	}

	// ��Ƶ����
	json_t_ptr pjQualityPri = json_object_get_s(pjRoot, JSON_VIDEOPRIOR);
	if (NULL == pjQualityPri)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get QualityPri is NULL!\n");
	}
	else
	{
		BOOL32 bQualityPri = (1 == atoi(json_string_value(pjQualityPri))) ? TRUE : FALSE;
		tConfAttrb.SetQualityPri(bQualityPri);
	}

	// 	json_t_ptr pjSat = json_object_get( pjRoot, JSON_SAT );
	// 	if ( NULL == pjSat )
	// 	{
	// 		OspPrintf( TRUE, FALSE, "[GetConfInfoFromJson] json_object_get Sat is NULL, retur FALSE!\n" );
	// 	}
	// 	{
	// 		BOOL32 bIsSatDCastMode = (u8)atoi( json_string_value( pjSat ) ) == 0 ? FALSE:TRUE;
	// 	    tConfAttrb.SetSatDCastMode( bIsSatDCastMode );
	// 	}
	// 
	// 	json_t_ptr pjSatBandWidth = json_object_get( pjRoot, JSON_SATBANDWIDTH );
	// 	if ( NULL == pjSatBandWidth )
	// 	{
	// 		OspPrintf( TRUE, FALSE, "[GetConfInfoFromJson] json_object_get SatBandWidth is NULL!\n" );
	// 	}

		//�Ƿ񹫹�����
	json_t_ptr pjPublicConf = json_object_get_s(pjRoot, JSON_PUBLISHCONF);
	if (NULL == pjPublicConf)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get PublicConf is NULL!\n");
	}
	else
	{
		tConfAttrb.SetPublicConf((u8)atoi(json_string_value(pjPublicConf)));
	}

	//���鿪������
	json_t_ptr pjOpenMode = json_object_get_s(pjRoot, JSON_OPENMODE);
	if (NULL == pjOpenMode)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get OpenMode is NULL!\n");
	}
	else
	{
		u8 byCMMode = 0;
		switch ((u8)atoi(json_string_value(pjOpenMode)))
		{
		case 0:
			byCMMode = CONF_OPENMODE_CLOSED;
			break;
		case 1:
			byCMMode = CONF_OPENMODE_OPEN;
			break;
		default:
			byCMMode = CONF_OPENMODE_OPEN;
			break;
		}
		tConfAttrb.SetOpenMode(byCMMode);
	}

	//�����Ƿ��ջ��� 0-�Ƿ�գ�1-���(�ն������)
	json_t_ptr pjClosed = json_object_get_s(pjRoot, JSON_NODISTURB);
	if (NULL == pjClosed)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get Closed is NULL!\n");
	}
	else
	{
		tConfAttrb.SetConfNoDisturb((u8)atoi(json_string_value(pjClosed)) == 1 ? TRUE : FALSE);
	}

	//�Ƿ��л���ϳ�ģ��
	json_t_ptr pjVmpModule = json_object_get_s(pjRoot, JSON_VMPMODULE);
	if (NULL == pjVmpModule)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get VmpModule is NULL!\n");
	}
	else
	{
		BOOL32 bIsHasVmpModule = (u8)atoi(json_string_value(pjVmpModule)) == 0 ? FALSE : TRUE;
		tConfAttrb.SetHasVmpModule(bIsHasVmpModule);
	}

	//�Ƿ�����ѯģ��
	json_t_ptr pjPollModule = json_object_get_s(pjRoot, JSON_POLLMODULE);
	if (NULL == pjPollModule)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get PollModule is NULL!\n");
	}
	else
	{
		BOOL32 bIsHasPollModule = (u8)atoi(json_string_value(pjPollModule)) == 0 ? FALSE : TRUE;
		tConfAttrb.SetHasPollModule(bIsHasPollModule);
	}

	//�Ƿ��л���ģ��
	json_t_ptr pjMixModule = json_object_get_s(pjRoot, JSON_MIXMODULE);
	if (NULL == pjMixModule)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get MixModule is NULL!\n");
	}
	else
	{
		BOOL32 bIsHasMixModule = (u8)atoi(json_string_value(pjMixModule)) == 0 ? FALSE : TRUE;
		tConfAttrb.SetHasMixModule(bIsHasMixModule);
	}

	//��һ����
	json_t_ptr pjUniFormatting = json_object_get_s(pjRoot, JSON_ONEREFORMING);
	if (NULL == pjUniFormatting)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get UniFormating is NULL!\n");
	}
	else
	{
		u8 byUniformMode = atoi(json_string_value(pjUniFormatting)) == 0 ? CONF_UNIFORMMODE_NONE : CONF_UNIFORMMODE_VALID;
		tConfAttrb.SetUniformMode(byUniformMode);
	}

	//�Ƿ���XMPU������
	json_t_ptr pjXmpuser = json_object_get_s(pjRoot, JSON_HASXMPUSER);
	if (NULL == pjXmpuser)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get Xmpuser is NULL!\n");
	}
	else
	{
		BOOL32 bIsHasXmpuSer = (u8)atoi(json_string_value(pjXmpuser)) == 0 ? FALSE : TRUE;
		tConfAttrb.SetHasXmpuSer(bIsHasXmpuSer);
	}

	//�Ƿ��е���ǽģ��
	json_t_ptr pjHduModule = json_object_get_s(pjRoot, JSON_HDUMODULE);
	if (NULL == pjHduModule)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get HduModule is NULL!\n");
	}
	else
	{
		BOOL32 bIsHasHduModule = (u8)atoi(json_string_value(pjHduModule)) == 0 ? FALSE : TRUE;
		tConfAttrb.SetHasTvWallModule(bIsHasHduModule);
	}

	//��Moid
	json_t_ptr pjDomainMoid = json_object_get_s(pjRoot, JSON_MOID);
	if (NULL == pjDomainMoid)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get DomainMoid is NULL!\n");
	}
	else
	{
		tConfInfo.SetDomainMoid(json_string_value(pjDomainMoid));
	}

	//��name
	json_t_ptr pjDomainName = json_object_get_s(pjRoot, JSON_DOMAINNAME);
	if (NULL == pjDomainName)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get DomainName is NULL!\n");
	}
	else
	{
		tConfInfo.SetDomainName(json_string_value(pjDomainName));
	}
	//���鿪ʼʱ��
	json_t_ptr pjStartTime = json_object_get_s(pjRoot, JSON_CONFSTARTTIME);
	if (pjStartTime == NULL)
	{
		OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get StartTime is NULL!\n");
	}
	else
	{
		const char* pStartTime = json_string_value(pjStartTime);
		if (pjStartTime != NULL)
		{
			struct tm tmInfo;
			time_t ti;
			int i = sscanf(pStartTime, "%d-%d-%d %d:%d:%d",
				&(tmInfo.tm_year), &(tmInfo.tm_mon), &(tmInfo.tm_mday),
				&(tmInfo.tm_hour), &(tmInfo.tm_min), &(tmInfo.tm_sec));
			if (tmInfo.tm_year > 1900 && tmInfo.tm_mon > 0)
			{
				tmInfo.tm_year -= 1900;
				tmInfo.tm_mon--;
				tmInfo.tm_isdst = -1;
				ti = mktime(&tmInfo);
				tConfInfo.SetStartTime(ti);
			}
			else
			{
				OspPrintf(TRUE, FALSE, "[GetConfInfoFromJson] json_object_get StartTime is error, tm_year: %d tm_mon: %d!\n",
					tmInfo.tm_year, tmInfo.tm_mon);
			}
		}
	}

	// �������ն�����
	json_t_ptr pjMaxJoinedMt = json_object_get_s(pjRoot, JSON_MAXJOINEDMT);
	if (NULL != pjMaxJoinedMt)
	{
		// �����������ն�����
		tConfAttrb.SetMaxJoinedMtNum(atoi(json_string_value(pjMaxJoinedMt)));
	}
	else
	{
		// û����Ĭ������Ϊ192
		tConfAttrb.SetMaxJoinedMtNum(MAXNUM_CONF_MT);
	}
	
	//�Զ�¼����Ϣ
	TConfAutoRecAttrb tConfAutoRecAttrb;
	TRecStartPara tRecStartPara;
	json_t_ptr pjAutoRecAttrb = json_object_get_s(pjRoot, JSON_AUTORECATTRB);
	if( pjAutoRecAttrb != NULL )
	{
		json_t_ptr pjAutoRec = json_object_get_s(pjAutoRecAttrb, JSON_AUTOREC);
		if( pjAutoRec == NULL )
		{
			LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetConfInfoFromJson]pjAutoRec is NULL, return!\n" );
		}
		else
		{
			tConfAutoRecAttrb.SetAutoRec(strtoul(json_string_value(pjAutoRec), 0, 10));
		}
		json_t_ptr pjPublishMode = json_object_get_s( pjAutoRecAttrb, JSON_PUBLISH_MODE );
		if( pjPublishMode == NULL )
		{
			LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetConfInfoFromJson]publishmode is NULL, return!\n" );
		}
		else
		{
			tRecStartPara.SetPublishMode((u8)strtoul(json_string_value(pjPublishMode), 0, 10));
		}
		json_t_ptr pjIsRecMainVid = json_object_get_s( pjAutoRecAttrb, JSON_IS_REC_MAIN_VID );
		if( pjIsRecMainVid == NULL )
		{
			LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetConfInfoFromJson]isrecmainvideo is NULL, return!\n" );
		}
		else
		{
			tRecStartPara.SetIsRecMainAudio(strtoul(json_string_value(pjIsRecMainVid), 0, 10));
			tRecStartPara.SetIsRecMainVideo(strtoul(json_string_value(pjIsRecMainVid), 0, 10));
		}
		json_t_ptr pjIsRecDstream = json_object_get_s( pjRoot, JSON_IS_REC_DSTREAM );
		if( pjIsRecDstream == NULL )
		{
			LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetConfInfoFromJson]isrecdstream is NULL, return!\n" );
		}
		else
		{
			tRecStartPara.SetIsRecDStream(strtoul(json_string_value(pjIsRecDstream), 0, 10));
		}
		tConfAutoRecAttrb.SetRecParam(tRecStartPara);
		tConfAttrb.SetAutoRecAttrb(tConfAutoRecAttrb);
	}
	else
	{
		LogPrint( LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetConfInfoFromJson]pjAutoRecAttrb is NULL, return!\n" );
	}

	// ������Ϣ
	json_t_ptr pjCascadeInfo = json_object_get_s(pjRoot, JSON_CASCADECONF);
	if (NULL != pjCascadeInfo)
	{
		TCascadeSetToCM tCascadeSet;
		if (GetCascadeSetFromJson(pjCascadeInfo, tCascadeSet))
		{
			tConfAttrb.SetSupportCascade((tCascadeSet.m_byCascadeMode == 1) ? TRUE : FALSE);
			tConfAttrb.SetConfDisPlaySpySrc((tCascadeSet.m_byIsUpload == 1) ? TRUE : FALSE);
			//�ش�����*1024
			u32 dwSndSpyBandWidth  = tCascadeSet.m_dwSpyBW*1024;
			tConfAttrb.SetSndSpyBandWidth(dwSndSpyBandWidth);
			tConfAttrb.SetSupportMultiSpy((tCascadeSet.m_byIsSpy == 1) ? TRUE : FALSE);
		}
	}

	// CapSupport CapSupportEx
	tCapSupport.SetDStreamType(VIDEO_DSTREAM_H264_H239);
	tCapSupport.SetDStreamMediaType(MEDIA_TYPE_H264);
	tCapSupport.SetDStreamResolution(VIDEO_FORMAT_CIF);			//˫���ֱ���
	tCapSupport.SetDStreamFrmRate(VIDEO_FPS_2997_1);			//֡��
	//tMain.SetAudioMediaType(MEDIA_TYPE_G7221C);				//��Ƶ����
	tMain.SetVideoFrameRate(VIDEO_FPS_2997_1);					//֡��
	tCapSupport.SetMainSimCapSet(tMain);
	tCapSupport.SetSecondSimCapSet(tSecond);
	//tCapSupportEx.SetMainAudioSubType(MEDIA_TYPE_G7221C_SUBTYPE_24K);		//��Ƶ��ģʽ  todo
	tConfInfo.SetCapSupport(tCapSupport);
	//	tConfInfo.SetCapSupportEx( tCapSupportEx );   todo

	tConfAttrb.SetPrsMode(TRUE);
	tConfAttrb.SetReleaseMode(CONF_RELEASEMODE_NOMT);

	tConfAttrb.SetIsOccupyVPU(TRUE);
	tConfAttrb.SetOccupyVpuType(TConfAttrb::em_Occupy_16);

	tConfInfo.SetConfAttrb(tConfAttrb);
	
	return TRUE;
}

/*=============================================================================
�� �� ���� GetConfInfoFromJson
��    �ܣ� Jsonת��ΪTConfInfo��δ���ýṹ�ڲ���GUID��DomainName
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static BOOL32 GetConfInfoFromJson(const s8 * pchJsonBuf, TConfInfo & tConfInfo )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetConfInfoFromJson] pchJsonBuf is NULL, retur FALSE!\n" );
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetConfInfoFromJson] json_loads err!\n" );
		return FALSE;
	}

	return GetConfInfoFromJson(pjRoot, tConfInfo);
}

#define SetSpeakerAliasToJsonObj(pjObj, tSpeaker) SetStringToJson(pjObj, JSON_SPEAKERALIAS, tSpeaker.m_achAlias)

#define SetChairAliasToJsonObj(pjObj, tChair) SetStringToJson(pjObj, JSON_CHAIRMANALIAS, tChair.m_achAlias)

#define SetCreatorNameToJsonObj(pjObj, abyCreator) SetStringToJson(pjObj, JSON_CREATORNAME, abyCreator)

#define SetConfMaxJoinedMtNumToJsonObj(pjObj, mtNum) SetUIntAsStringToJson(pjObj, JSON_MAXJOINEDMT, mtNum)

#define SetConfDurationToJsonObj(pjObj, confDuration) SetUIntAsStringToJson(pjObj, JSON_DURATION, confDuration)

/*=============================================================================
�� �� ���� SetConfInfoToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         ��Ҳ                    ����
=============================================================================*/
static void SetConfInfoToJson(s8 * pchJsonBuf, u32 &dwJsonBufLen, TConfInfo tConfInfo/*, s32 nMeetingId*/)
{
	json_t_ptr pjRoot = NULL;
	if (!LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE)) return;

	s8 achTmpBuf[256] = { 0 };
	u8 byTmp = 0;

	// ConfE164
	SetConfE164ToJsonObj(pjRoot, tConfInfo.GetConfE164());

	// ConfName
	SetConfNameToJsonObj(pjRoot, tConfInfo.GetConfName());

	// CreatorName
	SetCreatorNameToJsonObj(pjRoot, tConfInfo.GetCreaterAlias());

	// ����
	SetStringToJson(pjRoot, JSON_DOMAINNAME, tConfInfo.GetDomainName());

	// ��Moid
	SetStringToJson(pjRoot, JSON_MOID, tConfInfo.GetDomainMoid());

	//confid
	s8 achConfId[MAXLEN_CONFID * 2 + 1] = { 0 };
	tConfInfo.GetConfId().GetConfIdString(achConfId, sizeof(achConfId));
	SetStringToJson(pjRoot, JSON_CONFID, achConfId);

	// �Ƿ�˿ڻ���
	SetBoolAsStringToJson(pjRoot, JSON_ISPORTCONF, tConfInfo.GetConfAttrb().IsPortMediaConf());

	// ��������
	SetStringToJson(pjRoot, JSON_PSW, tConfInfo.GetConfPwd());

	// ����
	SetUIntAsStringToJson(pjRoot, JSON_BANDWIDTH, tConfInfo.GetBitRate());

	// �ֱ���
	SetUIntAsStringToJson(pjRoot, JSON_RES, tConfInfo.GetMainVideoFormat());

	// ����ʱ��
	SetConfDurationToJsonObj(pjRoot, tConfInfo.GetDuration());

	// ��������ģʽ
	SetUIntAsStringToJson(pjRoot, JSON_ENCRYPTMODE, tConfInfo.GetConfAttrb().GetEncryptMode());

	memset(achTmpBuf, 0, sizeof(achTmpBuf));
	s32 nTmpLen = 0;
	tConfInfo.GetMediaKey().GetEncryptKey((u8*)achTmpBuf, &nTmpLen);
	// �Զ�����
	SetBoolAsStringToJson(pjRoot, JSON_ENCRYPT_MANUAL, nTmpLen == 0);

	// ����������Կ
	SetStringToJson(pjRoot, JSON_ENCRYPTKEY, achTmpBuf);

	// ��ϯ
	SetChairAliasToJsonObj(pjRoot, tConfInfo.GetChairAlias());

	// ������
	SetSpeakerAliasToJsonObj(pjRoot, tConfInfo.GetSpeakerAlias());

	// ����ģʽ
	SetUIntAsStringToJson(pjRoot, JSON_MIXMODE, tConfInfo.GetStatus().GetMixerMode());
	// ����ģʽ
	if (tConfInfo.GetStatus().GetMixerMode() == mcuVacMix || 
		tConfInfo.GetStatus().GetMixerMode() == mcuVacPartMix ||
		tConfInfo.GetStatus().GetMixerMode() == mcuVacWholeMix)
	{
        SetUIntAsStringToJson(pjRoot, JSON_VACINTERVAL, tConfInfo.GetTalkHoldTime());
	}
	else
	{
		SetUIntAsStringToJson(pjRoot, JSON_VACINTERVAL, 0);
	}

	// ��ʼ����
	SetBoolAsStringToJson(pjRoot, JSON_ALLMUTE, tConfInfo.GetConfAttrb().IsAllInitDumb());

	// ��ʼ����
	SetBoolAsStringToJson(pjRoot, JSON_ALLSILENCE, tConfInfo.GetConfAttrb().IsAllInitSilence());

	// ˫������ģʽ
	SetUIntAsStringToJson(pjRoot, JSON_DUALMODE, tConfInfo.GetConfAttrb().GetDualMode());

	//�����˵�Դ
	SetUIntAsStringToJson(pjRoot, JSON_SPEAKERSRC, tConfInfo.GetConfAttrb().GetSpeakerSrc());

	// ����ģʽ
	SetUIntAsStringToJson(pjRoot, JSON_CALLMODE, tConfInfo.m_tStatus.GetCallMode());

	// ���м��
	SetUIntAsStringToJson(pjRoot, JSON_CALLINTERVAL, tConfInfo.m_tStatus.GetCallInterval());

	// ���д���
	SetUIntAsStringToJson(pjRoot, JSON_CALLTIMES, tConfInfo.m_tStatus.GetCallTimes());

	// �Ƿ񹫿�����
	SetUIntAsStringToJson(pjRoot, JSON_PUBLISHCONF, tConfInfo.GetConfAttrb().GetPublicConf());
	// ���鿪������
	switch (tConfInfo.GetConfAttrb().GetOpenMode())
	{
	case CONF_OPENMODE_CLOSED:
		byTmp = 0;
		break;
	case CONF_OPENMODE_OPEN:
		byTmp = 1;
		break;
	default:
		byTmp = 1;
		break;
	}
	SetUIntAsStringToJson(pjRoot, JSON_OPENMODE, byTmp);
	// �ն������
	SetBoolAsStringToJson(pjRoot, JSON_NODISTURB, tConfInfo.GetConfAttrb().IsConfNoDisturb());
	// ��Ƶ����
	SetBoolAsStringToJson(pjRoot, JSON_VIDEOPRIOR, tConfInfo.GetConfAttrb().IsQualityPri());
	// �Ƿ��л���ϳ�ģ��
	SetBoolAsStringToJson(pjRoot, JSON_VMPMODULE, tConfInfo.GetConfAttrb().IsHasVmpModule());
	// �Ƿ�����ѯģ��
	SetBoolAsStringToJson(pjRoot, JSON_POLLMODULE, tConfInfo.GetConfAttrb().IsHasPollModule());
	// �Ƿ��л���ģ��
	SetBoolAsStringToJson(pjRoot, JSON_MIXMODULE, tConfInfo.GetConfAttrb().IsHasMixModule());
	// �Ƿ��е���ǽģ��
	SetBoolAsStringToJson(pjRoot, JSON_HDUMODULE, tConfInfo.GetConfAttrb().IsHasTvWallModule());
	//�Ƿ�����������
	SetBoolAsStringToJson(pjRoot, JSON_ISVOICEINSPIRE, tConfInfo.GetConfAttrb().GetVoiceInspireEnable());

	// �Ƿ�����xmpu������
	SetHasXmpuSerToJsonObj(pjRoot, tConfInfo.GetConfAttrb().IsHasXmpuSer());

	memset(achTmpBuf, 0, sizeof(achTmpBuf));
	tConfInfo.GetKdvStartTime().GetString(achTmpBuf, 20);
	// ���鿪ʼʱ��
	SetStringToJson(pjRoot, JSON_CONFSTARTTIME, achTmpBuf);

	memset(achTmpBuf, 0, sizeof(achTmpBuf));
	u32 dwEndtime = (u32)(tConfInfo.GetStartTime() + tConfInfo.GetDuration() * 60);
	tConfInfo.SetStartTime(dwEndtime);
	tConfInfo.GetKdvStartTime().GetString(achTmpBuf, 20);
	// �������ʱ��
	SetStringToJson(pjRoot, JSON_CONFENDTIME, achTmpBuf);

	// ����ն�������
	SetConfMaxJoinedMtNumToJsonObj(pjRoot, tConfInfo.GetMaxJoinedMtNum());

	// ��һ����
	SetBoolAsStringToJson(pjRoot, JSON_ONEREFORMING, tConfInfo.GetConfAttrb().IsAdjustUniformPack());

	// ������Ϣ
	TCascadeSetToCM tCascadeSet;
	tCascadeSet.m_byCascadeMode = tConfInfo.GetConfAttrb().IsSupportCascade() ? 1 : 0;
	tCascadeSet.m_byIsUpload = tConfInfo.GetConfAttrb().IsConfDisPlaySpySrc() ? 1 : 0;
	tCascadeSet.m_byIsSpy = tConfInfo.GetConfAttrb().IsSupportMultiSpy() ? 1 : 0;
	tCascadeSet.m_dwSpyBW = tConfInfo.GetConfAttrb().GetSndSpyBandWidth();
	json_t_ptr pjCascadeInfo = CreatCascadeSetJson(tCascadeSet);
	if (NULL != pjCascadeInfo)
	{
		json_object_set_s(pjRoot, JSON_CASCADECONF, pjCascadeInfo);
	}

	//���ǻ�������
	json_t_ptr pjSatConfig = CreatSatConfigJson(tConfInfo.GetConfAttrb().IsSatDCastMode(),
												tConfInfo.GetConfAttrb().GetSatDCastIp(),
												tConfInfo.GetConfAttrb().GetSatDCastPort(),
												tConfInfo.GetConfAttrb().GetSatReturnNum());
	if (NULL != pjSatConfig)
	{
		json_object_set_s(pjRoot, JSON_SATCONF, pjSatConfig);
	}

	//vmp��Ϣ
// 	TVMPParam tVmpParam = tConfInfo.m_tStatus.GetVmpParam();
// 	json_t_ptrpjVmpParam = CreatVmpParamSetJson(tVmpParam);
// 	if (pjVmpParam != NULL)
// 	{
// 		json_object_set_new( pjRoot, JSON_VMPPARAM, pjVmpParam );
// 	}
	//mix��Ϣ
// 	TMixParam tMixParam = tConfInfo.m_tStatus.GetMixerParam();
// 	json_t_ptrpjMixParam = CreatMixParamSetJson(tMixParam);
// 	if (pjMixParam != NULL)
// 	{
// 		json_object_set_new( pjRoot, JSON_MIXPARAM, pjMixParam );
// 	}

	DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

/*=============================================================================
�� �� ���� SetEndAllSubConfToJson
��    �ܣ� 
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� void
�� �� ֵ�� void 
----------------------------------------------------------------------
�޸ļ�¼    ��
��  ��		�汾		�޸���		�߶���    �޸�����
2014/08/26  5.0         �ܹ��                    ����
=============================================================================*/
#define SetEndAllSubConfToJsonObj(pjRoot, bEndAll) SetBoolAsStringToJson(pjRoot, JSON_ENDALLSUBCONF, bEndAll)

static BOOL32 SetEndAllSubConfToJson( s8 * pchJsonBuf, u32 &dwJsonBufLen, const BOOL32 bEndAll )
{	
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetEndAllSubConfToJsonObj(pjRoot, bEndAll));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

static BOOL32 GetEndAllSubConfFromJson( s8 * pchJsonBuf, BOOL32 &bEndAll )
{
	if ( NULL == pchJsonBuf )
	{
		OspPrintf( TRUE, FALSE, "[GetEndAllSubConfFromJson] Param is NULL, return FLASE!\n" );
		return FALSE;
	}
	
	json_error_t jReason;
	json_t_ptr pjRoot = json_loads( pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason );
	if ( NULL ==  pjRoot )
	{
		OspPrintf( TRUE, FALSE, "[GetEndAllSubConfFromJson] json_loads err, retur FALSE!\n" );
		return FALSE;
	}
	
	json_t_ptr pjEndAll = json_object_get_s( pjRoot, JSON_ENDALLSUBCONF );
	if ( NULL == pjEndAll )
	{
		OspPrintf( TRUE, FALSE, "[GetEndAllSubConfFromJson] json_object_get endallsubconf is NULL, retur FALSE!\n" );
		return FALSE;
	}
	
	bEndAll = (atoi( json_string_value( pjEndAll ) ) == 0) ? FALSE : TRUE;
	
	return TRUE;
}

static BOOL32 GetVipMtListFromJson(json_t_ptr pjRoot, u8 * atVipIdx, u16 wVipNum)
{
	if (!pjRoot)
	{
		return FALSE;
	}
	// vip�ն��б�
	json_t_ptr pjVipMtArray = json_object_get_s(pjRoot, JSON_VIPMT);
	if (NULL == pjVipMtArray)
	{
		LogPrint(LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetVipMtListFromJson] json_object_get VipMtArray is NULL!\n");
		return FALSE;
	}

	u16 wMtNum = getmin(json_array_size(pjVipMtArray), wVipNum);
	u16 wMtIdx = 0;
	for (wMtIdx = 0; wMtIdx < wMtNum; wMtIdx++)
	{
		json_t_ptr pjVipMtInfo = json_array_get_s(pjVipMtArray, wMtIdx);
		if (NULL == pjVipMtInfo)
		{
			continue;
		}

		json_t_ptr pjMtIdx = json_object_get_s(pjVipMtInfo, JSON_MTINDEX);
		if (NULL == pjMtIdx)
		{
			continue;
		}

		atVipIdx[wMtIdx] = atoi(json_string_value(pjMtIdx));
	}
	return TRUE;
}

static BOOL32 GetVipMtListFromJson(const s8 * pchJsonBuf, u8 *atVipIdx, u16 wVipNum)
{
	if (NULL == pchJsonBuf || NULL == atVipIdx)
	{
		LogPrint(LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetVipMtListFromJson]Param is NULL, return!\n");
		return FALSE;
	}

	json_error_t jReason;
	json_t_ptr pjRoot = json_loads(pchJsonBuf, JSON_DISABLE_EOF_CHECK, &jReason);
	if (NULL == pjRoot)
	{
		LogPrint(LOG_LVL_ERROR, MID_MCU_MAUSSN, "[GetVipMtListFromJson] json_loads err!\n");
		return FALSE;
	}

	BOOL32 bRet = GetVipMtListFromJson(pjRoot, atVipIdx, wVipNum);

	return bRet;
}

static BOOL32 SetVipMtListToJsonObj(json_t_ptr pjRoot, u8 * atVipIdx, u16 wVipNum)
{
	if (NULL == pjRoot)
	{
		OspPrintf(TRUE, FALSE, "[SetVipMtListFromJson]pjRoot is NULL, retur!\n");
		return FALSE;
	}

	json_t_ptr pjVipMtArray = json_array();
	if (NULL == pjVipMtArray)
	{
		OspPrintf(TRUE, FALSE, "[SetVipMtListFromJson] json_object VmpMtArray is NULL!\n");
		return FALSE;
	}
	else
	{
		u16 wChnIdx = 0;
		for (wChnIdx = 0; wChnIdx < wVipNum; wChnIdx++)
		{
			if (atVipIdx[wChnIdx] == 0)
			{
				continue;
			}

			json_t_ptr pjVipMtObj = json_object();
			if (NULL == pjVipMtObj)
			{
				OspPrintf(TRUE, FALSE, "[CreatVmpParamSetJson] json_object VmpMtObj is NULL!\n");
				continue;
			}

			SetUIntAsStringToJson(pjVipMtObj, JSON_MTINDEX, atVipIdx[wChnIdx]);

			json_array_append_s(pjVipMtArray, pjVipMtObj);
		}
	}
	json_object_set_s(pjRoot, JSON_VIPMT, pjVipMtArray);

	return TRUE;
}

static BOOL32 SetVipMtListToJson(s8 * pchJsonBuf, u32 &dwJsonBufLen, u8 *atVipIdx, u16 wVipNum)
{
	json_t_ptr pjRoot = NULL;
	ReturnIfFailed(LoadJson(pchJsonBuf, dwJsonBufLen, pjRoot, TRUE));
	ReturnIfFailed(SetVipMtListToJsonObj(pjRoot, atVipIdx, wVipNum));
	return DumpJson(pjRoot, pchJsonBuf, MAXLEN_JSONBUF, dwJsonBufLen);
}

#endif  // _JSON_TRANSLATE_H_
