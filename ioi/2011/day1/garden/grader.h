#ifndef __GRADER_H__
#define __GRADER_H__

#ifdef __cplusplus
extern "C" {
#endif

void answer(int x);

void count_routes(int N, int M, int P, int R[][2], int Q, int G[]);
typedef void (*count_routesFunction)(int N, int M, int P, int R[][2], int Q, int G[]);
#ifdef __cplusplus
}
#endif

#endif /* __GRADER_H__ */
