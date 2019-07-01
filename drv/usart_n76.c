#include "main.h"
 //WIFI-DMX.COM
xdata DMX_TypeDef DMX_RegStructure;
xdata DMX_Type DMX_Reg;

void DMX512_Receive(DMX_TypeDef xdata *DMX,DMX_Type xdata *D,uint8_t xdata schang)
{
	if (RI) 
	{                                    
		clr_RI;                          
		if(RB8 == 0){
			D->UDR = SBUF;
		}
		else{
			D->UDR = SBUF|0x0100;		
		}

		if (((D->UDR & 0x0100) == 0)&&(RUN_State==RUN_Normal)){  
			if(!(D->UDR&0x00ff)){
				D->aFlagMark = Signal_Dmx;	
				D->pDMXData  = 0;D->pAddrData = 0;D->pRDMData = 0;		 
			}
			else if((D->UDR&0x00ff)==DMXAutoReceiveMark){
				D->aFlagMark = Signal_Slave;
				D->pDMXData  = 0;D->pAddrData = 0;D->pRDMData = 0;
				DMXCRC_Slave=0;
				if(SYS_State!=SYS_Slave){	
					if(D->DMX_Chang_Mark++>6)Task_Cmd(&Task_st[TMotoZ],&Task_MotoZ,TaskEnable,Task_Null);		   
				}
			}else D->DMX_Chang_Mark=0;
		}
		else if(D->aFlagMark == Signal_Dmx){
			if(D->pAddrData == 0) {
				if((D->UDR&0x00ff)!= 0){ 
					D->aFlagMark = Signal_Null; //error, reset flag
					D->DMX_Chang_Mark=0;
				}
				else{
					if(SYS_State!=SYS_Dmx){			    
						if(D->DMX_Chang_Mark++>6)Task_Cmd(&Task_st[TDMXUpdate],&Task_DMXUpdate,TaskEnable,Task_Null);					
					}
					//if(D->DMX_Chang_Mark++>6){if((MainNormal()&&(DMX->DMXChange != schang))){SystemNum=BackSystemTime+1;}DMX->DMXChange = schang;}				
				}
			}

//			DMX->dmx_Recv_data[D->pAddrData]= (uint8_t)D->UDR; 
						
			if(++D->pAddrData>=Memory_Struct.Memory_Addr){
				if(D->pDMXData <= Memory_Struct.Memory_Chan)DMX->DMXReceiveNow[D->pDMXData++] = (uint8_t)D->UDR; 
			}	
			//接收到512个数据		
			if ((D->pDMXData > Memory_Struct.Memory_Chan)||(D->pAddrData > 512)){
				if((schang)||(D->pAddrData > 512)){
					D->aFlagMark = Signal_Null;
					D->pAddrData = 0;
					if(D->pDMXData > Memory_Struct.Memory_Chan){
						Task_Cmd(&Task_st[TDMXUpdate],&Task_DMXUpdate,TaskEnable,&Task_Null);
					}				
				}
			}	
		} 
		else if(D->aFlagMark == Signal_Slave){			   		
			if(D->pAddrData<D485_SLAVE){			
				DMX->DMXReceiveNow[D->pAddrData++]=(uint8_t)D->UDR;	
				if(D->pAddrData<=DMX_CRC)DMXCRC_Slave=DMXCRC_Slave+DMX->DMXReceiveNow[D->pAddrData-1];			  		  
			}
			else{
				D->aFlagMark = Signal_Null;
				D->pAddrData = 0;
				if(DMX->DMXReceiveNow[DMX_CRC]==DMXCRC_Slave)Task_Cmd(&Task_st[TMotoZ],&Task_MotoZ,TaskEnable,Task_Null); 
				//if(D->DMX_Chang_Mark++>6){if((MainNormal()&&(DMX->DMXChange != schang))){SystemNum=BackSystemTime+1;}DMX->DMXChange = schang;}  
			}
		}	
	}

	if(TI)
	{
		clr_TI;                          
	 	  
		if(D->DMXTxCounter<D485_MASTER){
			if(D->DMXTxCounter<DMX_CRC)DMXCRC=DMXCRC+DMX->DMXTransmitNow[D->DMXTxCounter];
		    if(D->DMXTxCounter==DMX_CRC){
				SendData(DMXCRC);
				D->DMXTxCounter++;
			}
			else
			SendData(DMX->DMXTransmitNow[D->DMXTxCounter++]);
		}
		else{
			D->DMXTxCounter=0;
			DMX512_Slave; 
			D->DMXTransmitFinish=1;
		}			  
	}

}


