#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void uji(double w0,double w1, double w2,double x1[],double x2[],double alp,int y[]);

void jst(double w0,double w1,double w2,double x1[],double x2[],int y[],double alp){
	int epoch,i;
	double in,gin,gint,err;
	double sse=0;
	double mse;
	for(epoch=1;epoch<=100;epoch++){
		printf("epoch %d\n",epoch);
		printf("w0\tw1\tw2\talpha\tin\tgin\tgint\terr\tsse\t\tw0 update\tw1 update\tw2 update\n");
		for(i=0;i<45;i++){
			printf("%.3f\t%.3f\t%.3f\t",w0,w1,w2);
			in=w0+w1*x1[i]+w2*x2[i];
			gin=1/(1+exp(-in));
			gint=gin*(1-gin);
			err=y[i]-gint;
			w0=w0+alp*err*gint*1;
			w1=w1+alp*err*gint*x1[i];
			w2=w2+alp*err*gint*x2[i];
			sse=sse+err*err;
			printf("%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t\t%.5f\t\t%.5f\t\t%.5f\n",alp,in,gin,gint,err,sse,w0,w1,w2);
		}
		mse=sse/i;
		sse=0;
		printf("\n\n");
		uji(w0,w1,w2,x1,x2,alp,y);
	}
}

void uji(double w0,double w1, double w2,double x1[],double x2[],double alp,int y[]){
	int predict[45],i;
	double ps=0,in,gin,gint;
	printf("pengujian\n");
	printf("w0\tw1\tw2\talpha\tin\tg(in)\tg'(in)\tprediction\n");
	for(i=0;i<5;i++){
		in=w0+w1*x1[i]+w2*x2[i];
		gin=1/(1+exp(-in));
		gint=gin*(1-gin);
		if(gint<=alp*1){
			predict[i]=3;
		}else if(gint>alp*1.6){
			predict[i]=2;
		}else predict[i]=1;
		printf("%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t    %d ",w0,w1,w2,alp,in,gin,gint,predict[i]);
		if(predict[i]==y[i]){
			printf("*");
			ps++;
		}
		printf("\n");
	}
	for(i=15;i<20;i++){
		in=w0+w1*x1[i]+w2*x2[i];
		gin=1/(1+exp(-in));
		gint=gin*(1-gin);
		if(gint<=alp*1){
			predict[i]=3;
		}else if(gint>alp*1.6){
			predict[i]=2;
		}else predict[i]=1;
		printf("%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t    %d ",w0,w1,w2,alp,in,gin,gint,predict[i]);
		if(predict[i]==y[i]){
			printf("*");
			ps++;
		}
		printf("\n");
	}
	for(i=30;i<35;i++){
		in=w0+w1*x1[i]+w2*x2[i];
		gin=1/(1+exp(-in));
		gint=gin*(1-gin);
		if(gint<=alp*1){
			predict[i]=3;
		}else if(gint>alp*1.6){
			predict[i]=2;
		}else predict[i]=1;
		printf("%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t    %d ",w0,w1,w2,alp,in,gin,gint,predict[i]);
		if(predict[i]==y[i]){
			printf("*");
			ps++;
		}
		printf("\n");
	}
	printf("\n\tAkurasi: %f %%",(ps/15)*100);
	printf("\n\n\n");
}

void main(){
	double	w0=((double)rand())/10000000000,
			w1=((double)rand())/10000000000,
			w2=((double)rand())/10000000000;
	double x1[45]={3.2,3.40 ,4.30 ,2.30 ,2.50 ,2.60 ,3.50 ,4.10 ,3.45 ,2.65 ,3.50 ,4.50 ,3.56 ,3.15 ,2.75 ,-0.50 ,-1.50 ,-1.30 ,-1.35 ,-2.50 ,-2.60 ,-1.45 ,-1.75 ,-2.10 ,-2.15 ,-1.25 ,-2.10 ,-2.25 ,-1.65 ,-2.25 ,2.20 ,3.40 ,2.30 ,1.50 ,2.50 ,2.40 ,3.50 ,2.60 ,3.40 ,2.30 ,1.45 ,2.35 ,1.24 ,1.45 ,2.45};
	double x2[45]={2.4,2.3,3.3,3.4,2.5,4.1,2.65,3.45,3.65,2.5,2.75,2.85,3.75,2.65,3.45,0.2,0.3,-1.4,-1.35,0.1,-1.75,-1.1,-1.25,-1.75,-2.25,-1.15,-2.3,-2.35,0.15,-1.15,-1,-1.2,-2.3,-2.3,-1.3,-1.25,-1.1,-2.1,-1.5,-1.4,-3.2,-2.3,-3.2,-2.1,-2.22};
	int y[45]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
	double alp=0.01;
	jst(w0,w1,w2,x1,x2,y,alp);
}
