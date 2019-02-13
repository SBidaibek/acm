#ifndef __GRADER_H__
#define __GRADER_H__

#ifdef __cplusplus
extern "C" {
#endif

int besthub(int R, int L, int X[], long long B);

typedef int (*besthubFunction)(int R, int L, int X[], long long B);

#ifdef __cplusplus
}
#endif

#endif /* __GRADER_H__ */
