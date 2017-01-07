
void io_hlt(void);

void HariMain(void){
fin:
		io_hlt();//CALL HLT
		goto fin;
}