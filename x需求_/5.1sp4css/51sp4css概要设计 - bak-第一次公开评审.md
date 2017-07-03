---
typora-root-url: 5.1sp4css概要设计visio图
---

# 5.1sp4CSS概要设计

[TOC]

##1 基础功能移交会管
###1.1 会议重命名检测与修改

### 1.1.1 波及

> 会管通过个人模板创会
>
> 会管立即召开预约会议
>
> 会管通过公共模板创会
>
> 终端直接创会
>
> 终端通过公共模板创会
>
> 终端提前召开预约会议
>
> 跨域呼叫预分配号个人模板




###1.2 会议E164号分配
####1.2.1波及CSS上报UPU会议e164
>预约会议
>预分配e164个人模板
>固定虚拟会议室 

方案1

| REDIS数据结构 | key                   | field | value            |
| --------- | --------------------- | ----- | ---------------- |
| set       | bookconfs             |       | 预约会议E164         |
| hash      | bookconf/e164         | moid  | 预约会议所属用户域MOID    |
| set       | personaltemplates     |       | 预分配个人模板E164      |
| hash      | personaltemplate/e164 | moid  | 个人模板所属用户域MOID    |
| set       | virtualconfs          |       | 固定虚拟会议室E164      |
| hash      | virtualconf           | moid  | 固定虚拟会议室所属用户域MOID |


新增预约会议:
删除预约会议:
新增预分配个人模板:
删除预分配个人模板:
新增固定虚拟会议室:
删除固定虚拟会议室:
publish 频道: e164_notify 

```json
{
  "conftype" : "1/2/3/4", //1正召开会议,2预约会议,3预分配会议个人模板,4固定虚拟会议室
  "confe164" : "",
  "moid" : "", //用户域MOID
  "operator" : "add/delete"
}
```
当前css所用acl::redis库订阅推送功能存在漏消息问题

方案2

![会馆公示e164方案3](/会馆公示e164方案3.png)

```json
{
    "type" : "CM_MAU_ALLE164_NTF",
    "bookconfs" : [{"e164" :"", "moid":""}, ...], 
    "personaltemplates" : [{"e164" :"", "moid":""}, ...],
    "virtualconfs" : [{"e164" :"", "moid":""}, ...]
}
```

```json
{
  "type" : "CM_MAU_E164_NTF",
  "conftype" : "1/2/3/4", //1正召开会议,2预约会议,3预分配会议个人模板,4固定虚拟会议室
  "confe164" : "",
  "moid" : "",   //所归属用户域MOID
  "operator" : "add/delete"
}
```


方案3

![会馆公示e164方案3](/会馆公示e164号方案2.png)

```json
{
  "type" : "GET_E164_REQ",
  "routingkey" : "", //会管回复地址
  "platformdomainmoid" : "",
}
```

```json
{
    "type" : "GET_E164_ACK",
    "bookconfs" : [{"e164" :"", "moid":""}, ...], 
    "personaltemplates" : [{"e164" :"", "moid":""}, ...],
    "virtualconfs" : [{"e164" :"", "moid":""}, ...]
}
```

```json
{
    "type" : "GET_E164_NACK",
  	"errcode" : ""
}
```

```json
{
  "type" : "E164_NTF",
  "conftype" : "1/2/3/4", //1正召开会议,2预约会议,3预分配会议个人模板,4固定虚拟会议室
  "confe164" : "",
  "moid" : "",   //所归属用户域MOID
  "operator" : "add/delete"
}
```



###1.3公共模板数据移交会管

####1.3.1 波及终端通过公共模板创会
####1.3.2 波及会管直接通过公共模板创会
时序图

![会馆直接通过公共模板创会时序图](/会馆直接通过公共模板创会时序图.png)

历史CSS所维护公共模板数据存储于mpcddb数据库ttemplateinfo表



##2 终端获取会议数量流程

### 2.1 方案1

![终端获取会议数量](/终端获取会议数量.png)

NPPCLIENT缓存终端信息(读取AP数据库和BMC MQ通知)

### 2.2 方案2

![终端获取会议数量—方案2](/终端获取会议数量—方案2.png)

#### 2.2.1 新增NPPCLIENT_CM_GETMTINFO_REQ
消息定义

```json
{
  "type" : "NPPCLIENT_CM_GETMTINFO_REQ",
  "mtNO" : "", //终端E164
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_GETMTINFO_ACK",
  "mtNO" : "", //终端E164
  "mtmoid" : "", //终端MOID
  "moid" : "", //终端所属用户域moid
  "name" : "" //终端别名
  "limited" : "" //是否受限终端
}
```

```json
{
  "type" :　"CM_NPPCLIENT_GETMTINFO_NACK",
  "mtNO" : "",
  "errcode": "",
}
```

### 2.3 错误码

> 29501 //会管内部错误(终端不存在/域信息错误/解析JSON错误/数据库错误/其他错误) 



##3 终端获取会议列表流程

###3.1 终端获取正在召开会议列表

方案1

![终端获取正召开会议列表2](/终端获取正召开会议列表2.png)

方案2

![终端获取正召开会议列表](/终端获取正召开会议列表.png)



###3.2 终端获取预约会议列表流程

####3.2.1 时序图

![终端获取预约会议时序图](/终端获取预约会议时序图.png)


####3.2.2 新增NPPCLIENT到会管消息
消息定义：

```json
{
  "type" :　"NPPCLIENT_CM_GETBOOKCONFLIST_REQ",
  "moid" : "", //终端所在用户域MOID
}
```

```json
{
  "type" :　"CM_NPPCLIENT_GETBOOKCONFLIST_ACK",
  "bookconflist" :
  [
    {
       "confname" :　"",
 	   "confE164" : "",
       "mtnum" :　"",
       "openmode" : "",
       "mediatype":"",
	   "mediabitrate":"",   
	   "mediares":"",
       "publicconf" : "",
       "psw" : "",
       "starttime" : ""
    },
    ...
  ]
}
```

```json
{
  "type" :　"CM_NPPCLIENT_GETBOOKCONFlIST_NACK",
  "errcode": ""
}
```
####3.2.3 待确认
> 是否需要分包(一条MQ消息大概支持380个预约会议)
>



###3.3 终端获取公共模板
####3.3.1 时序图

![终端获取公共模板列表时序图](/终端获取公共模板列表时序图.png)

####3.3.2 新增NPPCLIENT到会管消息
消息定义

```json
{
  "type" : "NPPCLIENT_CM_GETTEMPLATECONFLIST_REQ",
  "moid" : "", //终端所在用户域MOID
}
```

```json
{
  "type" : "CM_NPPCLIENT_GETTEMPLATECONFLIST_ACK",
  "templateconflist" :
  [
    {
       "confname" :　"",
 	   "confE164" : "",
       "mediatype":"",
	   "mediabitrate":"",   
	   "mediares":"",
       "publicconf" : "",
       "psw" : "",
    },
    ...
  ]
}
```

```json
{
  "type" : "CM_NPPCLIENT_GETTEMPLATECONFLIST_NACK",
  "errcode" : ""
}
```

####3.3.3.其他

> 一个平台最多100个公共模板, 无需分包



###3.4 老终端获取全部会议列表

方案1

![2.5终端获取所有会议列表-数据结构](/2.5终端获取所有会议列表-数据结构.png)

![2.5终端获取所有会议列表](/2.5终端获取所有会议列表.png)

#### 3.4.1 虚拟会议室波及

经需求确认： 2.5终端获取所有会议 无需发送固定虚拟会议室列表



####3.5 错误码

> 29501 //会管内部错误 




##4 终端获取会议详情流程
###4.1 终端获取正召开会议详情

![终端获取正召开会议详情](/终端获取正召开会议详情.png)



###4.2 终端获取预约会议或公共模板详情

####4.2.1 时序图
![终端获取预约会议或公共模板详情](/终端获取预约会议或公共模板详情.png)

####4.2.2 新增NPPCLIENT到会管消息
消息定义：
```json
{
  "type" :　"NPPCLIENT_CM_GETCONFDETAIL_REQ",
  "confE164" : "",
}
```

```json
{
  "type" :　"CM_NPPCLIENT_GETCONFDETAIL_ACK",
  "guid" : "",
  "moid" : "",
  "domainname" : "",
  "confE164" : "",
  "confname" : "",
  "mediatype":"",
  "mediabitrate":"",   
  "mediares":"",
  "openmode" : "",
  "publicconf" : "",
  "dualmode" : "",
  "nodisturb" : "",
  "maxjoinedmt" : "",
  "mixmode" : "",
  "psw" : "",
  //预约会议特有(公共模板时填空值)
  "starttime" : "",
  "endtime" : "",
  "creatorname" : "",
  //用于终端提前召开预约会议(公共模板时填空值)
  "speakeralias" : "",
  "chairmanalias" : ""
  //公共模板特有(预约会议时填空值)
  "isportconf" : "",
  "encryptmode" : ""

}
```

```json
{
  "type" :　"CM_NPPCLIENT_GETCONFDETAIL_NACK",
  "confE164" : "",
  "errcode": ""
}
```
####4.2.3 错误码

> 29501 //会管内部错误(终端不存在/域信息错误/解析JSON错误/数据库错误/其他)



##5 终端创会流程
### 5.1 终端直接创会
####5.1.1 时序图

![终端直接创会时序图](/终端直接创会时序图.png)


####5.1.2 新增NPPCLIENT到会管消息

消息定义

```json
{
  "type" : "NPPCLIENT_CM_CREATECONF_REQ",
  "createbymt" : "1" //用于结会时报话单,会管需在CM_MAU_CREATECONF_REQ中带给CSS
  "...." //与CM_MAU_CREATECONF_REQ消息格式相同,会馆可直接传给CSS
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_CREATECONF_ACK",
  "confE164" : "",
}
```

```json
{
  "type" :　"CM_NPPCLIENT_CREATECONF_NACK",
  "errcode": "",
}
```

####5.1.3 错误码

> CSS及MCU回的错误码直接透传

> 29501 //会管内部错误



###5.2 跨域呼叫预分配e164个人模板
####5.2.1 时序图

![终端跨域级联个人模板时序图](/终端跨域级联个人模板时序图.png)

![终端跨域级联个人模板时序图2](/终端跨域级联个人模板时序图2.png)

####5.2.2 新增NPPCLIENT到会管消息

消息定义

```JSON
{
  "type"："NPPCLIENT_CM_CREATECONFBYTEMP_REQ",
  "mtNO" : "",
  "confE164" : "",
  "creatormoid" : "",
  "moid" : "",
  "creatorname" : "", //可能是上级会议E164
  "createbymt" : "1" //用于结会时报话单,会管需在CM_MAU_CREATECONF_REQ中带给CSS
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_CREATECONFBYTEMP_ACK",
  "confE164" : "",
}
```

```json
{
  "type" :　"CM_NPPCLIENT_CREATECONFBYTEMP_NACK",
  "errcode": "",
  "confE164" : ""
}
```
####5.2.3 移交会管功能点

>  租赁环境会议时长为4小时，自建默认为永久会议
>

####5.2.4 错误码

> CSS及MCU回的错误码直接透传

> 29501 //会管内部错误




####5.3 终端提前召开预约会议或通过公共模板创会
####5.3.1 时序图

![正召开会议](/正召开会议.png)

![端提前创建预约会议时序图-正常流程](/终端JOINCONF.png)



####5.3.2 新增NPPCLIENT到会管提前创建预约会议消息
消息定义

```json
{
  "type" : "NPPCLIENT_CM_ADDMT_REQ",
  "addmttype" : "0",
  "confE164" : "",
  "mtNO" : ""
}
```

```json
{
  "type" : "CM_NPPCLIENT_ADDMT_ACK",
  "confE164" : "",
  "mtNO" : ""
}
```

```json
{
  "type" : "CM_NPPCLIENT_ADDMT_NACK",
  "mtNO" : "",
  "confE164" : "",
  "errcode" : ""
}
```

```json
{
  "type"："NPPCLIENT_CM_AHEADBOOKCONF_REQ",
  "mtNO" : "",
  "confE164" : "",
  "creatorname" : "", //如果是手机终端，则其别名是电话号码
  "createbymt" : "1" //用于结会时报话单,会管需在CM_MAU_CREATECONF_REQ中带给CSS  
  //若预约会议的主席和发言人为空，则呼叫终端设置为主席和发言人
  "chairmanalias" : "", //可能不填
  "speakeralias" : "",  //可能不填
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_AHEADBOOKCONF_ACK",
  "confE164" : ""
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_AHEADBOOKCONF_NACK",
  "confE164" : "",
  "errcode": ""
}
```
```json
{
  "type"："NPPCLIENT_CM_CREATEPUBLICCONF_REQ",
  "mtNO" : "",
  "confE164" : "",
  "creatorname" : "", //如果是手机终端，则其别名是电话号码
  "createbymt" : "1" //用于结会时报话单,会管需在CM_MAU_CREATECONF_REQ中带给CSS  
  "duration" : "240" //终端创建公共模板，默认创建时长4小时
  "mt":				//公共模板信息中无终端列表，需要将呼叫终端填入终端列表
  [
	{
		"mtNO":"",
		"mttype":"0",
		"bitrate":"" 
	} 
  ],
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_CREATEPUBLICCONF_ACK",
  "confE164" : ""
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_CREATEPUBLICCONF_NACK",
  "confE164" : "",
  "errcode": ""
}
```
####5.3.3 废弃项

> 若终端不在终端列表中，需要将终端补充进终端列表，如果终端列表已满，则将列表中的最后一个终端替换成呼叫终端，且对应修改VMP,POLL,MIX, VIP终端列表

> 终端提前一个小时创建预约会议，则创建一个小时的临时会议

> 会管添加修改删除预约会议不再下发CSS(CSS不再存储预约会议数据信息)
>
> 会管快速新建预约预约会议并快速马上召开，不带E164号CSS规避策略
>
> 会管添加，修改，删除公共模板不再下发消息给CSS
####5.3.4 待确认

> 终端提前召开预约会议会议时长是原时长 + 提前的时长，而会管点立即召开还是原时长，是否需要统一规格

####5.3.5 错误码
> CSS及MCU回的错误码直接透传

> 29501 //会管内部错误
>
> 29502 // 预约会议不存在，会议也未召开
>
> 29503: //公共模板不存在




##6 NPPCLIENT与会管MQ消息走法

![NU_NPPCLIENT](/NU_NPPCLIENT.png)

NPPCLIENT需保存终端信息
```json
  {
     "protocol" : "",
     "productid" : "",
     "verid" :　"",
     "timeid" : "",
     "mtreqid" : "",
     "mtNO" : ""
  }
```



##7 延长会议时间

方案1

![延长会议时间时序图方案1](/延长会议时间时序图方案1.png)

![延长会议时间方案4](/延长会议时间方案4.png)

消息定义：

```JSON
{
    "type": "CMU_CM_DELAYCONF_REQ",
    "confE164": "0002433",
    "delay": "30",
    "mtreqid": "1"
}
```

```JSON
{
    "type": "CM_CMU_DELAYCONF_ACK",
    "confE164": "0002433",
    "mtreqid": "1"
}
```

```JSON
{
    "type": "CM_CMU_DELAYCONF_NACK",
    "confE164": "0002433",
    "mtreqid": "1",
    "errcode" : ""
}
```



方案2

![延长会议时间方案3](/延长会议时间方案3.png)



经终端需求和MCU组确认，无缩短会议时长实际消息的可能，可以删掉这段代码



##8 虚拟会议室相关

> 创会都走会管，CSS无需通知当前的正召开会议数量
>
> 会管会向BMC请求用户域的LICENSE，CSS也无需发送给会管
>
> 终端通过会管感知虚拟会议室使用情况及限制数
>
> 会管需要公示固定虚拟会议室的E164号码
>
> CSS和UPU新增虚拟会议室类型



##9 创结会相关

> 收到结会通知,CSS不再修改V_MEETING,MEETING数据库
>
> 包括不再有提前召开的预约会议如果结会时还未到点则仍使该会为预约会议逻辑

> 创会成功CSS不再更改V_MEETING, STATE为已召开



##10 HDU相关

>废除MAU_CM_HDULISTBYMOID_NTF，CSS不再上报HDU相关信息
>
>废除CM_MAU_GETHDUINFO_CMD，CM_MAU_SETHDUVOLUME_REQ，CM_MAU_GETHDUINFOBYMOID_REQ，会管不再通过CSS获取HDU信息及控制HDU



### 11 待确认点

> 是否需要校验终端及其用户域是否存在
