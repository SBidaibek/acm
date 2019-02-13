#include<bits/stdc++.h>
#include "grader.h"

using namespace std;

vector < int > findSequence (int N)
{
    vector < int > ans (N, 0);
    if (isSubsequence ({0, 1})) ans[0] = 1;
    return ans;
}

