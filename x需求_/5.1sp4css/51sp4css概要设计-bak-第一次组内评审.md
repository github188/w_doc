---
typora-root-url: 5.1sp4css概要设计visio图
---

# 5.1sp4CSS概要设计

[TOC]

## 1.会管相关
### 1.1NPPCLIENT与会管MQ消息走法



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




### 1.2会管需新增功能

#### 1.2.1公示预约会议,预分配个人模板,固定虚拟会议室E164号

##### 方案1

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

##### 方案2



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
    "bookconfs" : ["bookconf1E164", ...], 
    "personaltemplates" : ["temp1E164", ...],
    "virtualconfs" : ["virtualconfe164", ...]
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



### 1.3.终端直接创会走会管

#### 1.3.1.时序图

![终端直接创会时序图](/终端直接创会时序图.png)

#### 1.3.2.新增NPPCLIENT到会管消息

##### 消息定义

```json
{
  "type" : "NPPCLIENT_CM_MTCREATECONF_REQ",
   "mtNO" : "", //终端E164
  "...." //与CM_MAU_CREATECONF_REQ消息格式相同,不含创会者别名,创会者MOID由会管填入，所属用户域MOID
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_MTCREATECONF_ACK",
  "confE164" : "",
}
```

```json
{
  "type" :　"CM_NPPCLIENT_MTCREATECONF_NACK",
  "errcode": "",
}
```

#### 1.3.3.其他移交会管功能点

> 需校验该终端账号及其所属用户域在此服务域内是否存在，是否可用

> MEETING, V_MEETING数据库写入会议数据

>  CM_MAU_CREATECONF_REQ消息需增加"createbymt" : "",  //1是由终端触发，0是由会管触发 --用于话单上报, 终端MOID及终端所属用户域MOID也由会管填入--NPPCLIENT  添加
>

#### 1.3.4.错误码

> CSS及MCU回的错误码直接透传

> NPPCLIENT新增错误码：
>
> 29501-29600
>
> 暂定错误码：
>
> 29501: 会管内部错误(终端不存在:域信息错误:解析JSON错误:数据库错误:其他错误) 



### 1.4.预约会议相关

#### 1.4.1.获取终端所在用户域预约会议列表

##### 1.4.1.1.时序图

![终端获取预约会议时序图](/终端获取预约会议时序图.png)


##### 1.4.1.2.新增NPPCLIENT到会管消息
###### 消息定义：

```json
{
  "type" :　"NPPCLIENT_CM_GETBOOKCONFLIST_REQ",
  "mtNO" : "",
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
大概支持380个预约会议

##### 1.4.1.3.所获取会议需满足以下条件

>同终端用户域

>当天预约会议

>若是限制终端，则会议必须是开放会议（publicconf为1)

>终端必须在预约会议终端列表中

##### 1.4.1.4.其他移交会管功能点

> 需校验该终端账号及其所属用户域在此服务域内是否存在，是否可用

##### 1.4.1.5错误码


> 29501: 会管内部错误(终端不存在:域信息错误:解析JSON错误:数据库错误:其他错误) 



#### 1.4.2.终端获取预约会议详情

##### 1.4.2.1.新增NPPCLIENT到会管消息
###### 消息定义：
```json
{
  "type" :　"NPPCLIENT_CM_GETBOOKCONFDETAIL_REQ",
  "mtNO" : "",
  "confE164" : "",
}
```

```json
{
  "type" :　"CM_NPPCLIENT_GETBOOKCONFDETAIL_ACK",
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
  "starttime" : "",
  "endtime" : "",
  "psw" : "",
  "dualmode" : "",
  "creatorname" : "",
  "nodisturb" : "",
  "maxjoinedmt" : "",
  "mixmode" : ""
}
```

```json
{
  "type" :　"CM_NPPCLIENT_GETBOOKCONFDETAIL_NACK",
  "confE164" : "",
  "errcode": ""
}
```
##### 1.4.2.2.所获取预约会议详情需满足

>若是限制终端，则会议必须是开放会议（publicconf为1)

##### 1.4.2.3.移交会管功能点

> 需校验该终端账号及其所属用户域在此服务域内是否存在，是否可用

##### 1.4.2.4错误码

> 29501: 会管内部错误(终端不存在:域信息错误:解析JSON错误:数据库错误:其他错误) 



#### 1.4.3.终端提前召开预约会议

##### 1.4.3.1.时序图

![终端提前创建预约会议时序图-正常流程](/终端提前创建预约会议时序图-正常流程.png)

![终端提前创建预约会议时序图-预约会议已经召开](/终端提前创建预约会议时序图-预约会议已经召开.png)

##### 1.4.3.2.新增NPPCLIENT到会管提前创建预约会议消息

###### .消息定义

```json
{
  "type"："NPPCLIENT_CM_JOINCONF_REQ",
  "mtNO" : "",
  "confE164" : "",
  "psw" : "",   
  "mttype" : "",  
  "phonenumber" : "", //如果是手机终端，则其别名是电话号码，如果不是则为空
  "callbitrate" : ""
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_JOINCONF_ACK",
  "confE164" : ""
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_JOINCONF_NACK",
  "confE164" : "",
  "errcode": ""
}
```

##### 1.4.3.3.移交会管功能点

> 需校验该终端账号及其所属用户域在此服务域内是否存在，是否可用  ---是否有这个必要

> 若主席和发言人为空，需要将呼叫终端设为主席和发言人  ---获取详情进行判断，由nppclient写入

> 若终端不在终端列表中，需要将终端补充进终端列表，如果终端列表已满，则将列表中的最后一个终端替换成呼叫终端，且对应修改VMP,POLL,MIX, VIP终端列表
>
>  CM_MAU_CREATECONF_REQ消息需增加"createbymt" : "",  //1是由终端触发，0是由会管触发 --用于话单上报,终端MOID及其所属用户域MOID也由会管填入  ---由css写入或者会馆生成带入CSS
>
> 如果是手机终端，则终端别名是其电话号码  ---判断出是手机终端，设置终端别名到json
>
> 会管需校验终端所带预约会议密码  ---获取预约会议详情进行校验
>
> 如果会议已经召开，则会管需向MCU发送终端入会消息,且会管需回CM_NPPCLIENT_JOINCONF_ACK或CM_NPPCLIENT_JOINCONF_NACK

##### 1.4.3.4.废弃项

> 终端提前一个小时创建预约会议，则创建一个小时的临时会议

> 会管添加修改删除预约会议不再下发CSS(CSS不再存储预约会议数据信息)
>
> 会管快速新建预约预约会议并快速马上召开，不带E164号CSS规避策略

##### 1.4.3.5.待确认

> 终端提前召开预约会议会议时长是原时长 + 提前的时长，而会管点立即召开还是原时长，是否需要统一规格

##### 1.4.3.6.错误码
> CSS及MCU回的错误码直接透传

> NPPCLIENT新增错误码：
>
> 29501-29600
>
> 暂定错误码：
>
> 29501: 会管内部错误(终端不存在:域信息错误:解析JSON错误:数据库错误:其他错误) 
> 29502: 预约会议不存在，会议也未召开



### 1.5.公共模板相关

#### 1.5.1.获取终端所在用户域的公共模板
#####1.5.1.1时序图

![终端获取公共模板列表时序图](/终端获取公共模板列表时序图.png)

#####1.5.1.2消息定义

```json
{
  "type" : "NPPCLIENT_CM_GETTEMPLATECONFLIST_REQ",
  "mtNO" : "",
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

##### 1.5.1.3.所获取公共模板需满足以下条件

>和终端相同用户域

>如果是限制终端，则公共模板必须是开放会议属性(publicconf为1)

##### 1.5.1.4错误码

> 29501: 会管内部错误(终端不存在:域信息错误:解析JSON错误:数据库错误:其他错误) 



#### 1.5.2.终端获取公共模板详情

##### 1.5.2.1消息定义

```JSON
{
  "type" : "NPPCLIENT_CM_GETTEMPLATECONFDETAIL_REQ",
  "mtNO" : "",
}
```

```JSON
{
  "type" : "CM_NPPCLIENT_GETTEMPLATECONFDETAIL_ACK",
   "guid" : "",
  "moid" : "",
  "domainname" : "",
  "confE164" : "",
  "confname" : "",
  "encryptmode" : "",
  "mediatype":"",
  "mediabitrate":"",   
  "mediares":"",
  "openmode" : "",
  "mixmode" : ""
  "dualmode" : "",
  "publicconf" : "",
  "psw" : "",
  "nodisturb" : "",
  "maxjoinedmt" : "",
  "isportconf" : ""
}
```

```JSON
{
  "type" : "CM_NPPCLIENT_GETTEMPLATECONFDETAIL_NACK",
  "errcode" : "",
}
```

##### 1.5.2.2.所获取公共模板需满足以下条件

>和终端相同用户域

>如果是限制终端，则公共模板必须是开放会议属性(publicconf为1)

##### 1.5.2.3错误码

> 29501: 会管内部错误(终端不存在:域信息错误:解析JSON错误:数据库错误:其他错误) 



#### 1.5.3.会管直接通过公共模板创会

##### 1.5.3.1.时序图

![会管直接通过公共模板创会时序图](/会管直接通过公共模板创会时序图.png)

##### 1.5.3.2.移交会管功能点

> 会管需自己存储公共模板数据(历史CSS所维护公共模板数据存储于mpcddb数据库ttemplateinfo表)
>
> V_MEETING E164号由会管构造并写入
>
> 公共模板无创会时长，会管构造CM_MAU_CREATECONF_REQ需填入用户所选创会时长



#### 1.5.4.终端通过公共模板创会

##### 1.5.4.1.时序图

![终端创建公共模板会时序图](/终端创建公共模板会时序图.png)

##### 1.5.4.2消息定义
```json
{
  "type"："NPPCLIENT_CM_JOINCONF_REQ",
   "mtNO" : "",
  "confE164" : "",
  "psw" : "",
  "mttype" : "",  
  "phonenumber" : "", //如果是手机终端，则其别名是电话号码
  "callbitrate" : ""
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_JOINCONF_ACK",
  "confE164" : ""
}
```

```JSON
{
  "type" :　"CM_NPPCLIENT_JOINCONF_NACK",
  "confE164" : "",
  "errcode": ""
}
```

##### 1.5.4.3移交会管功能点

>  需校验该终端账号及其所属用户域在此服务域内是否存在，是否可用
>
>  MEETING, V_MEETING数据库写入会议数据	
>
>  终端创建公共模板，默认创建时长4小时
>
>  若公共模板有设密码，需校验终端所带密码,若终端所带密码为(d41d8cd98f00b204e9800998ecf8427e)，则无需校验(不发密码的老终端让它直接创会)
>
>  CM_MAU_CREATECONF_REQ消息需增加"createbymt" : "",  //1是由终端触发，0是由会管触发 --用于话单上报,终端MOID及其所属用户域MOID也由会管填入
>
>  公共模板信息中无终端列表，需要将呼叫终端填入终端列表



##### 1.5.4.4错误码

> CSS及MCU回的错误码直接透传

> NPPCLIENT新增错误码：
>
> 29501-29600
>
> 暂定错误码：
>
> 29501: 会管内部错误(终端不存在:域信息错误:解析JSON错误:数据库错误:其他错误) 
> 29503: 公共模板不存在



#### 1.5.5.废弃规格

> 会管添加，修改，删除公共模板不再下发消息给CSS



### 1.6预分配个人模板相关

#### 1.6.1时序图

![终端跨域级联个人模板时序图](/终端跨域级联个人模板时序图.png)

#### 1.6.2消息定义

```JSON
{
  "type"："NPPCLIENT_CM_CREATECONFBYTEMP_REQ",
   "mtNO" : "",
  "confE164" : "",
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
#### 1.6.3移交会管功能点

>  CM_MAU_CREATECONF_REQ消息需增加"createbymt" : "",  //1是由终端触发，0是由会管触发 --用于话单上报,终端MOID及其所属用户域MOID也由会管填入
>
>  租赁环境会议时长为4小时，自建默认为永久会议
>
>  创会者别名为所带终端E164号(其实是上级会议)
>
>  MEETING, V_MEETING数据库写入会议数据
>
>  如果会议已经召开，则会管需向MCU发送终端入会消息,但会管需回CM_NPPCLIENT_CREATECONFBYTEMP_ACK或CM_NPPCLIENT_CREATECONFBYTEMP_NACK

#### 1.6.4错误码

> CSS及MCU回的错误码直接透传

> NPPCLIENT新增错误码：
>
> 29501-29600
>
> 暂定错误码：
>
> 29501: 会管内部错误(终端不存在:域信息错误:解析JSON错误:数据库错误:其他错误) 



### 1.7延长会议时间

方案1

![延长会议时间时序图方案1](/延长会议时间时序图方案1.png)

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

经终端需求和MCU组确认，无缩短会议时长实际消息的可能，可以删掉这段代码





### 1.8虚拟会议室相关

> 创会都走会管，CSS无需通知当前的会议使用情况（会管也会向BMC请求用户域的LICENSE，CSS也无需发送给会管），终端通过会管感知虚拟会议室使用情况及限制数
>
> 会管需要公示固定虚拟会议室的E164号码



### 1.9创会结会相关

> CSS不再修改V_MEETING:STATE, MEETING:ACTUAL_ENDTIME,也不再有提前召开的预约会议如果结会时还未到点则仍使该会为预约会议逻辑

> 创会成功CSS不再更改V_MEETING, STATE为已召开



### 1.10HDU相关

>废除MAU_CM_HDULISTBYMOID_NTF，CSS不再上报HDU相关信息
>
>废除CM_MAU_GETHDUINFO_CMD，CM_MAU_SETHDUVOLUME_REQ，CM_MAU_GETHDUINFOBYMOID_REQ，会管不再通过CSS获取HDU信息及控制HDU



### 1.11.基础功能移交

>会议E164号分配

>会议重命名检测与修改



### 1.12 2.5老终端获取全部会议列表

![2.5终端获取所有会议列表-数据结构](/2.5终端获取所有会议列表-数据结构.png)

![2.5终端获取所有会议列表](/2.5终端获取所有会议列表.png)

### 1.13 终端获取会议数量

![终端获取会议数量](/终端获取会议数量.png)

###1.14 终端获取正在召开会议列表

![终端获取正召开会议列表](/终端获取正召开会议列表.png)