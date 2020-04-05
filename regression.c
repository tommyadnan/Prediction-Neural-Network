#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void uji(double w0,double w1, double w2,double w3,double x1[],double x2[],double x3[],double alp,double target[]);

void jst(double w0,double w1,double w2,double w3,double x1[],double x2[],double x3[],double target[],double alp){
	int epoch,i;
	double in,gin,gint,err;
	double sse=0;
	double mse;
	for(epoch=1;epoch<=100;epoch++){
		printf("epoch %d\n",epoch);
		printf("w0\tw1\tw2\tw3\tin\tgin\tgint\terr\tsse\t\tw0 update\tw1 update\tw2 update\tw3 update\n");
		for(i=0;i<20;i++){
			printf("%.3f\t%.3f\t%.3f\t%.3f\t",w0,w1,w2,w3);
			in=w0+w1*x1[i]+w2*x2[i];
			gin=1/(1+exp(-in));
			gint=gin*(1-gin);
			err=target[i]-gint;
			w0=w0+alp*err*gint*1;
			w1=w1+alp*err*gint*x1[i];
			w2=w2+alp*err*gint*x2[i];
			w3=w3+alp*err*gint*x3[i];
			sse=sse+err*err;
			printf("%.3f\t%.3f\t%.3f\t%.3f\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",in,gin,gint,err,sse,w0,w1,w2,w3);
		}
		mse=sse/i;
		sse=0;
		printf("\n\n");
		uji(w0,w1,w2,w3,x1,x2,x3,alp,target);
	}
}

void uji(double w0,double w1, double w2,double w3,double x1[],double x2[],double x3[],double alp,double target[]){
	int predict,i;
	double ps=0,in,gin,gint,err,mse,sse;
	printf("pengujian\n");
	printf("w0\t\tw1\t\tw2\t\tw3\t\talpha\tin\tg(in)\terror\tg'(in)\tsse\n");
	for(i=15;i<20;i++){
		in=w0+w1*x1[i]+w2*x2[i]+w3*x3[i];
		gin=1/(1+exp(-in));
		gint=gin*(1-gin);
		err=target[i]-gint;
		sse=err*err;
		printf("%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.4f\t",w0,w1,w2,w3,alp,in,gin,err,gint,sse);
		printf("\n");
	}
	printf("\n\tMSE: %f ",sse/5);
	printf("\n\n\n");
}

void main(){
	double	w0=((double)rand())/10000000000,
			w1=((double)rand())/10000000000,
			w2=((double)rand())/10000000000,
			w3=((double)rand())/10000000000;
	double x1[20]={2.131890483,1.323885928,0.776095862,0.987680339,2.399896413,1.081660751,2.316607926,1.425020606,2.363263913,1.535528449,1.33568501,1.760189282,1.568517523,1.735689059,1.760028934,0.469573043,0.849016674,1.525853767,1.334266831,2.223231064};
	double x2[20]={1.055384279,1.49579372,1.70350775,1.351191219,0.679693486,1.080676695,1.099353398,1.454996823,1.323514135,0.870868659,1.669351361,1.15083159,0.426149398,0.837301831,0.126095092,1.641712302,0.287479618,0.848441557,1.439090678,1.112826577};
	double x3[20]={-1.471117348,-1.526112772,-0.906629973,-0.012252564,-1.521340226,-1.269106584,-0.431126666,-0.108883956,-1.348431157,-0.397339887,-0.872477734,-0.259393938,-0.674986607,-0.730985567,-0.954516948,-1.420859509,-1.273478865,-1.962164391,-1.364906869,-0.662943509};
	double target[20]={0.029826521,0.093974477,0.542682841,0.999674005,-0.177142784,-0.023636441,0.821144958,1.081783446,0.322859454,0.551488964,0.658013405,0.860961054,0.096902519,0.337829013,-0.240499021,0.084340334,-0.5491441,-0.559279386,0.174872964,0.648281703};
	double alp=0.01;
	printf("%f",x1[0]);
	jst(w0,w1,w2,w3,x1,x2,x3,target,alp);
}