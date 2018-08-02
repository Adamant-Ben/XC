// SessionSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "SessionSocket.h"
#include "XiaoBiLiDlg.h"

// CSessionSocket

CSessionSocket::CSessionSocket(CXiaoBiLiDlg* pDlg)
{
	m_pDlg=pDlg;
	for(int i=0;i<4;i++)
		num_fs_rw[i]=0;
}
CSessionSocket::CSessionSocket()
{
}

CSessionSocket::~CSessionSocket()
{
	m_pDlg=NULL;
}


// CSessionSocket ��Ա����


void CSessionSocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	BYTE buff[1024];
	int ret=0;
	ret=Receive(buff,1024);
	if(ret==ERROR)
	{
		TRACE("ERROR");
	}
	else
	{
		/*CString str,strtemp;
		for(int i=0;i<sizeof(S_UWMU_2_AWMU_EA1)+3;i++)
			{strtemp.Format("%2x ",buff[i]);str+=strtemp;}
		AfxMessageBox(str);*/
		if((buff[0]==0x5A)&&(buff[2]==0x00)&&(buff[3]==0x20))  //����R_20
			m_pDlg->ProcData_CC_R20(buff);
		if((buff[0]==0x5A)&&(buff[2]==0x01)&&(buff[3]==0x20))  //����R_201
			m_pDlg->ProcData_CC_R201(buff);
		if((buff[0]==0x5A)&&(buff[2]==0x08)&&(buff[3]==0x20))  //����R_208
			memcpy(m_pDlg->pdata_r2008,buff,sizeof(AWRU_AWMU_R208));
		if((buff[0]==0x5A)&&(buff[2]==0x00)&&(buff[3]==0x30))  //����R_30
		{
			//AfxMessageBox("R_30����ͷͨ��");
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(buff,sizeof(S_UWMU_2_AWMU_EP));
			if((buff[sizeof(S_UWMU_2_AWMU_EP)]==(BYTE)(crcCheck%256))&&(buff[sizeof(S_UWMU_2_AWMU_EP)+1]==(BYTE)(crcCheck/256)))
			{
				
				//AfxMessageBox("R_30����ͷ��CRCУ��ͨ��");
				m_pDlg->ProcData_SX_R30(buff);
				/*CString str,strtemp;
				for(int i=0;i<10;i++)
				{
					strtemp.Format(" %d",m_pDlg->pdata_r30->communicationStatus[i]);
					str+=strtemp;
				}
				AfxMessageBox(str);*/
				m_pDlg->FuZhi_CC_S02();
				m_pDlg->FuZhi_SCH_S01_R30();
				m_pDlg->SSCCSocket->Send(m_pDlg->sendata_s02,sizeof(AWMU_AWRU_S02)+3);
				m_pDlg->ProcData_FAULT_R30();
				m_pDlg->page1->ShowData_R30();
				m_pDlg->Fuzhu_Test_Show();     //���Խ����ȡ��Ϣ //�����ٶ������ʾ ��ȡ��Ƿ��� ˮ��״̬//���һ���״̬	20180722���ؽ�����Ӷ���ϵͳ״̬		

			}
			else
				AfxMessageBox("����R_30CRCУ�����");
		}
		if((buff[2]==0x07)&&(buff[3]==0x30))  //����R_3007             20170427���
		{
			memcpy(m_pDlg->pdata_r3007,buff,sizeof(S_UWMU_2_AWMU_EA4));
		}
		if((buff[2]==0x06)&&(buff[3]==0x30))  //����R_306
		{
			//AfxMessageBox("R_306����ͷͨ��");
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(buff,sizeof(S_UWMU_2_AWMU_EA3));
			if((buff[sizeof(S_UWMU_2_AWMU_EA3)]==(BYTE)(crcCheck%256))&&(buff[sizeof(S_UWMU_2_AWMU_EA3)+1]==(BYTE)(crcCheck/256)))
			{
				//AfxMessageBox("R_306����ͷ��CRCУ��ͨ��");
				memcpy(m_pDlg->pdata_r306,buff,sizeof(S_UWMU_2_AWMU_EA3));
				m_pDlg->page1->ShowData_R306();
				m_pDlg->page2->ShowData_R306();
				
				/*CString str,strtemp;
				for(int i=0;i<sizeof(S_UWMU_2_AWMU_EA3);i++)
				{
					strtemp.Format(" %02x",buff[i]);
					str+=strtemp;
				}
				AfxMessageBox(str);*/
				
			}
			else
				AfxMessageBox("����R_306CRCУ�����");
		}
		if((buff[0]==0x5A)&&(buff[2]==0x05)&&(buff[3]==0x30))  //����R_305,����ģʽˮ�����ط�������̫������
		{
			//AfxMessageBox("R_305����ͷͨ��");
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(buff,sizeof(S_UWMU_2_DSU_EP));
			if((buff[sizeof(S_UWMU_2_DSU_EP)]==(BYTE)(crcCheck%256))&&(buff[sizeof(S_UWMU_2_DSU_EP)+1]==(BYTE)(crcCheck/256)))
			{
				//AfxMessageBox("R_305����ͷ��CRCУ��ͨ��");
				memcpy(m_pDlg->pdata_r305,buff,sizeof(S_UWMU_2_DSU_EP));
				memcpy(m_pDlg->page2->power_infor_page2,&(m_pDlg->pdata_r305->POCUfeedback),sizeof(POWER_INFO));  //�ںͶ���ϵͳ��ʾ��������ʾ����ϵͳ�ͻ������Ƶ�Ԫ��Ϣ
	            //memcpy(m_pDlg->page2->prcu_info_page2,&(m_pDlg->pdata_r305->PRCUfeedback),sizeof(PRCU_INFO));
				m_pDlg->ProcData_FAULT_R305();
				m_pDlg->FuZhi_CC_S024();
				m_pDlg->FuZhi_SCH_S01_R305();
				m_pDlg->SSCCSocket->Send(m_pDlg->sendata_s024,sizeof(AWRU_AWMU_S024)+3,0);
			}
			else
				AfxMessageBox("����R_305CRCУ�����");
		}
		if((buff[0]==0x5A)&&(buff[2]==0x04)&&(buff[3]==0x30))  //����R_304,ģʽ�л�ȷ�ϱ���
		{
			memcpy(m_pDlg->pdata_r304,buff,sizeof(S_UWMU_2_AWMU_EA1));
			unsigned short crcCheck=0;
			if(buff[sizeof(S_UWMU_2_AWMU_EA1)+3-1]==0x0d)
				crcCheck=m_pDlg->CRC16((unsigned char*)buff,sizeof(S_UWMU_2_AWMU_EA1));
			else 
				AfxMessageBox("����β����");
			if((buff[sizeof(S_UWMU_2_AWMU_EA1)]==crcCheck%256)&&(buff[sizeof(S_UWMU_2_AWMU_EA1)+1]==crcCheck/256))
			{
				if(m_pDlg->pdata_r304->modeSwitchAck==0x00)      //ģʽ�л�����δȷ�ϣ��ٴ��·�
					m_pDlg->SSSXSocket->SendTo(m_pDlg->sendata_s034,11,0,NULL);   
				else
				{
					m_pDlg->KillTimer_19();
					m_pDlg->FuZhi_SCH_S01_R304();
					if(0x01==m_pDlg->pdata_r10->workingMode)  //�е�������ת�ٸ������ƹ���
					{
						m_pDlg->page1->m_speed_cmd=0;
						m_pDlg->page1->SetDlgItemText(IDC_EDIT_SPEED_CMD,"0");
						m_pDlg->Auto_timer_start();
					}
					if(0x00==m_pDlg->pdata_r10->workingMode)  //�е�ң�غ�,������������
					{
						m_pDlg->Auto_timer_end();
						if((m_pDlg->pdata_r10->workingStage==0x00)&&(m_pDlg->pdata_r10->workingMode==0x00)&&(m_pDlg->page1->m_ksdd_flag==true))
							{
								m_pDlg->SetTimer_1();
						    }
					}
					//AfxMessageBox("������ģʽ�л�������ȷ��");

					//m_pDlg->ChangeTimer_S03();
					//m_pDlg->AfterModeSwitch_S02();
					//AfxMessageBox("ģʽ�л�������ȷ��");
					//CString str,strtemp;
			       // for(int i=0;i<9;i++)
			         // {strtemp.Format(" %02X",buff[i]);str+=strtemp;}
				//	AfxMessageBox(str);

				}
			}
		}
		if((buff[0]==0xA5)&&(buff[1]==0x10)&&(buff[2]==0x00)&&(buff[34]==0x0D))  //�ֲٺ�������ϢR_10
		{
			//AfxMessageBox("sd");
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CalculateSendCRC(buff,32);
			//if((buff[33]==crcCheck%256)&&(buff[32]==crcCheck/256))
				memcpy(m_pDlg->recdata_r10_wx,buff,35);  //��ֵ��recdata_r10_wx
				m_pDlg->SCHSocket->Send(m_pDlg->sendata_s01,23,0);
				/*CString str,strtemp;
				for(int i=0;i<23;i++)
				{
					strtemp.Format("%02X",m_pDlg->sendata_s01[i]);
					str+=strtemp;
				}
				if(!m_pDlg->file.fail())
		{
		   m_pDlg->file<<endl<<str;
		}*/
				m_pDlg->FuZhi_CC_S029(buff); //��ֵ�����ݴ洢
		}
		//if((buff[0]==0x5a)&&(buff[2]==0x00)&&(buff[3]==0x30))//�˶�
			//m_pDlg->m_txjs_sxzk+=1;
		if((buff[0]==0x5a)&&(buff[2]==0x01)&&(buff[3]==0x30))//R_301����Ԥ�÷���
		{
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(buff,sizeof(S_UWMU_2_AWMU_EA));
			if((buff[sizeof(S_UWMU_2_AWMU_EA)]==crcCheck%256)&&(buff[sizeof(S_UWMU_2_AWMU_EA)+1]==crcCheck/256))
			{
				memcpy(m_pDlg->pdata_r301,buff,sizeof(S_UWMU_2_AWMU_EA));
				if((m_pDlg->pdata_r301->BaoWenIndex==0x01)&&(m_pDlg->pdata_r301->missionPresetStatus==0x01))
				{
					m_pDlg->rwyz_fs_flag[0]=true;
					//AfxMessageBox("����Ԥ�ñ���һ��ȷ��");
					m_pDlg->SSSXSocket->SendTo(m_pDlg->sendata_s031_2,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);
				}
				else if((m_pDlg->pdata_r301->BaoWenIndex==0x02)&&(m_pDlg->pdata_r301->missionPresetStatus==0x01))
				{
					m_pDlg->rwyz_fs_flag[1]=true;
					//AfxMessageBox("����Ԥ�ñ��Ķ���ȷ��");
					m_pDlg->SSSXSocket->SendTo(m_pDlg->sendata_s031_3,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);
				}
				else if((m_pDlg->pdata_r301->BaoWenIndex==0x03)&&(m_pDlg->pdata_r301->missionPresetStatus==0x01))
				{
					m_pDlg->rwyz_fs_flag[2]=true;
					//AfxMessageBox("����Ԥ�ñ�������ȷ��");
					m_pDlg->SSSXSocket->SendTo(m_pDlg->sendata_s031_4,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);
				}
				else if((m_pDlg->pdata_r301->BaoWenIndex==0x04)&&(m_pDlg->pdata_r301->missionPresetStatus==0x01))
				{
					m_pDlg->rwyz_fs_flag[3]=true;
					AfxMessageBox("�������سɹ�");
					m_pDlg->SSCCSocket->Send(m_pDlg->sendata_s027_1,sizeof(AWRU_AWMU_S027_1)+3,0);
				}
				else 
				{
					int index=0;
					for(int i=0;i<4;i++)
						if(m_pDlg->rwyz_fs_flag[i]==false)
						{index=i;num_fs_rw[i]++;break;}
					if(num_fs_rw[index]==3)
						AfxMessageBox("����Ԥ�ñ���3�η���ʧ�ܣ�������������");
					else
					{
						if(index==0)
							m_pDlg->SSSXSocket->SendTo(m_pDlg->sendata_s031_1,sizeof(S_AWMU_2_UWMU_EA_1)+3,0,NULL);
						else if(index==1)
							m_pDlg->SSSXSocket->SendTo(m_pDlg->sendata_s031_2,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);
						else if(index==2)
							m_pDlg->SSSXSocket->SendTo(m_pDlg->sendata_s031_3,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);
						else if(index==3)
							m_pDlg->SSSXSocket->SendTo(m_pDlg->sendata_s031_4,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);
						else{}
					}
				}
			}
			else
				AfxMessageBox("����Ԥ�÷�������CRCУ�����");
		}
		if((buff[2]==0x07)&&(buff[3]==0x20))  //����R_207
		{
			if(buff[4]==0x01)
			{m_pDlg->SSCCSocket->Send(m_pDlg->sendata_s027_2,sizeof(AWRU_AWMU_S027_2)+3,0);}
			if(buff[4]==0x02)
			{m_pDlg->SSCCSocket->Send(m_pDlg->sendata_s027_3,sizeof(AWRU_AWMU_S027_2)+3,0);}
			if(buff[4]==0x03)
			{m_pDlg->SSCCSocket->Send(m_pDlg->sendata_s027_4,sizeof(AWRU_AWMU_S027_2)+3,0);}
		}
		if((buff[2]==0x02)&&(buff[3]==0x70))  //����R_7002 ��ʱ���ķ���
		{
			memcpy(m_pDlg->pdata_r7002,buff,sizeof(EMU_2_AWMU_EA_TIMESET));		
		}
		if((buff[2]==0x00)&&(buff[3]==0x70))  //����R_70
		{

			CString str,strtemp;
			/*for(int i=0;i<sizeof(S_EMU_2_AWMU_EP)+3;i++)
				{strtemp.Format("%02x ",buff[i]);str+=strtemp;}
			ofstream file("log.txt",ios::trunc);   //������Ϣд��rwyz.txt  trunc�ǽ���ǰ���ļ��Ƴ�  app�����ļ�ĩβд��
			if(!file.fail())
			{
				file<<str<<endl;
			}
			file.close();*/
			//AfxMessageBox("����R_70");
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(buff,sizeof(S_EMU_2_AWMU_EP));
			strtemp.Format("%04x ",crcCheck);
			str+=strtemp;
			strtemp.Format("%02x %02x",buff[sizeof(S_EMU_2_AWMU_EP)],buff[sizeof(S_EMU_2_AWMU_EP)+1]);
			str+=strtemp;
			//AfxMessageBox(str);
			if((buff[sizeof(S_EMU_2_AWMU_EP)]==crcCheck%256)&&(buff[sizeof(S_EMU_2_AWMU_EP)+1]==crcCheck/256))
			{
				//AfxMessageBox("����R_70У��ͨ��");
				memcpy(m_pDlg->pdata_r70,buff,sizeof(S_EMU_2_AWMU_EP));
				if(m_pDlg->pdata_r70->selfTestEndVerify==0x01);
					//AfxMessageBox("�Լ������ȷ��");
				memcpy(m_pDlg->page2->power_infor_page2,&(m_pDlg->pdata_r70->powerSystemInfo),sizeof(POWER_INFO));  //�ںͶ���ϵͳ��ʾ��������ʾ����ϵͳ�ͻ������Ƶ�Ԫ��Ϣ 
				if(0x01==m_pDlg->pdata_r70->EMUselfTestStatus) //�ڼ��ؽ�����ʾ�Ƿ�����Լ� 20180722
					m_pDlg->page1->pdata_page1->selfTest_light_state=true;
				else
					m_pDlg->page1->pdata_page1->selfTest_light_state=false;
				m_pDlg->FuZhi_SCH_S01_R70();
				m_pDlg->FuZhi_CC_S022();
				m_pDlg->SSCCSocket->Send(m_pDlg->sendata_s022,sizeof(AWMU_AWRU_S022)+3,0);
				m_pDlg->ProcData_YJ_R70();
			}
			else
				AfxMessageBox("����R_70CRCУ�����");
		}
		if((buff[0]==0x5a)&&(buff[1]==0x60))     //�������Ƶ�Ԫ���ñ���
		{
			if(buff[3]==0x0a)
			{
				if(buff[2]==1)
				{m_pDlg->page3->drawpicture(IDC_PICTURE_FSCG_WKD,1);m_pDlg->page3->m_wkdcspzFlag=true;}
				else if(buff[2]==2)
				{m_pDlg->page3->drawpicture(IDC_PICTURE_FSCG_FXD,1);m_pDlg->page3->m_fxdcspzFlag=true;}
				else if(buff[2]==3)
				{m_pDlg->page3->drawpicture(IDC_PICTURE_FSCG_ZWD,1);m_pDlg->page3->m_zwdcspzFlag=true;}
				else if(buff[2]==4)
				{m_pDlg->page3->drawpicture(IDC_PICTURE_FSCG_YWD,1);m_pDlg->page3->m_ywdcspzFlag=true;}
				else{}
			}
			if(buff[3]==0x0b)
			{
				if(buff[2]==1)
					m_pDlg->page3->drawpicture(IDC_PICTURE_CCWC_WKD,1);
				else if(buff[2]==2)
					m_pDlg->page3->drawpicture(IDC_PICTURE_CCWC_FXD,1);
				else if(buff[2]==3)
					m_pDlg->page3->drawpicture(IDC_PICTURE_CCWC_ZWD,1);
				else if(buff[2]==4)
					m_pDlg->page3->drawpicture(IDC_PICTURE_CCWC_YWD,1);
				else{}
			}
		}
		if((buff[0]==0x5a) && (buff[1]==0x01))
		{
			m_pDlg->page_cspz_yj_3->Draw();
		}
	}
	CSocket::OnReceive(nErrorCode);
}

IMPLEMENT_DYNAMIC(CSessionSocket,CSocket)