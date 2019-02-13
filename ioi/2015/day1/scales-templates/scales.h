//#ifndef __SCALES_H__
//#define __SCALES_H__

//extern "C" {

void init(int T);
void orderCoins();
void answer(int C[]);

int getMedian(int A, int B, int C);
int getHeaviest(int A, int B, int C);
int getLightest(int A, int B, int C);
int getNextLightest(int A, int B, int C, int D);

//}

//#endif /* __SCALES_H__ */
