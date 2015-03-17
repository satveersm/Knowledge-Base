@ TABLE OBEE11G_PROXY_ACTAS 
@ ( 
@ PROXY_USER_ID   VARCHAR2(30 BYTE) NOT NULL , 
@ PROXY_TARGET_ID VARCHAR2(30 BYTE) NOT NULL , 
@ PROXY_LEVEL     VARCHAR2(10 BYTE) NOT NULL , 
@ CONSTRAINT OBEE11G_PROXY_ACTAS_PK PRIMARY KEY ( PROXY_USER_ID , 
@ PROXY_TARGET_ID ) 
@ ENABLE 
@ ); 
@ . 
@ Create session variable PROXY and link this to PROXY_BLOCK initialization 
@ block and use below sql in edit source 
@ . 
@ SELECT PROXY_TARGET_ID 
@ FROM OBEE11G_PROXY_ACTAS 
@ WHERE UPPER(PROXY_USER_ID) = UPPER(':USER') 
@ AND UPPER(PROXY_TARGET_ID) = UPPER('VALUEOF(NQ_SESSION.RUNAS)') 
@ . 
@ Create session variables PROXYLEVEL and link this to PROXYLEVEL_BLOCK 
@ and use sql 
@ . 
@ . 
@ SELECT PROXY_LEVEL 
@ FROM OBEE11G_PROXY_ACTAS 
@ WHERE UPPER(PROXY_TARGET_ID) = UPPER('VALUEOF(NQ_SESSION.RUNAS)') 
@ AND  UPPER(PROXY_USER_ID) = UPPER('VALUEOF(NQ_SESSION.RUNASORIGUSER)') 
@ . 
@ . 
@ Create LogonParamSQLTemplate.xml @ 
@ BI_DIR\Oracle_BI1\bifoundation\web\msgdb\customMessages\ 
@ . 
@ . 
@ <?xml version="1.0" encoding="utf-8" ?> 
@ <WebMessageTables xmlns:sawm="com.siebel.analytics.web.messageSystem"> 
@  <WebMessageTable system="SecurityTemplates" table="Messages"> 
@    <WebMessage name="LogonParamSQLTemplate"> 
@       <XML> 
@        <logonParam name="RUNAS"> 
@        <!-- for EXECUTE PHYSICAL CONNECTION POOL, SQL_Paint.SQL_Paint =  --> 
@        <!-- SAS Repository physical_dbname.conn_pool_name --> 
@          <getValues>EXECUTE PHYSICAL CONNECTION POOL 
@ "DataSourceName"."ConnectionPoolName" 
@                   select PROXY_TARGET_ID from OBEE11G_PROXY_ACTAS where 
@ PROXY_USER_ID='@{USERID}' 
@          </getValues> 
@          <verifyValue> EXECUTE PHYSICAL CONNECTION POOL 
@ "DataSourceName"."ConnectionPoolName" 
@                   select PROXY_TARGET_ID from OBEE11G_PROXY_ACTAS where 
@ PROXY_USER_ID='@{USERID}' and PROXY_TARGET_ID='@{VALUE}' 
@          </verifyValue> 
@          <getDelegateUsers>EXECUTE PHYSICAL CONNECTION POOL 
@ "DataSourceName"."ConnectionPoolName" 
@                   select PROXY_USER_ID, PROXY_LEVEL from OBEE11G_PROXY_ACTAS 
@ where PROXY_TARGET_ID='@{USERID}' 
@          </getDelegateUsers> 
@        </logonParam> 
@     </XML> 
@   </WebMessage> 
@  </WebMessageTable> 
@ </WebMessageTables> 
@ . 
@ . 
@ //Update instanceconfig.xml file placed in   
@ instances\instances\config\OraclePresentationServicesComponenet\........ 
@ . 
@ other things r same. 
@ . 
@ //To restrict subject area visiblity use user name in rpd Presentation layer 
@ No access option 
@ . 
@ . 
